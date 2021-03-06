#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDesktopWidget>
#include <QIcon>
#include <QList>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <synchapi.h>

#include <cstring>
#include <string>
#include <thread>
#include <utility>
#include <vector>

extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/dict.h>
}

class TitleBar;
class BottomBarUI;
class LeftSideBarUI;
class ContentWidget;
class MusicPlayer;

#include "music_play/songinfro.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    /// 更新bottomui的播放slider和lable(其实这里函数名还是该加上lable的)
    void update_SliderPosition(qint64 position);

    /// 更新播放列表, 包括musicplayer的播放列表和contentui的显示信息
    void update_PlayList(const QStringList &list);

    /// 设置音量
    void setPlayerVolume(int value);

    void setNextSong();
    void setPreviousSong();

    // 这三个函数配合, 当播放条被点击的时候, 改变歌曲进度
    void playSliderMoved(int position);
    void playSliderReleased();
    void playSliderPressed(int position);

    /// 跳出新窗口显示播放列表
    void showPlayList();

    /// 当音量按钮被按下的时候改变音量状态(静音和非静音)
    void volume_btnClicked();

    void emitUpdatePlyalistSignal();
private slots:
    void play();
    void pause();
signals:
    void updatePlayList(const std::vector<SongInfro> &list);

protected:
    virtual void mousePressEvent(QMouseEvent *event);

private:
    void initUI();
    void initPlayer();
    void initConnect();

private:
    TitleBar *m_title_bar_;
    QVBoxLayout *p_layout_;
    QTableWidget *m_playlist_table_;
    QWidget *centerWindow;
    BottomBarUI *m_bottom_bar_;
    LeftSideBarUI *m_leftSide_bar_;
    ContentWidget *m_content_widget_;
    MusicPlayer *player_;

    int position;
    const QStringList *list;
    std::vector<SongInfro> playList;
};

#endif // MAINWINDOW_H
