#include"lv.h"

//汽车点火启动按键标志位
static int start_flag = 0;

//清空当前屏幕所有对象
void clear_screen() 
{
    lv_obj_t* scr = lv_scr_act();
    if(scr) 
        lv_obj_clean(scr);
}

//默认界面
void def()
{
    clear_screen() ;//清空屏幕
    //获取当前屏幕
    lv_obj_t* p = lv_screen_active();
    //创建一个图片控件,显示背景图片
    lv_obj_t* bg = lv_image_create(p);
    lv_image_set_src(bg, "A:/XiaoHong/photo/bg.bmp");
    
    /**********创建车内控制按键样式：begin**********/
    static lv_style_t style_ctl_button ;
    static int style_ctl_button_inited = 1; //初始化样式标志
    if (style_ctl_button_inited) 
    {
        lv_style_init(&style_ctl_button); // 仅初始化一次
        lv_style_set_bg_color(&style_ctl_button, lv_color_hex(0xa6c0bd));
        lv_style_set_size(&style_ctl_button,60,60);
        style_ctl_button_inited = 0; // 已初始化
    }
    /**********创建车内控制按键样式：end**********/

    /**********创建透明样式：begin**********/
    static lv_style_t tm_style;
    static int tm_style_inited = 1;
    if (tm_style_inited) 
    {
        lv_style_init(&tm_style); // 仅初始化一次
        lv_style_set_bg_opa(&tm_style, LV_OPA_0);//背景
        lv_style_set_border_opa(&tm_style, LV_OPA_0);//边框
        lv_style_set_shadow_opa(&tm_style, LV_OPA_0);//阴影
        lv_style_set_pad_all(&tm_style, 0);
        tm_style_inited = 0; // 标记为已初始化
    }
    /**********创建透明样式：end**********/

    /**********点火按键：begin**********/
    //创建点火按钮
    lv_obj_t* start_button = lv_button_create(p);
    //应用按钮样式
    lv_obj_add_style(start_button, &style_ctl_button, LV_STATE_DEFAULT);
    //重新设置位置大小
    lv_obj_set_pos(start_button,765,460);
    lv_obj_set_size(start_button,100,60);
    lv_obj_set_style_radius(start_button,80,LV_PART_MAIN);//将边框置为圆角
    lv_obj_t* start_text = lv_label_create(start_button);//创建标签
    lv_label_set_text(start_text,(start_flag==0)?("START"):("STOP"));//判断启动标志位来显示对应文字
    lv_obj_set_style_text_color(start_text,lv_color_hex(0x00ff00),LV_PART_MAIN);
    lv_obj_set_style_text_font(start_text, &lv_font_montserrat_24,LV_PART_MAIN);
    lv_obj_center(start_text);
    lv_obj_add_event_cb(start_button, car_start_func, LV_EVENT_CLICKED,NULL);
    /**********点火按键：end**********/

    /**********两个灯光按键：begin**********/
    //创建两个按键
    lv_obj_t* light_button = lv_button_create(p);
    lv_obj_t* dblight_button = lv_button_create(p);
    //按键上创建个图标
    lv_obj_t* lgtbt_pt = lv_image_create(light_button);
    lv_obj_t* dblgtbt_pt = lv_image_create(dblight_button);
    //按键应用按键样式
    lv_obj_add_style(light_button, &style_ctl_button, LV_STATE_DEFAULT);//添加按键样式到大灯
    lv_obj_add_style(dblight_button, &style_ctl_button, LV_STATE_DEFAULT);//添加按键样式到双闪
    //位置设置
    lv_obj_set_pos(light_button,735,530);
    lv_obj_set_pos(dblight_button,835,530);
    //显示图标
    lv_image_set_src(lgtbt_pt, "A:/XiaoHong/photo/lgt_bt.bmp");
    lv_image_set_src(dblgtbt_pt, "A:/XiaoHong/photo/dblgt_bt.bmp");
    //图标居中
    lv_obj_center(lgtbt_pt);
    lv_obj_center(dblgtbt_pt);
    //注册点击事件,绑定大灯和双闪回调
    lv_obj_add_event_cb(light_button, lgt, LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(dblight_button, dblgt, LV_EVENT_CLICKED,NULL);
    /**********两个灯光按键：end**********/
    
    /**********单座椅调节：begin**********/
    //创建四个按键（四个座位）
    lv_obj_t* zy_bt[4];  
    for(int i = 0;i < 4;i++)//座椅按键设置透明
    {
        zy_bt[i] = lv_button_create(p); 
        lv_obj_add_style(zy_bt[i],&tm_style,LV_STATE_DEFAULT);//应用透明样式
        lv_obj_add_event_cb(zy_bt[i], zy_ctrl, LV_EVENT_CLICKED,(void*)(i+1));//注册事件,绑定各座椅，松手执行回调函数
    }
    //设置按钮的大小  位置
    lv_obj_set_size(zy_bt[0],69,110);
    lv_obj_set_size(zy_bt[1],72,110);
    lv_obj_set_size(zy_bt[2],88,150);
    lv_obj_set_size(zy_bt[3],86,150);
    lv_obj_set_pos(zy_bt[0],740,80);//后右
    lv_obj_set_pos(zy_bt[1],840,80);//后左
    lv_obj_set_pos(zy_bt[2],720,200);//主驾
    lv_obj_set_pos(zy_bt[3],840,200);//副驾
    /**********单座椅调节：end**********/
    
    /**********功能按键：begin**********/
    //前挡风除雾，后挡风除雾，后备箱，座椅加热，环境参数，视频播放器
    //创建一个窗口用来存放这些按键
    lv_obj_t* win =  lv_obj_create(p);
    lv_obj_add_style(win,&tm_style,LV_STATE_DEFAULT);//窗口应用透明样式
    lv_obj_set_size(win,300,150);
    lv_obj_set_pos(win,30,450);
    lv_obj_set_scroll_dir(win,LV_DIR_HOR);//仅允许水平滑动
    //创建功能按键6个
    lv_obj_t* ctl_button[6];
    //给按键添加图标
    lv_obj_t* app;
    char app_pathname[256];//保存图标路径
    for(int i=0;i<6;i++)
    {
        ctl_button[i] = lv_button_create(win);//将按键创建在窗口上
        app = lv_image_create(ctl_button[i]);//图片创建在对应按键上
        sprintf(app_pathname,"A:/XiaoHong/photo/bt_%d.bmp",i+1);//拼接图片路径
        lv_image_set_src(app, app_pathname);//显示图片
        lv_obj_center(app);
        //按键位置 大小
        lv_obj_set_pos(ctl_button[i],1+(i*60),1);
        lv_obj_set_size(ctl_button[i],57,57);
        lv_obj_set_style_bg_color(ctl_button[i],lv_color_hex(0xb9b8b8),LV_PART_MAIN);//设置颜色
    }
    lv_obj_add_event_cb(ctl_button[0], win_front, LV_EVENT_CLICKED,NULL);//后备箱
    lv_obj_add_event_cb(ctl_button[1], win_rear, LV_EVENT_CLICKED,NULL);//后挡风除雾
    lv_obj_add_event_cb(ctl_button[2], pigu_hot, LV_EVENT_CLICKED,NULL);//座椅加热
    lv_obj_add_event_cb(ctl_button[3], car_bag, LV_EVENT_CLICKED,NULL);//后备箱
    lv_obj_add_event_cb(ctl_button[4], lvgl_Mokuai, LV_EVENT_CLICKED,NULL);//环境
    if(start_flag == 1)//车辆启动，调用询问函数
        lv_obj_add_event_cb(ctl_button[5], warning_if, LV_EVENT_CLICKED,NULL);//
    else//未启动，直接调用视频函数
        lv_obj_add_event_cb(ctl_button[5], video, LV_EVENT_CLICKED,NULL);//视频
    /**********功能按键：end**********/
   

    /**********点火状态：begin**********/
    if(start_flag == 1)
    {
        lv_obj_t* warning_menu = lv_image_create(bg);//背景上创建一个图片
        lv_image_set_src(warning_menu,"A:/XiaoHong/photo/warning_menu.bmp");//提示菜单关闭
        lv_obj_set_style_align(warning_menu,LV_ALIGN_BOTTOM_MID,LV_PART_MAIN);
        lv_obj_t* you = lv_image_create(p);//油量图标
        lv_image_set_src(you, "A:/XiaoHong/photo/you.bmp");
        lv_obj_set_pos(you, 110, 138);//设置图片位置
        //油量条
        lv_obj_t* slider = lv_slider_create(bg);//创建一个滑块控件
        lv_slider_set_range(slider, 0, 100);//范围0-100
        lv_slider_set_value(slider, 50, LV_ANIM_ON);//初始值50
        lv_obj_set_size(slider, 200, 20);//设置大小
        lv_obj_set_pos(slider, 180, 152);//设置位置
        lv_obj_set_style_opa(slider, LV_OPA_0,LV_PART_KNOB);//隐藏旋钮
        lv_obj_set_style_bg_color(slider, lv_color_hex(0xF0F0F0),LV_PART_MAIN);//背景灰色
        lv_obj_set_style_border_color(slider, lv_color_hex(0xD0D0D0),LV_PART_MAIN);//灰色边框
        lv_obj_set_style_border_width(slider, 2,LV_PART_MAIN);//边框粗细
        lv_obj_set_style_radius(slider, 25,LV_PART_MAIN); //圆角25
        //已填充部分
        lv_obj_set_style_bg_color(slider, lv_color_hex(0x2196F3),LV_PART_INDICATOR);//蓝色
        lv_obj_set_style_radius(slider, 25,LV_PART_INDICATOR); //圆角25
    }
    /**********点火状态：end**********/

    /**********熄火状态：begin**********/
    if(start_flag == 0)
    {
        /*主菜单按键*/
        //创建1个按键，主菜单按键
        lv_obj_t* button = lv_button_create(bg);
        lv_obj_t* menu_pj = lv_image_create(button);//按键上创建一个图片
        lv_image_set_src(menu_pj,"A:/XiaoHong/photo/menu_pj.bmp");
        lv_obj_center(menu_pj);
        lv_obj_set_size(button,60,60);
        //设置按钮的位置
        lv_obj_set_align(button,LV_ALIGN_BOTTOM_MID);
        //按钮颜色
        lv_obj_set_style_bg_color( button, lv_color_hex(0xffffff),LV_PART_MAIN);
        //注册事件,绑定到按键，松手执行回调函数，主菜单函数
        lv_obj_add_event_cb(button, menu, LV_EVENT_CLICKED,NULL);
    }
    /**********熄火状态：end**********/
}

//启动按钮函数
static void car_start_func()
{
    //将汽车启动标志位置翻转，重新绘制默认界面
    start_flag = 1 ^ start_flag;
    def();
}

//主菜单函数
void menu()
{
    clear_screen() ;
    //获取当前屏幕
    lv_obj_t* p = lv_screen_active();
    //屏幕白色
    lv_obj_set_style_bg_color(p,lv_color_hex(0xffffff),LV_PART_MAIN);
    
    /**********创建透明样式：begin**********/
    static lv_style_t tm_style;
    static int tm_style_inited = 1;
    if (tm_style_inited) 
    {
        lv_style_init(&tm_style); // 仅初始化一次
        lv_style_set_bg_opa(&tm_style, LV_OPA_0);//背景
        lv_style_set_border_opa(&tm_style, LV_OPA_0);//边框
        lv_style_set_shadow_opa(&tm_style, LV_OPA_0);//阴影
        lv_style_set_pad_all(&tm_style, 0);
        tm_style_inited = 0; // 标记为已初始化
    }
    /**********创建透明样式：end**********/

    /**********显示menu文本：begin**********/
    //创建标签在左上角，显示绿色menu文本
    lv_obj_t *menu_label = lv_label_create(p);
    lv_label_set_text(menu_label, "menu");
    lv_obj_set_align(menu_label,LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_bg_color(menu_label,lv_color_hex(0x00ff00),LV_PART_MAIN);
    lv_obj_set_style_text_font(menu_label, &lv_font_montserrat_40,LV_PART_MAIN);
    /**********显示menu文本：end**********/

    /**********窗口及背景创建：begin**********/
    //在屏幕上创建一个1024*550窗口，底部居中显示
    lv_obj_t* obj =  lv_obj_create(p);
    lv_obj_set_size(obj,1024,550);
    lv_obj_set_align(obj,LV_ALIGN_BOTTOM_MID);
    lv_obj_add_style(obj,&tm_style,LV_STATE_DEFAULT);//应用透明样式
    lv_obj_set_scroll_dir(obj,LV_DIR_HOR);//仅水平滑动
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);// 隐藏滚动条
    //给窗口添加个背景
    lv_obj_t * bg = lv_image_create(obj);
    lv_image_set_src(bg, "A:/XiaoHong/photo/menu_bg.bmp");
    lv_obj_set_pos(bg,0,0);
    /**********窗口及背景创建：end**********/

    /***********返回按键：begin**********/
    //窗口右上角添加50*50红色返回按键
    lv_obj_t* bt = lv_button_create(p);
    lv_obj_set_size(bt,50,50);
    lv_obj_set_align(bt,LV_ALIGN_TOP_RIGHT);
    lv_obj_set_style_bg_color(bt,lv_color_hex(0xff0000),LV_PART_MAIN);
    lv_obj_t *bt_label = lv_label_create(bt);//创建标签显示文本
    lv_label_set_text(bt_label, "X");//给按钮添加个X
    lv_obj_center(bt_label);
    lv_obj_add_event_cb(bt, def, LV_EVENT_CLICKED,NULL);//注册事件，点击返回初始界面
    /***********返回按键：end**********/
    
    /**********应用程序图标创建：begin**********/
    //在窗口上创建7个按键座位应用程序已经图标
    lv_obj_t* button[7];
    lv_obj_t* app;//图标控件
    char app_pathname[256];//存放图标路径
    for(int i = 0 ; i<7 ; i++)
    {
        sprintf(app_pathname,"A:/XiaoHong/photo/app_%d.bmp",i+1);//拼接图标路径
        button[i] = lv_button_create(obj);
        lv_obj_set_size(button[i],300,420);//设置按钮的大小
        lv_obj_add_style(button[i],&tm_style,LV_STATE_DEFAULT);//应用透明样式
        lv_obj_set_pos(button[i],20+i*(75+300),30);//设置按钮的位置,间隔25
        app = lv_image_create(button[i]);//按键上创建图标
        lv_image_set_src(app, app_pathname);//图标显示
        lv_obj_center(app);//图标居中
    }
    //注册事件,绑定到按键，松手执行回调函数
    lv_obj_add_event_cb(button[0], Canshu, LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(button[1], video, LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(button[2], photos, LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(button[3], everyday, LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(button[4], play, LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(button[5], other, LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(button[6], other, LV_EVENT_CLICKED,obj);
}
