#include "dialogadd.h"
#include "ui_dialogadd.h"
#include <QPushButton>
#include "database.h"
#include <QMessageBox>
#include "secondwindow.h"

DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),SLOT(close()));
}


DialogAdd::~DialogAdd()
{
    delete ui;
}

void DialogAdd::on_buttonBox_accepted()
{
    struct data word;
    QString t = ui->lineTour->text();
    if(t!=NULL){
        word.tour = t.toStdString();
       // if(checkTour(word.tour)==true){
        QString f = ui->lineFIO->text();
        word.fio = f.toStdString();
        if(checkFio(word.fio)==true){
            QString c = ui->lineCoun->text();
            word.coun = c.toStdString();
            if(checkCoun(word.coun)==true){
                QString m = ui->lineMag->text();
                if(m!=NULL){
                word.mag = m.toStdString();
                DataBase dat;
                dat.download();
                dat.add_data(word);
                dat.write2file();
                QMessageBox box;
                box.setText("Successful");
                box.exec();
                this->close();}else{
                    QMessageBox box;
                    box.setText("Check the entered data");
                    box.exec();
                    }
                }else {
                    QMessageBox box;
                    box.setText("Check the entered data");
                    box.exec();
                }
            } else{
                QMessageBox box;
                box.setText("Check the entered data");
                box.exec();
                }
        } else {
            QMessageBox box;
            box.setText("Check the entered data");
            box.exec();
        }
}



