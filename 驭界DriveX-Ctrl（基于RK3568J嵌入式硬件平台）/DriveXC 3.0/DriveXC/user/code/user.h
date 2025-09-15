/*
    用户交互界面头文件
*/

#pragma once

#define IP "192.168.137.5"//ip地址
#define DK 5674//端口号
#define CLIENT_MAX_NUM 10//客户端最大值

extern pthread_t client_tid;
//客户端线程client
void* client_thread(void* arg);
//客户端接收服务器消息线程
static void* RecvToServer_thread(void* arg);
//客户端给服务器发消息线程
static void* SendToServer_thread(void* arg);
static void ta_event_cb(lv_event_t * e);
void user_FanKui();
static void user_back();
//退出帮助界面回调函数
void back_help_cb();
void user_exit();
