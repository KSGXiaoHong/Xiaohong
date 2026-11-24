/*
    lvgl UI界面头文件
*/

#pragma once

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <linux/input.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <time.h>
#include <pthread.h>
#include <termios.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <sys/select.h>
#include <sys/time.h>
#include "lvgl/lvgl.h"
#include "lvgl/demos/lv_demos.h"
#include "LVGL/examples/lv_examples.h"
#include "lcdpjt.h"
#include "bmp.h"
#include "touch.h"
#include "car.h"
#include "play.h"
#include "mokuai.h"
#include "mp4.h"
#include "photo.h"
#include "everyday.h"
#include "game.h"
#include "map.h"
#include "user.h"

#define LV_USE_GIF 1
#define LV_USE_FS_STDIO 1   //开启文件系统，允许解码器使用 fopen\fclose 等函数
#define LV_FS_STDIO_LETTER 'A'
#define LV_FS_POSIX_LETTER 'A'
#define CTRL_NUM 7//功能按键数量
#define APP_NUM 9 //应用程序数量

extern char buf_recv[1024];
extern int ready_read;
extern lv_obj_t* ta2;
//清空当前屏幕所有对象
void clear_screen() ;
//背景界面
void def();
//启动按钮函数
static void car_start_func();
//锁车按键
static void car_lock();
//主菜单函数
void menu();
