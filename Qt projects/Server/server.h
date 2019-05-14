#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "D:\Qt projects\lab\database.h"
//#include "LPbase.h"
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>


class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent=nullptr);
    ~Server();
public slots:
    void slotNewConnection();//âõîä
    void slotClientDis();//âûõîä
    //void slotServerRead();// ÷òåíèå
    void slotReadClient();
    void slotSendToCLient(QString mess);

private:
    QTcpServer * mtser;
    //QTcpSocket * mtsoc;
    int server_status;
    QMap<int,QTcpSocket *> SClient;
    //QSqlDatabase db;
    //QSqlQuery query(db);
};
