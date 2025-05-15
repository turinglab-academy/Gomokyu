#include "wndsetting.h"
#include "ui_wndsetting.h"

wndSetting::wndSetting(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::wndSetting)
{
    ui->setupUi(this);
}

wndSetting::~wndSetting()
{
    delete ui;
}
