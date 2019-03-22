#ifndef DIALOGFIND_H
#define DIALOGFIND_H

#include <QDialog>

namespace Ui {
class DialogFind;
}

class DialogFind : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFind(QWidget *parent = nullptr);
    ~DialogFind();

private:
    Ui::DialogFind *ui;
signals:
    void FindDB();
private slots:
    void okClicked();
};

#endif // DIALOGFIND_H
