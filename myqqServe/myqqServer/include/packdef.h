#ifndef _PACKDEF_H
#define _PACKDEF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include "err_str.h"
#include <malloc.h>

#include<iostream>
#include<map>
#include<list>


//边界值
#define _DEF_SIZE 45
#define _DEF_BUFFERSIZE 1000
#define _DEF_PORT 8000
#define _DEF_SERVERIP "0.0.0.0"  


#define TRUE true
#define FALSE false


#define _DEF_LISTEN 128
#define _DEF_EPOLLSIZE 4096
#define _DEF_IPSIZE 16
#define _DEF_COUNT 10
#define _DEF_TIMEOUT 10
#define _DEF_SQLIEN 400



#define BOOL bool
#define DEF_PACK_BASE  (10000)


////注册
//#define  DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
//#define  DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)
////登录
//#define  DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
//#define  DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)
////创建房间
//#define DEF_PACK_CREATEROOM_RQ  (DEF_PACK_BASE + 4)
//#define DEF_PACK_CREATEROOM_RS  (DEF_PACK_BASE + 5)
////加入房间
//#define DEF_PACK_JOINROOM_RQ  (DEF_PACK_BASE + 6)
//#define DEF_PACK_JOINROOM_RS  (DEF_PACK_BASE + 7)
////房间列表请求
//#define DEF_PACK_ROOM_MEMBER    (DEF_PACK_BASE + 8)
////音频数据
//#define DEF_PACK_AUDIO_FRAME    (DEF_PACK_BASE + 9)
////退出房间请求
//#define DEF_PACK_LEAVEROOM_RQ   (DEF_PACK_BASE + 10)
////退出房间回复
//#define DEF_PACK_LEAVEROOM_RS   (DEF_PACK_BASE + 11)

typedef enum Net_PACK
{
    DEF_PACK_REGISTER_RQ = 10000,
    DEF_PACK_REGISTER_RS,

    DEF_PACK_LOGIN_RQ,
    DEF_PACK_LOGIN_RS,

    DEF_PACK_CREATEROOM_RQ,
    DEF_PACK_CREATEROOM_RS,

    DEF_PACK_JOINROOM_RQ ,
    DEF_PACK_JOINROOM_RS,

    DEF_PACK_ROOM_MEMBER ,

    DEF_PACK_AUDIO_FRAME,

    DEF_PACK_LEAVEROOM_RQ ,
    DEF_PACK_LEAVEROOM_RS ,

    DEF_PACK_ADD_FRIEND_RQ,
    DEF_PACK_ADD_FRIEND_RS,

    DEF_PACK_FRIEND_INFO,

    DEF_PACK_CHAT_RQ,
    DEF_PACK_CHAT_RS,

    DEF_PACK_OFFLINRE_RQ,
    DEF_PACK_OFFLINRE_RS,

    DEF_PACK_VIDEO_FRAME,
    DEF_PACK_FORCE_OFFLINE,
}Net_PACK;

//注册请求结果
#define userid_is_exist      0
#define register_sucess      1

//登录请求结果
#define userid_no_exist      0
#define password_error       1
#define login_sucess         2
#define user_online          3

//创建房间结果
#define room_is_exist        0
#define create_success       1

//加入房间结果
#define room_no_exist        0
#define join_success         1

//上传请求结果
#define file_is_exist        0
#define file_uploaded        1
#define file_uploadrq_sucess 2
#define file_upload_refuse   3

//上传回复结果
#define fileblock_failed     0
#define fileblock_success    1

//下载请求结果
#define file_downrq_failed   0
#define file_downrq_success  1

#define _downloadfileblock_fail  0
#define _downloadfileblock_success	1

#define DEF_PACK_COUNT (100)

#define MAX_PATH            (280 )
#define MAX_SIZE            (60  )
#define DEF_HOBBY_COUNT     (8  )
#define MAX_CONTENT_LEN     (4096 )


/////////////////////网络//////////////////////////////////////


#define DEF_MAX_BUF	  1024
#define DEF_BUFF_SIZE	  4096


typedef int PackType;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//登录请求
typedef struct STRU_LOGIN_RQ
{
    STRU_LOGIN_RQ()
    {
        m_nType = DEF_PACK_LOGIN_RQ;
        memset(m_szUser,0,MAX_SIZE);
        memset(m_szPassword,0,MAX_SIZE);
    }

    PackType m_nType;   //包类型
    char     m_szUser[MAX_SIZE] ; //用户ID
    char     m_szPassword[MAX_SIZE];  //密码
} STRU_LOGIN_RQ;


//登录回复
typedef struct STRU_LOGIN_RS
{
    STRU_LOGIN_RS()
    {
        m_nType= DEF_PACK_LOGIN_RS;
        m_UserID = 0;
        m_lResult = 0;
    }
    PackType m_nType;   //包类型
    int  m_UserID;
    int  m_lResult ; //注册结果

} STRU_LOGIN_RS;


//注册请求
typedef struct STRU_REGISTER_RQ
{
    STRU_REGISTER_RQ()
    {
        m_nType = DEF_PACK_REGISTER_RQ;
        memset(m_szUser,0,MAX_SIZE);
        memset(m_szPassword,0,MAX_SIZE);
    }

    PackType m_nType;   //包类型
    char     m_szUser[MAX_SIZE] ; //用户名
    char     m_szPassword[MAX_SIZE];  //密码

} STRU_REGISTER_RQ;

//注册回复
typedef struct STRU_REGISTER_RS
{
    STRU_REGISTER_RS()
    {
        m_nType= DEF_PACK_REGISTER_RS;
        m_lResult = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ; //注册结果

} STRU_REGISTER_RS;

typedef struct STRU_FORCE_OFFLINE
{
    STRU_FORCE_OFFLINE(){
        nType = DEF_PACK_FORCE_OFFLINE;
        m_userID = 0;
    }
    int nType;
    int m_userID;
}STRU_FORCE_OFFLINE;

//创建房间请求
typedef struct STRU_CREATEROOM_RQ
{
    STRU_CREATEROOM_RQ()
    {
        m_nType = DEF_PACK_CREATEROOM_RQ;
        m_UserID = 0;
        m_RoomID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;
    int m_RoomID;

} STRU_CREATEROOM_RQ;

//创建房间回复
typedef struct STRU_CREATEROOM_RS
{
    STRU_CREATEROOM_RS()
    {
        m_nType= DEF_PACK_CREATEROOM_RS;
        m_lResult = 0;
        m_RoomId = 0;
        m_AudioPort = 0;
        memset( m_AudioIP, 0, 20);
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int  m_RoomId;
    int  m_AudioPort;
    char m_AudioIP[20];


} STRU_CREATEROOM_RS;

//加入房间请求
typedef struct STRU_JOINROOM_RQ
{
    STRU_JOINROOM_RQ()
    {
        m_nType = DEF_PACK_JOINROOM_RQ;
        m_UserID = 0;
        m_RoomID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;
    int m_RoomID;

} STRU_JOINROOM_RQ;

//加入房间回复
typedef struct STRU_JOINROOM_RS
{
    STRU_JOINROOM_RS()
    {
        m_nType= DEF_PACK_JOINROOM_RS;
        m_lResult = 0;
        m_RoomId = 0;
        m_AudioPort = 0;
        memset(m_AudioIP,0,20);
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int  m_RoomId;
    int m_AudioPort;
    char m_AudioIP[20];

} STRU_JOINROOM_RS;

//房间成员请求
typedef struct STRU_ROOM_MEMBER_RQ
{
    STRU_ROOM_MEMBER_RQ()
    {
        m_nType= DEF_PACK_ROOM_MEMBER;
        m_AudioPort = 0;
        m_UserID = 0;
        memset(m_szUser,0,MAX_SIZE);
        memset(m_RtmpUrl,0,MAX_SIZE);
        memset(m_AudioIP,0,MAX_SIZE);
    }
    PackType m_nType;   //包类型
    int m_UserID;
    int m_AudioPort;
    char m_szUser[MAX_SIZE];
    char m_RtmpUrl[MAX_SIZE];
    char m_AudioIP[20];

} STRU_ROOM_MEMBER_RQ;

//离开房间请求
typedef struct STRU_LEAVEROOM_RQ
{
    STRU_LEAVEROOM_RQ()
    {
        m_nType = DEF_PACK_LEAVEROOM_RQ;
        m_nUserId = 0;
        m_RoomId = 0;
    }
    PackType   m_nType;   //包类型
    int    m_nUserId; //用户ID
    int    m_RoomId;
} STRU_LEAVEROOM_RQ;

//离开房间回复
typedef struct STRU_LEAVEROOM_RS
{
    STRU_LEAVEROOM_RS()
    {
        m_nType = DEF_PACK_LEAVEROOM_RS;
        m_UserID = 0;
        memset(szUserName,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int m_UserID;
    char szUserName[MAX_SIZE];
} STRU_LEAVEROOM_RS;


#endif



