#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}
//清空
void loginDialog::on_pb_clear_clicked()
{
    ui->le_name->setText("");
    ui->le_password->setText("");
}
//清空
void loginDialog::on_pb_rigister_clear_clicked()
{
    ui->le_register_name->setText("");
    ui->le_register_password->setText("");
    ui->le_register_confirm->setText("");
}
#include<QMessageBox>
#include<QRegExp>
//登录的提交
void loginDialog::on_pb_commit_clicked()
{
    //验证合法性
    QString name = ui->le_name->text();
    QString password = ui->le_password->text();

//    QMessageBox::about();
//    QMessageBox::information();
//    QMessageBox::critical();
//    QMessageBox::warning();
//    QMessageBox::question();
   //1.非空
    if(name.isEmpty() || name.remove(" ").isEmpty() || password.isEmpty())
    {
        QMessageBox::about(this,"提示","用户名或密码为空");
        return;
    }
    //name a-z A-Z 0-9长度10个以内
    QRegExp reg("[a-zA-Z0-9]{1,10}");
    bool res = reg.exactMatch(name);
    if(!res)
    {
        QMessageBox::about(this,"提示","用户名非法");
        return;
    }
    if(name.length()>10 || password.length()>20)
    {
        QMessageBox::about(this,"提示","用户名或密码过长");
        return;
    }

    Q_EMIT SIG_LoginCommit(name,password);
}


void loginDialog::on_pb_register_commit_clicked()
{
    //验证合法性
    QString name = ui->le_register_name->text();
    QString password = ui->le_register_password->text();
    QString confirm = ui->le_register_confirm->text();
    //1.非空
     if(name.isEmpty() || name.remove(" ").isEmpty() || password.isEmpty()||confirm.isEmpty())
     {
         QMessageBox::about(this,"提示","用户名或密码为空");
         return;
     }
     //name a-z A-Z 0-9长度10个以内
     QRegExp reg("[a-zA-Z0-9]{1,10}");
     bool res = reg.exactMatch(name);
     if(!res)
     {
         QMessageBox::about(this,"提示","用户名非法");
         return;
     }
     if(name.length()>10 || password.length()>20)
     {
         QMessageBox::about(this,"提示","用户名或密码过长");
         return;
     }
     if(password != confirm)
     {
         QMessageBox::about(this,"提示","密码两次输入不一致");
         return;
     }

     Q_EMIT SIG_RegisterCommit(name,password);
}
