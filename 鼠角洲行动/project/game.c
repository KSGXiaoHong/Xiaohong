#include"game.h"

//开始游戏函数
void play_game()
{
    //初始化随机数种子
    srand(time(NULL));
    // 调用bmp_dis函数，显示加载图片
    bmp_dis("./photo/bc.bmp",0,0);
    // 延时两秒
    sleep(1);
    // 显示游戏菜单主界面图片
    bmp_dis("./photo/play.bmp",0,0);
    // 调用test_touch_play检测在主菜单界面点击的位置，返回标志位
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
            play_gm();break;
        }
        // 当返回2时，表示点击到退出游戏按键
        case 2:
        {
            play_game_over();break;
        }
        default:break;
    }
}

//游戏二阶段
void game_next()
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
                bmp_dis("./photo/play.bmp", 0, 0);play_game();return;
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

//指定位置和大小显示搜索动画\
size分别为1 2 4 6 9 12
void gif_search(int x,int y,int size)
{
    char loading_path[100];
    // 生成加载图片路径：./photo/loading_${size}.bmp
    sprintf(loading_path, "./photo/loading_%d.bmp", size);
    // 显示加载图片（坐标x,y）
    bmp_dis(loading_path, x, y);
}
//搜寻物资函数
void game_search()
{
    
    //初始化随机数种子
    srand(time(NULL));
    //定义物资基础大小,背包中一个格子图片70*70
    const unsigned int WUZI = 70;
    //打印背包界面,bag图片624*600
    bmp_dis("./photo/bag.bmp",200,0);
    //随机数5个，0~100，占用格子数\
    17时大红3*4,3*3\
    27,37时，中红2*3,2*2\
    47,57,67,77时，小红1*1,1*2\
    11,22,33,……,99,大金1*2以上的\
    %5==0，小金\
    其他情况,蓝绿紫随机
    // 背包有效显示区域（相对于屏幕的坐标）
    // 基于背包的左上角(200,0)加上内部偏移
    const int BAG_START_X = 200 + 110;  // 背包内显示区域左上角X
    const int BAG_START_Y = 0 + 90;     // 背包内显示区域左上角Y
    const int BAG_END_X = 200 + 520;    // 背包内显示区域右下角X
    const int BAG_END_Y = 0 + 585;      // 背包内显示区域右下角Y
    int sy_size = 410;//每行剩余空的位置
    //记录当前行最高物品的高度
    int max_h = 0; 
    int fg_y = 0;//换行显示标志位
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
            sprintf(wuzi_path, "./photo/boss.bmp");
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
            rand_wuzi = rand() % 4 + 1;
            sprintf(wuzi_path, "./photo/red_b_%d.bmp", rand_wuzi);
        }
        else if(r[i] == 37)//3*2
        {
            w=3;h=2;load_size = 6;
            // 中红3*2
            rand_wuzi = rand() % 5 + 1;
            sprintf(wuzi_path, "./photo/red_c_%d.bmp", rand_wuzi);
        }
        else if(r[i] == 47 || r[i] == 57)//2*1小红
        {
            w=2;h=1;load_size = 2;
            // 小红2*1
            rand_wuzi = rand() % 3 + 1;
            sprintf(wuzi_path, "./photo/red_d_%d.bmp", rand_wuzi);
        } 
        else if(r[i] == 67 || r[i] == 77)//1*1
        {
            w=1;h=1;load_size = 1;
            // 小红1*1
            rand_wuzi = rand() % 4 + 1;
            sprintf(wuzi_path, "./photo/red_e_%d.bmp", rand_wuzi);
        }
        else if(r[i]%11 == 0)//大金
        {
            w=2;h=2;load_size = 4;
            //大金2*2
            rand_wuzi = rand() % 3 + 1;
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
            rand_wuzi = rand() % 16 + 1;
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
        if(r[i]==1)sleep(10);
        else if(r[i] == 17) sleep(8);
        else if(r[i] == 27) sleep(7);
        else if(r[i] == 37) sleep(6);
        else if(r[i] == 47 || r[i] == 57) sleep(4);
        else if(r[i] == 67 || r[i] == 77) sleep(3);
        else if(r[i]%11 == 0) sleep(3);
        else if(r[i]%5 == 0) sleep(2);
        else sleep(1);
        bmp_dis(wuzi_path, now_x, now_y); // 物资图片（与加载动画同位置）
        if(r[i]==1)//检视
            bmp_dis("./photo/js.bmp",10,350);
        
        // 6. 更新行高和下一个位置
        if (height > max_h)
        {
            max_h = height;
        }
        now_x += width; // 下一个物品的X坐标
    }
}
