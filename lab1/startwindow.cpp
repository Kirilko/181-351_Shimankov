#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include "regwin.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_login_clicked()
{
    MainWindow *wnd = new MainWindow();
    wnd->show();
    this->close();
}

void StartWindow::on_registr_clicked()
{
    RegWin *wnd = new RegWin();
    wnd->show();
    this->close();
}
