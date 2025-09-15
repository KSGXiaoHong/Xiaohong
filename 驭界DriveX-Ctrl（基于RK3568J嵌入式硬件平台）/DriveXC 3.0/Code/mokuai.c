#include "mokuai.h"

//初始化定时器变量 关闭时释放资源
static lv_timer_t *timer = NULL;
//定义参数值标签(温 湿 压 海 距)5个
lv_obj_t* mokuai_lable[5];

//初始化US100
static int Uart_US100_Init(const char* filename , int baudrate)
{
    //1.打开串口 : 读写打开
    int fd = open(filename , O_RDWR);
    if(fd == -1)
    {
        printf("open uart error\n");
        return -1 ;
    }

    //2.配置串口结构体信息
    struct termios myserial ; //保存串口配置信息
    //2.1清空结构体:将所有的都初始化为0
    memset(&myserial, 0 , sizeof(myserial));
    myserial.c_cflag |= (CLOCAL | CREAD);
    //2.2设置控制模式状态，本地连接，接受使能
	//设置 数据位
	myserial.c_cflag &= ~CSIZE;   //清空数据位
	myserial.c_cflag &= ~CRTSCTS; //无硬件流控制
	myserial.c_cflag |= CS8;      //数据位:8

	myserial.c_cflag &= ~CSTOPB;//   //1位停止位
	myserial.c_cflag &= ~PARENB;  //不要校验

    //2.3设置波特率：
    switch(baudrate)
    {
        case 9600:
            cfsetospeed(&myserial, B9600);  //设置波特率,B9600是定义的宏
	        cfsetispeed(&myserial, B9600);
            break ;
        case 115200 :
            cfsetospeed(&myserial, B115200);  //设置波特率,B115200是定义的宏
            cfsetispeed(&myserial, B115200);
            break ;
        case 38400:
            cfsetospeed(&myserial, B38400);  //设置波特率,B38400是定义的宏
	        cfsetispeed(&myserial, B38400);
            break ;
    }

    /* 刷新输出队列,清除正接受的数据 */
	tcflush(fd, TCIFLUSH);
	/* 改变配置 */
	tcsetattr(fd, TCSANOW, &myserial);
	return fd;
}

//初始化GY39
static int Uart_GY39_Init(const char* filename , int baudrate)
{
    //1.打开串口 : 读写打开
    int fd = open(filename , O_RDWR);
    if(fd == -1)
    {
        printf("open uart error\n");
        return -1 ;
    }

    //2.配置串口结构体信息
    struct termios myserial ; //保存串口配置信息
    //2.1清空结构体:将所有的都初始化为0
    memset(&myserial, 0 , sizeof(myserial));
    myserial.c_cflag |= (CLOCAL | CREAD);
    //2.2设置控制模式状态，本地连接，接受使能
	//设置 数据位
	myserial.c_cflag &= ~CSIZE;   //清空数据位
	myserial.c_cflag &= ~CRTSCTS; //无硬件流控制
	myserial.c_cflag |= CS8;      //数据位:8

	myserial.c_cflag &= ~CSTOPB;//   //1位停止位
	myserial.c_cflag &= ~PARENB;  //不要校验

    //2.3设置波特率：
    switch(baudrate)
    {
        case 9600:
            cfsetospeed(&myserial, B9600);  //设置波特率,B9600是定义的宏
	        cfsetispeed(&myserial, B9600);
            break ;
        case 115200 :
            cfsetospeed(&myserial, B115200);  //设置波特率,B115200是定义的宏
            cfsetispeed(&myserial, B115200);
            break ;
        case 38400:
            cfsetospeed(&myserial, B38400);  //设置波特率,B38400是定义的宏
	        cfsetispeed(&myserial, B38400);
            break ;
    }
    /* 刷新输出队列,清除正接受的数据 */
	tcflush(fd, TCIFLUSH);
	/* 改变配置 */
	tcsetattr(fd, TCSANOW, &myserial);
	return fd;
}

//显示测量的参数
void lvgl_Mokuai()
{
    /**********遮罩层和窗口：begin**********/
    lv_obj_t* mask = lv_obj_create(lv_scr_act());//当前屏幕创建遮罩
    lv_obj_set_size(mask, 1024, 600);
    lv_obj_center(mask);
    lv_obj_set_style_bg_opa(mask,LV_OPA_50,LV_PART_MAIN);//半透
    lv_obj_add_flag(mask,LV_OBJ_FLAG_CLICKABLE);//隔绝
    lv_obj_t* Mk_win = lv_obj_create(mask);//遮罩上创建主窗口
    lv_obj_set_size(Mk_win, 400, 320);
    lv_obj_center(Mk_win);
    lv_obj_set_style_bg_color(Mk_win, lv_color_hex(0x2d3243), LV_PART_MAIN);//窗口背景
    /**********遮罩层和窗口：end**********/
    
    /**********关闭按键：begin**********/
    lv_obj_t *close_btn = lv_btn_create(Mk_win);//创建按键
    lv_obj_set_size(close_btn, 30, 30);
    lv_obj_align(close_btn, LV_ALIGN_TOP_RIGHT, 0, 0); 
    lv_obj_set_style_bg_color(close_btn, lv_color_hex(0xff5252), LV_PART_MAIN);//红色背景
    lv_obj_add_event_cb(close_btn, close_window_cb, LV_EVENT_CLICKED, mask);//关闭事件.传入遮罩层
    //按钮文字（X符号）
    lv_obj_t *btn_label = lv_label_create(close_btn);
    lv_label_set_text(btn_label, "X");
    lv_obj_center(btn_label);
    /**********关闭按键：end**********/

    /**********参数：begin**********/
    //创建参数数值标签样式
    static lv_style_t style_lable;
    static int style_lable_flag = 1;
    if(style_lable_flag)
    {
        lv_style_set_text_color(&style_lable, lv_color_hex(0xe0e0e0));//颜色
        lv_style_set_text_font(&style_lable, &lv_font_montserrat_20);//大小
        style_lable_flag = 0;
    }
    //参数说明图片
    lv_obj_t* canshu_pt = lv_image_create(Mk_win);//创建图片
    lv_image_set_src(canshu_pt,"A:/XiaoHong/photo/canshu.bmp");//路径
    lv_obj_align(canshu_pt,LV_ALIGN_LEFT_MID,0,-15);//位置
    for(int i = 0;i < 5;i++)
    {
        mokuai_lable[i] = lv_label_create(Mk_win);//窗口上创建标签
        lv_obj_align(mokuai_lable[i], LV_ALIGN_TOP_RIGHT, 0, 50+(i*30));//位置，上下相隔30
        lv_obj_add_style(mokuai_lable[i] , &style_lable , LV_STATE_DEFAULT);//应用样式
    }
    //各参数默认文本显示
    lv_label_set_text(mokuai_lable[0], " -- °C");
    lv_label_set_text(mokuai_lable[1], " -- % ");
    lv_label_set_text(mokuai_lable[2], " -- Pa");
    lv_label_set_text(mokuai_lable[3], " -- m");
    lv_label_set_text(mokuai_lable[4], " -- cm");
    /**********参数：end**********/

    //创建刷新定时器1秒刷新一次
    timer = lv_timer_create(mokuai_timer, 1000, NULL);
}

//定时器回调函数 定时刷新传感器数据
void mokuai_timer(lv_timer_t *timer)
{
    //更新从模块数据结构体中的数据
    pthread_mutex_lock( &(mk_data.mutex) );//拿锁
    int temp = mk_data.T;
    int hum = mk_data.Hum;
    int press = mk_data.P;
    int alt = mk_data.H;
    int dist = mk_data.L;
    pthread_mutex_unlock( &(mk_data.mutex) );//释放

    //判断是否测到数据
    if(temp == -1 && hum == -1 && press == -1 && 
       alt == -1 && dist == -1)
        return;
    lv_label_set_text_fmt(mokuai_lable[0], " %d °C", temp);//更新温度到标签
    lv_label_set_text_fmt(mokuai_lable[1], " %d %%", hum);//更新湿度到标签
    lv_label_set_text_fmt(mokuai_lable[2], " %d Pa", press);//更新气压到标签
    lv_label_set_text_fmt(mokuai_lable[3], " %d m", alt);//更新海拔到标签
    lv_label_set_text_fmt(mokuai_lable[4], " %d cm", dist);//更新距离到标签
}

//模块窗口关闭回调函数
void close_window_cb(lv_event_t *e)
{
    //获取传递的遮罩层
    lv_obj_t* mask = lv_event_get_user_data(e);
    if(mask)
        lv_obj_del(mask);//销毁遮罩层
    if(timer) 
    {
        lv_timer_del(timer);//删除定时器
        timer = NULL;//定时器置为空
    }
}

//线程函数，不断获取测量的参数值
void* MK_thread(void* arg)
{
    /**********初始化模块：begin**********/
    MokuaiPaths* paths = (MokuaiPaths*)arg;//转换传入的路径格式
    //初始化GY39串口
    int fd_gy39 = Uart_GY39_Init(paths->gy39_path, 9600);
    if (fd_gy39 == -1) 
    {
        printf("GY39 open uart error\n");
        close(fd_gy39);
        return NULL;
    }
    //初始化US100串口
    int fd_us100 = Uart_US100_Init(paths->us100_path, 9600);
    if (fd_us100 == -1) 
    {
        printf("US100 open uart error\n");
        close(fd_us100);
        return NULL;
    }
    /**********初始化模块：end**********/
    
    /**********配置模块：begin**********/
    //配置GY39
    char gy39_cmd[3] = {0xA5, 0x82, 0x27};//要发送给gy39的数据
    char us100_cmd = 0x55;////要发送给us100的数据
    char gy39_buf[20] = {0};//存放从gy39读到的数据
    unsigned char us100_buf[2] = {0};//存放从us100读到的数据
    //循环检测两个传感器
    while(1)
    {
        int L=-1 , T=-1 ,H=-1 ,Hum=-1 ,P=-1 ;//初始化检测的值为-1
        write(fd_gy39, gy39_cmd, 3);//把数据发送给gy39
        write(fd_us100,&us100_cmd,1);//把数据发送给us100
        sleep(1);//延时等待传感器响应
        read(fd_gy39,gy39_buf,20);//读取gy39的数据并计算
        if(gy39_buf[2] == 0x45)//模式 温湿度气压海拔
        {
            T = gy39_buf[4] << 8 | gy39_buf[5] ;//温度
            T = T/100;
            Hum = gy39_buf[10] << 8 | gy39_buf[11];//湿度
            Hum = Hum/100;
            P = gy39_buf[6] << 24 | gy39_buf[7] << 16 | gy39_buf[8] << 8 | gy39_buf[9];//气压
            P=P/100;
            H = gy39_buf[12] << 8 | gy39_buf[13];//海拔
        }
        read(fd_us100,us100_buf,2);//读取us100的数据并计算
        L = us100_buf[0] << 8 | us100_buf[1] ; //测到的距离数据处理
        L = L/10;
        //读到的数据更新到模块数据结构体中
        pthread_mutex_lock( &(mk_data.mutex) );//拿锁
        mk_data.H = H;
        mk_data.Hum = Hum;
        mk_data.L = L;
        mk_data.T = T;
        mk_data.P = P;
        pthread_mutex_unlock( &(mk_data.mutex) );//释放
    }
    /**********配置模块：end**********/
}
