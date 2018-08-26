#include "mainwindow.h"

int volume = 0x65;//最后4位表示现在是否处于静音状态
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	this->initUI();
	this->initPlayer();
    this->initConnect();
    //play->play();
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
	m_bottomBar = new BottomBarUI();
	//侧边栏 (左边)
	m_leftSideBar = new LeftSideBarUI();
	//内容部分
	m_contentWidget = new ContentWidget();
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
}
void MainWindow::update_SliderPosition(qint64 position) {
	this->m_bottomBar->setSliderPosition(position, player->getSongTotalTime());
}

void MainWindow::update_PlayList(const QStringList &list) {
	player->addMusicToList(list);
    this->list = &list;
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
    QTableWidget *playlistTable = new QTableWidget(this);
    playlistTable->setObjectName(QStringLiteral("playlistTable"));
    playlistTable->setGeometry(QRect(747, 345,250,300));
     qDebug()<<"------------触发--------------";
     playlistTable->show();
     //todo 给主窗口添加一个mouseEvent和一个状态(tablewidget是否在显示),
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
MainWindow::~MainWindow()
{
}
