#include"touch.h"


//获取点击屏幕时坐标函数\
返回一个结构体类型\
结构体保存x、y坐标
Point test_xy()
{
    //定义一个Point变量，给成员赋初值
    Point p;
    p.x = -1;
    p.y = -1;
    //打开触摸屏文件
    int fd_xy = open("/dev/input/event6",O_RDWR);
    if(fd_xy == -1)
    {
        perror("open input");
        return p;
    }
    //定义一个struct input_event类型变量，读取信息
    struct input_event event;
    while(1)
    {
        //读文件的信息
        int r = read(fd_xy,&event,sizeof(event));
        if(r == -1)
        {
            perror("read");
            return p;
        }
        //判断event的类型是否为触摸屏
        if(event.type == EV_ABS)
        {
            //如果是横坐标
            if(event.code == ABS_X)
            {
                p.x = event.value;
            }
            //如果是纵坐标
            if(event.code == ABS_Y)
            {
                p.y = event.value;
            }
            if(p.y!=-1&&p.x!=-1)
            {
                break;
            }
        }
        else
        {
            continue;
        }
    }
    close(fd_xy);
    return p;
}

//触摸屏属性获取,将Point类型的结构体成员p1作为标志位返回\
当点击屏幕时，返回的就是坐标；滑动上下左右滑，分别返回p1.x值为1234\
没有操作且超时，返回p1.x值为-1
Point hua_xy()
{
    //定义两个Point变量，给成员赋初值默认-1
    Point p1;//记录按下的坐标
    Point p2;//记录松开的坐标
    p1.x = -1;
    p1.y = -1;
    p2.x = -1;
    p2.y = -1;
    //打开触摸屏文件，非阻塞
    int fd_xy = open("/dev/input/event6",O_RDWR| O_NONBLOCK);
    if(fd_xy == -1)
    {
        perror("open input");
        return p1;
    }
    //定义一个struct input_event类型变量，读取输入事件
    struct input_event event;
    //定义一个变量用来记录未点击屏幕的时间
    unsigned int time_temp = 0;
    //检测按键的循环
    while(1)
    {
        //进入循环一次，时间加1
        time_temp=time_temp+1;
        //读触摸屏的信息
        int r = read(fd_xy,&event,sizeof(event));
        // 1ms延时，可以实现time_temp和time_ms的延时到毫秒级
        usleep(1000); 
        //判断游戏启动标志位，为0说明游戏没有运行
        if(fg_game == 0)
            ;//啥都不干
        if(fg_game == 1 && time_temp==time_ms)//标志位为1，说明游戏进行中,当到达设置的时间退出按键检测
            break;
        if(r != sizeof(event))
        {
            continue;
        }
        //屏幕有输入事件，才会进入下方代码块，改变p1和p2的值
        {
            //判断event的类型为触摸屏并且检测到类型为X的坐标
            if(event.type == EV_ABS && event.code == ABS_X)
            {
                //p1为-1说明是第一次点下去，讲读到的value值给p1
                if(p1.x==-1)
                    p1.x = event.value;
                // 否则不是第一次碰到，获取到的值更新给p2
                else//后面获取到的值给p2
                    p2.x = event.value;
            }
            //y轴同理
            else if(event.type == EV_ABS && event.code == ABS_Y)
            {
                if(p1.y==-1)
                    p1.y = event.value;
                else
                    p2.y = event.value;
            }
            //松手时跳出按键检测函数，此时p1为触屏的坐标，p2为松手的坐标
            if(event.type == EV_KEY && event.code == BTN_TOUCH && event.value == 0)
                break;
        }
    }
    close(fd_xy);//关闭触摸屏文件
    //计算点击屏幕的类型，并返回相应的值
    //当只点击屏幕，p2没有被赋值，为默认的-1
    if(p2.x==-1&&p2.y==-1)
    {
        return p1;//返回p1，点击的坐标，p1做标志位
    }
    //从屏幕左侧向右侧滑动
    else if(p1.x<p2.x)
    {
        //计算差值
        int x = abs(p2.x-p1.x);//右滑的幅度
        int y = abs(p1.y-p2.y);//上下滑动的幅度
        //左右滑动的幅度大于上下滑动的幅度
        if(x>y)
            p1.x = 4;//右滑，p1的x赋值为4，p1作为标志位返回
        //上下滑动幅度大于左右
        else
        {
            //点击的纵坐标大于松手的纵坐标\
            说明从下往上滑动
            if(p1.y>p2.y)
                p1.x = 1;//上滑，p1的x赋值为1，p1作为标志位返回
            else
                p1.x = 2;//下滑，p1的x赋值为2，p1作为标志位返回
        }
    }
    //从屏幕右侧向左侧滑动，同理
    else
    {
        int x = abs(p2.x-p1.x);//右滑的幅度
        int y = abs(p1.y-p2.y);//上下滑动的幅度
        //左右滑动的幅度大于上下滑动的幅度
        if(x>y)
            p1.x = 3;//左滑，p1的x赋值为4，p1作为标志位返回
        //上下滑动幅度大于左右
        else
        {
            if(p1.y>p2.y)
                p1.x = 1;//上滑，p1的x赋值为1，p1作为标志位返回
            else
                p1.x = 2;//下滑，p1的x赋值为2，p1作为标志位返回
        }
    }
    return p1;//返回p1
}

//指定矩形区域触屏反馈,点击到了返回1\
点击到左上角返回键返回2（鼠角洲用） 否则不断检测\
传入坐标，a，b为横坐标，c，d为纵坐标\
ac决定左上坐标，bd决定右上，ad决定坐下，bd决定右下
int test_touch(int a,int b,int c,int d)
{
    while(1)
    {
        //判断触摸屏幕的状态，
        Point p = hua_xy();
        //没有滑行动作,为点击
        if(p.x != 1 && p.x != 2 && p.x != 3 && p.x != 4 )
        {
            //判断点击屏幕指定位置
            if(p.x > a && p.x < b && p.y > c && p.y <d)
                return 1;//点到了，返回1
            //如果点击在左上角返回按键，返回0
            else if(p.x > 0 && p.x < 90 && p.y > 0 && p.y <90)
                return 0;
            else//其他地方返回3
                return 3;//返回3
        }
        else
            continue;
    }
}
