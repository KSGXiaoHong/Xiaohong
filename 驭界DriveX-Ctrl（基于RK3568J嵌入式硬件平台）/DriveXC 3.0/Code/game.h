/* 
    游戏应用程序头文件
*/

#pragma once

#include "lv.h"

//点击开始游戏执行该函数
void play_game();
//游戏初始界面函数\
检测触屏位置\
返回1表示点击开始游戏，2退出游戏
static int test_touch_play();
//选择难度界面函数，返回地鼠停留的时间
static unsigned int Nan_du();
//游戏运行主函数
static void game_run();
//退出游戏函数
static void play_game_over();
//游戏二阶段，摸金函数
static void game_next();
//搜寻物资函数
static void game_search();
//指定位置和大小显示搜索动画\
size分别为1 2 4 6 9 12
static void gif_search(int x,int y,int size);
