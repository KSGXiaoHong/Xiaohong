#include"bmp.h"

//初始化bmp，返回bmp的描述符
static int Bmp_Init(const char* pathname)
{
    //打开文件
    int fd_bmp = open(pathname,O_RDONLY);
    if(fd_bmp == -1)
    {
        perror("not bmp");
        return fd_bmp;
    }
    //从文件头读两个字节
    char buf[2] = {0};
    read(fd_bmp,buf,2);
    //判断为bmp图片
    if(buf[0] == 0x42 && buf[1] == 0x4d)
    {
        return fd_bmp;
    }
}

//写入像素数组的赖子数
static int lz = 0;
//传入bmp的描述符，读取图片信息，返回指针p,读到的数据\
将长宽色深信息读到whd中
static char* Read_bmp(int fd_bmp,int* w,int* h,short* d)
{
    //光标到宽度的地址
    lseek(fd_bmp,0x12,SEEK_SET);
    //读到的宽度给w
    read(fd_bmp,w,4);
    //宽度读完后，紧接就是高度h
    read(fd_bmp,h,4);
    //偏移到色深的地址
    lseek(fd_bmp,0x1c,SEEK_SET);
    //读取色深24/32
    read(fd_bmp,d,2);
    //计算像素数组一行的大小,宽度乘色深
    unsigned int line_size = abs(*w)*(*d)/8;
    unsigned int  laizi = 0;
    //需要对齐，如果不够四位就补个大小
    if(line_size % 4 !=0)
    {
        //要补的大小就是4减去已有大小
        laizi = 4-line_size%4;
    }
    //实际一行大小需要加上赖子
    line_size = line_size + laizi;
    //像素数组大小需要再乘高度
    unsigned long bmp_arr = line_size*abs(*h);
    
    //申请一块大小为bmp_arr空间用来保存读到的数据
    char* p = (char*)malloc(bmp_arr);
    lseek(fd_bmp,54,SEEK_SET);
    read(fd_bmp,p,bmp_arr);
    lz = laizi; 
    return p;
}

//将图片信息写入到LCD，bmp中为bgra，lcd为argb，需要重新组合\
传入长宽色深用来判断，传入的参数为像素数组p,宽k，高h，色深d，位置x,y
static void Write_bmp(char* p,int w,int h,short d,int x,int y)
{
    int color;//重新组合后的像素点颜色
    unsigned char a,r,g,b;
    int id = 0;//像素数组下标便宜
    int real_h = abs(h);
    int real_w = abs(w);
    for(int i = 0; i < real_h; i++)//遍历行，共h行
    {
        //遍历列
        for(int j = 0; j < real_w; j++)
        {
            b = p[id++];
            g = p[id++];
            r = p[id++];
            if(d==32)
                a=p[id++];
            else
                a=0;
            color = (a<<24)|(r<<16)|(g<<8)|b;
            // 计算显示坐标（BMP是倒序存储）
            int disp_x = x + j;
            int disp_y = y + (real_h - 1 - i);  // Y坐标翻转
            
            Display_point(disp_x, disp_y, color);
        }
        id+=lz;
        //printf("lz=%d\n",lz);
    }
}

//指定位置显示指定图片的函数\
路径、坐标
void bmp_dis(char* pathname,int x,int y)
{
    int fd_lcd = Lcd_Init();
    int fd_bmp = Bmp_Init(pathname);
    if(fd_bmp == -1)
    {
        return;
    }
    int w,h;
    short d;
    char* p = Read_bmp(fd_bmp,&w,&h,&d);
    Write_bmp(p,w,h,d,x,y);
    Free_bmp(p,fd_bmp);
    Lcd_free(fd_lcd);
}

//关闭bmp文件
static void Free_bmp(char* p,int fd_bmp)
{
    free(p);
    close(fd_bmp);
}
