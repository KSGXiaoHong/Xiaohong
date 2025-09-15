#include"play.h"

//初始化创建k客户端线程标志位
int creat_flag = 1;

//帮助界面
void help()
{
    help_app();
}
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

//地图应用程序
void map()
{
    map_menu();
}

//用户服务
void user()
{
    lv_obj_t* scr = lv_scr_act();//获取当前屏幕
    lv_obj_clean(scr);  // 清除屏幕上的所有元素
    //标志位为1才创建线程
    if(creat_flag == 1)
    {
        pthread_t client_tid;
        //创建客户端线程,连接客户端
        pthread_create(&client_tid, NULL, client_thread, NULL);
    }
    usleep(6666);//延时等待server_error判断
    if(server_error)//未连接上显示出错
    {
        bmp_dis("/XiaoHong/photo/server.bmp",200,200);
        sleep(1);
        menu();
    }
    else//连接成功显示键盘
    {
        user_FanKui();//创建键盘
    }
}

//关于界面
void other()
{
    lv_obj_t *scr = lv_scr_act();//获取当前屏幕
    lv_obj_clean(scr);  // 清除屏幕上的所有元素
    bmp_dis("./photo/bbxx.bmp",0,0);
    test_touch(0,1024,0,600);//点击任意区域返回
    menu();
}
