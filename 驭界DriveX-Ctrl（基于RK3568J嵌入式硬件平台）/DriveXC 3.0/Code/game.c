#include"game.h"

int fg_game = 0;//定义全局变量，游戏运行标志位
int time_ms = 0;//地鼠显示时长

//点击开始游戏执行该函数
void play_game()
{
    //初始化随机数种子
    srand(time(NULL));
    //调用bmp_dis函数，显示加载图片
    bmp_dis("./photo/bc.bmp",0,0);
    //延时1秒
    sleep(1);
    //显示游戏菜单主界面图片
    bmp_dis("./photo/play.bmp",0,0);
    //调用test_touch_play检测在主菜单界面点击的位置，返回标志位
    int flag = test_touch_play();//游戏主界面函数
    // 判断标志位
    switch (flag)
    {
        // 当返回1时，表示点击到了开始游戏按键
        case 1:
        {
            // 显示难度界面
            bmp_dis("./photo/nandu.bmp",0,0);
            // 调用选择难度函数
            time_ms = Nan_du();//难度选择,返回值更新为全局变量-地鼠停留的时间
            bmp_dis("./photo/bc.bmp",0,0);//显示加载界面
            sleep(1);
            //开始游戏，游戏运行函数
            game_run();break;
        }
        // 当返回2时，表示点击到退出游戏按键
        case 2:
        {
            play_game_over();break;
        }
        default:break;
    }
}

//游戏初始界面函数\
检测触屏位置\
返回1表示点击开始游戏，2退出游戏
static int test_touch_play()
{
    while(1)
    {
        // 调用hua_xy函数，接收触摸屏幕的类型
        Point p = hua_xy();
        //不为上下左右滑,说明是点击或者无操作
        if(p.x != 1 && p.x != 2 && p.x != 3 && p.x != 4 )
        {   
            //判断点击的位置是开始游戏的位置
            if(p.x > 266 && p.x < 480 && p.y > 425 && p.y <500)
                return 1;//返回1
            //退出游戏的位置
            else if(p.x > 535 && p.x < 760 && p.y > 425 && p.y <500)
                return 2;//返回2
            else //点击了其他位置就继续循环检测触摸屏
                continue;
        }
    }
}

//选择难度界面函数，返回地鼠停留的时间
static unsigned int Nan_du()
{
    while(1)
    {
        //点击到了难度1
        if(1==test_touch(180,315,330,460))
            return 1000;//1s出现一次
        //点击到了难度2
        else if(1==test_touch(355,490,330,460))
            return 600;//0.6s出现一次
        //点击到了难度3
        else if(1==test_touch(530,670,330,460))
            return 300;//0.3s出现一次
        //点击到了难度4
        else if(1==test_touch(705,845,330,460))
            return 260;//0.25s出现一次
        else
            continue ;
    }    
}

//游戏运行主函数
static void game_run()
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
                play_game();return;
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
static void play_game_over()
{  
    //将游戏开始标志位置0
    fg_game = 0;
    bmp_dis("./photo/bc.bmp",0,0);
    sleep(1);
    bmp_dis("./photo/goodbye.bmp",0,0);
    sleep(1);
    return;
}

//游戏二阶段，摸金函数
static void game_next()
{
    //显示搜寻物资界面在屏幕中间，150*70
    bmp_dis("./photo/search.bmp",510,290);
    //检测是否点击到搜寻物资按键
    while(1)
    {
        int touch = test_touch(510,760,290,360);
        printf("%d\n",touch);
        switch(touch)
        {
            case 0://点击了返回按键
            {
                //显示游戏主界面，并再次调用开始游戏play_game()，当游戏真正结束，该函数执行完毕，返回
                bmp_dis("./photo/play.bmp", 0, 0);
                play_game();
                return;
            }
            case 1://返回1表示点到了搜寻物资按键
            {
                // 调用搜寻物资函数
                game_search();
                fg_game=0;
                return;
            }
            default:continue; //点到其他地方
        }
    }
}

//搜寻物资函数
static void game_search()
{
    //定义物资基础大小,背包中一个格子图片70*70
    const unsigned int WUZI = 70;
    //打印背包界面,bag图片624*600
    bmp_dis("./photo/bag.bmp",190,0);
    //随机数5个，0~100，占用格子数\
    17时大红3*4,3*3\
    27,37时，中红2*3,2*2\
    47,57,67,77时，小红1*1,1*2\
    11,22,33,……,99,大金1*2以上的\
    %5==0，小金\
    其他情况,蓝绿紫随机
    // 背包有效显示区域（相对于屏幕的坐标）
    // 基于背包的左上角(200,0)加上内部偏移
    const int BAG_START_X = 200 + 100;  // 背包内显示区域左上角X
    const int BAG_START_Y = 0 + 90;     // 背包内显示区域左上角Y
    const int BAG_END_X = 200 + 520;    // 背包内显示区域右下角X
    const int BAG_END_Y = 0 + 585;      // 背包内显示区域右下角Y
    int sy_size = 420;//每行剩余空的位置
    //记录当前行最高物品的高度
    int max_h = 0; 
    int w = 0, h = 0;  // 物资的宽和高（以WUZI为单位）
    // 当前物资放置位置,进入循环之前就为
    int now_x = BAG_START_X;
    int now_y = BAG_START_Y;
    //用来存放生成的5个随机数
    int r[5] = {0};
    for(int i = 0; i < 5 ; i++)
    {
        r[i] = (rand()%100+1);//生成一个1到100的随机数
        printf("r[i] = %d\n",r[i]);
        char wuzi_path[100]; // 存放物资图片路径
        int rand_wuzi;//随机选择图片用
        int load_size = 0;
        //判断生成的数
        if(r[i] == 1)//非洲之心
        {
            w=1;h=1;load_size = 1;
            rand_wuzi = rand() % 2 + 1;//随机取一个值，选择的图片
            sprintf(wuzi_path, "./photo/boss%d.bmp",rand_wuzi);
        }
        else if(r[i] == 17)//大红
        {
            w=4;h=3;load_size = 12;
            // 大红4*3：2张图片（red_a_1/2.bmp）
            rand_wuzi = rand() % 2 + 1;//随机取一个值，选择的图片
            sprintf(wuzi_path, "./photo/red_a_%d.bmp", rand_wuzi);
        }
        else if(r[i] == 27)//3*3 中红
        {
            w=3; h=3;load_size = 9;
            // 中红3*3：4张（red_b_1-4.bmp）
            rand_wuzi = rand() % 5 + 1;
            sprintf(wuzi_path, "./photo/red_b_%d.bmp", rand_wuzi);
        }
        else if(r[i] == 37)//3*2
        {
            w=3;h=2;load_size = 6;
            // 中红3*2
            rand_wuzi = rand() % 9 + 1;
            sprintf(wuzi_path, "./photo/red_c_%d.bmp", rand_wuzi);
        }
        else if(r[i] == 47 || r[i] == 57)//2*1小红
        {
            w=2;h=1;load_size = 2;
            // 小红2*1
            rand_wuzi = rand() % 12 + 1;
            sprintf(wuzi_path, "./photo/red_d_%d.bmp", rand_wuzi);
        } 
        else if(r[i] == 67 || r[i] == 77)//1*1
        {
            w=1;h=1;load_size = 1;
            // 小红1*1
            rand_wuzi = rand() % 4 + 1;
            sprintf(wuzi_path, "./photo/red_e_%d.bmp", rand_wuzi);
        }
        else if(r[i]%11 == 0 || r[i]%13 == 0)//大金
        {
            w=2;h=2;load_size = 4;
            //大金2*2
            rand_wuzi = rand() % 15 + 1;
            sprintf(wuzi_path, "./photo/yellow_a_%d.bmp", rand_wuzi);
        }
        else if(r[i]%5 == 0)//小金
        {
            w=1;h=1;load_size = 1;
            //1*1
            rand_wuzi = rand() % 5 + 1;
            sprintf(wuzi_path, "./photo/yellow_b_%d.bmp", rand_wuzi);
        }
        else//蓝绿紫70*70
        {
            w=1;h=1;load_size = 1;
            //其他1*1
            rand_wuzi = rand() % 20 + 1;
            sprintf(wuzi_path, "./photo/ot_%d.bmp", rand_wuzi);
        }
        //计算实际尺寸
        int width = w * WUZI;
        int height = h * WUZI;
        if (now_x + width > BAG_END_X) 
        {
            // 换行到下一行
            now_y += max_h; // 基于当前行最高高度换行
            now_x = BAG_START_X;
            max_h = 0; // 重置行高
        }
        // 4. 确保不超出底部边界
        if (now_y + height > BAG_END_Y)
        {
            break; // 空间不足，停止显示
        }
         // 5. 【同步显示】加载动画和物资图片使用同一位置（now_x, now_y）
        gif_search(now_x, now_y, load_size); // 加载动画
        // 根据物资类型设置休眠时间
        if(r[i]==1)sleep(6);
        else if(r[i] == 17) sleep(5);
        else if(r[i] == 27) sleep(4);
        else if(r[i] == 37) sleep(4);
        else if(r[i] == 47 || r[i] == 57) sleep(2);
        else if(r[i] == 67 || r[i] == 77) sleep(2);
        else if(r[i]%11 == 0 || r[i]%13 == 0) sleep(2);
        else if(r[i]%5 == 0) sleep(2);
        else sleep(1);
        bmp_dis(wuzi_path, now_x, now_y); // 物资图片（与加载动画同位置）
        if(r[i]==1 && rand_wuzi==1)//检视
            bmp_dis("./photo/js.bmp",10,350);
        // 6. 更新行高和下一个位置
        if (height > max_h)
        {
            max_h = height;
        }
        now_x += width; // 下一个物品的X坐标
    }
}

//指定位置和大小显示搜索动画\
size分别为1 2 4 6 9 12
static void gif_search(int x,int y,int size)
{
    char loading_path[100];
    // 生成加载图片路径：./photo/loading_${size}.bmp
    sprintf(loading_path, "./photo/loading_%d.bmp", size);
    // 显示加载图片（坐标x,y）
    bmp_dis(loading_path, x, y);
}
