/* 
    用户交互 游戏界面文件
*/

#ifndef _GAME_H
#define _GAME_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<stdio.h>
#include <dirent.h>
#include<stdlib.h>
#include <sys/mman.h>
#include<linux/input.h>
#include<math.h>
#include<time.h>
#include"lcdpjt.h"
#include"touch.h"
#include"bmp.h"
//声明外部全局变量
extern int fg_game;
extern unsigned int time_ms;
//开始游戏函数
void play_game();
//游戏二阶段
void game_next();
//指定位置和大小显示搜索动画\
size分别为1 2 4 6 9 12
void gif_search(int x,int y,int size);
//搜寻物资函数
void game_search();

#endif