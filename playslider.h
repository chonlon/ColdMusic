#ifndef PLAYSLIDER_H
#define PLAYSLIDER_H

#include <QObject>
#include <QSlider>
#include <QEvent>
#include <QMouseEvent>
#include <QCoreApplication>

class PlaySlider:public QSlider
{
    Q_OBJECT
public:
    PlaySlider(QWidget* parent=0) : QSlider(parent) {}
protected:
    void mousePressEvent(QMouseEvent *event);
signals:
    // 点击后更新歌曲进度
    void playSliderPressed(int position);
};

#endif // PLAYSLIDER_H
