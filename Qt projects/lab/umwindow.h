#ifndef UMWINDOW_H
#define UMWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QStandardItemModel>

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

private:
    Ui::UMWindow *ui;
    QSqlTableModel *model;
    QStandardItemModel *qmodel;
};

#endif // UMWINDOW_H
