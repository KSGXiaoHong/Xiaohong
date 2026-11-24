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
static void popup_image_time(const char* img_path,uint32_t delay_ms,int x,int y)
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
