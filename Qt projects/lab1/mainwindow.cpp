#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QString>


int authorizing(QString log, QString pass){
    QFile file("text.txt");
    QString wfile;
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sWindow = new SecondWindow();
    connect(sWindow, &SecondWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
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

