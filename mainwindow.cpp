#include "mainwindow.h"

#include "music_play/musplayer_qmediaplayer.h"

static int volume = 0x65;//最后1位表示现在是否处于静音状态
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	this->initUI();
	this->initPlayer();
    this->initConnect();
    //this->setWindowOpacity(0.5);
}

void MainWindow::initPlayer() {
    player_ = new MusicPlayer_QMediaPlayer;
    player_->setVolume(50);
}

void MainWindow::initUI()
{
	//设置窗口无边框(以便自己定义窗口边框)
	setWindowFlags(Qt::FramelessWindowHint);

	//设置窗口大小属性
	setFixedSize(1022, 670);
	//    this->setMinimumSize(1022, 670);
	//    this->setMaximumHeight(670);
	//    this->setMaximumSize(1400, 900);
    //设置标题栏
    m_title_bar_ = new TitleBar(this);
    installEventFilter(m_title_bar_);
	//底部播放部分
    m_bottom_bar_ = new BottomBarUI(this);
	//侧边栏 (左边)
    m_leftSide_bar_ = new LeftSideBarUI(this);
	//内容部分
    m_content_widget_ = new ContentWidget(this);

    m_playlist_table_ = nullptr;

	//图标
	this->setWindowIcon(QIcon(":/logo/coldmusic_logo.png"));
	this->setWindowTitle("Cold Music");

	//设置背景图片
	centerWindow = new QWidget();
	centerWindow->setAutoFillBackground(true);
	QPalette palette;
	QPixmap pixmap(":/background/bckg.png");
	palette.setBrush(backgroundRole(), QBrush(pixmap));

	//调整布局
	centerWindow->setPalette(palette);
	this->setCentralWidget(centerWindow);
    p_layout_ = new QVBoxLayout(this);
	QHBoxLayout *pHLayout = new QHBoxLayout();
    pHLayout->addWidget(m_leftSide_bar_);
    pHLayout->addWidget(m_content_widget_);
    p_layout_->addWidget(m_title_bar_);
    p_layout_->addLayout(pHLayout);
    p_layout_->addWidget(m_bottom_bar_);
	//pLayout->addStretch();
    p_layout_->setSpacing(0);
    p_layout_->setContentsMargins(0, 0, 0, 0);
    centerWindow->setLayout(p_layout_);
}

void MainWindow::initConnect() {
    connect(player_, SIGNAL(positionChanged(qint64)), this, SLOT(update_SliderPosition(qint64)));
    connect(m_leftSide_bar_, SIGNAL(addedMusic(QStringList)), this, SLOT(update_PlayList(QStringList)));
    //connect(m_leftSideBar, SIGNAL(updatePlayList(QStringList)), this,SLOT(update_PlayListToShow(QStringList)));
    connect(m_bottom_bar_, SIGNAL(volumeSliderValueChanged(int)), this, SLOT(setPlayerVolume(int)));
    connect(m_bottom_bar_, SIGNAL(nextbtnClicked()), this, SLOT(setNextSong()));
    connect(m_bottom_bar_, SIGNAL(previousbtnClicked()), this, SLOT(setPreviousSong()));
    connect(m_bottom_bar_, SIGNAL(playSong()), this, SLOT(play()));
    connect(m_bottom_bar_, SIGNAL(pauseSong()), this, SLOT(pause()));

    //这里两个slot需要配合, 避免拖动slider的时候导致刺耳的声音
    connect(m_bottom_bar_, SIGNAL(playSliderMoved(int)), this, SLOT(playSliderMoved(int)));
    connect(m_bottom_bar_, SIGNAL(playSliderRelased()), this, SLOT(playSliderReleased()));
    //slider被点击的时候
    connect(m_bottom_bar_, SIGNAL(playSliderPressed(int)), this, SLOT(playSliderPressed(int)));
    connect(m_bottom_bar_, SIGNAL(showPlayListBtnClicked()), this, SLOT(showPlayList()));
    connect(m_bottom_bar_, SIGNAL(volume_btnClicked()), this, SLOT(volume_btnClicked()));

    connect(this, SIGNAL(updatePlayList(const std::vector<SongInfro>&)), m_content_widget_, SLOT(updateMusicList(const std::vector<SongInfro>&)));
}

static void getSongsInfor(const QStringList *list, std::vector<SongInfro>* playList){
    AVFormatContext *fmt_ctx = nullptr;
    AVDictionaryEntry *tag = nullptr;

    std::string ba;
    int32_t index = 0;
    //读取所有mp3信息
    for(QString fileName : (*list)) {
        //QString 转string转char*
        //目的是转成本地化编码(gbk)
        ba = fileName.toStdString();
        const char *fileName_const_char = ba.c_str();
        if (avformat_open_input(&fmt_ctx, fileName_const_char, nullptr, nullptr))//throw exception
            return;

       (*playList).emplace_back(index);
        //对于某一个mp3文件, 读取信息
        while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))) {
            if(!strcmp(tag->key, "artist")) {
                QString value = QString::fromUtf8(tag->value);
                (*playList).back().artist = std::move(value);
            } else if(!strcmp(tag->key, "title")) {
                QString value = QString::fromUtf8(tag->value);
                (*playList).back().title = std::move(value);
            } else if(!strcmp(tag->key, "album")) {
                QString value =QString::fromUtf8(tag->value);
                (*playList).back().album = std::move(value);
            }
         }
        playList->back().total_time = fmt_ctx->duration;
        index++;
        avformat_close_input(&fmt_ctx);
    }
}
void MainWindow::update_SliderPosition(qint64 position) {
    this->m_bottom_bar_->setSliderPosition(position, static_cast<qint64>(player_->getSongTotalTime()));
}

void MainWindow::update_PlayList(const QStringList &list) {
    player_->addMusicToList(list);

    //在界面主线程里面分析信息会导致卡顿.
    //所以增加线程, 在子线程里面完成.
    std::thread p(getSongsInfor, &list, &playList);
    p.join();
    if(!this->playList.empty())
        emit updatePlayList(this->playList);

}

void MainWindow::setPlayerVolume(int value) {
    player_->setVolume(static_cast<uint8_t>(value));
    volume &= 1;
    volume = (value<<1) | volume;
}

void MainWindow::setNextSong() {
    player_->setNextSong();
}

void MainWindow::setPreviousSong() {
    player_->setPreviousSong();
}

void MainWindow::playSliderMoved(int position) {
    this->position = position;
}

void MainWindow::playSliderReleased() {
    player_->setDuration(static_cast<uint8_t>(this->position));
}

void MainWindow::playSliderPressed(int position) {
    player_->setDuration(static_cast<uint8_t>(position));
}

void MainWindow::showPlayList() {
    m_playlist_table_ = new QTableWidget();
    m_playlist_table_->setObjectName(QStringLiteral("playlistTable"));
    m_playlist_table_->setGeometry(QRect(747, 345,250,300));
     qDebug()<<"------------触发--------------";
     m_playlist_table_->show();
     //给主窗口添加一个mouseEvent和一个状态(tablewidget是否在显示),
     //tablewidget在显示的时候, mouseEvent函数有效, 点击则销毁这个tablewidget
     //由于tablewidget显示在主窗口上面, 那么优先响应的应该是这个tablewidget的点击(即在tablewidget范围内的点击不会销毁tablewidget)
}

void MainWindow::volume_btnClicked() {
    if(volume & 1) {
        player_->setVolume(0);
        volume &=0xfe;
    } else {
        player_->setVolume(static_cast<uint8_t>(volume >> 1));
        volume |= 1;
    }
}

void MainWindow::play()
{
    player_->play();
}

void MainWindow::pause()
{
    player_->pause();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if(this->m_playlist_table_) {
        delete this->m_playlist_table_;
        this->m_playlist_table_ = nullptr;
    }
}
MainWindow::~MainWindow()
{
}
