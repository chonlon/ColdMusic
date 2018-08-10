#include "leftsidebarui.h"
#include "ui_leftsidebarui.h"

LeftSideBarUI::LeftSideBarUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftSideBarUI)
{
    ui->setupUi(this);
}

LeftSideBarUI::~LeftSideBarUI()
{
    delete ui;
}
