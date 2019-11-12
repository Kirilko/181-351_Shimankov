#ifndef REGWIN_H
#define REGWIN_H

#include <QMainWindow>

namespace Ui {
class RegWin;
}

class RegWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegWin(QWidget *parent = nullptr);
    ~RegWin();

private slots:
    void on_actionBack_triggered();

    void on_pushButtonLog_clicked();

private:
    Ui::RegWin *ui;
};

#endif // REGWIN_H
