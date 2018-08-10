#ifndef LEFTSIDEBARUI_H
#define LEFTSIDEBARUI_H

#include <QWidget>

namespace Ui {
class LeftSideBarUI;
}

class LeftSideBarUI : public QWidget
{
    Q_OBJECT

public:
    explicit LeftSideBarUI(QWidget *parent = 0);
    ~LeftSideBarUI();

private:
    Ui::LeftSideBarUI *ui;
};

#endif // LEFTSIDEBARUI_H
