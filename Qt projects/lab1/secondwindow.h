#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    void SetTemp(int temp);
    int t;

private:
    Ui::SecondWindow *ui;
    QStandardItemModel *model;
signals:
    void firstWindow();
private slots:
    void on_actionadd_triggered();
    void on_actiondelete_triggered();
    void on_actionlogout_triggered();
};

#endif // SECONDWINDOW_H
