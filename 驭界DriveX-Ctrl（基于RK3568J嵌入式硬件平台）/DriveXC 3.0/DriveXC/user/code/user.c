#include "lv.h"

// char IP[64] = {0};//定义IP地址
// int DK = 0;//定义端口号

//未连接上服务器标志位
int server_error = 0;
//控制客户端的两个子线程同步退出 标志位
static int exit_client_fg = 0;
//往客户端写数据缓冲取
char buf_send[1024] = {0};
//从客户端读数据缓冲取
char buf_recv[1024] = {0};
//写数据就绪标志位
static int ready_send = 0;
//读数据就绪标志位
int ready_read = 0;
// 创建第二个文本区域 接收服务器消息
lv_obj_t* ta2 = NULL;
//服务器的套接字
int socket_fd = -1;
extern int creat_flag ;
//客户端线程client
void* client_thread(void* arg)
{
    puts("laile");
    server_error = 0;          // 重置连接错误标志
    exit_client_fg = 0;        // 重置退出标志
    ready_send = 0;            // 重置发送标志
    ready_read = 0;            // 重置接收标志
    buf_send[0] = '\0';        // 清空发送缓冲区
    buf_recv[0] = '\0';        // 清空接收缓冲区
    //设置线程属性分离，自动释放资源
    pthread_detach(pthread_self());
    //同步退出标志位置零
    exit_client_fg = 0;
    //创建一个套接字
    //指定协议族为IPV4协议、流式套接字、不知名
    socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if( socket_fd == -1 )
    {
        perror("客户端套接字创建失败:");
        return NULL;
    }

    //定义一个网络地址结构体，保存服务器的信息
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;//IPV4协议
    server_addr.sin_addr.s_addr = inet_addr(IP);//ip
    server_addr.sin_port = htons(DK);//端口号
    //连接服务器
    if(connect(socket_fd,(struct sockaddr*)&server_addr,(socklen_t)sizeof(server_addr)) == -1)
    {
        //连接出错标志位置1
        server_error = 1;
        perror("连接服务器出错");
        return NULL;
    }
    puts("连接成功");
    server_error = 0;//连接出错标志位置0
    //线程id
    pthread_t t1 = 0;
    pthread_t t2 = 0;
    //创建线程接收服务器的消息 传入套接字
    pthread_create(&t1, NULL, RecvToServer_thread, &socket_fd);
    //创建线程给服务器发消息
    pthread_create(&t2, NULL, SendToServer_thread, &socket_fd);
    //主线程等待子线程结束
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    //关闭连接并退出
    close(socket_fd);
    printf("已断开连接\n");
}

//客户端接收服务器消息线程
static void* RecvToServer_thread(void* arg)
{
    if( socket_fd == -1 )
    {
        perror("客户端套接字有误:");
        return NULL;
    }
    exit_client_fg = 0;//同步退出标志位重置
    while(!exit_client_fg)//判断是否退出
    {
        //select监听客户端套接字，设置超时（1秒）
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(socket_fd, &readfds);  // 监听服务器数据
        struct timeval tv = {1, 0};   // 超时1秒
        //阻塞等待数据或超时
        int ret = select(socket_fd + 1, &readfds, NULL, NULL, &tv);
        if (ret < 0) 
        {
            perror("接收select出错");
            break;
        } 
        else if (ret == 0) 
        {
            continue;  // 超时，检查标志位后继续循环
        }
        //检查是否就绪
        if(FD_ISSET(socket_fd, &readfds))
        {
            //清空缓冲区
            buf_recv[0] = '\0';  
            //从服务器读
            ssize_t recv_len = recv(socket_fd, buf_recv, sizeof(buf_recv), 0);
            if (recv_len <= 0) 
            {
                perror("接收失败或服务器断开");
                exit_client_fg = 1;//同步退出标志位置1
                break;
            }
            printf("服务器回复：%s", buf_recv);//读到数据终端打印
            ready_read = 1;//读到数据，将读数据标志位置1  主函数中打印读到的数据
        }
    }
    close(socket_fd);
}

//客户端给服务器发消息线程
static void* SendToServer_thread(void* arg)
{
    if( socket_fd == -1 )
    {
        perror("客户端套接字有误:");
        return NULL;
    }
    //重置同步退出标志位
    exit_client_fg = 0;
    while(!exit_client_fg)//判断同步退出标志
    {//循环检测写标志位是否就绪
        if(ready_send)//写数据标志位就绪
        {
            //往服务器写数据
            if(send(socket_fd , buf_send , strlen(buf_send),0) == -1)
            {
                perror("客户端写入失败");
                exit_client_fg = 1;
                break;
            }
            ready_send = 0;//写完置0
            //输入###退出
            if(strcmp(buf_send,"###") == 0)
            {
                creat_flag = 1;
                ready_read = 1;//读数据标志位置1
                exit_client_fg = 1;//线程退出标志位
                strcpy(buf_recv,"byebye");//显示数据拜拜
                break;
            }
        }
    }
    close(socket_fd);
}
void user_exit()
{
    menu();
}

// 扩展事件回调：处理输入完成事件，将内容存入buf
static void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);

    //显示/隐藏键盘
    if(code == LV_EVENT_FOCUSED) {
        lv_keyboard_set_textarea(kb, ta);
        lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
    if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }

    // 输入完成（按回车）时，将内容存入buf_send
    if(code == LV_EVENT_READY) 
    {
        // 获取文本区域的输入内容（返回const char*）
        const char* input_str = lv_textarea_get_text(ta);
        // 复制到buf
        strncpy(buf_send, input_str, sizeof(buf_send));
        // 调试：打印存入的内容
        LV_LOG_USER("buf = %s", buf_send);
        ready_send = 1;//写数据就绪
    }
}

//创建键盘函数 用户输入反馈
void user_FanKui(void)
{
    lv_obj_clean(lv_scr_act());
    // 创建虚拟键盘
    lv_obj_t * kb = lv_keyboard_create(lv_screen_active());
    // 创建第一个文本区域ta1 给服务器发消息
    lv_obj_t * ta1 = lv_textarea_create(lv_screen_active());
    lv_obj_align(ta1, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_event_cb(ta1, ta_event_cb, LV_EVENT_ALL, kb);  // 关联回调
    lv_textarea_set_placeholder_text(ta1, "please input");
    lv_obj_set_size(ta1, 500, 200);//文本区大小
    lv_keyboard_set_textarea(kb, ta1);// 初始关联键盘到ta1
    // 创建第二个文本区域ta1 接收服务器消息
    ta2 = lv_textarea_create(lv_screen_active());
    lv_obj_align(ta2, LV_ALIGN_TOP_RIGHT, 10, 10);
    lv_textarea_set_placeholder_text(ta2, "server message");
    lv_obj_set_size(ta2, 500, 200);
    //创建返回按键
    lv_obj_t* exit_user = lv_btn_create(lv_scr_act());
    lv_obj_align(exit_user,LV_ALIGN_CENTER,5,-20);//居中
    lv_obj_set_size(exit_user, 50, 50);
    lv_obj_set_style_bg_color(exit_user, lv_color_hex(0xffeeee),LV_PART_MAIN);
    lv_obj_add_event_cb(exit_user,user_back,LV_EVENT_CLICKED,NULL);//点击返回执行退出函数
}

//退出反馈界面函数
static void user_back()
{
    if(exit_client_fg != 1) //线程退出标志位
        creat_flag = 0;//下次进入不创建新县城
    lv_obj_clean(lv_scr_act()); 
    menu();
}

//退出帮助界面回调函数
void back_help_cb()
{
    lv_obj_clean(lv_scr_act());//清空屏幕
    menu();
}