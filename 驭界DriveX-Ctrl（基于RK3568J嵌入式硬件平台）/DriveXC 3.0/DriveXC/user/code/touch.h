/* 
    触摸屏相关操作文件
*/

#pragma once

#include "lv.h"

//声明外部全局变量
extern int* plcd;//lcd映射空间首地址
extern int lcd_fd;//lcd文件描述符
extern int fg_game;//游戏运行标志位game.c
extern int time_ms;//地鼠显示时长

//存放操作屏幕时获取到的坐标
typedef struct touch
{
    int x;
    int y;
}Point;

//获取点击屏幕时坐标函数\
返回一个结构体类型\
结构体保存x、y坐标
Point test_xy();

//触摸屏属性获取,将Point类型的结构体成员p1作为标志位返回\
当点击屏幕时，返回的就是坐标；滑动上下左右滑，分别返回p1.x值为1234\
没有操作且超时，返回p1.x值为-1
Point hua_xy();


//指定矩形区域触屏反馈，点击到了返回1，点击到左上角返回键返回2，否则不断检测\
传入坐标，a，b为横坐标，c，d为纵坐标，ac决定坐上，保存决定右上，ad决定坐下，bd决定右下
int test_touch(int a,int b,int c,int d);
