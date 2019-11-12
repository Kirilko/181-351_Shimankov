#include "dialogfind.h"
#include "ui_dialogfind.h"
#include <QPushButton>

DialogFind::DialogFind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFind)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::Ok),SIGNAL(clicked()),SLOT(okClicked()));
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),SLOT(close()));
}
void DialogFind::okClicked(){

};

DialogFind::~DialogFind()
{
    delete ui;
}
