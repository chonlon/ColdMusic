#include "contentwidget.h"
#include "ui_contentwidget.h"

ContentWidget::ContentWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ContentWidget)
{
	ui->setupUi(this);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //ui->tableWidget->setWindowOpacity(0.1);
    //QPalette pal = ui->tableWidget->palette();
       // pal.setBrush(this->backgroundRole(),QBrush(QPixmap("")) );
//        QPalette palette;
//        palette.setColor(QPalette::Background, QColor(192,253,123,100)); // 最后一项为透明度
//        palette.setBrush(QPalette::Background, QBrush(QPixmap(":/background/resource/background/transparent.png")));
//        ui->tableWidget->setPalette(palette);
    ui->tableWidget->setStyleSheet("background-color:rgba(255,255,255,128)");
//    QPalette pll = ui->tableWidget->palette();
//    pll.setBrush(QPalette::Base,QBrush(QColor(255,255,255,0)));
//    ui->tableWidget->setPalette(pll);
	//ui->tableWidget->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");
	//ui->tableWidget->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
}
void ContentWidget::addMusicToList(){}
ContentWidget::~ContentWidget()
{
	delete ui;
}
