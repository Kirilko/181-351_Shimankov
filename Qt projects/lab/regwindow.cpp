#include "regwindow.h"
#include "ui_regwindow.h"
#include "startwindow.h"
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>

RegWindow::RegWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegWindow)
{
    ui->setupUi(this);
}

RegWindow::~RegWindow()
{
    delete ui;
}

void RegWindow::on_actionBack_triggered()
{
    StartWindow *wnd = new StartWindow();
    this->close();
    wnd->show();
}

void RegWindow::on_pushButtonLog_clicked()
{
    QMessageBox msgBox;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Test");
    if(!db.open())
        qDebug()<<db.lastError().text();
    QSqlQuery query(db);
    query.exec("CREATE TABLE User("
               "login VARCHAR(20) NOT NULL, "
               "password VARCHAR(20) NOT NULL,"
               "level VARCHAR(20) NOT NULL"
               ")");

    QString login = ui->lineEdit_log_2->text();
    QString password = ui->lineEdit_pass_2->text();
    /*query.bindValue(":login","admin");
    query.bindValue(":password","123");
    query.bindValue(":level","1");
    query.exec();
    query.bindValue(":login","manager1");
    query.bindValue(":password","111");
    query.bindValue(":level","2");
    query.exec();
    query.bindValue(":login","user1");
    query.bindValue(":password","1");
    query.bindValue(":level","3");
    query.exec();*/
    int temp=0;
    query.exec("SELECT * FROM User");
        while(query.next())
            if(query.value(0).toString()==login.toLocal8Bit().constData()){
                temp=1;
                msgBox.setText("Login already used");
                msgBox.exec();
            }     
    if(temp==0){
        query.prepare("INSERT INTO User(login, password, level) "
                          "VALUES (:login, :password, :level)");
        query.bindValue(":login",login);
        query.bindValue(":password",password);
        query.bindValue(":level","3");
        query.exec();
        msgBox.setText("Succesful");
        msgBox.exec();
    }
    db.close();
}
