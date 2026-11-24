/*
    帮助应用程序头文件
*/
#pragma once

#include "lv.h"

//帮助 应用程序
void help_app();
//退出帮助界面回调函数
static void close_help_cb();
//显示指定说明书函数  1设备说明、3驾驶界面说明、2菜单说明
static void help_book(lv_event_t* e);
//退出说明书回调函数
static void back_help_cb();
