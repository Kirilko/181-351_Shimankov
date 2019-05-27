#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "startwindow.h"
#include "adminwindow.h"
#include "umwindow.h"
#include "database.h"
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include "crypto.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 33333);
    connect(socket, SIGNAL(connected()), SLOT(slot_connected()));
    connect(socket, SIGNAL(readyRead()), SLOT(slot_ready_read()));
}
void LoginWindow::slot_connected()
{
    QMessageBox msgBox;
    msgBox.setText("You are on the server");
    msgBox.exec();
}

void LoginWindow::slot_ready_read(){
    QByteArray arr,arr_d;
    std::string mess;
    QMessageBox msgBox;
    while (socket->bytesAvailable() > 0)
    {
        arr = socket->readAll();
    }

    crypto c;
    arr_d = c.decrypt(arr);
    mess = arr_d.toStdString();
    /*QMessageBox m;
    m.setText(QString::fromStdString(mess));
    m.exec();*/
    if (mess == "1")
    {
        AdminWindow *m = new AdminWindow();
        m->show();
        this->close();
        msgBox.setText("Authorized as admin");
        msgBox.exec();
    }
    else
    {
        //	std::string sl = login.toStdString();
            //	std::string sll;
            //	sll.insert(0, sl, 0, 7);
            //	if (sll == "manager")
        if (mess == "2")
        {
            UMWindow *w = new UMWindow();
            w->SetTemp(2);
            w->show();
            this->close();
            msgBox.setText("Authorized as manager");
            msgBox.exec();
        }
        else
        {
            if (mess == "3")
            {//msgBox.setText("Hello "+login+"!");
            //msgBox.exec();
                UMWindow *w = new UMWindow();
                w->SetTemp(3);
                w->show();
                this->close();
                msgBox.setText("Authorized as simple user");
                msgBox.exec();
            }
            else
            {
                msgBox.setText("Wrong login or password");
                msgBox.setInformativeText("Again?");
                msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
                msgBox.setDefaultButton(QMessageBox::Save);
                msgBox.exec();
            }
        }
    }
}

void LoginWindow::slot_send_to_server(QString message){
    QByteArray array,arr_d;
    array.append(message);
    crypto c;
    arr_d = c.encrypt(array);
    socket->write(arr_d);
}

void LoginWindow::slot_disconected(){

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


void LoginWindow::on_pushButtonLog_clicked()
{
    QMessageBox msgBox;
    QString login = ui->lineEdit_log->text();
    QString password = ui->lineEdit_pass->text();
    /*if(authorizing(login,password)=="1"){
        msgBox.setText("Authorized as admin");
        AdminWindow *w = new AdminWindow();
        this->close();
        w->show();
    } else if(authorizing(login,password)=="2"){
        msgBox.setText("Authoised as manager");
        UMWindow *w = new UMWindow();
        w->SetTemp(2);
        w->show();
        this->close();       
    } else if(authorizing(login,password)=="3"){
        msgBox.setText("Authorized as simple user");
        UMWindow *w = new UMWindow();
        w->SetTemp(3);
        w->show();
        this->close();
    } else if(authorizing(login,password)=="0"){
        msgBox.setText("Invalid Data");
    }
    msgBox.exec();*/
    if(login == NULL || password == NULL){
        msgBox.setText("Fill empty areas");
        msgBox.exec();
    }else{
    QString message;
        message = "authorize " + login + " " + password;
        slot_send_to_server(message);
    }
}
