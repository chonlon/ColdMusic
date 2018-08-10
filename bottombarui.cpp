#include "bottombarui.h"
#include "ui_bottombarui.h"

BottomBarUI::BottomBarUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottomBarUI)
{
    ui->setupUi(this);
}

BottomBarUI::~BottomBarUI()
{
    delete ui;
}
