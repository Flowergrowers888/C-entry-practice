#include <graphics.h>
#include <stdio.h>
//初始化游戏
void initGame(){
    initgraph(600,500);////创建界面
    loadimage(NULL,"C:/Users/Gaius Julius Caesar/Downloads/bk.jpg");//加载图片默认到原点

    setlinecolor(BLACK);//线条颜色
    for(int i=0;i<20;i++){//绘制棋盘
        line(0,i*25,500,25*i);
        line(25*i,0,25*i,500);
    }
    setlinestyle(PS_SOLID,2);//线条风格固态，宽度为2
    line(500,0,500,500);//最后一条竖线

    setbkmode(0);//设置透明背景
    settextcolor(BLACK);//设置文字颜色
    outtextxy(520,20,"P1:Black");//输出玩家信息
    outtextxy(520,40,"P2:White");
}
int main(){

    initGame();

    //07该到鼠标信息
    //卡屏
    getchar();
    return 0;
}

/*
    //创建界面
    initgraph(600,500);

  
    // //插入背景图，贴图三部曲（定义变量，赋值，显示输出）
    // IMAGE img;//定义
    // loadimage(&img,"C:/Users/Gaius Julius Caesar/Downloads/bk.jpg");//加载
    // putimage(0,0,&img);//贴图，前俩参数代表x，y图片位置，第三个就是显示图片的变量
    //loadimage如果定义为空则默认直接加载到初始化图形中
    loadimage(NULL,"C:/Users/Gaius Julius Caesar/Downloads/bk.jpg");

    setlinecolor(BLACK);//设置线条颜色
    //画线 两点坐标  棋盘 500*500  每格25*25
    
    for (int i=0;i<21;i++){
        
        line(0,25*i,500,25*i);
        line(25*i,0,25*i,500);
        }
    
    //插入文字
    //设置文字颜色及背景颜色为透明
    settextcolor(BLACK);
    setbkmode(0);
    //根据坐标插入文字
    outtextxy(520,30,"P1：Black");
    outtextxy(520,60,"P2：White");
*/