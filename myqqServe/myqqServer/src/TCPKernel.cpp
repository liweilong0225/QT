#include<TCPKernel.h>
#include "packdef.h"
#include<stdio.h>

using namespace std;


////注册
//#define  DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
//#define  DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)
////登录
//#define  DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
//#define  DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)

static const ProtocolMap m_ProtocolMapEntries[] =
{
    {DEF_PACK_REGISTER_RQ , &TcpKernel::RegisterRq},
    {DEF_PACK_LOGIN_RQ , &TcpKernel::LoginRq},
    {0,0}
};
#define RootPath   "/home/colin/Video/"

int TcpKernel::Open()
{
    m_sql = new CMysql;
    m_tcp = new TcpNet(this);
    m_tcp->SetpThis(m_tcp);
    pthread_mutex_init(&m_tcp->alock,NULL);
    pthread_mutex_init(&m_tcp->rlock,NULL);
    if(  !m_sql->ConnectMysql("localhost","root","wl940225","myqq")  )
    {
        printf("Conncet Mysql Failed...\n");
        return FALSE;
    }
    else
    {
        printf("MySql Connect Success...\n");
    }
    if( !m_tcp->InitNetWork()  )
    {
        printf("InitNetWork Failed...\n");
        return FALSE;
    }
    else
    {
        printf("Init Net Success...\n");
    }

    return TRUE;
}

void TcpKernel::Close()
{
    m_sql->DisConnect();
    m_tcp->UnInitNetWork();
}


void TcpKernel::DealData(int clientfd,char *szbuf,int nlen)
{
    PackType *pType = (PackType*)szbuf;
    int i = 0;
    while(1)
    {
        if(*pType == m_ProtocolMapEntries[i].m_type)
        {
            PFUN fun= m_ProtocolMapEntries[i].m_pfun;
            (this->*fun)(clientfd,szbuf,nlen);
        }
        else if(m_ProtocolMapEntries[i].m_type == 0 &&
                m_ProtocolMapEntries[i].m_pfun == 0)
            return;
        ++i;
    }
    return;
}
//注册请求结果
#define userid_is_exist      0
#define register_sucess      1

//注册
void TcpKernel::RegisterRq(int clientfd,char* szbuf,int nlen)
{
    printf("clientfd:%d RegisterRq\n", clientfd);

    STRU_REGISTER_RQ * rq = (STRU_REGISTER_RQ *)szbuf;
    STRU_REGISTER_RS rs;

    //根据用户名查用户
    char sqlStr[1024] = {0};
    sprintf(sqlStr,"select name from t_user where name = '%s';",rq->m_szUser);
    list<string> resList;
    if(!m_sql->SelectMysql(sqlStr,1,resList))
    {
        printf("Select error:%s\n",sqlStr);
        return;
    }
    if(resList.size()==0)
    {
        //没有用户可以注册--写表
        rs.m_lResult = register_sucess;

        sprintf(sqlStr,"insert into t_user(name,password) values('%s' , '%s' );"
                ,rq->m_szUser,rq->m_szPassword);
        if(!m_sql->UpdataMysql(sqlStr))
        {
         printf("UpdataMysql error:%s \n",sqlStr);
        }

    }else
    {
        //有用户就注册失败
        rs.m_lResult = userid_is_exist;
    }
    m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );
}

//登录请求结果
#define userid_no_exist      0
#define password_error       1
#define login_sucess         2
#define user_online          3

//登录
void TcpKernel::LoginRq(int clientfd ,char* szbuf,int nlen)
{
    printf("clientfd:%d LoginRq\n", clientfd);

    STRU_LOGIN_RQ * rq = (STRU_LOGIN_RQ *)szbuf;
    STRU_LOGIN_RS rs;

    //查用户名 密码
    char sqlStr[1024] = "";
    sprintf(sqlStr,"select password,id from t_user where name = '%s';",rq->m_szUser);
    list<string> resList;

    if(!m_sql->SelectMysql(sqlStr,2,resList))
    {
        printf("SelectMysql error:%s\n",sqlStr);
        return;
    }
    if(resList.size()>0)
    {
        //有用户
        if(strcmp(resList.front().c_str(),rq->m_szPassword) == 0)
        {
            //密码一致
            rs.m_lResult = login_sucess;
            resList.pop_front();
            int id = atoi(resList.front().c_str());
            rs.m_UserID = id;

            m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );
            //m_mapIDToFD[id] = clientfd;
            if(m_mapIDToFD.find(id) != m_mapIDToFD.end())
            {//找到了
                //强制前一个下线
                STRU_FORCE_OFFLINE offline;
                offline.m_userID = id;
                m_tcp->SendData(m_mapIDToFD[id],(char*)&offline,sizeof(offline));
            }
            m_mapIDToFD[id] = clientfd;
            return;
        }else
        {//密码不一致
            rs.m_lResult = password_error;
        }
    }else{
        //没有用户
        rs.m_lResult = userid_no_exist;
    }

    m_tcp->SendData( clientfd , (char*)&rs , sizeof(rs) );
}



