#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "umwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    void SetTemp(int temp);
    int t;

private slots:
    void on_actionBack_2_triggered();

    void on_pushButtonLog_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
