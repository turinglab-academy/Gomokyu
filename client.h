#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

#include "CommonService.h"

class Client
{
    QHostAddress ipaddr;
    unsigned int port;
    QTcpSocket *socket;
    TURN turn;
public:
    Client();
};

#endif // CLIENT_H
