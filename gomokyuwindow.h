#ifndef GOMOKYUWINDOW_H
#define GOMOKYUWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class GomokyuWindow;
class wndSetting;
}
QT_END_NAMESPACE

class GomokyuWindow : public QMainWindow
{
    Q_OBJECT

public:
    GomokyuWindow(QWidget *parent = nullptr);
    ~GomokyuWindow();

private slots:
    void on_actionNew_Game_triggered();

    void on_actionSetting_triggered();

    void on_actionE_xit_triggered();

    void on_timerOn_clicked();

    void on_timerOff_clicked();

    void onTimeout();

private:
    Ui::GomokyuWindow *ui;
    QTimer *timer;
    unsigned int currentTime;
    QPixmap digit[10];
};
#endif // GOMOKYUWINDOW_H
