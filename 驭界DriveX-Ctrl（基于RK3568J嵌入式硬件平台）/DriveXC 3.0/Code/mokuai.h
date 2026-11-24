/*
    参数检测头文件
*/

#pragma once

#include "lv.h"

//保存两个传感器串口路径
typedef struct 
{
    char* gy39_path;
    char* us100_path;
} MokuaiPaths;

//初始化传感器测量到的模块数据结构体\
供模块线程函数和lvgl显示内容同时访问
struct 
{
    int T;//温度
    int Hum;//湿度
    unsigned int P;//气压
    unsigned L;//距离
    int H;//海拔
    pthread_mutex_t mutex;//线程互斥锁
} mk_data;

/*
    串口初始化函数：
        @filename : 你想要配置的串口路径名
        @baudrate : 你想要配置的波特率,目前支持9600 115200 38400
*/
static int Uart_US100_Init(const char* filename , int baudrate);
//传入串口路径，波特率
static int Uart_GY39_Init(const char* filename , int baudrate);
//显示测量的参数
void lvgl_Mokuai();
//定时器回调函数 定时刷新传感器数据
void mokuai_timer(lv_timer_t *timer);
//模块窗口关闭回调函数
void close_window_cb(lv_event_t *e);
//线程函数，不断获取测量的参数值
void* MK_thread(void* arg);
