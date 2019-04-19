#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <secondwindow.h>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
    void SetTemp(int temp);
    int t;

private:
    Ui::MainWindow *ui;
    SecondWindow *sWindow;
    QTcpSocket *sock;
private slots:
    void on_pushButtonLog_clicked();
    void slot_connected();
    void slot_ready_read();
    void slot_disconnected();
    void slot_send_to_serv(QString message);
    void on_actionBack_triggered();
};

#endif // MAINWINDOW_H
