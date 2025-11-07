/*
    图片相关处理文件
*/

#ifndef _BMP_H
#define _BMP_H

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
#include"lcdpjt.h"
#include"touch.h"
#include"game.h"

//初始化bmp,返回fd_bmp
int Bmp_Init(const char* pathname);
//传入bmp的描述符，读取图片信息
char* Read_bmp(int fd_bmp,int* w,int* h,short* d);
//将图片信息写入到LCD，bmp中为bgra，lcd为argb，需要重新组合\
传入长宽色深用来判断，传入的参数为像素数组p,宽k，高h，色深d，位置x,y
void Write_bmp(char* p,int w,int h,short d,int x,int y);
//指定位置显示指定图片的函数\
路径、坐标
void bmp_dis(char* pathname,int x,int y);
//关闭文件
void Free_bmp(char* p,int fd_bmp);
#endif