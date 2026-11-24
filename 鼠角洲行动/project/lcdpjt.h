/*
    lcd相关显示文件
*/

#ifndef _LCDPJT_H
#define _LCDPJT_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<stdio.h>
#include <dirent.h>
#include<stdlib.h>
#include <sys/mman.h>
#include"game.h"
#include"touch.h"
#include"bmp.h"

#define LCD_SIZE ((1024)*(600)*(4))//lcd分辨率
#define RED (0xff0000)//红色
#define GREEN (0x00ff00)//绿色
#define BLUE (0x0000ff)//蓝色
#define wite (0xffffff)//白色
#define black (0x000000)//黑色
#define pink (0xf525cf)

//打开lcd文件和映射
int Lcd_Init();
//在x,y坐标显示一个color颜色的点
void Display_point(int x , int y , int color);
//lcd屏幕显示的color颜色
void Display_lcd(int color);
//整个屏幕显示红色
void Lcd_red();
//整个屏幕显示绿色
void Lcd_green();
//整个屏幕显示蓝色
void Lcd_blue();
//关闭文件和解除映射
void Lcd_free(int lcd_fd);


#endif