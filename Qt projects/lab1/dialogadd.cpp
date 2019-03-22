#include "dialogadd.h"
#include "ui_dialogadd.h"
#include <QPushButton>
#include "database.h"
#include <QMessageBox>

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
    word.tour = t.toStdString();
    QString f = ui->lineFIO->text();
    word.fio = f.toStdString();
    QString c = ui->lineCoun->text();
    word.coun = c.toStdString();
    QString m = ui->lineMag->text();
    word.mag = m.toStdString();
    DataBase dat;
    dat.download();
    dat.add_data(word);
    dat.write2file();
    QMessageBox box;
    box.setText("Successful");
    box.exec();
    this->close();
}



