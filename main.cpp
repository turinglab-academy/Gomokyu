#include "gomokyuwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GomokyuWindow w;

    w.setWindowTitle("온라인 오목");
    w.show();
    return a.exec();
}
