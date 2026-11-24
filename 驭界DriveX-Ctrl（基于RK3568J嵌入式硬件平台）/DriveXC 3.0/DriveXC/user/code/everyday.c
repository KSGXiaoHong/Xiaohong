#include "everyday.h"

//创建全屏日历
void eveyday_start()
{
    printf("%d\n",time(NULL));
    /**********日历窗口：begin**********/
    clear_screen();//清空屏幕
    lv_obj_t* everyday_win = lv_obj_create(lv_scr_act());//创建窗口
    lv_obj_set_size(everyday_win, 1024, 600); //全屏大小
    lv_obj_center(everyday_win);//居中
    lv_obj_clear_flag(everyday_win, LV_OBJ_FLAG_SCROLLABLE); //禁止滚动
    //创建标签在左上角，显示日历文字
    lv_obj_t *everyday_label = lv_label_create(everyday_win);
    lv_label_set_text(everyday_label, "everyday");
    lv_obj_set_align(everyday_label,LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_bg_color(everyday_label,lv_color_hex(0xffffff),LV_PART_MAIN);
    lv_obj_set_style_text_font(everyday_label, &lv_font_montserrat_30,LV_PART_MAIN);
    /**********日历窗口：end**********/
    
    /**********日历：begin**********/
    lv_obj_t *calendar = lv_calendar_create(everyday_win);//创建日历控件
    lv_obj_set_size(calendar, 1024 - 40, 600 - 100);//设置日历大小
    lv_obj_align(calendar, LV_ALIGN_BOTTOM_MID, 0, 0); //下对齐居中
    lv_obj_add_event_cb(calendar, event_handler, LV_EVENT_ALL, NULL);
    lv_calendar_set_today_date(calendar, 2025, 8, 16);//显示今天
    lv_calendar_set_showed_date(calendar, 2025, 8);
    lv_calendar_header_dropdown_create(calendar);//添加日历头部导航
    /**********日历：end**********/

    /**********关闭按键：begin**********/
    lv_obj_t* close_btn = lv_btn_create(everyday_win);//创建按钮
    lv_obj_set_size(close_btn, 40, 40); //按钮大小
    lv_obj_set_align(close_btn,LV_ALIGN_TOP_RIGHT);
    lv_obj_set_style_bg_color(close_btn, lv_color_hex(0xFF5252), LV_STATE_DEFAULT);
    lv_obj_t *close_label = lv_label_create(close_btn);//关闭按键上创建一个标签
    lv_label_set_text(close_label, "X");//标签内容
    lv_obj_set_style_text_color(close_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN); //白色文字
    lv_obj_set_style_text_font(close_label, &lv_font_montserrat_24, LV_PART_MAIN); //字体大小
    lv_obj_center(close_label); //标签居中
    lv_obj_add_event_cb(close_btn, close_everyday_cb, LV_EVENT_CLICKED, everyday_win);//传入日历窗口
    /**********关闭按键：end**********/
}

//日历事件处理函数
static void event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_current_target(e);

    if(code == LV_EVENT_VALUE_CHANGED) 
    {
        lv_calendar_date_t date;
        if(lv_calendar_get_pressed_date(obj, &date)) 
        {
            LV_LOG_USER("Clicked date: %02d.%02d.%d", date.day, date.month, date.year);
        }
    }
}

//关闭按钮回调函数，传入日历窗口
static void close_everyday_cb(lv_event_t *e)
{
    //获取传递的日历窗口
    lv_obj_t *everyday_win = lv_event_get_user_data(e);
    if(everyday_win) 
        lv_obj_del(everyday_win); //销毁日历窗口
    menu();//回到菜单
}
