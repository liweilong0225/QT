#ifndef MYQQDIALOG_H
#define MYQQDIALOG_H

#include <QDialog>
#include"qmytcpclient.h"
#include"Packdef.h"
#include"logindialog.h"
namespace Ui {
class MyQQDialog;
}

class MyQQDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyQQDialog(QWidget *parent = 0);
    ~MyQQDialog();

private slots:
    void on_pb_test_clicked();

    void slot_ReadyData(char*,int);

    void slot_LoginCommit(QString name,QString password);

    void slot_RegisterCommit(QString name,QString password);

    void solt_RegisterRs(char *buf, int nlen);

    void solt_LoginRs(char *buf,int nlen);

    void solt_ForceOffline(char *buf,int nlen);

private:
    Ui::MyQQDialog *ui;
    QMyTcpClient * m_tcpClient;
    loginDialog * m_loginDlg;
    int m_id;
};

#endif // MYQQDIALOG_H
