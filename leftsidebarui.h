#ifndef LEFTSIDEBARUI_H
#define LEFTSIDEBARUI_H

#include <QWidget>
#include <QList>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QDir>

namespace Ui {
	class LeftSideBarUI;
}

class LeftSideBarUI : public QWidget
{
	Q_OBJECT

public:
	explicit LeftSideBarUI(QWidget *parent = 0);
	~LeftSideBarUI();

signals:
    //已经添加歌曲(多个歌曲), 发射信号以更新列表.
	void addedMusic(const QStringList& list);


    void updatePlayList(const QStringList& list);

private slots:
    //添加音乐按钮被点击, 更新播放列表
    //首先打开一个路径, 读取改路径下的所有歌曲.
	void on_addmusic_clicked();

private:
	Ui::LeftSideBarUI *ui;
};

#endif // LEFTSIDEBARUI_H
