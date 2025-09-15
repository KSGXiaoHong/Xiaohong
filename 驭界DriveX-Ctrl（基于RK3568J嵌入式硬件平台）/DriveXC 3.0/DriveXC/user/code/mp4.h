/*
    视频播放器应用程序头文件
*/

#pragma once

#include "lv.h"

//管道文件路径
#define FIFO_NAME "/home/test.fifo"
#define NUM 4//视屏数量，方便修改视频

//lvgl初始化视频列表
void lvgl_mp4();
//关闭小窗视频界面函数
static void close_win_event_cb();
//选择哪一个视频播放函数
static void video_play_event_cb(lv_event_t *e);
//检测是否全屏，\
返回1表示点击是，2否
int touch_really();
//关闭全屏回调
void close_really_event_cb();
//驾驶时播放视频 警告弹窗函数
void warning_if();
//清除遮罩和警告窗口
void clean_warning(lv_event_t* e);
//清除遮罩和警告窗口并播放
static void clean_warning_start(lv_event_t* e);
//播放暂停函数
void start_stop();
//停止函数
void video_over();
//快进函数
void seek_up();
//后退函数
void seek_down();
