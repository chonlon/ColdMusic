#ifndef BOTTOMBARUI_H
#define BOTTOMBARUI_H

#include <QWidget>

namespace Ui {
class BottomBarUI;
}

class BottomBarUI : public QWidget
{
    Q_OBJECT

public:
    explicit BottomBarUI(QWidget *parent = 0);
    ~BottomBarUI();

private:
    Ui::BottomBarUI *ui;
};

#endif // BOTTOMBARUI_H
