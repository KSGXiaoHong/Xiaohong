#include"game.h"
#include"touch.h"
#include"bmp.h"
#include"lcdpjt.h"

int main()
{
    //初始化lcd屏幕
    int lcd_fd = Lcd_Init();
    //调用play_game函数开始游戏
    play_game();
    //关闭lcd
    Lcd_free(lcd_fd);
}