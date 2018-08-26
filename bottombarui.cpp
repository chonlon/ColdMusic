#include "bottombarui.h"
#include "ui_bottombarui.h"

#include <QDebug>

BottomBarUI::BottomBarUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BottomBarUI)
{
	ui->setupUi(this);
    ui->volume_slider->setValue(50);
    playState = PLAYING;
    connect(ui->volume_slider, SIGNAL(sliderMoved(int)), SLOT(on_volume_slider_sliderMoved(int)));
    connect(ui->next_btn, SIGNAL(clicked(bool)), this, SIGNAL(nextbtnClicked()));
    connect(ui->play_btn, SIGNAL(clicked(bool)), this,SLOT(playpauseSong()));
    connect(ui->previous_btn, SIGNAL(clicked(bool)), this, SIGNAL(previousbtnClicked()));
    connect(ui->play_slider, SIGNAL(sliderMoved(int)), this, SIGNAL(playSliderMoved(int)));
    connect(ui->play_slider, SIGNAL(playSliderPressed(int)), this, SIGNAL(playSliderPressed(int)));
    connect(ui->play_slider, SIGNAL(sliderReleased()), this, SIGNAL(playSliderRelased()));
}

void BottomBarUI::setSliderPosition(qint64 position, qint64 totalTime) {
	if (!totalTime) return;
	//if (!ui->horizontalSlider->isSliderDown());

	//这3个参数分别代表了时，分，秒；60000毫秒为1分钟，所以分钟第二个参数是先除6000,第3个参数是直接除1s
	QTime total_time(0, (totalTime / 60000) % 60, (totalTime / 1000) % 60);

	//传进来的time参数代表了当前的时间
	QTime current_time(0, (position / 60000) % 60, (position / 1000) % 60);
	ui->label->setText(current_time.toString(tr("mm:ss")));
    ui->label_2->setText(total_time.toString(tr("mm:ss")));
	int ss = (100 * position) / totalTime;
	ui->play_slider->setValue(ss);
}
BottomBarUI::~BottomBarUI()
{
	delete ui;
}

void BottomBarUI::on_volume_slider_sliderMoved(int position)
{
    //qDebug()<<"slider moved "<<position;
    emit volumeSliderValueChanged(position);
}


void BottomBarUI::playpauseSong() {
    if(playState == PLAYING) {
        qDebug()<<"playing";
       ui->play_btn->setStyleSheet("QPushButton{border-image: url(:/icon/resource/icon/play_normal.png);}\
                                       QPushButton:hover{border-image: url(:/icon/resource/icon/play_hover.png);}\
                                       QPushButton:pressed{border-image: url(:/icon/resource/icon/play_hover.png);}");
       emit pauseSong();
       playState = PAUSING;
    } else if(playState == PAUSING) {
        qDebug()<<"pausing";
        ui->play_btn->setStyleSheet("QPushButton{border-image: url(:/icon/resource/icon/pause_normal.png);}\
                                        QPushButton:hover{border-image: url(:/icon/resource/icon/pause_hover.png);}\
                                        QPushButton:pressed{border-image: url(:/icon/resource/icon/pause_hover.png);}");
        emit playSong();
        playState = PLAYING;
    }
}

void BottomBarUI::on_play_slider_sliderPressed()
{

}

void BottomBarUI::on_pushButton_6_clicked()
{
    qDebug()<<"------------触发--------------";
    emit showPlayListBtnClicked();
}

void BottomBarUI::on_volume_btn_clicked()
{
    emit volume_btnClicked();
}
