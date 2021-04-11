#include "myqqdialog.h"
#include "ui_myqqdialog.h"
#include<QCryptographicHash>
#include<QMessageBox>

#define MD5_KEY 1234

static QByteArray GetMD5(QString val)
{
    QCryptographicHash hash(QCryptographicHash::Md5);
    QString key = QString("%1_%2").arg(val).arg( MD5_KEY );

    hash.addData( key.toLocal8Bit() );
    QByteArray bt = hash.result();

    return bt.toHex();  //十六进制数，AD1234F...32位 MD5
}

MyQQDialog::MyQQDialog(QWidget *parent) :
    QDialog(parent),m_id(0),
    ui(new Ui::MyQQDialog)
{
    ui->setupUi(this);

    m_tcpClient = new QMyTcpClient;
    connect(m_tcpClient , SIGNAL(SIG_ReadyData(char*,int)) , this , SLOT(slot_ReadyData(char*,int)) );

    m_loginDlg = new loginDialog;
    connect(m_loginDlg , SIGNAL(SIG_LoginCommit(QString,QString)) ,
            this , SLOT( slot_LoginCommit(QString,QString)) );
    connect(m_loginDlg , SIGNAL(SIG_RegisterCommit(QString,QString)) ,
            this , SLOT( slot_RegisterCommit(QString,QString)) );
    m_loginDlg->show();
    //this->hide();
}

MyQQDialog::~MyQQDialog()
{
    delete ui;
    if(m_tcpClient)
    {
        delete m_tcpClient;
        m_tcpClient = NULL;
    }
    if(m_loginDlg)
    {
        delete m_loginDlg;
        m_loginDlg = NULL;
    }
}

void MyQQDialog::on_pb_test_clicked()
{
    STRU_LOGIN_RQ rq;
    strcpy(rq.m_szUser,"111");
    strcpy(rq.m_szPassword,"111");
    m_tcpClient->SendData( (char*)&rq , sizeof(rq) );
}

void MyQQDialog::slot_ReadyData(char *buf,int nlen)
{
    int type = *(int*) buf;
    switch(type)
    {
    case  DEF_PACK_LOGIN_RS:
        qDebug()<<" DEF_PACK_LOGIN_RS";
        solt_LoginRs(buf,nlen);
        break;
    case  DEF_PACK_REGISTER_RS:
        qDebug()<<" DEF_PACK_REGISTER_RS";
        solt_RegisterRs(buf,nlen);
        break;
    case DEF_PACK_FORCE_OFFLINE:
        solt_ForceOffline(buf,nlen);
        break;
    default:
        break;
    }
    delete [] buf;
}

//提交登录
void MyQQDialog::slot_LoginCommit(QString name,QString password)
{
    STRU_LOGIN_RQ rq;
    //Unicode中文兼容
    std::string strName = name.toStdString();
    const char* bufName = strName.c_str();
    strcpy_s( rq.m_szUser , MAX_SIZE , bufName );

    QByteArray btPassword = GetMD5( password );
    memcpy(rq.m_szPassword,btPassword.data(),btPassword.size());

    m_tcpClient->SendData( (char*)&rq , sizeof(rq));
}

//提交注册
void MyQQDialog::slot_RegisterCommit(QString name, QString password)
{
    STRU_REGISTER_RQ rq;
    //Unicode中文兼容
    std::string strName = name.toStdString();
    const char* bufName = strName.c_str();
    strcpy_s( rq.m_szUser , MAX_SIZE , bufName );

    QByteArray btPassword = GetMD5( password );
    memcpy(rq.m_szPassword,btPassword.data(),btPassword.size());

    qDebug()<<rq.m_szPassword;
    m_tcpClient->SendData( (char*)&rq , sizeof(rq));
}

//注册回复
void MyQQDialog::solt_RegisterRs(char *buf, int nlen)
{
    STRU_REGISTER_RS * rs = (STRU_REGISTER_RS*)buf;
    switch (rs->m_lResult)
    {
    case userid_is_exist:
        QMessageBox::about(m_loginDlg,"提示","注册失败，用户已存在");
        break;
    case register_sucess:
        QMessageBox::about(m_loginDlg,"提示","注册成功");
        break;
    default:
        break;
    }
}

//登录回复
void MyQQDialog::solt_LoginRs(char *buf, int nlen)
{
    STRU_LOGIN_RS * rs = (STRU_LOGIN_RS*)buf;
    switch (rs->m_lResult)
    {
    case userid_no_exist:
        QMessageBox::about(m_loginDlg,"提示","登录失败，用户不存在");
        break;
    case password_error:
        QMessageBox::about(m_loginDlg,"提示","登录失败，密码错误");
        break;
    case login_sucess:
        //QMessageBox::about(m_loginDlg,"提示","登录成功");
        //id 赋值
        m_id = rs->m_UserID;
        //ui 跳转
        m_loginDlg->hide();
        this->show();
        break;
    default:
        break;
    }
}

//强制下线
void MyQQDialog::solt_ForceOffline(char *buf, int nlen)
{
    STRU_FORCE_OFFLINE * rs = (STRU_FORCE_OFFLINE*)buf;
    if(rs->m_userID == m_id)
    {
        QMessageBox::about(this,"提示","异地登录，强制下线");

        //退出程序
        exit(0);
    }
}


