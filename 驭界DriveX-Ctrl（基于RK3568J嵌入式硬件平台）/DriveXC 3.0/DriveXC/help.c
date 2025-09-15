#include "help.h"

//帮助 应用程序
void help_app()
{
    //帮助窗口
    lv_obj_t* p = lv_scr_act();//获取当前屏幕
    lv_obj_clean(p);//清空
    lv_obj_t* help_win = lv_obj_create(p);//创建帮助界面窗口
    lv_obj_set_style_bg_color(help_win,lv_color_hex(0xd8e8ce),LV_PART_MAIN);
    lv_obj_set_size(help_win,1024,600);//全屏
    lv_obj_center(help_win);
    lv_obj_set_scroll_dir(help_win, LV_DIR_NONE); //禁止滑动NONE

    //关闭按键
    lv_obj_t* close_help = lv_btn_create(help_win);//右上角创建红色关闭按键
    lv_obj_set_style_bg_color(close_help,lv_color_hex(0xff5555),LV_PART_MAIN);
    lv_obj_align(close_help,LV_ALIGN_TOP_RIGHT,0,0);
    lv_obj_set_size(close_help,50,50);
    lv_obj_add_event_cb(close_help,close_help_cb,LV_EVENT_CLICKED,NULL);

    //创建标签在左上角，显示显示help文本
    lv_obj_t *help_label = lv_label_create(help_win);
    lv_label_set_text(help_label, "help");
    lv_obj_set_align(help_label,LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_bg_color(help_label,lv_color_hex(0x0000ff),LV_PART_MAIN);
    lv_obj_set_style_text_font(help_label, &lv_font_montserrat_40,LV_PART_MAIN);

    //创建三个按键，设备说明、菜单说明、驾驶界面说明
    lv_obj_t* help_btn[3];
    lv_obj_t* help_btn_pt;//图片说明按键
    char help_path[64];//图片路径
    for(int i = 0;i < 3;i++)
    {
        help_btn[i] = lv_obj_create(help_win);//创建按键
        lv_obj_set_scroll_dir(help_btn[i], LV_DIR_NONE); //禁止滑动NONE
        lv_obj_set_size(help_btn[i],150,150);
        lv_obj_set_style_bg_color(help_btn[i],lv_color_hex(0xeeeeee),LV_PART_MAIN);
        help_btn_pt = lv_image_create(help_btn[i]);//创建按键图
        lv_obj_center(help_btn_pt);
        sprintf(help_path,"A:/XiaoHong/photo/help_btn_%d.bmp",i+1);//拼接路径
        lv_image_set_src(help_btn_pt, help_path);//图显示
        lv_obj_set_pos(help_btn[i],20+(i*180),60);//按键之间间隔180-150
        //绑定说明书函数，传入点击的是第几个按键，用来选择第几个说明书
        lv_obj_add_event_cb(help_btn[i],help_book,LV_EVENT_CLICKED,(void*)(i+1));
    }
}

//退出帮助界面回调函数
static void close_help_cb()
{
    lv_obj_clean(lv_scr_act());//清空屏幕
    menu();
}

//显示指定说明书函数  1设备说明、3驾驶界面说明、2菜单说明
static void help_book(lv_event_t* e)
{
    //保存按下的第几个说明书 1 2 3 
    int flag_help_bt = (int)lv_event_get_user_data(e);
    //说明书图片路径
    char help_book_path[64];
    //拼接路径
    sprintf(help_book_path,"A:/XiaoHong/photo/help_book_%d.bmp",flag_help_bt);
    lv_obj_t* p = lv_scr_act();//获取当前屏幕
    lv_obj_clean(p);  // 清除屏幕上的所有元素
    //创建窗口
    lv_obj_t* win = lv_obj_create(p);
    lv_obj_set_size(win,900,600);
    lv_obj_set_style_bg_color(win,lv_color_hex(0xffffff),LV_PART_MAIN);
    lv_obj_center(win);
    lv_obj_set_scroll_dir(win, LV_DIR_VER);  // 仅垂直滑动
    //窗口显示图片，使用说明
    lv_obj_t* help_pt = lv_image_create(win);
    lv_image_set_src(help_pt,help_book_path);
    //返回按键，屏幕左上角
    lv_obj_t* exit_btn = lv_btn_create(p);
    lv_obj_align(exit_btn,LV_ALIGN_TOP_LEFT,0,0);
    lv_obj_set_size(exit_btn,40,40);
    lv_obj_set_style_bg_color(exit_btn,lv_color_hex(0xdd0000),LV_PART_MAIN);
    lv_obj_add_event_cb(exit_btn,back_help_cb,LV_EVENT_CLICKED,NULL);//点击返回
}

//退出说明书回调函数
static void back_help_cb()
{
    lv_obj_clean(lv_scr_act());//清空屏幕
    help_app();
}