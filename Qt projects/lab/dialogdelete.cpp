#include "dialogdelete.h"
#include "ui_dialogdelete.h"
#include <QPushButton>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include "umwindow.h"
#include "crypto.h"

void DialogDelete::SetTemp(int temp){
    te = temp;
}
DialogDelete::DialogDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDelete)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),SLOT(close()));

    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 33333);
    connect(socket, SIGNAL(connected()), SLOT(slot_connected()));
    connect(socket, SIGNAL(readyRead()), SLOT(slot_ready_read()));
}

DialogDelete::~DialogDelete()
{
    delete ui;
}

void DialogDelete::slot_send_to_server(QString message){
    QByteArray array,array_d;
    array.append(message);
    crypto c;
    array_d = c.encrypt(array);
    socket->write(array_d);
}

void DialogDelete::slot_disconected(){

}
void DialogDelete::slot_ready_read(){
    QByteArray arr,arr_d;
    int mess;
    QMessageBox msgBox;
    while (socket->bytesAvailable() > 0)
    {
        arr = socket->readAll();

    }
    crypto c;
    arr_d = c.decrypt(arr);
    mess = arr.toInt();
    if(mess==0){
        msgBox.setText("Data added");
        msgBox.exec();
    } else if (mess==1){
        msgBox.setText("Data Base already contain this data");
        msgBox.exec();
    }
}
void DialogDelete::on_buttonBox_accepted()
{
    QMessageBox msgBox;


    QString t = ui->lineTour->text();
    QString f = ui->lineFIO->text();
    if(checkFio(f.toStdString())!="1"){
        f = QString::fromStdString(checkFio(f.toStdString()));
        QString c = ui->lineCoun->text();
        if(checkFio(c.toStdString())!="1"){
            c = QString::fromStdString(checkFio(c.toStdString()));
            QString m = ui->lineMag->text();
            int temp;
            if(te==1){
                slot_send_to_server("add "+t+" "+f+" "+c+" "+m);
            } else if(te==2){
                slot_send_to_server("delete Tour "+t+" "+f+" "+c+" "+m);
            }
        }else{
            msgBox.setText("Check data");
            msgBox.exec();
        }
    }else {
        msgBox.setText("Check data");
        msgBox.exec();
    }
}
