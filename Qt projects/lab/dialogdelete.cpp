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

void DialogDelete::SetTemp(int temp){
    te = temp;
}
DialogDelete::DialogDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDelete)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),SLOT(close()));
}

DialogDelete::~DialogDelete()
{
    delete ui;
}

void DialogDelete::on_buttonBox_accepted()
{
    QMessageBox msgBox;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Tour");
    if(!db.open())
        qDebug()<<db.lastError().text();
    QSqlQuery query(db);
    query.exec("CREATE TABLE User("
               "tour VARCHAR(20) NOT NULL, "
               "fio VARCHAR(20) NOT NULL,"
               "country VARCHAR(20) NOT NULL,"
               "magazine VARCHAR(20) NOT NULL"
               ")");

    QString t = ui->lineTour->text();
    QString f = ui->lineFIO->text();
    QString c = ui->lineCoun->text();
    QString m = ui->lineMag->text();
    int temp;
    query.exec("SELECT * FROM User");
    if(te==1){
        while(query.next())
             if((query.value(0).toString()==t.toLocal8Bit().constData())&&(query.value(1).toString()==f.toLocal8Bit().constData())
                     &&(query.value(2).toString()==c.toLocal8Bit().constData())&&(query.value(3).toString()==m.toLocal8Bit().constData())){
                 temp=1;
                 msgBox.setText("Data Base already contain this data");
                 msgBox.exec();
              }
        if(temp==0){
            query.prepare("INSERT INTO User(tour, fio, country, magazine) "
                              "VALUES (:tour, :fio, :country, :magazine)");
            query.bindValue(":tour",t);
            query.bindValue(":fio",f);
            query.bindValue(":country",c);
            query.bindValue(":magazine",m);
            query.exec();
            msgBox.setText("Data added");
            msgBox.exec();
        }
    } else if(te==2){
        while(query.next())
            if((query.value(0).toString()==t.toLocal8Bit().constData())&&(query.value(1).toString()==f.toLocal8Bit().constData())
                    &&(query.value(2).toString()==c.toLocal8Bit().constData())&&(query.value(3).toString()==m.toLocal8Bit().constData())){
                temp = 1;
        std::string temp = "DELETE FROM User WHERE tour = '"+t.toStdString()+"' AND fio = '"+f.toStdString()+"' AND country = '"+c.toStdString()+"' AND magazine = '"+m.toStdString()+"'";
        query.exec(QString::fromStdString(temp));
        msgBox.setText("Data deleted");
        msgBox.exec();
            }
        if(temp == 0){
            msgBox.setText("Data Base doesn't contain this data");
            msgBox.exec();
        }
    }
    db.close();
}
