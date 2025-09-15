#include "mp4.h"

static lv_obj_t* mask = NULL;//遮罩层对象
int fd = -1 ;//管道文件描述符初始化

//lvgl初始化视频列表
void lvgl_mp4()
{
    /**********初始化视频界面：begin**********/
    lv_obj_t* p = lv_scr_act();//获取当前屏幕
    if(p) 
        lv_obj_clean(p);//清空屏幕
    lv_obj_set_scroll_dir(p, LV_DIR_NONE);//禁止屏幕滑动
    lv_obj_set_scrollbar_mode(p, LV_SCROLLBAR_MODE_OFF); //隐藏滚动条
    lv_obj_t* vd_bg = lv_image_create(p);//创建视频界面的背景
    lv_image_set_src(vd_bg, "A:/XiaoHong/photo/video_bg.bmp");
    //屏幕右侧创建75*600的红色关闭按键
    lv_obj_t *close_btn = lv_btn_create(p);
    lv_obj_set_size(close_btn,75,600);
    lv_obj_set_pos(close_btn,950,0);
    lv_obj_set_style_radius(close_btn, 0, LV_PART_MAIN);//直角边框
    lv_obj_set_style_bg_color(close_btn,lv_color_hex(0xff0000),LV_PART_MAIN);
    lv_obj_add_event_cb(close_btn, close_win_event_cb, LV_EVENT_CLICKED, NULL); //绑定关闭小窗事件
    /**********初始化视频界面：end**********/

    /**********透明样式：begin**********/
    static lv_style_t tm_style;
    static int tm_style_inited = 0;
    if (!tm_style_inited) 
    {
        lv_style_init(&tm_style); // 仅初始化一次
        lv_style_set_bg_opa(&tm_style, LV_OPA_0);  // 背景
        lv_style_set_border_opa(&tm_style, LV_OPA_0);//边框
        lv_style_set_shadow_opa(&tm_style, LV_OPA_0);//阴影
        tm_style_inited = 1; // 标记为已初始化
    }
    /**********透明样式：end**********/

    /**********视频列表：begin**********/
    //创建窗口用来存放视频缩略图
    lv_obj_t *video_win = lv_obj_create(vd_bg);//创建到屏幕的背景上
    lv_obj_set_pos(video_win,600,0);//窗口位置
    lv_obj_set_size(video_win, 350, 600); //窗口大小
    lv_obj_set_style_radius(video_win, 0, LV_PART_MAIN);//直角边框
    lv_obj_set_style_border_opa(video_win, LV_OPA_TRANSP, LV_PART_MAIN);//边框透明
    lv_obj_set_style_bg_color(video_win,lv_color_hex(0xb4eaf7),LV_PART_MAIN);
    //创建按键加图片作为视频缩略图
    lv_obj_t* vd_bt[NUM];//按键个数
    lv_obj_t* video_btn_pt = NULL;//声明图片对象
    char video_pt_pathname[256] ;//保存图片路径
    for(int i = 0;i < NUM;i++)
    {
        vd_bt[i] = lv_btn_create(video_win);//创建视频按键
        lv_obj_set_pos(vd_bt[i],0,i*(140+30));//按键在窗口的位置 间隔30
        lv_obj_set_size(vd_bt[i], 200, 140); //按键大小
        lv_obj_add_style(vd_bt[i], &tm_style, LV_STATE_DEFAULT);//按键应用透明样式
        video_btn_pt = lv_image_create(vd_bt[i]);//按键上创建缩略图片
        lv_obj_center(video_btn_pt);//居中
        //拼接缩略图路径
        sprintf(video_pt_pathname,"A:/XiaoHong/photo/video_pt_%d.bmp",i+1);
        lv_image_set_src(video_btn_pt, video_pt_pathname);//显示图片
        lv_obj_add_event_cb(vd_bt[i], video_play_event_cb, LV_EVENT_CLICKED,(void*)(i+1)); //绑定播放事件,传入要播放第几个视频
    }
    /**********视频列表：end**********/

    /***********控制视频按键：begin**********/
    //创建窗口 存放控制按键
    lv_obj_t *ctrl_video_win = lv_obj_create(vd_bg); //创建到背景图片上
    lv_obj_set_pos(ctrl_video_win,0,350);//窗口位置
    lv_obj_set_size(ctrl_video_win, 600, 249); //窗口大小
    lv_obj_set_style_radius(ctrl_video_win, 0, LV_PART_MAIN);//直角边框
    lv_obj_set_style_border_opa(ctrl_video_win, LV_OPA_TRANSP, LV_PART_MAIN);//边框透明
    lv_obj_set_style_bg_color(ctrl_video_win,lv_color_hex(0xffffff),LV_PART_MAIN);//白色
    //创建按键加图片作为控制按键
    lv_obj_t* vd_ctrl_bt[4] ;//四个按键
    lv_obj_t* video_ctrl_btn_pt[4] ;//四个图片
    for(int i = 0;i < 4;i++)
    {
        vd_ctrl_bt[i] = lv_btn_create(ctrl_video_win);//窗口上创建按键
        video_ctrl_btn_pt[i] = lv_image_create(vd_ctrl_bt[i]);//按键上创建图片
        lv_obj_add_style(vd_ctrl_bt[i], &tm_style, LV_STATE_DEFAULT);//按键应用透明样式
        lv_obj_center(video_ctrl_btn_pt[i]);//居中图片
    }
    lv_obj_set_size(vd_ctrl_bt[0], 150, 140); //按键大小
    lv_obj_set_align(vd_ctrl_bt[0],LV_ALIGN_CENTER);//居中 播放按键
    lv_obj_set_size(vd_ctrl_bt[1], 150, 140); //按键大小
    lv_obj_set_align(vd_ctrl_bt[1],LV_ALIGN_RIGHT_MID);//右侧 停止按键
    lv_obj_set_size(vd_ctrl_bt[2], 100, 63); //按键大小
    lv_obj_set_align(vd_ctrl_bt[2],LV_ALIGN_TOP_LEFT);//左上 快进按键
    lv_obj_set_size(vd_ctrl_bt[3], 100, 63); //按键大小
    lv_obj_set_align(vd_ctrl_bt[3],LV_ALIGN_BOTTOM_LEFT);//左下 后退按键
    //显示按键图片
    lv_image_set_src(video_ctrl_btn_pt[0], "A:/XiaoHong/photo/start_stop.bmp");
    lv_image_set_src(video_ctrl_btn_pt[1], "A:/XiaoHong/photo/video_over.bmp");
    lv_image_set_src(video_ctrl_btn_pt[2], "A:/XiaoHong/photo/seek_up.bmp");
    lv_image_set_src(video_ctrl_btn_pt[3], "A:/XiaoHong/photo/seek_down.bmp");
    //注册各按键事件
    lv_obj_add_event_cb(vd_ctrl_bt[0], start_stop, LV_EVENT_CLICKED, NULL); //绑定播放事件
    lv_obj_add_event_cb(vd_ctrl_bt[1], video_over, LV_EVENT_CLICKED, NULL); //绑定暂停事件
    lv_obj_add_event_cb(vd_ctrl_bt[2], seek_up, LV_EVENT_CLICKED, NULL); //绑定快进事件
    lv_obj_add_event_cb(vd_ctrl_bt[3], seek_down, LV_EVENT_CLICKED, NULL); //绑定后退事件
    /***********控制视频按键：end**********/
}

//关闭小窗视频界面函数
static void close_win_event_cb()
{
    system("pkill -9 mplayer");//终止视频播放
    if(fd != -1) //如果管道文件已打开
    {
        close(fd);//关闭管道文件
        fd = -1;//置为-1
    }
    if(mask)//清除遮罩层
    {
        lv_obj_del(mask);
        mask = NULL;
    }
    lv_obj_clean(lv_scr_act());//清空屏幕
    menu();//回到主菜单
}

//选择哪一个视频播放函数
static void video_play_event_cb(lv_event_t *e)
{
    int flag_video_bt = (int)lv_event_get_user_data(e);//获取点击到的视频序号
    char video_pathname[256] ;//视频播放指令
    //显示选择界面，是否全屏
    bmp_dis("/XiaoHong/photo/really.bmp",0,0);
    //获取点击位置
    int really_flag = touch_really();
    if(really_flag == 0)//点击到了否
    {
        //拼接小窗播放指令 播放第flag_video_bt个视频
        sprintf(video_pathname,"mplayer -slave -quiet -input file=/home/test.fifo -vo fbdev2 -geometry 0:0 -zoom -x   600 -y 351 /XiaoHong/photo/video_%d.mp4 ",flag_video_bt);
        //创建遮罩层将视频列表锁定
        mask = lv_obj_create(lv_scr_act());
        lv_obj_set_pos(mask,600,0);//位置
        lv_obj_set_size(mask, 350, 600); //大小
        lv_obj_set_style_bg_opa(mask,LV_OPA_100,LV_PART_MAIN);
        lv_obj_add_flag(mask,LV_OBJ_FLAG_CLICKABLE);
        pid_t pid = fork() ; //创建一个子进程
        if(pid == -1)
        {
            perror("fork error");
            return  ;
        }
        if(pid > 0)//父进程
        {
            unlink(FIFO_NAME);//清楚旧管道
            //创建新管道
            if(mkfifo(FIFO_NAME, 0666) == -1) 
            {
                perror("mkfifo error");
                return;
            }
        }
        else if(pid == 0)//子进程
        {
            system(video_pathname);//执行播放指令
            exit(0);//退出
        }
    }
    //标志位为1时
    else if(really_flag == 1)
    {
        //拼接全屏播放指令，右边留一列作为退出按键
        sprintf(video_pathname,"mplayer -slave -quiet -input file=/home/test.fifo -vo fbdev2 -geometry 0:0 -zoom -x 950 -y 600 /XiaoHong/photo/video_%d.mp4 ",flag_video_bt);
        //获取当前活跃屏幕并创建全屏遮罩层
        mask = lv_obj_create(lv_scr_act());
        lv_obj_set_pos(mask,0,0);//位置
        lv_obj_set_size(mask, 1024, 600); //大小
        lv_obj_set_style_bg_opa(mask,LV_OPA_100,LV_PART_MAIN);
        lv_obj_add_flag(mask,LV_OBJ_FLAG_CLICKABLE);//在当前屏幕创建退出按钮
        //遮罩上创建关闭按键
        lv_obj_t *close_btn = lv_btn_create(lv_scr_act());
        lv_obj_set_size(close_btn,75,600);
        lv_obj_set_pos(close_btn,950,0);
        lv_obj_set_style_radius(close_btn, 0, LV_PART_MAIN);//直角边框
        lv_obj_set_style_bg_color(close_btn,lv_color_hex(0xffffff),LV_PART_MAIN);
        //按键上创建文本
        lv_obj_t* title = lv_label_create(close_btn);
        lv_label_set_text(title, "touch\nthis\nclose\nvideo\n");
        lv_obj_set_style_text_color(title,lv_color_hex(0x000000),LV_PART_MAIN);
        lv_obj_center(title);
        lv_obj_add_event_cb(close_btn, close_really_event_cb, LV_EVENT_CLICKED, NULL); // 绑定关闭全屏事件
        pid_t pid = fork() ; //创建一个子进程
        if(pid == -1)
        {
            perror("fork error");
            return ;
        }
        if(pid > 0)//父进程
        {
            //清楚旧管道
            unlink(FIFO_NAME);
            //创建新管道
            if(mkfifo(FIFO_NAME, 0666) == -1) 
            {
                perror("mkfifo error");
                return;
            }
        }
        else if(pid == 0)//子进程
        {
            system(video_pathname);//执行拼接好的指令
            exit(0);
        }
    }
}

//检测是否全屏，\
返回1表示点击是，2否
int touch_really()
{
    while(1)
    {
        // 调用hua_xy函数，接收触摸屏幕的类型
        Point p = hua_xy();
        //不为上下左右滑,说明是点击或者无操作
        if(p.x != 1 && p.x != 2 && p.x != 3 && p.x != 4 )
        { 
            if(p.x > 60 && p.x < 200 && p.y > 225 && p.y <295)
                return 1;//返回1
            else if(p.x > 400 && p.x < 540 && p.y > 225 && p.y <295)
                return 0;//返回2
            else //点击了其他位置就继续循环检测触摸屏
                continue;
        }
    }
}

//关闭全屏回调
void close_really_event_cb()
{
    //停止视频播放
    system("pkill -9 mplayer");
    //关闭管道
    if(fd != -1) 
    {
        close(fd);
        fd = -1;
    }
    if(mask)
    {
        lv_obj_del(mask);//删除遮罩
        mask = NULL;
    }
    //重新初始化界面
    lvgl_mp4();
}

//驾驶时播放视频 警告弹窗函数
void warning_if()
{
    //创建q全屏遮罩层
    mask = lv_obj_create(lv_scr_act());
    lv_obj_set_size(mask, 1024, 600);
    lv_obj_set_pos(mask,0,0);
    lv_obj_set_style_bg_opa(mask,LV_OPA_30,LV_PART_MAIN);
    lv_obj_add_flag(mask,LV_OBJ_FLAG_CLICKABLE);//隔绝遮罩层下方
    //创建弹窗
    lv_obj_t* win_warning = lv_obj_create(mask);
    lv_obj_set_scroll_dir(win_warning, LV_DIR_NONE);//禁止滑动
    lv_obj_set_size(win_warning, 300, 300);  // 窗口大小
    lv_obj_center(win_warning);              // 居中显示
    lv_obj_set_style_radius(win_warning, 0, LV_PART_MAIN);//直角边框
    lv_obj_set_style_border_opa(win_warning, LV_OPA_0,LV_PART_MAIN);//边框
    lv_obj_set_style_bg_color(win_warning, lv_color_hex(0xa6c0bd), LV_PART_MAIN);
    //创建图片，询问是否打开视频
    lv_obj_t* video_warning = lv_image_create(win_warning);
    lv_image_set_src(video_warning,"A:/XiaoHong/photo/video_warning.bmp");
    lv_obj_align(video_warning,LV_ALIGN_TOP_MID,0,0);
    //创建两个按键
    lv_obj_t* yes = lv_btn_create(win_warning);
    lv_obj_t* no = lv_btn_create(win_warning);
    lv_obj_set_size(yes,100,50);
    lv_obj_align(yes,LV_ALIGN_BOTTOM_LEFT,0,0);
    lv_obj_set_style_bg_color(yes,lv_color_hex(0xff0000),LV_PART_MAIN);
    lv_obj_set_size(no,100,50);
    lv_obj_align(no,LV_ALIGN_BOTTOM_RIGHT,0,0);
    lv_obj_set_style_bg_color(no,lv_color_hex(0x00ff00),LV_PART_MAIN);
    lv_obj_t* yes_title = lv_label_create(yes);
    lv_obj_t* no_title = lv_label_create(no);
    lv_label_set_text(yes_title, "Yes!");
    lv_label_set_text(no_title, "No!");
    lv_obj_set_style_text_color(yes_title,lv_color_hex(0xffffff),LV_PART_MAIN);
    lv_obj_set_style_text_font(yes_title, &lv_font_montserrat_20,LV_PART_MAIN);
    lv_obj_set_style_text_color(no_title,lv_color_hex(0xffffff),LV_PART_MAIN);
    lv_obj_set_style_text_font(no_title, &lv_font_montserrat_20,LV_PART_MAIN);
    lv_obj_add_event_cb(yes, clean_warning_start, LV_EVENT_CLICKED,mask);//传入遮罩层
    lv_obj_add_event_cb(no, clean_warning, LV_EVENT_CLICKED,mask);//传入遮罩层
}

//清除遮罩和警告窗口
void clean_warning(lv_event_t* e)
{
    if(mask)
    {
        lv_obj_del(mask);//销毁遮罩
        mask = NULL;
    }
}

//清除遮罩和警告窗口并播放
static void clean_warning_start(lv_event_t* e)
{
    clean_warning(e);//清楚原有窗口和遮罩
    video(NULL);//调用视频
}

//播放暂停函数
void start_stop()
{
    //打开文件写入指令
    fd = open(FIFO_NAME,O_RDWR);   
    write(fd,"pause\n",strlen("pause\n"));
}

//停止函数
void video_over()
{
    
    //执行指令  
    system("pkill -9 mplayer");
    //清除遮罩层
    if(mask)
    {
        lv_obj_del(mask);
        mask = NULL;
    }
    //重新绘制
    lvgl_mp4();
}

//快进函数
void seek_up()
{
    //打开文件写入指令
    fd = open(FIFO_NAME,O_RDWR);   
    write(fd,"seek +5\n",strlen("seek +5\n"));
}

//后退函数
void seek_down()
{
    //打开文件写入指令
    fd = open(FIFO_NAME,O_RDWR);   
    write(fd,"seek -5\n",strlen("seek -5\n"));
}
