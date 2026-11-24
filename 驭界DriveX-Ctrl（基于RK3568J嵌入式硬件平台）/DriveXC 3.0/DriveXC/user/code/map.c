#include "lv.h"

//绘制地图菜单主界面
void map_menu()
{
    lv_obj_t* p = lv_scr_act();//获取当前屏幕
    lv_obj_clean(p);  //清除屏幕上的所有元素

    /**********中国地图：begin**********/
    lv_obj_t* zg = lv_btn_create(p);//创建按键 中国地图
    lv_obj_t* zg_pt = lv_image_create(zg);//图片说明
    lv_obj_center(zg_pt);
    lv_image_set_src(zg_pt,"A:/XiaoHong/photo/zg_pt.bmp");
    lv_obj_set_size(zg,341,500);
    lv_obj_set_style_bg_color(zg,lv_color_hex(0x00ff00),LV_PART_MAIN);//设置颜色
    lv_obj_align(zg,LV_ALIGN_TOP_MID,0,0);//中上
    lv_obj_add_event_cb(zg, dis_map, LV_EVENT_CLICKED, (void*)1);//传入1
    /**********中国地图：end**********/

    /**********湖南地图：begin**********/
    lv_obj_t* hn = lv_btn_create(p);//创建按键 湖南地图
    lv_obj_t* hn_pt = lv_image_create(hn);//图片说明
    lv_obj_center(hn_pt);
    lv_image_set_src(hn_pt,"A:/XiaoHong/photo/hn_pt.bmp");
    lv_obj_set_size(hn,341,600);
    lv_obj_set_style_bg_color(hn,lv_color_hex(0xff0000),LV_PART_MAIN);//设置颜色
    lv_obj_align(hn,LV_ALIGN_LEFT_MID,0,0);//左中
    lv_obj_add_event_cb(hn, dis_map, LV_EVENT_CLICKED, (void*)2);//传入2
    /**********湖南地图：end**********/

    /**********广东地图：begin**********/
    lv_obj_t* gd = lv_btn_create(p);//创建按键 广东地图
    lv_obj_t* gd_pt = lv_image_create(gd);//图片说明
    lv_obj_center(gd_pt);
    lv_image_set_src(gd_pt,"A:/XiaoHong/photo/gd_pt.bmp");
    lv_obj_set_size(gd,341,600);
    lv_obj_set_style_bg_color(gd,lv_color_hex(0x0000ff),LV_PART_MAIN);//设置颜色
    lv_obj_align(gd,LV_ALIGN_RIGHT_MID,0,0);//右中
    lv_obj_add_event_cb(gd, dis_map, LV_EVENT_CLICKED, (void*)3);//传入3
    /**********广东地图：end**********/
    
    //关闭按键
    lv_obj_t* back = lv_btn_create(p);
    lv_obj_set_size(back,341,100);
    lv_obj_set_style_bg_color(back,lv_color_hex(0x000000),LV_PART_MAIN);//设置颜色
    lv_obj_align(back,LV_ALIGN_BOTTOM_MID,0,0);//中下
    lv_obj_add_event_cb(back, menu, LV_EVENT_CLICKED, NULL);//返回主菜单
}

//显示什么地图，1中国地图，2湖南地图，3广东地图
void dis_map(lv_event_t *e)
{
    //保存按下的是什么地图
    int map_flag = (int)lv_event_get_user_data(e);
    char* map_pt_path = NULL;
    if(map_flag == 1)//中国地图
    {
        map_pt_path = "A:/XiaoHong/photo/map.bmp";
    }
    else if(map_flag == 2)//湖南地图
    {
        map_pt_path = "A:/XiaoHong/photo/hunan.bmp";
    }
    else if(map_flag == 3)//广东地图
    {
        map_pt_path = "A:/XiaoHong/photo/guangdong.bmp";
    }
    lv_obj_t* p = lv_scr_act();//获取当前屏幕
    lv_obj_clean(p);  //清除屏幕上的所有元素

    lv_obj_t* map_win = lv_obj_create(p);//创建显示窗口
    lv_obj_set_size(map_win,1024,600);
    lv_obj_center(map_win);
    lv_obj_t* map_pt = lv_image_create(map_win);//窗口显示地图
    lv_obj_set_pos(map_pt,0,0);
    lv_image_set_src(map_pt,map_pt_path);
    lv_obj_t* back = lv_btn_create(map_pt);//图片上创建返回按键
    lv_obj_set_size(back,50,50);
    lv_obj_set_style_bg_color(back,lv_color_hex(0xff0000),LV_PART_MAIN);//设置颜色
    lv_obj_align(back,LV_ALIGN_TOP_LEFT,0,0);//右上角
    lv_obj_add_event_cb(back, map_menu, LV_EVENT_CLICKED,NULL);//点击回到地图菜单
}