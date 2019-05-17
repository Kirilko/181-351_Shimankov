#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class RegWindow;
}

class RegWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegWindow(QWidget *parent = nullptr);
    ~RegWindow();
private:
     QTcpSocket *socket;

private slots:
    void on_actionBack_triggered();

    void on_pushButtonLog_clicked();

    void slot_connected();
    void slot_send_to_server(QString mess);
    void slot_disconected();
    void slot_ready_read();

private:
    Ui::RegWindow *ui;
};

#endif // REGWINDOW_H
