#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H

#include <QDialog>

namespace Ui {
class DialogDelete;
}

class DialogDelete : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDelete(QWidget *parent = nullptr);
    ~DialogDelete();
    void SetTemp(int temp);
    int te;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogDelete *ui;
};

#endif // DIALOGDELETE_H
