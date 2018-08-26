#include "contentwidget.h"
#include "ui_contentwidget.h"

ContentWidget::ContentWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ContentWidget)
{
	ui->setupUi(this);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	ui->tableWidget->setWindowOpacity(0.1);
	//ui->tableWidget->setStyleSheet("QTabWidget:pane {border-top:0px solid #e8f3f9;background:  transparent; }");
	//ui->tableWidget->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
}
void ContentWidget::addMusicToList(){}
ContentWidget::~ContentWidget()
{
	delete ui;
}
