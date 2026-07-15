#include <graphics.h>
#include <stdio.h>

int main(){
    //创建界面
    initgraph(600,500);

    /*
    // //插入背景图，贴图三部曲（定义变量，赋值，显示输出）
    // IMAGE img;//定义
    // loadimage(&img,"C:/Users/Gaius Julius Caesar/Downloads/bk.jpg");//加载
    // putimage(0,0,&img);//贴图，前俩参数代表x，y图片位置，第三个就是显示图片的变量
    //loadimage如果定义为空则默认直接加载到初始化图形中*/
    
    loadimage(NULL,"C:/Users/Gaius Julius Caesar/Downloads/bk.jpg");

    setlinecolor(BLACK);//设置线条颜色
    //画线 两点坐标  棋盘 500*500  每格25*25
    
    for (int i=0;i<21;i++){
        
        line(0,25*i,500,25*i);
        line(25*i,0,25*i,500);
        }
    
   
    //卡屏
    getchar();
    return 0;
}
