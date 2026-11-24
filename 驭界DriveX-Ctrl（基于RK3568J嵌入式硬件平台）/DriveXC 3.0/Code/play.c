#include"play.h"

//参数检测应用程序
void Canshu()
{
    lvgl_Mokuai(NULL);
}

//视频播放器应用程序
void video()
{
    lvgl_mp4();
}

//相册应用程序
void photos()
{
    lv_obj_t *scr = lv_scr_act();//获取当前屏幕
    lv_obj_clean(scr);  // 清除屏幕上的所有元素
    photo();
    menu();//重新调用菜单界面函数
}

//日历应用程序
void everyday()
{
    eveyday_start();
}

//鼠角洲行动应用程序
void play()
{
    lv_obj_t *scr = lv_scr_act();//获取当前屏幕
    lv_obj_clean(scr);  // 清除屏幕上的所有元素
    // 调用bmp_dis函数，显示加载图片
    bmp_dis("./photo/loading1.bmp",0,0);
    sleep(1);
    play_game();//执行游戏
    menu();//重新调用菜单界面函数
}

//其他待添加功能
void other()
{
    lv_obj_t *scr = lv_scr_act();//获取当前屏幕
    lv_obj_clean(scr);  // 清除屏幕上的所有元素
    bmp_dis("./photo/other.bmp",0,0);
    test_touch(0,1024,0,600);//点击任意区域返回
    menu();
}