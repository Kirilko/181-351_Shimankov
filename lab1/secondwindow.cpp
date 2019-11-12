#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "dialogadd.h"
#include "dialogfind.h"
#include "dialogdelete.h"
#include "database.h"
#include <QMessageBox>


void SecondWindow::SetTemp(int temp){
    t = temp;
}
SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    emit on_actionRefresh_triggered();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_actionadd_triggered()
{
    if(t == 1){
    DialogAdd *wnd = new DialogAdd(this);
    wnd->show();
    } else { QMessageBox m;
    m.setText("Don't have permission");
    m.exec();
    }


}

void SecondWindow::on_actiondelete_triggered()
{
    if(t == 1){
    DialogDelete *wnd = new DialogDelete(this);
    wnd->show();
    } else { QMessageBox m;
    m.setText("Don't have permission");
    m.exec();
    }
}


void SecondWindow::on_actionlogout_triggered()
{

    this->close();
    emit firstWindow();
}

void SecondWindow::on_actionRefresh_triggered()
{
    QStandardItem *item;

    model = new QStandardItemModel(0,4,this);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, "Тур");
    model->setHeaderData(1, Qt::Horizontal, "Клиент");
    model->setHeaderData(2, Qt::Horizontal, "Страна");
    model->setHeaderData(3, Qt::Horizontal, "Регистрация");

    DataBase base;
    base.download();
        for (int i = 0; i < base.db.size() ; i++)
        {
            item = new QStandardItem(QString::fromStdString(base.db[i].tour));
            model->setItem(i, 0, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].fio));
            model->setItem(i, 1, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].coun));
            model->setItem(i, 2, item);

            item = new QStandardItem(QString::fromStdString(base.db[i].mag));
            model->setItem(i, 3, item);
        }

}

void SecondWindow::on_BTNFind_clicked()
{
    QStandardItem *item;
    model = new QStandardItemModel(0,4,this);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, "Тур");
    model->setHeaderData(1, Qt::Horizontal, "Клиент");
    model->setHeaderData(2, Qt::Horizontal, "Страна");
    model->setHeaderData(3, Qt::Horizontal, "Регистрация");
    QString word = ui->lineFIND->text();
    std::string temp = word.toStdString();
    DataBase base;
    base.download();
    base.finding(temp);
    for (int i = 0; i < base.db.size() ; i++)
    {
        item = new QStandardItem(QString::fromStdString(base.db[i].tour));
        model->setItem(i, 0, item);

        item = new QStandardItem(QString::fromStdString(base.db[i].fio));
        model->setItem(i, 1, item);

        item = new QStandardItem(QString::fromStdString(base.db[i].coun));
        model->setItem(i, 2, item);

        item = new QStandardItem(QString::fromStdString(base.db[i].mag));
        model->setItem(i, 3, item);
    }
}
