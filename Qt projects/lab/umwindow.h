#ifndef UMWINDOW_H
#define UMWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QTcpSocket>
#include "database.h"

namespace Ui {
class UMWindow;
}

class UMWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UMWindow(QWidget *parent = nullptr);
    ~UMWindow();
    void SetTemp(int temp);
    int t;

private slots:
    void on_actionLogOut_triggered();

    void on_actionRefresh_triggered();

    void on_actionAdd_triggered();

    void on_actionDelete_triggered();

    void on_BTNFind_clicked();

    void slot_send_to_server(QString mess);
    void slot_disconected();
    void slot_ready_read();
private:
    Ui::UMWindow *ui;
    QSqlTableModel *model;
    QStandardItemModel *qmodel;
    QTcpSocket *socket;
    DataBase base;
};

#endif // UMWINDOW_H
