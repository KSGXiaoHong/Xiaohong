#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <linux/input.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <time.h>
#include <pthread.h>
#include <termios.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sqlite3.h>

#define IP "172.130.1.24"//ip地址
#define DK 5674//端口号
#define CLIENT_MAX_NUM 10//允许连接的客户端最大值

//线程互斥锁
static pthread_mutex_t client_mutex ;

//客户端套接字 用于广播，给每一个客户端发消息
int client_fdd[CLIENT_MAX_NUM] = {0};
//已客户端连接个数
int client_num = 0;

//服务器接收客户端消息线程
static void* RecvToClient_thread(void* arg)
{
    //设置线程属性分离，自动释放资源
    pthread_detach(pthread_self());
    //客户端套接字
    int client_fd = *((int*)arg);
    printf("已连接客户端:fd=%d\n",client_fd);
    while(1)
    {
        //select监听客户端套接字，设置超时（1秒）
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(client_fd, &readfds);  // 监听服务器数据
        struct timeval tv = {1, 0};   // 超时1秒
        //阻塞等待数据或超时
        int ret = select(client_fd + 1, &readfds, NULL, NULL, &tv);
        if (ret < 0) 
        {
            perror("接收select出错");
            break;
        } 
        else if (ret == 0) 
        {
            continue;  // 超时，继续循环
        }
        //就绪
        if(FD_ISSET(client_fd, &readfds))
        {
            char buf[1024] = {0};//存放读到的数据
            //从客户端读数据
            ssize_t ret = recv(client_fd , buf , sizeof(buf),0);
            if(ret < 0)
            {
                perror("从客户端读数据出错");
                break;
            }
            //读到的是###，退出
            if(strcmp(buf,"###") == 0)
            {
                printf("客户端(fd=%d)已退出\n",client_fd);
                close(client_fd);
                printf("已关闭client_fd = %d\n",client_fd);
                return NULL;
            }
            printf("收到客户端(fd=%d)数据:%s\n", client_fd, buf);
            // 回复客户端
            char *reply = "    OK Thank you!!!";
            send(client_fd, reply, strlen(reply), 0);
        }
    }
}

//服务器给客户端发消息线程
static void* SendToClient_thread(void* arg)
{
    //设置线程属性分离
    pthread_detach(pthread_self());
    while(1)
    {
        //select监听键盘输入，设置超时（1秒）
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(0, &readfds);  // 监听键盘,标准输入文件描述符为0
        struct timeval tv = {1, 0};   // 超时1秒
        //阻塞等待数据或超时
        int ret = select(0+1, &readfds, NULL, NULL, &tv);
        if (ret < 0) 
        {
            perror("发送select出错");
            break;
        } 
        else if (ret == 0) 
        {
            continue;  // 超时后继续循环
        }
        //检查是否就绪
        if(FD_ISSET(0, &readfds))
        {
            char buf[1024] = {0};
            //从键盘输入数据到buf
            fgets(buf,sizeof(buf),stdin);
            //
            for(int i = 0;i < client_num;i++)
            {
                //往每一个服务器写数据
                send(client_fdd[i] , buf , strlen(buf),0);
            }
        }
    }
}

//服务器线程server
int main()
{
    //创建一个套接字
    //指定协议族为IPV4协议、流式套接字、不知名
    int socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if( socket_fd == -1 )
    {
        perror("服务器创建套接字失败");
        return -1;
    }
    //设置套接字端口号可重用
    int n = 1;
    setsockopt(socket_fd,SOL_SOCKET,SO_REUSEPORT,&n,sizeof(n));
    setsockopt(socket_fd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(n));
    //定义一个网络地址结构体 保存服务器的网络通信地址
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;//IPV4协议
    s_addr.sin_addr.s_addr = inet_addr(IP);//指定ip地址
    s_addr.sin_port = htons(DK);//制定端口号  主机字节序列转换成网络字节序列
    //绑定服务器的网络通信地址
    if(bind(socket_fd,(struct sockaddr*)&s_addr,(socklen_t)sizeof(s_addr))== -1)
    {
        perror("服务器绑定失败");
        return -1;
    }
    //监听套接字
    if(listen(socket_fd,CLIENT_MAX_NUM) == -1)
    {
        perror("服务器监听出错");
        close(socket_fd);
        return -1;
    }
    puts("服务器已启动");
    while(1)
    {
        struct sockaddr_in client_addr ;//保存客户端的网络通信地址
        socklen_t client_len = sizeof(client_addr) ; //保存客户端的网络通信地址的长度
        //监听套接字，将客户端的套接字保存在client_fdd的第client_num个元素
        int client_fd = accept(socket_fd,(struct sockaddr*)&client_addr,&client_len);
        if(client_fd == -1)//连接失败
        {
            perror("连接客户端失败");
            close(client_fdd[client_num]);
            continue ;
        }
        printf("已连接客户端：IP=%s,端口=%d,fd=%d\n",
                inet_ntoa(client_addr.sin_addr),
                ntohs(client_addr.sin_port),
                client_fd);
        send(client_fd , "OK Come On!!!!!!!!!!!!" , strlen("OK Come On!!!!!!!!!!!!"),0);
        //创建线程  接收客户端消息，传入客户端的套接字
        pthread_t tid1;
        pthread_create(&tid1,NULL,RecvToClient_thread,(void*)&client_fd);
        //创建线程  给客户端发消息，传入客户端的套接字
        pthread_t tid2;
        pthread_create(&tid2,NULL,SendToClient_thread,(void*)&client_fd);
        pthread_mutex_lock(&client_mutex);  //加锁
        int flag = 0;
        //保存当前fd
        for(int i = 0;i < client_num;i++)
        {
            //遍历数组看有没有重复的，有就跳过
            if(client_fdd[i]!=client_fd)
                continue;
            else
                flag = 1;
        }
        if(flag == 0)
        {
            client_fdd[client_num] = client_fd;
            client_num++;//准备保存下一个
        }
        pthread_mutex_unlock(&client_mutex);  //解锁
        //继续循环监听
    }
}