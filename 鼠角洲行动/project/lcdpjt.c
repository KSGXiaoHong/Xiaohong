#include"lcdpjt.h"

//用来保存映射空间首地址
int* plcd = NULL;

//打开lcd文件和映射
int Lcd_Init()
{
    int lcd_fd = open("/dev/fb0",O_RDWR);
    if(lcd_fd == -1)
    {
        perror("open lcd");
        return lcd_fd;
    }
    //开启文件的映射关系
    plcd = mmap(NULL,
            LCD_SIZE,
            PROT_READ | PROT_WRITE,
            MAP_SHARED,
            lcd_fd,
            0);
    if(plcd == NULL)
    {
        perror("mmap");
        return lcd_fd;
    }
    return lcd_fd;
}

//输入要显示的点的坐标和颜色
void Display_point(int x , int y , int color)
{
    if(x>=0&&x<1024&&y>=0&&y<600)
    {
        //颜色的值赋给指定坐标位置
        *(plcd+x+1024*y)=color;
    }
    return ;
}

//lcd屏幕显示的指定颜色
void Display_lcd(int color)
{
    for(int i = 0;i < 600 ; i++)
    {
        for(int j = 0 ; j < 1024 ; j++)
        {
            Display_point(j,i,color);
        }
    }
}

void Lcd_red()
{
    for(int i = 0;i < 600 ; i++)
    {
        for(int j = 0 ; j < 1024 ; j++)
        {
            Display_point(j,i,RED);
        }
    }
}
void Lcd_green()
{
    for(int i = 0;i < 600 ; i++)
    {
        for(int j = 0 ; j < 1024 ; j++)
        {
            Display_point(j,i,GREEN);
        }
    }
}
void Lcd_blue()
{
    for(int i = 0;i < 600 ; i++)
    {
        for(int j = 0 ; j < 1024 ; j++)
        {
            Display_point(j,i,BLUE);
        }
    }
}

//解除映射关闭文件
void Lcd_free(int lcd_fd)
{
    munmap(plcd,LCD_SIZE);
    close(lcd_fd);
}