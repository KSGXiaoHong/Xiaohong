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
    

    //初始化车载屏幕界面：begin
    def();
    
    /*Handle LVGL tasks*/ 
    while(1) 
    {
        lv_timer_handler();
        usleep(5000);
    }
    return 0;
}
