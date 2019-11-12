#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H

#include <QDialog>
#include <QTcpSocket>

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

    void slot_send_to_server(QString mess);
    void slot_disconected();
    void slot_ready_read();

private:
    Ui::DialogDelete *ui;
    QTcpSocket *socket;
};

#endif // DIALOGDELETE_H
