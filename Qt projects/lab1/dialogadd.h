#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = nullptr);
    ~DialogAdd();

private:
    Ui::DialogAdd *ui;
private slots:


    void on_buttonBox_accepted();
};

#endif // DIALOGADD_H
