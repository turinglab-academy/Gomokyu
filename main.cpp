#include "gomokyuwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GomokyuWindow wndMain;

    wndMain.setWindowTitle("온라인 오목");
    wndMain.show();
    return app.exec();
}
