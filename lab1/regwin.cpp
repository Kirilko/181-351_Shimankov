#include "regwin.h"
#include "ui_regwin.h"
#include "startwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

RegWin::RegWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegWin)
{
    ui->setupUi(this);
}

RegWin::~RegWin()
{
    delete ui;
}

void RegWin::on_actionBack_triggered()
{
    StartWindow *wnd = new StartWindow();
    wnd->show();
    this->close();
}

void RegWin::on_pushButtonLog_clicked()
{
    QString login = ui->lineEdit_log->text();
    QString password = ui->lineEdit_pass->text();
    QMessageBox msgBox;
    QFile file("text.txt");
    QString wfile;
    if((file.exists())&&(file.open(QIODevice::ReadOnly))){
    wfile = file.readAll();
    }
    file.close();
    if(login==NULL||password==NULL){
        msgBox.setText("Fill empty area");
        msgBox.exec();
    }else
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        if(wfile.contains(" "+login+" ")){
            msgBox.setText("This username already used");
        } else{
            wfile+=" "+login+" "+password+" "+"level3"+"\n";
            msgBox.setText("Congratulations");
        }
        int res = msgBox.exec();
        if (res == QMessageBox::Close){
            close();
        }
        QTextStream stream(&file);
        stream << wfile;
        file.close();
        }else {
            msgBox.setText("bullshit");
            msgBox.exec();
    }
}
