#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QTcpSocket>
#include "database.h"


namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_actionLogOut_triggered();

    void on_actionRefresh_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void slot_send_to_server(QString mess);
    void slot_disconected();
    void slot_ready_read();

    void on_pushButton_3_clicked();

private:
    Ui::AdminWindow *ui;
    QSqlTableModel *model;
    QStandardItemModel *qmodel;
    QTcpSocket *socket;
    DataBase base;
};

#endif // ADMINWINDOW_H
