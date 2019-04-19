#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QString>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sWindow = new SecondWindow();


    sock = new QTcpSocket(this);
    sock->connectToHost("127.0.0.1",33333);
    connect(sock,SIGNAL(connected()),SLOT(slot_connected()));
    connect(sock,SIGNAL(readyRead()),SLOT(slot_ready_read()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int authorizing(QString log, QString pass){
    QFile file("text.txt");
    QString wfile;
    QString message = "Auth&"+log+" "+pass;

    if((file.exists())&&(file.open(QIODevice::ReadOnly))){
        while(!file.atEnd()){
            wfile = file.readLine();
            if(wfile.contains(" "+pass+" ")&&wfile.contains(" "+log+" ")){
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
}

void MainWindow::on_pushButtonLog_clicked()
{
    QString login = ui->lineEdit_log->text();
    QString password = ui->lineEdit_pass->text();
    QMessageBox msgBox;
    if(authorizing(login, password) == 1){
          msgBox.setText("Authorized as admin");
          sWindow->SetTemp(1);
          sWindow->show();
          this->close();
    } else if (authorizing(login, password) == 2){
        msgBox.setText("Authorized as manager");
        sWindow->SetTemp(1);
        sWindow->show();
        this->close();
    } else if (authorizing(login, password) == 3){
       msgBox.setText("Authorized as simple user");
       sWindow->SetTemp(2);
       sWindow->show();
       this->close();
} else {
          msgBox.setText("Invalid Data");
          msgBox.setInformativeText("Do you want to try again?");
          msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
          msgBox.setDefaultButton(QMessageBox::Retry);
    }

        int res = msgBox.exec();
        if (res == QMessageBox::Close){
            close();
        }
}

void MainWindow::slot_connected(){
    QMessageBox msg;
    msg.setText("Connected");
    msg.exec();
}

void MainWindow::slot_ready_read(){
    QByteArray array;
    std::string message = "";
    while(sock->bytesAvailable()>0){
        array = sock->readAll();
        message = array.toStdString();
    }
    QMessageBox msg;
    msg.setText(QString::fromStdString(message));
    msg.exec();
}

void MainWindow::slot_send_to_serv(QString message){
    QByteArray array;
    array.append(message);
    sock->write(array);
}

void MainWindow::slot_disconnected(){

}

void MainWindow::on_actionBack_triggered()
{
    StartWindow *wnd = new StartWindow();
    wnd->show();
    this->close();
}
