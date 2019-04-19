#include "dialogdelete.h"
#include "ui_dialogdelete.h"
#include <QPushButton>

DialogDelete::DialogDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDelete)
{
    ui->setupUi(this);

    connect(ui->buttonBox->button(QDialogButtonBox::Ok),SIGNAL(clicked()),SLOT(okClicked()));
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),SLOT(close()));
}
void DialogDelete::okClicked(){

};

DialogDelete::~DialogDelete()
{
    delete ui;
}
