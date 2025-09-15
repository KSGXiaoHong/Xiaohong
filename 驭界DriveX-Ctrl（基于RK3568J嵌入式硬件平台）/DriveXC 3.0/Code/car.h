/*
    汽车相关功能功能头文件
*/

#pragma once

#include "lv.h"

//调节座椅函数
void zy_ctrl(lv_event_t *e);
//调节座椅界面关闭调节函数
void back_button_cb(lv_event_t *e);
//灯光实现函数
void lgt();
//双闪实现函数
void dblgt();
//图片弹窗,提示点击按键后的状态，传入图片路径 显示时长ms 坐标
static void popup_image_time(const char* img_path,uint32_t delay_ms,int x,int y);
//定时器回调函数 删除弹出的图片
static void delimg_timer_cb(lv_timer_t* timer);
//前挡风除雾
void win_front();
//后挡风除雾
void win_rear();
//座椅加热
void pigu_hot();
//打开后备箱
void car_bag();
