#include "startwindow.h"
#include "ui_startwindow.h"
#include "loginwindow.h"
#include "regwindow.h"

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
    LoginWindow *wnd = new LoginWindow();
    this->close();
    wnd->show();
}

void StartWindow::on_registr_clicked()
{
    RegWindow *wnd = new RegWindow();
    this->close();
    wnd->show();
}
