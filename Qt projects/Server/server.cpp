#include "server.h"
#include <QDebug>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>


Server::Server(QObject *parent)
    : QObject(parent)
{
    mtser = new QTcpServer(this);
    connect(mtser, &QTcpServer::newConnection, this, &Server::slotNewConnection);
    if(!mtser->listen(QHostAddress::Any, 33333)&&server_status==0)
    {
        qDebug() << "Server is not started";
    }
    else {
        server_status = 1;
        qDebug() << "Server is started";
    }


}
Server::~Server()
{
    if (server_status == 1)
    {
        //mtsoc->close();

        foreach(int i, SClient.keys()) {
            QTextStream os(SClient[i]);
            os.setAutoDetectUnicode(true);
            os << QDateTime::currentDateTime().toString() << "\n";
            SClient[i]->close();
            SClient.remove(i);
        }
        mtser->close();
        qDebug() << QString::fromUtf8("server stoped");
        server_status = 0;
    }
}
void Server::slotNewConnection()
{
    if (server_status == 1)
    {
        /*
        mtsoc = mtser->nextPendingConnection();
        mtsoc->write("hello world");
            connect(mtsoc, &QTcpSocket::readyRead, this, &server::slotReadClient);
            connect(mtsoc, &QTcpSocket::disconnected, this, &server::slotClientDis);*/
        qDebug() << QString::fromUtf8("Congratulation, you have a new connection!");
        QTcpSocket* clientSocket =mtser->nextPendingConnection();
        int id = clientSocket->socketDescriptor();
        SClient[id] = clientSocket;
        connect(SClient[id],  SIGNAL(readyRead()), this, SLOT(slotReadClient()));
        connect(SClient[id], &QTcpSocket::disconnected, this, &Server::slotClientDis);
    }
}
void Server::slotClientDis()
{
    QObject * object = QObject::sender();
    QTcpSocket * socket = static_cast<QTcpSocket *>(object);
    socket->close();
}
void Server::slotSendToCLient(QString mess)
{
    QObject * object = QObject::sender();
    QTcpSocket * socket = static_cast<QTcpSocket *>(object);
    QByteArray arr;
    arr.append(mess);
    socket->write(arr);
}

void Server::slotReadClient()
{
    QTcpSocket *clientSocket = (QTcpSocket*)sender();
    int id = (int)clientSocket->socketDescriptor();
    QByteArray array = clientSocket->readAll();
    std::string log,pass;
    std::string message;
    message = array.toStdString();
    qDebug() << QString::fromStdString(message);
    int pos = message.find(" ");
    //std::string name_of_func = message.substr(0,pos);
    std::string action = message.substr(0, pos);
    message.erase(0,pos+1);
    if(action=="authorize")
    {

        pos=message.find(" ");
        log = message.substr(0,pos);
        message.erase(0,pos+1);
        pos=message.find(" ");
        pass = message.substr(0,pos);
        message.erase(0,pos+1);
       // clientSocket->write(authorizing(log,pass));

        qDebug() << "login = " << QString::fromStdString(log)
                 << "password = " << QString::fromStdString(pass)
                 << "level = " << authorizing(QString::fromStdString(log),QString::fromStdString(pass));
        slotSendToCLient(authorizing(QString::fromStdString(log),QString::fromStdString(pass)));
    } else if(action=="add"){

    } else if(action == "registration"){
        pos = message.find(" ");
        QString log = QString::fromStdString(message.substr(0, pos));
        message.erase(0, pos + 1);
        pos = message.find(" ");
        QString pass = QString::fromStdString(message.substr(0, pos));
        message.erase(0, pos + 1);
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("Test");
            if(!db.open())
                qDebug()<<db.lastError().text();
            QSqlQuery query(db);
            int temp=0;
                query.exec("SELECT * FROM User");
                    while(query.next())
                        if(query.value(0).toString()==log){
                            temp=1;
                        }
                if(temp==0){
                    query.prepare("INSERT INTO User(login, password, level) "
                                      "VALUES (:login, :password, :level)");
                    query.bindValue(":login",log);
                    query.bindValue(":password",pass);
                    query.bindValue(":level","3");
                    query.exec();
                    qDebug() << "login = " << log
                             << "password = " << pass
                             << "level = " << 3;
                }
                db.close();
    } else if (action=="show") {
        std::string t;
        DataBase base;
        std::string name = message;
        base.download(QString::fromStdString(name), t);
        slotSendToCLient(QString::fromStdString(t));
    } else if (action=="delete") {
        pos = message.find(" ");
        QString name = QString::fromStdString(message.substr(0, pos));
        message.erase(0, pos + 1);
        std::string del = message;
        qDebug() << name << QString::fromStdString(del);
        if(name=="Test"){
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
                    db.setDatabaseName("Test");
                    if(!db.open())
                        qDebug()<<db.lastError().text();
                    QSqlQuery query(db);
                std::string temp = "DELETE FROM User WHERE login = '"+del+"'";
                query.exec(QString::fromStdString(temp));
        }else if(name=="Tour"){

        }
    }
}

