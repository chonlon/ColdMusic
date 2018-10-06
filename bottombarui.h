#ifndef BOTTOMBARUI_H
#define BOTTOMBARUI_H

#include <QWidget>
#include <QTime>

#define PLAYING 0
#define PAUSING 1

namespace Ui {
	class BottomBarUI;
}

class BottomBarUI : public QWidget
{
	Q_OBJECT

public:
	explicit BottomBarUI(QWidget *parent = 0);
	~BottomBarUI();

    //设置播放滑杆的位置(随着歌曲播放改变), 暂时把timelable的值的设置也放到这里面
	void setSliderPosition(qint64 position, qint64 totalTime);

    //这个函数主要是为了在初始化的时候读入数据(上次关闭位置), 设置声音滑杆的位置, 但是暂时不用, 固定为50.
    void setVolumePosition(int position){}

signals:
    void volumeSliderValueChanged(int value);

    void nextbtnClicked();
    void previousbtnClicked();

    void playSong();
    void pauseSong();

    //这里signal的传递是: this->MainWindow->MusicPlayer
    //调整slider的时候调整歌曲进度
    void playSliderRelased();
    void playSliderMoved(int position);
    void playSliderPressed(int position);

    void showPlayListBtnClicked();

    void volume_btnClicked();

private slots:

    void on_volume_slider_sliderMoved(int position);
    //根据现在播放状态设置播放/暂停
    void playpauseSong();

    void on_play_slider_sliderPressed();

    void on_pushButton_6_clicked();
    //设置音量, 值为1到100整数
    void on_volume_btn_clicked();

private:
	Ui::BottomBarUI *ui;
	qint64 song_TotalTime;

    int playState;
};

#endif // BOTTOMBARUI_H
