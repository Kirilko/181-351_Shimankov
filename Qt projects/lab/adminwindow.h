#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QStandardItemModel>


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

private:
    Ui::AdminWindow *ui;
    QSqlTableModel *model;
    QStandardItemModel *qmodel;
};

#endif // ADMINWINDOW_H
