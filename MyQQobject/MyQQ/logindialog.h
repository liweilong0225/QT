#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();
signals:
    void SIG_LoginCommit(QString name,QString Password);
    void SIG_RegisterCommit(QString name,QString Password);
private slots:
    void on_pb_clear_clicked();

    void on_pb_rigister_clear_clicked();

    void on_pb_commit_clicked();

    void on_pb_register_commit_clicked();

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
