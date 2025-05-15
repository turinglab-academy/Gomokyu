#ifndef WNDSETTING_H
#define WNDSETTING_H

#include <QFrame>

namespace Ui {
class wndSetting;
}

class wndSetting : public QFrame
{
    Q_OBJECT

public:
    explicit wndSetting(QWidget *parent = nullptr);
    ~wndSetting();

private:
    Ui::wndSetting *ui;
};

#endif // WNDSETTING_H
