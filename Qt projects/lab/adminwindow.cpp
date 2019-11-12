#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "startwindow.h"
#include "database.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "crypto.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 33333);
    connect(socket, SIGNAL(connected()), SLOT(slot_connected()));
    connect(socket, SIGNAL(readyRead()), SLOT(slot_ready_read()));
    slot_send_to_server("show Test");
}
std::string mess;
void AdminWindow::slot_ready_read(){
    QByteArray arr,arr_d;

    while (socket->bytesAvailable() > 0)
    {
        arr = socket->readAll();

    }
    crypto c;
    arr_d = c.decryptAES(c.passphrase.toLatin1(),arr);
    mess = arr_d.toStdString();
    base.transformStr2BD("Test", mess);
    QStandardItem *item;

    qmodel = new QStandardItemModel(0,3,this);
    ui->tableView->setModel(qmodel);
    qmodel->setHeaderData(0, Qt::Horizontal, "login");
    qmodel->setHeaderData(1, Qt::Horizontal, "password");
    qmodel->setHeaderData(2, Qt::Horizontal, "level");
    for (int i = 0; i < base.db.size() ; i++)
    {
        item = new QStandardItem(QString::fromStdString(base.db[i].tour));
        qmodel->setItem(i, 0, item);

        item = new QStandardItem(QString::fromStdString(base.db[i].fio));
        qmodel->setItem(i, 1, item);

        item = new QStandardItem(QString::fromStdString(base.db[i].coun));
        qmodel->setItem(i, 2, item);
    }
}
void AdminWindow::slot_send_to_server(QString message){
    QByteArray array,array_d;
    array.append(message);
    crypto c;
    array_d = c.encryptAES(c.passphrase.toLatin1(),array);
    socket->write(array_d);
}

void AdminWindow::slot_disconected(){

}
AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_actionLogOut_triggered()
{
    StartWindow *w = new StartWindow();
    this->close();
    w->show();
}
QStandardItem *item;
void AdminWindow::on_actionRefresh_triggered()
{
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Test");
    if(!db.open())
        qDebug()<<db.lastError().text();
    QSqlQuery query(db);
    query.exec("CREATE TABLE User("
               "login VARCHAR(20) NOT NULL, "
               "password VARCHAR(20) NOT NULL,"
               "level VARCHAR(20) NOT NULL"
               ")");
    query.prepare("INSERT INTO User(login, password, level) "
                      "VALUES (:login, :password, :level)");
    model = new QSqlTableModel(this, db);
    model->setTable("User");
    model->select();
    ui->tableView->setModel(model);*/
    base.finding("Tour"," ");
    for (int i = 0; i < base.db.size() ; i++)
    {
        item = new QStandardItem(QString::fromStdString(base.db[i].tour));
        qmodel->setItem(i, 0, item);

        item = new QStandardItem(QString::fromStdString(base.db[i].fio));
        qmodel->setItem(i, 1, item);

        item = new QStandardItem(QString::fromStdString(base.db[i].coun));
        qmodel->setItem(i, 2, item);
    }
    slot_send_to_server("show Test");
}

void AdminWindow::on_pushButton_2_clicked()
{



    qmodel = new QStandardItemModel(0,3,this);
    ui->tableView->setModel(qmodel);
    qmodel->setHeaderData(0, Qt::Horizontal, "login");
    qmodel->setHeaderData(1, Qt::Horizontal, "password");
    qmodel->setHeaderData(2, Qt::Horizontal, "level");

    QString temp = ui->lineEdit->text();
    base.finding("Test",temp.toStdString());
        for (int i = 0; i < base.db.size() ; i++)
        {
            item = new QStandardItem(QString::fromStdString(base.db[i].tour));
            qmodel->setItem(i, 0, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].fio));
            qmodel->setItem(i, 1, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].coun));
            qmodel->setItem(i, 2, item);
        }
}

void AdminWindow::on_pushButton_clicked()
{
    QString t = ui->lineEdit_3->text();
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Test");
        if(!db.open())
            qDebug()<<db.lastError().text();
        QSqlQuery query(db);
    std::string temp = "DELETE FROM User WHERE login = '"+t.toStdString()+"'";
    query.exec(QString::fromStdString(temp));
    emit on_actionRefresh_triggered();
    */
    slot_send_to_server("delete Test "+ t);
}

void AdminWindow::on_pushButton_3_clicked()
{
    QString t = ui->lineEdit_3->text();
    slot_send_to_server("change "+ t);
}
