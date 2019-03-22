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

private:
    Ui::DialogDelete *ui;
signals:
    void DeleteDB();
private slots:
    void okClicked();
};

#endif // DIALOGDELETE_H
