/*
    日历应用程序头文件
*/

#pragma once

#include "lv.h"

//创建全屏日历
void eveyday_start();
//日历事件处理函数
static void event_handler(lv_event_t *e);
//关闭按钮回调函数，传入日历窗口
static void close_everyday_cb(lv_event_t *e);
