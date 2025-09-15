/*
    用户交互界面头文件
*/

#pragma once

#include "lv.h"

#define IP "172.130.1.24"//ip地址
#define DK 5674//端口号
#define CLIENT_MAX_NUM 10//客户端最大值

//声明创建k客户端线程标志位
extern int creat_flag ;

//创建键盘函数 用户输入反馈
void user_FanKui();
//客户端线程client
void* client_thread(void* arg);
//客户端接收服务器消息线程
static void* RecvToServer_thread(void* arg);
//客户端给服务器发消息线程
static void* SendToServer_thread(void* arg);
//键盘输入回调 回车存储数据
static void ta_event_cb(lv_event_t * e);
//退出反馈界面函数
static void user_back();
