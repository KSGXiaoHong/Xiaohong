#include "photo.h"

//滑动浏览照片函数
void photo()
{
    
    bmp_dis("photo/loading_pt.bmp",0,0);
    sleep(2);
    //照片标志位
    int flag_pt = 1;
    while(1)
    {
        switch(flag_pt)
        {
            case 1:
            {
                bmp_dis("photo/pt1.bmp",0,0);
                break;
            }
            case 2:
            {
                bmp_dis("photo/pt2.bmp",0,0);
                break;
            }
            case 3:
            {
                bmp_dis("photo/pt3.bmp",0,0);
                break;
            }
            case 4:
            {
                bmp_dis("photo/pt4.bmp",0,0);
                break;
            }
            case 5:
            {
                bmp_dis("photo/pt5.bmp",0,0);
                break;
            }
            default:break;
        }
        //检测滑动方向
        Point p_fx = hua_xy();
        if(p_fx.x==1)//上划退出
        {
            bmp_dis("photo/loading_pt.bmp",0,0);
            sleep(1);
            return ;
        }
        else if(p_fx.x==3)//左滑
        {
            //先判断是否为最后张
            if(flag_pt == 5)
            {
                bmp_dis("photo/last_pt.bmp",400,280);
                sleep(1);
            }
            else
                flag_pt++;//下一张图
        }
        else if(p_fx.x==4)//右滑
        {
            //先判断是否为第一张
            if(flag_pt == 1)
            {
                bmp_dis("photo/first_pt.bmp",400,280);
                sleep(1);
            }
            else
                flag_pt--;//上一张图
        }
    }
}