#include "contentwidget.h"
#include "ui_contentwidget.h"
#include <QDebug>

ContentWidget::ContentWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ContentWidget)
{
	ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    ui->tableWidget->setStyleSheet("background-color:rgba(255,255,255,128)");

    //禁止编辑单元格内容
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //选中一行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //去掉水平滚动条
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //垂直滚动条按项移动
    ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    //去除水平表头
    //ui->tableWidget->horizontalHeader()->setFixedHeight(0);
    //去除垂直表头
    ui->tableWidget->verticalHeader()->setFixedWidth(0);
    //设置无边框
    ui->tableWidget->setFrameShape(QFrame::NoFrame);
    //设置不显示格子线
    ui->tableWidget->setShowGrid(false);
    //设置右键菜单
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    //设置背景颜色
    QPalette pal;
    pal.setBrush(QPalette::Base, QBrush(QColor(255, 255, 255)));
    ui->tableWidget->setPalette(pal);
    //设置竖直滚动条样式
    ui->tableWidget->setStyleSheet("QScrollBar{background:transparent; width: 5px;}"
        "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
        "QScrollBar::handle:hover{background:gray;}"
        "QScrollBar::sub-line{background:transparent;}"
        "QScrollBar::add-line{background:transparent;}");
    //使拖动操作生效
    ui->tableWidget->setAcceptDrops(true);
    setAcceptDrops(true);
}

void ContentWidget::updateMusicList(const std::vector<SongInfro>& infroList) {

    const int index_column = 0;
    const int title_column = 1;
    const int artist_column = 2;
    const int album_column = 3;
    const int time_column = 4;
    for(SongInfro i : infroList) {
        qDebug()<<i.currentIndex<<":"<<i.title<<"\n";
        ui->tableWidget->insertRow(i.currentIndex);

        QTableWidgetItem *item_index = new QTableWidgetItem(QString::number(i.currentIndex));
        item_index->setTextColor(QColor(25,25,25));
        item_index->setFont(QString::fromLocal8Bit("微软雅黑", 10));
        ui->tableWidget->setItem(i.currentIndex, index_column, item_index);

        QTableWidgetItem *item_title = new QTableWidgetItem(i.title);
        item_title->setTextColor(QColor(25,25,25));
        item_title->setFont(QString::fromLocal8Bit("微软雅黑", 10));
        ui->tableWidget->setItem(i.currentIndex, title_column, item_title);

        QTableWidgetItem *item_artist = new QTableWidgetItem(i.artist);
        item_artist->setTextColor(QColor(25,25,25));
        item_artist->setFont(QString::fromLocal8Bit("微软雅黑", 10));
        ui->tableWidget->setItem(i.currentIndex, artist_column, item_artist);

        QTableWidgetItem *item_album = new QTableWidgetItem(i.album);
        item_album->setTextColor(QColor(25,25,25));
        item_album->setFont(QString::fromLocal8Bit("微软雅黑", 10));
        ui->tableWidget->setItem(i.currentIndex, album_column, item_album);

        // 将时间(s)转换为显示的时间格式:(xx:xx)
        QString total_time;
        total_time.append(QString::number(i.total_time/60));
        total_time.push_back(":");
        total_time.append(QString::number((i.total_time%60)));

        QTableWidgetItem *item_time = new QTableWidgetItem(total_time);
        item_time->setTextColor(QColor(25,25,25));
        item_time->setFont(QString::fromLocal8Bit("微软雅黑", 10));
        ui->tableWidget->setItem(i.currentIndex, time_column, item_time);
    }

}
void ContentWidget::addMusicToList(){}

ContentWidget::~ContentWidget()
{
	delete ui;
}
