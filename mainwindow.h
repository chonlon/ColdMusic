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
#include <synchapi.h>

#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <thread>

class MusicPlayer;

extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/dict.h>
}

#include "titlebar.h"
#include "bottombarui.h"
#include "leftsidebarui.h"
#include "contentwidget.h"
#include "music_play/songinfro.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
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
private slots:
    void play();
    void pause();
signals:
    void updatePlayList(const std::vector<SongInfro>& list);
protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
	void initUI();
	void initPlayer();
    void initConnect();
private:
    TitleBar* m_title_bar_;
    QVBoxLayout *p_layout_;
    QTableWidget *m_playlist_table_;
	QWidget* centerWindow;
    BottomBarUI* m_bottom_bar_;
    LeftSideBarUI* m_leftSide_bar_;
    ContentWidget* m_content_widget_;
    MusicPlayer* player_;

    int position;
    const QStringList* list;
    std::vector<SongInfro> playList;
};

#endif // MAINWINDOW_H
