#include "server.h"
#include <QDebug>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include "crypto.h"
#include <QCryptographicHash>

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
    QByteArray arr,arr_d;
    arr.append(mess);
    crypto c;
    arr_d = c.encryptAES(c.passphrase.toLatin1(),arr);
    socket->write(arr_d);
}

void Server::slotReadClient()
{
    QTcpSocket *clientSocket = (QTcpSocket*)sender();
    int id = (int)clientSocket->socketDescriptor();
    QByteArray array = clientSocket->readAll();
    crypto c;
    QByteArray array_d = c.decryptAES(c.passphrase.toLatin1(),array);
    std::string message;
    message = array_d.toStdString();
    qDebug() << QString::fromStdString(message);
    int pos = message.find(" ");
    //std::string name_of_func = message.substr(0,pos);
    std::string action = message.substr(0, pos);
    message.erase(0,pos+1);
    if(action=="authorize")
    {
        std::string log,pass;
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
        int temp = 0;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
                db.setDatabaseName("Tour");
                if(!db.open())
                    qDebug()<<db.lastError().text();
        QSqlQuery query(db);
        pos = message.find(" ");
        QString t = QString::fromStdString(message.substr(0, pos));
        message.erase(0, pos + 1);
        pos = message.find(" ");
        QString f = QString::fromStdString(message.substr(0, pos));
        message.erase(0, pos + 1);
        pos = message.find(" ");
        QString c = QString::fromStdString(message.substr(0, pos));
        message.erase(0, pos + 1);
        QString m = QString::fromStdString(message);
        query.exec("SELECT * FROM User");
        while(query.next())
             if((query.value(0).toString()==t.toLocal8Bit().constData())&&(query.value(1).toString()==f.toLocal8Bit().constData())
                     &&(query.value(2).toString()==c.toLocal8Bit().constData())&&(query.value(3).toString()==m.toLocal8Bit().constData())){
                 temp=1;
              }
        if(temp==0){
            query.prepare("INSERT INTO User(tour, fio, country, magazine) "
                              "VALUES (:tour, :fio, :country, :magazine)");
            query.bindValue(":tour",t);
            query.bindValue(":fio",f);
            query.bindValue(":country",c);
            query.bindValue(":magazine",m);
            query.exec();
        }
        db.close();
        slotSendToCLient(QString::number(temp));
    } else if(action == "registration"){
        pos = message.find(" ");
        QString log = QString::fromStdString(message.substr(0, pos));
        message.erase(0, pos + 1);
        pos = message.find(" ");
        QString pass = QString::fromStdString(message.substr(0, pos));
        message.erase(0, pos + 1);
       //QByteArray hash, hpass;
       //hpass.append(pass);
       //hash = QCryptographicHash::hash(hpass, QCryptographicHash::Md5);
        //hpass.clear();
        //for(int i = 0; i< hash.size();i++){
          //  hpass.append(hash[i]);
        //}
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
                    query.prepare("INSERT INTO User(login, password, level)"
                                      "VALUES (:login, :password, :level)");
                    query.bindValue(":login",log);
                    //query.bindValue(":password",hpass);
                    query.bindValue(":password",pass);
                    query.bindValue(":level","3");
                    query.exec();
                    qDebug() << "login = " << log
                             << "password = " << pass
                             << "level = " << 3;
                }
                db.close();
                slotSendToCLient(QString::number(temp));
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
        if(name=="Test"){
            pos = message.find(" ");
            QString del =QString::fromStdString(message.substr(0, pos));
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("Test");
            if(!db.open())
               qDebug()<<db.lastError().text();
            QSqlQuery query(db);
            std::string temp = "DELETE FROM User WHERE login = '"+del.toStdString()+"'";
            query.exec(QString::fromStdString(temp));
        }else if(name=="Tour"){
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("Tour");
            if(!db.open())
                qDebug()<<db.lastError().text();
            QSqlQuery query(db);
            pos = message.find(" ");
            QString t = QString::fromStdString(message.substr(0, pos));
            message.erase(0, pos + 1);
            pos = message.find(" ");
            QString f = QString::fromStdString(message.substr(0, pos));
            message.erase(0, pos + 1);
            pos = message.find(" ");
            QString c = QString::fromStdString(message.substr(0, pos));
            message.erase(0, pos + 1);
            QString m = QString::fromStdString(message);
            std::string tem = "DELETE FROM User WHERE tour = '"+t.toStdString()+"' AND fio = '"+f.toStdString()+"' AND country = '"+c.toStdString()+"' AND magazine = '"+m.toStdString()+"'";
            query.exec(QString::fromStdString(tem));
            db.close();
        }
    } else if(action == "change"){
        QString change =QString::fromStdString(message);
        qDebug() << change;
        if(change!="admin"){
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("Test");
            if(!db.open())
               qDebug()<<db.lastError().text();
            QSqlQuery query(db);
            std::string temp;
            query.exec("SELECT * FROM User");
            while(query.next()){
                if(query.value(0).toString()==change){
                    if(query.value(2).toString()=="3")
                        temp = "UPDATE User SET level = 2 WHERE login = '" +change.toStdString()+"'";
                    else if (query.value(2).toString()=="2")
                        temp = "UPDATE User SET level = 3 WHERE login = '" +change.toStdString()+"'";
                    query.exec(QString::fromStdString(temp));
                }
                }
            db.close();
            }
        }
    }


