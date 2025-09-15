#include"lv.h"


int main(void)
{
    /**********模块线程创建：begin**********/
    MokuaiPaths pth = { "/dev/ttyS1","/dev/ttyS0" } ;//指定串口路径
    pthread_t tid;//创建一个线程来不断检测
    //初始化线程互斥锁
    pthread_mutex_init( &(mk_data.mutex),NULL);
    pthread_create(&tid,NULL,MK_thread,(void*)&pth);//在mokuai.h
    /**********模块线程创建：end**********/

    /**********lvgl初始化：begin**********/
    lv_init();
    /*Linux frame buffer device init*/
    lv_display_t * disp = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp, "/dev/fb0");
    lv_indev_t* indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event6");
    /**********lvgl初始化:end**********/
    
    //开机界面
    bmp_dis("./photo/wel.bmp",0,0);
    sleep(2);
    //初始化车载屏幕界面
    def();
    
    /*Handle LVGL tasks*/ 
    while(1) 
    {
        if(ready_read)//判断读数据是否就绪
        {
            lv_textarea_set_text(ta2, buf_recv);
            ready_read = 0;//重置读数据就绪
        }
        lv_timer_handler();
        usleep(5000);
    }
    return 0;
}
