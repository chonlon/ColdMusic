#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QMediaPlayer>
#include <QList>
#include <QTableWidget>

#include "titlebar.h"
#include "bottombarui.h"
#include "leftsidebarui.h"
#include "contentwidget.h"
#include "music_play/musicplayer.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void update_SliderPosition(qint64 position);
	void update_PlayList(const QStringList& list);
    void setPlayerVolume(int value);

    void setNextSong();
    void setPreviousSong();

    void playSliderMoved(int position);
    void playSliderReleased();
    void playSliderPressed(int position);

    void showPlayList();
    void volume_btnClicked();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
	void initUI();
	void initPlayer();
	void initConnect();

private:
	TitleBar* m_titleBar;
	QVBoxLayout *pLayout;
    QTableWidget *m_playlistTable;
	QWidget* centerWindow;
	BottomBarUI* m_bottomBar;
	LeftSideBarUI* m_leftSideBar;
	ContentWidget* m_contentWidget;
	MusicPlayer* player;
	QMediaPlayer *play;

    int position;
    const QStringList* list;
};

#endif // MAINWINDOW_H
