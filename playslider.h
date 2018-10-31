#ifndef PLAYSLIDER_H
#define PLAYSLIDER_H
#include <QtCore/QObject>
#include <QObject>
#include <QSlider>
#include <QEvent>
#include <QMouseEvent>
#include <QCoreApplication>

class PlaySlider:public QSlider
{
    Q_OBJECT
public:
    PlaySlider(QWidget* parent=nullptr) : QSlider(parent) {}
protected:
    /// 重载这个函数是为了在鼠标点击窗口的时候把tablewidget销毁
    void mousePressEvent(QMouseEvent *event);
signals:
    /// 点击后更新歌曲进度
    void playSliderPressed(int position);
};

#endif // PLAYSLIDER_H
