#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "umwindow.h"
#include <QTcpSocket>

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
private:
    QTcpSocket *socket;

private slots:
    void slot_connected();
    void slot_ready_read();
    void slot_send_to_server(QString mess);
    void slot_disconected();

    void on_actionBack_2_triggered();

    void on_pushButtonLog_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
