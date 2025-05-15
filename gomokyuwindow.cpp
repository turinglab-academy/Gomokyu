#include "gomokyuwindow.h"
#include "wndsetting.h"
#include "./ui_gomokyuwindow.h"

GomokyuWindow::GomokyuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GomokyuWindow)
    , timer(new QTimer(this))
    , currentTime(0)
{
    ui->setupUi(this);
    // 위도우의 크기를 880 × 675로 고정
    setFixedSize(880, 675);

    connect(timer, &QTimer::timeout, this, &GomokyuWindow::onTimeout);

    for(int i = 0; i < 10; i++)
    {
        digit[i].load(":/images/no_" + QString::fromStdString(std::to_string(i)) + ".png");
    }

    ui->lblTmOne->setPixmap(digit[0]);
    ui->lblTmTen->setPixmap(digit[0]);
    ui->lblTmHundred->setPixmap(digit[0]);
}

GomokyuWindow::~GomokyuWindow()
{
    delete ui;
}

void GomokyuWindow::on_actionNew_Game_triggered()
{

}


void GomokyuWindow::on_actionSetting_triggered()
{
    wndSetting *wnd = new wndSetting;

    wnd->setWindowTitle("게임 설정");
    wnd->show();
}


void GomokyuWindow::on_actionE_xit_triggered()
{
    close();
}


void GomokyuWindow::on_timerOn_clicked()
{
    timer->start(1000);
}


void GomokyuWindow::on_timerOff_clicked()
{
    timer->stop();
}

void GomokyuWindow::onTimeout()
{
    currentTime = (currentTime + 1) % 30;
    ui->lblTmOne->setPixmap(digit[currentTime % 10]);
    ui->lblTmTen->setPixmap(digit[(currentTime / 10) % 10]);
}

