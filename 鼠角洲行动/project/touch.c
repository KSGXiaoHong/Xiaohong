#include"touch.h"

int fg_game = 0;//定义全局变量，游戏运行标志位
unsigned int time_ms = 0;//地鼠显示时长

//获取点击屏幕时坐标函数，返回一个结构体类型，结构体保存x、y坐标
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
    //定义一个struct input_event类型变量，读取输入的
    struct input_event event;
    // 定义一个变量用来记录读取的时间
    unsigned int time_temp = 0;
    // 检测按键的循环
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

//选择难度，返回地鼠停留的时间
unsigned int Nan_du()
{
    while(1)
    {
        //点击到了难度1
        if(1==test_touch(280,440,320,390))
            return 1000;//1s出现一次
        //点击到了难度2
        else if(1==test_touch(580,740,320,390))
            return 600;//0.6s出现一次
        //点击到了难度3
        else if(1==test_touch(280,440,450,530))
            return 300;//0.3s出现一次
        //点击到了难度4
        else if(1==test_touch(580,740,450,530))
            return 180;//0.18s出现一次
        else
            continue ;
    }    
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

//检测游戏初始界面的触屏位置，\
返回1表示点击开始游戏，2退出游戏
int test_touch_play()
{
    while(1)
    {
        // 调用hua_xy函数，接收触摸屏幕的类型
        Point p = hua_xy();
        //不为上下左右滑,说明是点击或者无操作
        if(p.x != 1 && p.x != 2 && p.x != 3 && p.x != 4 )
        {   
            //判断点击的位置是开始游戏的位置
            if(p.x > 390 && p.x < 620 && p.y > 290 && p.y <335)
                return 1;//返回1
            //退出游戏的位置
            else if(p.x > 390 && p.x < 620 && p.y > 385 && p.y <444)
                return 2;//返回2
            else //点击了其他位置就继续循环检测触摸屏
                continue;
        }
    }
}

//游戏开始主函数
void play_gm()
{
    //将游戏运行标志位置位
    fg_game = 1;
    // 显示背景、初始分数
    bmp_dis("./photo/game.bmp",0,0);//显示游戏运行界面
    bmp_dis("./photo/back.bmp", 0, 0);       // 返回键
    bmp_dis("./photo/score_0.bmp", 90, 0); // 初始分数0分图片
    int score = 0;// 击中次数
    int error = 0;// 未击中次数
    // 地鼠图片尺寸90x90
    const int MOUSE_W = 90;
    const int MOUSE_H = 90;
    //游戏主循环
    while (score!=3) //击中3次，退出循环
    {
        int mouse_x, mouse_y;//定义两个变量作为老鼠出现的坐标
        //坐标的值范围x（0~1024-90），坐标的值范围y（0~600-90）
        do 
        {
            mouse_x = rand() % (1024 - MOUSE_W);  // 确保不超出屏幕宽度
            mouse_y = rand() % (600 - MOUSE_H);   // 确保不超出屏幕高度
            // 避开左上角返回键（0x0）和顶部分数区（90x90）
        } while (mouse_x < 180 && mouse_y < 90);

        // 显示地鼠
        bmp_dis("./photo/mouse.bmp", mouse_x, mouse_y);
        // 检测是否触摸到地鼠
        int hit = 0;//击中标志位
        // 检测地鼠区域触摸（mouse_x到mouse_x+MOUSE_W为x范围，mouse_y到mouse_y+MOUSE_H为y范围）
        int touch_xy = test_touch(mouse_x, mouse_x + MOUSE_W, mouse_y, mouse_y + MOUSE_H);
        //判断返回值
        switch(touch_xy)
        {
            case 0://点击了返回按键
            {
                //显示游戏主界面，并再次调用开始游戏play_game()，当游戏真正结束，该函数执行完毕，返回
                bmp_dis("./photo/play.bmp", 0, 0);play_game();return;
            }
            case 1://返回1表示点击了地鼠区域
            {
                hit = 1;//置位
                break;
            }
            case 3://没打到
            {
                hit = 0;
                break;
            }
            default:continue;
        }
        char score_path[50];//组合图片路径
        // 处理击中/未击中
        if (hit) 
        {
            // 显示击中效果（500ms）
            bmp_dis("./photo/beat.bmp", mouse_x, mouse_y);
            usleep(500000); 
            // 更新分数
            score += 1;
            //覆盖游戏运行图、返回键、更新组合的分数图
            bmp_dis("./photo/game.bmp",0,0);
            bmp_dis("./photo/back.bmp", 0, 0);   
            sprintf(score_path, "./photo/score_%d.bmp",score);//将图片路径组合
            bmp_dis(score_path, 90, 0); // 刷新分数图片
        }
        else
        {
            //显示未击中效果（500ms）
            bmp_dis("./photo/beatno.bmp",mouse_x, mouse_y);
            usleep(500000); 
            score = 0;//分数清空
            error++;//未击中次数增加
            //覆盖游戏运行图、返回键、更新组合的分数图
            bmp_dis("./photo/game.bmp",0,0);
            bmp_dis("./photo/back.bmp", 0, 0); 
            sprintf(score_path, "./photo/score_%d.bmp",score);
            bmp_dis(score_path, 90, 0); // 刷新分数图片
        }
        //8次没打中游戏失败,退出循环
        if(error==8)
            break;
        // 短暂延迟（控制地鼠出现速度）
        usleep(100000); // 0.1秒后出现下一个地鼠
    }
    // 打地鼠结束，判断是否打完
    if(error==8)//判断未击中次数
        bmp_dis("./photo/gameover.bmp", 0, 0);//显示游戏失败图
    else//地鼠全部消灭
    {
        //游戏二阶段，舔包界面
        game_next();
        test_touch(0, 1024, 0, 600); // 点击全屏任意位置
        bmp_dis("./photo/gameok.bmp", 0, 0);//显示游戏胜利图
    }
    //游戏运行标志位置0
    fg_game = 0;
    // 等待触摸任意位置返回主界面（用test_touch检测全屏）
    test_touch(0, 1024, 0, 600); // 点击全屏任意位置调用play_game()函数返回主菜单界面
    play_game();
}

//退出游戏函数
void play_game_over()
{
    //将游戏开始标志位置0
    fg_game = 0;
    bmp_dis("./photo/bc.bmp",0,0);
    sleep(2);
    bmp_dis("./photo/goodbye.bmp",0,0);
    return;
}