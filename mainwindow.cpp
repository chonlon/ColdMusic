#include "mainwindow.h"

int volume = 0x65;//最后1位表示现在是否处于静音状态
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	this->initUI();
	this->initPlayer();
    this->initConnect();
    //this->setWindowOpacity(0.5);
}

void MainWindow::initPlayer() {
	player = new MusicPlayer();
	player->setVolume(50);
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
	m_titleBar = new TitleBar(this);
	installEventFilter(m_titleBar);
	//底部播放部分
    m_bottomBar = new BottomBarUI(this);
	//侧边栏 (左边)
    m_leftSideBar = new LeftSideBarUI(this);
	//内容部分
    m_contentWidget = new ContentWidget(this);

    m_playlistTable = NULL;

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
	pLayout = new QVBoxLayout(this);
	QHBoxLayout *pHLayout = new QHBoxLayout();
	pHLayout->addWidget(m_leftSideBar);
	pHLayout->addWidget(m_contentWidget);
	pLayout->addWidget(m_titleBar);
	pLayout->addLayout(pHLayout);
	pLayout->addWidget(m_bottomBar);
	//pLayout->addStretch();
	pLayout->setSpacing(0);
	pLayout->setContentsMargins(0, 0, 0, 0);
	centerWindow->setLayout(pLayout);
}

void MainWindow::initConnect() {
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(update_SliderPosition(qint64)));
    connect(m_leftSideBar, SIGNAL(addedMusic(QStringList)), this, SLOT(update_PlayList(QStringList)));
    //connect(m_leftSideBar, SIGNAL(updatePlayList(QStringList)), this,SLOT(update_PlayListToShow(QStringList)));
    connect(m_bottomBar, SIGNAL(volumeSliderValueChanged(int)), this, SLOT(setPlayerVolume(int)));
    connect(m_bottomBar, SIGNAL(nextbtnClicked()), this, SLOT(setNextSong()));
    connect(m_bottomBar, SIGNAL(previousbtnClicked()), this, SLOT(setPreviousSong()));
    connect(m_bottomBar, SIGNAL(playSong()), player, SLOT(play()));
    connect(m_bottomBar, SIGNAL(pauseSong()), player, SLOT(pause()));

    //这里两个slot需要配合, 避免拖动slider的时候导致刺耳的声音
    connect(m_bottomBar, SIGNAL(playSliderMoved(int)), this, SLOT(playSliderMoved(int)));
    connect(m_bottomBar, SIGNAL(playSliderRelased()), this, SLOT(playSliderReleased()));
    //slider被点击的时候
    connect(m_bottomBar, SIGNAL(playSliderPressed(int)), this, SLOT(playSliderPressed(int)));
    connect(m_bottomBar, SIGNAL(showPlayListBtnClicked()), this, SLOT(showPlayList()));
    connect(m_bottomBar, SIGNAL(volume_btnClicked()), this, SLOT(volume_btnClicked()));

    connect(this, SIGNAL(updatePlayList(const std::vector<SongInfro>&)), m_contentWidget, SLOT(updateMusicList(const std::vector<SongInfro>&)));
}
void MainWindow::update_SliderPosition(qint64 position) {
	this->m_bottomBar->setSliderPosition(position, player->getSongTotalTime());
}

void MainWindow::update_PlayList(const QStringList &list) {
	player->addMusicToList(list);
    AVFormatContext *fmt_ctx = NULL;
    AVDictionaryEntry *tag = NULL;

    std::string ba;
    //读取所有mp3信息
    for(QString fileName : list) {
        //QString 转string转char*
        ba = fileName.toStdString();
        const char *fileName_const_char = ba.c_str();
        if (avformat_open_input(&fmt_ctx, fileName_const_char, NULL, NULL))//throw exception
            return;
        //对于某一个mp3文件, 读取信息
        int index;
        this->playList.emplace_back(index);
        while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))) {
            if(!strcmp(tag->key, "artist")) {
                QString value = QString::fromUtf8(tag->value);
                this->playList.back().artist = std::move(value);
            } else if(!strcmp(tag->key, "title")) {
                QString value = QString::fromUtf8(tag->value);
                this->playList.back().title = std::move(value);
            } else if(!strcmp(tag->key, "album")) {
                QString value = QString::fromUtf8(tag->value);
                this->playList.back().album = std::move(value);
            }
         }
        index++;
        avformat_close_input(&fmt_ctx);
        Sleep(1);
    }
    //this->list = &list;
    emit updatePlayList(this->playList);
}

void MainWindow::setPlayerVolume(int value) {
    player->setVolume(value);
    volume &= 1;
    volume = (value<<1) | volume;
}

void MainWindow::setNextSong() {
    player->nextSong();
}

void MainWindow::setPreviousSong() {
    player->previousSong();
}

void MainWindow::playSliderMoved(int position) {
    this->position = position;
}

void MainWindow::playSliderReleased() {
    player->setDuration(this->position);
}

void MainWindow::playSliderPressed(int position) {
    player->setDuration(position);
}

void MainWindow::showPlayList() {
    m_playlistTable = new QTableWidget(this);
    m_playlistTable->setObjectName(QStringLiteral("playlistTable"));
    m_playlistTable->setGeometry(QRect(747, 345,250,300));
     qDebug()<<"------------触发--------------";
     m_playlistTable->show();
     //给主窗口添加一个mouseEvent和一个状态(tablewidget是否在显示),
     //tablewidget在显示的时候, mouseEvent函数有效, 点击则销毁这个tablewidget
     //由于tablewidget显示在主窗口上面, 那么优先响应的应该是这个tablewidget的点击(即在tablewidget范围内的点击不会销毁tablewidget)
}

void MainWindow::volume_btnClicked() {
    if(volume & 1) {
        player->setVolume(0);
        volume &=0xfe;
    } else {
        player->setVolume(volume >> 1);
        volume<<1;
        volume |= 1;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if(this->m_playlistTable) {
        delete this->m_playlistTable;
        this->m_playlistTable = NULL;
    }
}
MainWindow::~MainWindow()
{
}
