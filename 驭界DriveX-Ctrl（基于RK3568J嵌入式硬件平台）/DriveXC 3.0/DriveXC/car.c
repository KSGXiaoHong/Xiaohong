#include "car.h"

//遮罩层
static lv_obj_t* mask = NULL;

//座椅调节函数
void zy_ctrl(lv_event_t *e)
{
    //保存按下的第几个座位
    int flag_zy_bt = (int)lv_event_get_user_data(e);

    /**********创建遮罩层和窗口：begin**********/
    //当前屏幕创建遮罩层，所有元素创建在这个遮罩层上
    lv_obj_t* p = lv_scr_act();
    mask = lv_obj_create(p);
    lv_obj_set_pos(mask,0,0);//位置
    lv_obj_set_size(mask, 1024, 600); //大小
    lv_obj_set_style_bg_opa(mask,LV_OPA_50,LV_PART_MAIN);//半透明
    lv_obj_add_flag(mask,LV_OBJ_FLAG_CLICKABLE);//隔绝层下对象
    //创建一个窗口
    lv_obj_t* win =  lv_obj_create(mask);
    lv_obj_set_size(win,724,400);
    lv_obj_center(win);
    lv_obj_set_style_bg_color(win, lv_color_hex(0xFFFFFF),LV_PART_MAIN); //白色背景
    /**********获取当前活跃屏幕并创建遮罩层和窗口：end**********/

    /**********调节座位窗口：begin**********/
    //添加图片标题说明显示当前操作的座椅
    lv_obj_t* title_zy = lv_image_create(win);
    lv_obj_set_align(title_zy, LV_ALIGN_TOP_MID);  //标题位置
    lv_obj_t* zy_pt = lv_image_create(win);//创建座椅图片
    lv_obj_set_align(zy_pt,LV_ALIGN_BOTTOM_RIGHT);//右下
    lv_image_set_src(zy_pt,"A:/XiaoHong/photo/zy_pt.bmp");//显示图片
    //添加返回按键在右上角
    lv_obj_t* back_button = lv_button_create(win);
    lv_obj_set_size(back_button,50,50);
    lv_obj_set_align(back_button,LV_ALIGN_TOP_RIGHT);
    lv_obj_set_style_text_color(back_button,lv_color_hex(0xff0000),LV_PART_MAIN);
    //给关闭按键显示个X
    lv_obj_t* back_txt = lv_label_create(back_button);
    lv_label_set_text(back_txt, "X"); // 显示“X”符号
    lv_obj_set_style_text_color(back_txt,lv_color_hex(0xffffff),LV_PART_MAIN);
    lv_obj_center(back_txt);//居中
    lv_obj_add_event_cb(back_button, back_button_cb, LV_EVENT_CLICKED, mask);//点击按钮关闭，遮罩层对象传入
    //看是那个座位被选中,显示对应标题
    switch(flag_zy_bt)
    {
        case 1:
            lv_image_set_src(title_zy, "A:/XiaoHong/photo/zy_4_text.bmp");break;
        case 2:
            lv_image_set_src(title_zy, "A:/XiaoHong/photo/zy_3_text.bmp");break;
        case 3:
            lv_image_set_src(title_zy, "A:/XiaoHong/photo/zy_2_text.bmp");break;
        case 4:
            lv_image_set_src(title_zy, "A:/XiaoHong/photo/zy_1_text.bmp");break;
    }
    /**********调节座位窗口：end**********/

    /**********调节座椅按键图标：begin**********/
    //创建5个按键,前，后，仰，卧，加热
    lv_obj_t* zy_button[5];
    lv_obj_t* zy_btn_pt;//按键创建图片
    char zy_pathname[256];//按键图标路径
    for(int i = 0;i < 5;i++)
    {
        sprintf(zy_pathname,"A:/XiaoHong/photo/zy_%d.bmp",i+1);
        zy_button[i] = lv_button_create(win);//创建按键
        lv_obj_set_style_bg_color(zy_button[i], lv_color_hex(0xb9b8b8),LV_PART_MAIN); // 灰色
        lv_obj_set_size(zy_button[i],50,50);
        zy_btn_pt = lv_image_create(zy_button[i]);//创建图片
        lv_obj_center(zy_btn_pt);
        lv_image_set_src(zy_btn_pt, zy_pathname);//显示图片
    }
    //五个按键位置不同
    lv_obj_set_pos(zy_button[0],110,85);
    lv_obj_set_pos(zy_button[1],170,85);
    lv_obj_set_pos(zy_button[2],110,145);
    lv_obj_set_pos(zy_button[3],110,210);
    lv_obj_set_pos(zy_button[4],170,210);
    /**********调节座椅按键图标：end**********/

    //每个按键添加对应功能，并传入是第几个座位触发的按键
    // lv_obj_add_event_cb(zy_button[0], wait, LV_EVENT_CLICKED, (void*)flag_zy_bt);
    // lv_obj_add_event_cb(zy_button[1], wait, LV_EVENT_CLICKED, (void*)flag_zy_bt);
    // lv_obj_add_event_cb(zy_button[2], wait, LV_EVENT_CLICKED, (void*)flag_zy_bt);
    // lv_obj_add_event_cb(zy_button[3], wait, LV_EVENT_CLICKED, (void*)flag_zy_bt);
    // lv_obj_add_event_cb(zy_button[4], wait, LV_EVENT_CLICKED, (void*)flag_zy_bt);
}

//调节座椅界面关闭调节函数
void back_button_cb(lv_event_t *e)
{
    //获取传递的遮罩层并清除
    lv_obj_t* mask = lv_event_get_user_data(e);
    if(mask)
        lv_obj_del(mask); //销毁窗口
}

//灯光实现函数
void lgt()
{
    //用来控制点亮灯的状态
    static int lgt_flag = 0;
    lv_obj_t* lgt_pt = NULL;//定义灯光图片对象
    if(lgt_pt!=NULL)//对象不为空，已经创建了，需要先删除
    {
        lv_obj_del(lgt_pt);//删除当前的灯光对象
        lgt_pt = NULL;//置空
    }
    lgt_pt = lv_image_create(lv_scr_act());//在当前屏幕创建灯光图片
    lv_obj_set_pos(lgt_pt,512,0);//位置
    switch(lgt_flag)//选择灯光状态
    {
        case 0://默认先打开示廓灯
        {
            lv_image_set_src(lgt_pt, "A:/XiaoHong/photo/dis_no.bmp");
            break;
        }
        case 1://近光
        {
            lv_image_set_src(lgt_pt, "A:/XiaoHong/photo/dis_1.bmp");
            break;
        }
        case 2://远光
        {
            lv_image_set_src(lgt_pt, "A:/XiaoHong/photo/dis_2.bmp");
            lgt_flag = -1;//重置灯光状态
            break;
        }
    }
    lgt_flag++;//进入下一个状态 
}

//双闪实现函数
void dblgt()
{
    /**********只创建一次进程共享内存：begin**********/
    static int pid = -1;//pid赋初值
    static int dblt_shm_id = -1;//共享内存赋初值
    static int* dblt_fg = NULL;//共享内存映射地址
    if(dblt_shm_id == -1)//说明共享内存未创建，
    {
        key_t dblt_key = ftok("/XiaoHong/PIN",1);//创建钥匙
        if(dblt_key == -1)//创建失败
        {
            perror("key");
            return ;
        }
        dblt_shm_id = shmget(dblt_key,4096,IPC_CREAT | 0664);//创建共享内存
        if(dblt_shm_id == -1)//创建失败
        {
            perror("shmid");
            return ;
        }
        //映射共享内存到程序地址空间
        dblt_fg = shmat(dblt_shm_id,NULL,0);//共享地址空间存放双闪标志位
        if(dblt_fg == NULL)//映射失败
        {
            perror("shmat");
            return ;
        }
    }
    /**********只创建一次进程共享内存：end**********/

    /**********双闪实现逻辑：begin***********/
    if(pid == -1)//第一次进来时
        *dblt_fg = 1;//双闪置位
    else//不是第一次进来，说明已经创建了子进程
    {
        *dblt_fg = 0;//关闭双闪标志位，子进程死循环结束
        wait(NULL);//等子进程
        pid = -1;//重置标志位
    }
    if(*dblt_fg == 1)//判断双闪标志打开
    {
        //创建子进程，父进程结束，让子进程成为僵尸进程
        pid = fork();
        if(pid == 0)//子进程
        {
            //子进程通过共享的标志位来决定是否退出循环
            while(*dblt_fg) //阻塞在这实现双闪
            {
                //显示双闪
                bmp_dis("/XiaoHong/photo/left_blin.bmp", 462, 0);
                bmp_dis("/XiaoHong/photo/right_blin.bmp", 562, 0);
                usleep(500000); // 0.5秒亮
                //关闭双闪
                bmp_dis("/XiaoHong/photo/dblgt_no.bmp", 462, 0);
                bmp_dis("/XiaoHong/photo/dblgt_no.bmp", 562, 0);
                usleep(500000); // 0.5秒灭
            }
            exit(0); // 退出子进程
        }
    }
    /**********双闪实现逻辑：end***********/
}

//图片弹窗函数 提示点击按键后的状态 传入图片路径 显示时长ms 坐标
void popup_image_time(const char* img_path,uint32_t delay_ms,int x,int y)
{
    lv_obj_t* ctrl_img = lv_image_create(lv_scr_act());//创建一个图片控件
    lv_image_set_src(ctrl_img, img_path); //设置图片路径
    lv_obj_set_pos(ctrl_img, x, y); //坐标
    //给图片创建定时器，指定时间后执行popup_timer_cb函数,ctrl_img作为参数存储到定时器结构体的user_data中
    lv_timer_t* timer = lv_timer_create(delimg_timer_cb, delay_ms, ctrl_img);
    lv_timer_set_repeat_count(timer, 1); // 只执行一次
}

//定时器回调函数 删除弹出的图片
static void delimg_timer_cb(lv_timer_t* timer) 
{
    //获取定时器结构体指针的传进来的参数
    lv_obj_t* ctrl_img = timer->user_data;
    //判断指针不为空并且对象有效
    if (ctrl_img && lv_obj_is_valid(ctrl_img))
        lv_obj_del(ctrl_img); //删除图片
    lv_timer_del(timer);//删除定时器
}

//前挡风除雾
void win_front()
{
    static int fg = 1;//第一次进入为1，打开
    if(fg)
        popup_image_time("A:/XiaoHong/photo/bt_1_on.bmp",1000,289,257);
    else 
        popup_image_time("A:/XiaoHong/photo/bt_1_off.bmp",1000,289,257);
    fg = !fg;//取反
}

//后挡风除雾
void win_rear()
{
    static int fg = 1;//第一次进入为1，打开
    if(fg)
        popup_image_time("A:/XiaoHong/photo/bt_2_on.bmp",1000,87,251);
    else
        popup_image_time("A:/XiaoHong/photo/bt_2_off.bmp",1000,87,251);
    fg = !fg;
}

//座椅加热
void pigu_hot()
{
    static int fg = 1;//第一次进入为1，打开
    if(fg)
        popup_image_time("A:/XiaoHong/photo/bt_3_on.bmp",1000,731,179);
    else
        popup_image_time("A:/XiaoHong/photo/bt_3_off.bmp",1000,731,179);
    fg = !fg;
}

//打开后备箱
void car_bag()
{
    static int fg = 1;//第一次进入为1，打开
    if(fg)
        popup_image_time("A:/XiaoHong/photo/bt_4_on.bmp",1000,87,251);
    else
        popup_image_time("A:/XiaoHong/photo/bt_4_off.bmp",1000,87,251);
    fg = !fg;
}

//定义一个标签对象，用来显示测量的温度
lv_obj_t* wd_test = NULL;
//定义一个窗口，用来显示文字提示
lv_obj_t* win_text = NULL;
//定义一个窗口用来显示设定的温度
lv_obj_t* kt_win = NULL;
//温度定时器，用来定时显示测量到的温度值
static lv_timer_t* wd_timer = NULL;
//文本定时器，用来定时显示窗口的提示文本
static lv_timer_t* text_timer = NULL;
//显示设定温度等级对象
static lv_obj_t* wd_dj = NULL;
//温度设定标签创建标志位
static int wd_dj_flag = 1;
static int fs_i = 1;//风速默认一档
static int wd_i = 20;//温度默认20
static int auto_flag = 0;//保存自动按键的状态，1为开启，0为关闭
static int tf_flag = 0;//保存通风按键的状态，1为开启，0为关闭
static int nxh_flag = 0;//保存内循环按键的状态，1为开启，0为关闭
//空调功能
void kongtiao()
{
    lv_obj_t* p = lv_scr_act();//获取当前屏幕

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
    
    /**********背景图片：begin**********/
    lv_obj_t* kt = lv_image_create(p);//在遮罩上创建一个图片屏幕
    lv_obj_center(kt);//居中
    lv_image_set_src(kt,"A:/XiaoHong/photo/ktbg.bmp");//显示背景
    lv_obj_add_flag(kt,LV_OBJ_FLAG_CLICKABLE);//隔绝背景下的控件
    /**********背景图片：end**********/
    
    /**********创建返回按键：begin**********/
    lv_obj_t* kt_back_bt = lv_button_create(p);//创建返回按键
    lv_obj_set_pos(kt_back_bt,0,135);//位置
    lv_obj_set_size(kt_back_bt,92,232);//大小
    lv_obj_add_style(kt_back_bt,&tm_style,LV_STATE_DEFAULT);//应用透明样式
    //注册事件，触发空调回调函数回调并传入BACK
    lv_obj_add_event_cb(kt_back_bt,kt_cb,LV_EVENT_CLICKED,(void*)BACK);
    /**********创建返回按键：end**********/

    /**********文本窗口：begin**********/
    win_text = lv_obj_create(p);//创建文本显示窗口
    lv_obj_set_scroll_dir(win_text, LV_DIR_NONE);//禁止窗口滑动
    lv_obj_set_pos(win_text,507,21);//窗口位置
    lv_obj_set_size(win_text,447,70);//设置窗口大小
    lv_obj_add_style(win_text,&tm_style,LV_STATE_DEFAULT);//应用透明样式
    /**********文本窗口：end**********/

    /**********设定温度窗口：begin**********/
    kt_win = lv_obj_create(p);//在屏幕创建空调温度显示窗口
    lv_obj_set_scroll_dir(kt_win, LV_DIR_NONE);//禁止窗口滑动
    lv_obj_set_pos(kt_win,144,141);//设置窗口坐标
    lv_obj_set_size(kt_win,261,181);//设置窗口长宽
    lv_obj_set_style_bg_color(kt_win,lv_color_hex(0xb2eaf7),LV_PART_MAIN);//设置窗口颜色
    lv_obj_set_style_border_color(kt_win, lv_color_hex(0x485c70),LV_PART_MAIN);//边框颜色
    lv_obj_set_style_border_width(kt_win, 10,LV_PART_MAIN);//边框粗细
    /**********设定温度窗口：end**********/

    /**********当前温度显示：begin**********/
    wd_test = lv_label_create(p);//窗口上创建温度文本标签，默认20度
    lv_obj_set_pos(wd_test,271,40);//设置温度显示的位置
    lv_obj_set_style_text_font(wd_test, &lv_font_montserrat_48, LV_PART_MAIN);//文本大小
    lv_obj_set_style_text_color(wd_test, lv_color_hex(0xf87328), LV_PART_MAIN);//颜色
    lv_label_set_text(wd_test,"-- °C");//默认显示
    wd_timer = lv_timer_create(wd_timer_cb, 1000, NULL);//创建定时器，1秒刷新一次数据
    /**********当前温度显示：end**********/
    
    /**********风速设定：begin**********/
    //显示风速，传入NO，代表无操作，直接显示当前风速
    dis_fs(NO);
    lv_obj_t* fs_up = lv_btn_create(p);//风速加按键
    lv_obj_t* fs_down = lv_btn_create(p);//风速减按键
    lv_obj_set_pos(fs_up,831,114);//位置
    lv_obj_set_size(fs_up,142,100);//大小
    lv_obj_set_pos(fs_down,831,272);//位置
    lv_obj_set_size(fs_down,142,100);//大小
    lv_obj_add_style(fs_up,&tm_style,LV_STATE_DEFAULT);//应用透明样式
    lv_obj_add_style(fs_down,&tm_style,LV_STATE_DEFAULT);//应用透明样式
    lv_obj_add_event_cb(fs_up,kt_cb,LV_EVENT_CLICKED,(void*)FS_UP);//绑定回调函数并传入风速加
    lv_obj_add_event_cb(fs_down,kt_cb,LV_EVENT_CLICKED,(void*)FS_DOWN);//绑定回调函数并传入风速加
    /**********风速设定：end**********/

    /**********温度设定：begin**********/
    //显示温度,NO，代表无操作，直接显示当前风速
    dis_wd(NO);
    lv_obj_t* wd_up = lv_btn_create(p);//温度加按键
    lv_obj_t* wd_down = lv_btn_create(p);//温度减按键
    lv_obj_set_pos(wd_up,488,114);//位置
    lv_obj_set_size(wd_up,142,100);//大小
    lv_obj_set_pos(wd_down,488,272);//位置
    lv_obj_set_size(wd_down,142,100);//大小
    lv_obj_add_style(wd_up,&tm_style,LV_STATE_DEFAULT);//应用透明样式
    lv_obj_add_style(wd_down,&tm_style,LV_STATE_DEFAULT);//应用透明样式
    lv_obj_add_event_cb(wd_up,kt_cb,LV_EVENT_CLICKED,(void*)WD_UP);//绑定回调函数并传入温度加
    lv_obj_add_event_cb(wd_down,kt_cb,LV_EVENT_CLICKED,(void*)WD_DOWN);//绑定回调函数并传入温度加
    /**********温度设定：end**********/

    /**********功能按键：begin**********/
    //创建5个功能按键
    lv_obj_t* kt_ctrl_bt[5];
    //AUTO、A/C、加热、通风、内循环
    for(int i = 0;i < 5;i++)
    {
        kt_ctrl_bt[i] = lv_btn_create(p);
        //全部应用透明样式
        lv_obj_add_style(kt_ctrl_bt[i],&tm_style,LV_STATE_DEFAULT);
        if(i != 0)//除了AUTO按键其他按键大小相同,位置相隔100
        {
            lv_obj_set_size(kt_ctrl_bt[i],68,107);
            lv_obj_set_pos(kt_ctrl_bt[i],531+( (i-1)*100 ),428);
        }
    }
    lv_obj_set_pos(kt_ctrl_bt[0],653,207);//AUTO按键 单独设置
    lv_obj_set_size(kt_ctrl_bt[0],165,74);
    //绑定事件
    lv_obj_add_event_cb(kt_ctrl_bt[0],kt_cb,LV_EVENT_CLICKED,(void*)AUTO);//绑定回调函数并传入AUTO按键
    lv_obj_add_event_cb(kt_ctrl_bt[1],kt_cb,LV_EVENT_CLICKED,(void*)AC);//传入AC按键
    lv_obj_add_event_cb(kt_ctrl_bt[2],kt_cb,LV_EVENT_CLICKED,(void*)HOT);//传入加热按键
    lv_obj_add_event_cb(kt_ctrl_bt[3],kt_cb,LV_EVENT_CLICKED,(void*)TF);//传入通风按键
    lv_obj_add_event_cb(kt_ctrl_bt[4],kt_cb,LV_EVENT_CLICKED,(void*)NXH);//传入内循环按键
    /**********功能按键：end**********/
    
}

//空调按键回调函数
void kt_cb(lv_event_t* e)
{
    int kt_flag = 0;//用来存放传入的值
    //获取参数的值
    if(e != NULL)
        kt_flag = (int)lv_event_get_user_data(e);
    //判断触发回调的是哪个按键
    switch(kt_flag)
    {
        //点击了返回按键
        case BACK:
        {
            //清除屏幕当前所有元素
            lv_obj_clean(lv_scr_act());
            if(wd_timer) //判断温度测试定时器是否存在
            {
                lv_timer_del(wd_timer);//删除温度显示定时器
                wd_timer = NULL;//定时器置为空
            }
            wd_dj_flag = 1;//将温度设定标志位重新置1，再次创建
            wd_test = NULL;//当前温度的标签置为空
            win_text = NULL;//显示文字提示的窗口置为空
            kt_win = NULL;//显示设定温度的窗口置为空
            //回到主界面
            def();
            break;
        }
        //点击了风速+
        case FS_UP:
        {
            //调用风速回调函数，并传入风速加，
            dis_fs(FS_UP);
            break;
        }
        //点击了风速-
        case FS_DOWN:
        {
            //调用风速回调函数，并传入风速加，
            dis_fs(FS_DOWN);
            break;
        }
        //点击了温度+
        case WD_UP:
        {
            //调用风速回调函数，并传入风速加，
            dis_wd(WD_UP);
            break;
        }
        //点击了温度-
        case WD_DOWN:
        {
            //调用风速回调函数，并传入风速加，
            dis_wd(WD_DOWN);
            break;
        }
        //点击了AUTO
        case AUTO:
        {
            auto_flag = !auto_flag;//切换按键状态
            if(auto_flag)
            {
                wd_i = 23;//设置温度为23
                fs_i = 2;//设置风速为2
                dis_kt_text("A:/XiaoHong/photo/auto.bmp");//文本框显自动已开启
                dis_fs(NO);//显示风速
                dis_wd(NO);//显示温度
            }
            else
                dis_kt_text("A:/XiaoHong/photo/noauto.bmp");//文本框显示自动已关闭
            break;
        }
        //点击了A/C
        case AC:
        {
            wd_i = 16;//设置温度为16
            fs_i = 5;//设置风速为5
            dis_kt_text("A:/XiaoHong/photo/ac.bmp");//文本框显示制冷
            dis_fs(NO);//显示风速
            dis_wd(NO);//显示温度
            break;
        }
        //点击了加热
        case HOT:
        {
            wd_i = 30;//设置温度为30
            fs_i = 5;//设置风速为5
            dis_kt_text("A:/XiaoHong/photo/hot.bmp");//文本框显示制热
            dis_fs(NO);//显示风速
            dis_wd(NO);//显示温度
            break;
        }
        //点击了通风
        case TF:
        {
            //先判断空调是否关闭
            if(fs_i == 0)
            {
                if(wd_dj && lv_obj_is_valid(wd_dj))
                    lv_label_set_text_fmt(wd_dj, " -- °C");//温度显示--
                return ;
            }
            tf_flag = !tf_flag;//切换按键状态
            if(tf_flag)
            {
                wd_i = 20;//设置温度为23
                fs_i = 3;//设置风速为2
                dis_kt_text("A:/XiaoHong/photo/tf.bmp");//文本框显自动已开启
                dis_fs(NO);//显示风速
                dis_wd(NO);//显示温度
            }
            else
                dis_kt_text("A:/XiaoHong/photo/notf.bmp");//文本框显示自动已关闭
            break;
        }
        //点击了内循环
        case NXH:
        {
            //先判断空调是否关闭
            if(fs_i == 0)
            {
                if(wd_dj && lv_obj_is_valid(wd_dj))
                    lv_label_set_text_fmt(wd_dj, " -- °C");//温度显示--
                return ;
            }
            nxh_flag = !nxh_flag;//切换按键状态
            if(nxh_flag)
            {
                dis_kt_text("A:/XiaoHong/photo/nxh.bmp");//文本框显自动已开启
                dis_fs(NO);//显示风速
                dis_wd(NO);//显示温度
            }
            else
                dis_kt_text("A:/XiaoHong/photo/nonxh.bmp");//文本框显示自动已关闭
            break;
        }
    }
}

//定时器回调函数 定时刷新温度数据
static void wd_timer_cb(lv_timer_t *timer)
{
    //更新从模块数据结构体中的温度值
    pthread_mutex_lock( &(mk_data.mutex) );//拿锁
    int temp = mk_data.T;//更新温度 
    pthread_mutex_unlock( &(mk_data.mutex) );//释放
    //判断是否测到数据
    if(temp == -1 )
        return;
    if(wd_test && lv_obj_is_valid(wd_test))
        lv_label_set_text_fmt(wd_test, " %d °C", temp);//更新温度到标签
}

//显示设定温度函数，传入按下的按键和窗口对象
static void dis_wd(int wd_flag)
{
    //先判断空调是否关闭
    if(fs_i == 0)
    {
        if(wd_dj && lv_obj_is_valid(wd_dj))
            lv_label_set_text_fmt(wd_dj, " -- °C");//温度显示--
        return ;
    }
    if(fs_i == 0)//如果空调是关闭状态
    {
        if(wd_dj && lv_obj_is_valid(wd_dj))
            lv_label_set_text_fmt(wd_dj, " -- °C");//温度显示--
        return ;//退出
    }
    if(wd_flag == WD_UP)//点击的是温度加
    {
        if(wd_i == 30)//判断温度到最大值
        {
            dis_kt_text("A:/XiaoHong/photo/wd_max.bmp");//文本框显示 温度达最大
            return ;
        }
        else//否则温度加
        {
            wd_i++;
            dis_kt_text("A:/XiaoHong/photo/wd_up.bmp");//文本框显示 温度增加
        }
    }
    else if(wd_flag == WD_DOWN)//点击了温度减按键
    {
        if(wd_i == 16)//判断温度到最小值
        {
            dis_kt_text("A:/XiaoHong/photo/wd_min.bmp");//文本框显示 温度已达最低
            return ;
        }
        else//否则温度减
        {
            wd_i--;
            dis_kt_text("A:/XiaoHong/photo/wd_down.bmp");//文本框显示 温度减少
        }
    }
    //判断温度等级标签创建标志位
    if(wd_dj_flag)
    {
        if(kt_win)//设定温度窗口存在
            wd_dj = lv_label_create(kt_win);//窗口上创建设定温度标签
        else
            return ;
        wd_dj_flag = 0;//标志位置0
        lv_obj_center(wd_dj);
        lv_obj_set_style_text_font(wd_dj, &lv_font_montserrat_48, LV_PART_MAIN);//文本大小
        lv_obj_set_style_text_color(wd_dj, lv_color_hex(0xf87328), LV_PART_MAIN);//颜色
    }
    //选择温度等级的图片
    lv_label_set_text_fmt(wd_dj, " %d °C", wd_i);//更新温度
}

//显示风速函数，传入点击的加还是减 
static void dis_fs(int fs_flag)
{
    if(fs_flag == FS_UP)//点击的是风速加
    {
        if(fs_i == 0)//判断空调关闭
        {
            fs_i++;//将风速等级增加
            dis_wd(NO);//并显示温度
        }
        else if(fs_i == 5)//判断风速到最大值
        {
            dis_kt_text("A:/XiaoHong/photo/fs_max.bmp");//文本框显示 风速达最大
            return ;
        }
        else//否则风速加
        {
            fs_i++;
            dis_kt_text("A:/XiaoHong/photo/fs_up.bmp");//文本框显示 风速增加
        }
    }
    else if(fs_flag == FS_DOWN)//点击了风速减按键
    {
        if(fs_i == 0)//判断空调关闭
            return ;//退出
        else//否则风速减
        {
            fs_i--;
            dis_kt_text("A:/XiaoHong/photo/fs_down.bmp");//文本框显示 风速减少
        }
    }
    //创建图片控减，显示风速等级
    lv_obj_t* fs_dj = lv_image_create(lv_scr_act());
    lv_obj_set_pos(fs_dj,149,478);//位置
    //选择风速等级的图片
    switch(fs_i)
    {
        case 0://空调关闭
            lv_image_set_src(fs_dj,"A:/XiaoHong/photo/fs_0.bmp");//显示风速0
            dis_kt_text("A:/XiaoHong/photo/fs_min.bmp");//文本框显示 空调已关闭
            wd_i = 20;//重置温度
            //重置功能按键标志位
            auto_flag = 0;
            tf_flag = 0;
            nxh_flag = 0;
            dis_wd(NO);//显示温度
            break;
        case 1:
            lv_image_set_src(fs_dj,"A:/XiaoHong/photo/fs_1.bmp");
            break;
        case 2:
            lv_image_set_src(fs_dj,"A:/XiaoHong/photo/fs_2.bmp");
            break;
        case 3:
            lv_image_set_src(fs_dj,"A:/XiaoHong/photo/fs_3.bmp");
            break;
        case 4:
            lv_image_set_src(fs_dj,"A:/XiaoHong/photo/fs_4.bmp");
            break;
        case 5:
            lv_image_set_src(fs_dj,"A:/XiaoHong/photo/fs_5.bmp");
            break;
    }
}

//图片文本显示函数,传入图片路径
void dis_kt_text(char* text_path)
{
    //在文本显示窗口上创建一个图片 显示提示信息
    lv_obj_t* text_kt = lv_image_create(win_text);
    lv_obj_center(text_kt);//居中
    lv_image_set_src(text_kt,text_path);//显示路径指定的图片文字
    text_timer = lv_timer_create(text_timer_cb, 1000, text_kt);//创建定时器 显示一秒 传入图片对象
    lv_timer_set_repeat_count(text_timer, 1); // 只执行一次
}

//文本显示定时器回调
static void text_timer_cb(lv_timer_t* timer)
{
    //获取定时器结构体指针的传进来的参数
    lv_obj_t* kt_text = timer->user_data;
    //判断指针不为空并且对象有效
    if (kt_text && lv_obj_is_valid(kt_text))
        lv_obj_del(kt_text); //删除图片
    lv_timer_del(timer);//删除定时器
}
