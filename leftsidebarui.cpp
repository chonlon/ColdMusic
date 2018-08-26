#include "leftsidebarui.h"
#include "ui_leftsidebarui.h"
#include <QDebug>
LeftSideBarUI::LeftSideBarUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LeftSideBarUI)
{
	ui->setupUi(this);
}

LeftSideBarUI::~LeftSideBarUI()
{
	delete ui;
}

void LeftSideBarUI::on_addmusic_clicked()
{

    //TODO: 扫描子文件夹
	QString dirPath = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("choose dir"));
	if (dirPath.size() == 0)
		return;
	QDir dir(dirPath);
	QStringList fileList = dir.entryList(QStringList() << "*.mp3" << "*.wav", QDir::Files);

//    //更新playList显示的
//    emit updatePlayList(fileList);

	for (int i = 0; i < fileList.size(); i++) {
		fileList[i] = dir.absoluteFilePath(fileList.at(i));
	}
	//TODO
    //发出信号, 更新当前playList(musicplayer)
	emit addedMusic(fileList);
	//把列表输出到文件中
}
