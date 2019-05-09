#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "startwindow.h"
#include "adminwindow.h"
#include "umwindow.h"
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_actionBack_2_triggered()
{
    StartWindow *wnd = new StartWindow();
    this->close();
    wnd->show();
}
/*int authorizing(QString log, QString pass){
   // QFile file("text.txt");
    QString wfile;
    if((file.exists())&&(file.open(QIODevice::ReadOnly))){
        while(!file.atEnd()){
            wfile = file.readLine();
            if(wfile.contains("'"+pass+"'")&&wfile.contains("'"+log+"'")){
                if(log=="admin"){
                    file.close();
                    return 1;
                } else if(wfile.contains("level2")){
                    file.close();
                    return 2;
                } else if(wfile.contains("level3")){
                    file.close();
                    return 3;
                }
            }
        }
    }
    return 0;
}*/
int authorizing(QString log, QString pass){
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
        query.prepare("INSERT INTO User(login, password, level) "
                          "VALUES (:login, :password, :level)");
        if(query.exec("SELECT * FROM User")){
            while (query.next()) {
                if((log==query.value(0).toString())&&(pass==query.value(1).toString())){
                    if(query.value(2)=="3"){
                        db.close();
                        return 3;
                    }
                    else if(query.value(2)=="2"){
                        db.close();
                        return 2;
                    }
                    else if(query.value(2)=="1"){
                        db.close();
                        return 1;
                    }
                }
            }
        }
        db.close();
        return 0;
}

void LoginWindow::on_pushButtonLog_clicked()
{
    QMessageBox msgBox;
    QString login = ui->lineEdit_log->text();
    QString password = ui->lineEdit_pass->text();
    if(authorizing(login,password)==1){
        msgBox.setText("Authorized as admin");
        AdminWindow *w = new AdminWindow();
        this->close();
        w->show();
    } else if(authorizing(login,password)==2){
        msgBox.setText("Authoised as manager");
        UMWindow *w = new UMWindow();
        w->SetTemp(2);
        w->show();
        this->close();       
    } else if(authorizing(login,password)==3){
        msgBox.setText("Authorized as simple user");
        UMWindow *w = new UMWindow();
        w->SetTemp(3);
        w->show();
        this->close();
    } else if(authorizing(login,password)==0){
        msgBox.setText("Invalid Data");
    }
    msgBox.exec();
}
