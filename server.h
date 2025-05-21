#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

enum class TURN { client, server };

class server : public QTcpServer
{
    QHostAddress ipaddr;
    unsigned int port;
    QTcpSocket *socket;
    TURN turn;

    Q_OBJECT
public:
    server(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr socketDescriptor) override;
};

#endif // SERVER_H
