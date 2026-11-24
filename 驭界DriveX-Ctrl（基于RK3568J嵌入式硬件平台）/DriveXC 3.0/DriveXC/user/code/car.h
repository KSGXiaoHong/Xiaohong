/*
    汽车相关功能功能头文件
*/

#pragma once

#include "lv.h"

#define NO 0//啥也没有
#define BACK 1 //返回按键
#define FS_UP 2 //风速加按键
#define FS_DOWN 3 //风速减按键
#define WD_UP 4 //温度加按键
#define WD_DOWN 5 //温度减按键
#define AUTO 6//AUTO按键
#define AC 7//A/C按键
#define HOT 8//加热按键
#define TF 9//通风按键
#define NXH 10//内循环按键


//调节座椅函数
void zy_ctrl(lv_event_t *e);
//调节座椅界面关闭调节函数
void back_button_cb(lv_event_t *e);
//灯光实现函数
void lgt();
//双闪实现函数
void dblgt();
//图片弹窗,提示点击按键后的状态，传入图片路径 显示时长ms 坐标
void popup_image_time(const char* img_path,uint32_t delay_ms,int x,int y);
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
//空调功能
void kongtiao();
//空调按键回调函数
void kt_cb(lv_event_t* e);
//定时器回调函数 定时刷新温度数据
static void wd_timer_cb(lv_timer_t *timer);
//显示设定温度函数，传入按下的按键和窗口对象
static void dis_wd(int wd_flag);
//显示风速函数，传入点击的加还是减 
static void dis_fs(int fs_flag);
//文本框显示图片函数,传入图片路径
void dis_kt_text(char* text_path);
//文本显示定时器回调
static void text_timer_cb(lv_timer_t *timer);