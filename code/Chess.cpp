#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")//多媒体接口
int flag=0;//黑白标志
int ChessMap[21][21]={0};//记录棋子数组用来判断胜利,这里21不是20是因为脏数据导致之前的记录会弹对话框“error station”

int judge(int ChessX,int ChessY){//游戏判定
    int temp=2-flag%2;//判定标志黑1，白2
    //五子横线
    for(int i=ChessX-4,j=ChessY;i<=ChessX;i++){
        if(i>=1&&i<=15&&temp==ChessMap[i][j]&&temp==ChessMap[i+1][j]&&temp==ChessMap[i+2][j]
            &&temp==ChessMap[i+3][j]&&temp==ChessMap[i+4][j]){
                return 1;
            }
    }
    //五子竖线
    for(int i=ChessX,j=ChessY-4;j<=ChessY;j++){
        if(j>=1&&j<=15&&temp==ChessMap[i][j]&&temp==ChessMap[i][j+1]&&temp==ChessMap[i][j+2]
            &&temp==ChessMap[i][j+3]&&temp==ChessMap[i][j+4]){
                return 1;
            }
    }   
    //左右斜线
    for(int i=ChessX-4,j=ChessY-4;i<=ChessX,j<=ChessY;i++,j++){
        if(i>=1&&i<=15&&j>=1&&j<=15&&temp==ChessMap[i][j]&&temp==ChessMap[i+1][j+1]&&temp==ChessMap[i+2][j+2]
            &&temp==ChessMap[i+3][j+3]&&temp==ChessMap[i+4][j+4]){
                return 1;
            }
    }
    //右左斜线
    for(int i=ChessX-4,j=ChessY+4;i<=ChessX,j>=ChessY;i++,j--){
        if(i>=1&&i<=15&&j>=1&&j<=15&&temp==ChessMap[i][j]&&temp==ChessMap[i+1][j-1]&&temp==ChessMap[i+2][j-2]
            &&temp==ChessMap[i+3][j-3]&&temp==ChessMap[i+4][j-4]){
                return 1;
            }
    }
    return 0;
}

//初始化游戏
void initGame(){
    initgraph(600,500,SHOWCONSOLE);////创建界面
    loadimage(NULL,"C:/Users/Gaius Julius Caesar/Downloads/bk.jpg");//加载图片默认到原点

    setlinecolor(BLACK);//线条颜色
    for(int i=0;i<20;i++){//绘制棋盘
        line(0,i*25,500,25*i);
        line(25*i,0,25*i,500);
    }
    setlinestyle(PS_SOLID,2);//线条风格，宽度为2
    line(500,0,500,500);//最后一条竖线

    setbkmode(0);//设置透明背景
    settextcolor(BLACK);//设置文字颜色
    outtextxy(520,20,"P1:Black");//输出玩家信息
    outtextxy(520,40,"P2:White");
}

//开始游戏
void PlayGame(){
        //鼠标信息
    MOUSEMSG Msg;//定义变量
    HWND hwnd=GetHWnd();//获取窗口句柄
    int ChessX=0,ChessY=0;//棋子坐标索引
    //int MapX=0,MapY=0;//记录棋盘地图下标，和教程不同，就是ChessX和ChessY
    while(1){
        Msg=GetMouseMsg();//获取鼠标信息
        ChessX=(Msg.x+12.5)/25;//此处只是索引，不能在此处*25原因不是整数而是浮点数，可以取整
        ChessY=(Msg.y+12.5)/25;
        
        printf("ChessX=%d,ChessY=%d\n",ChessX*25,ChessY*25);
        /*       
        if(Msg.uMsg==WM_LBUTTONDOWN){
            printf("X:%d,Y:%d\n",Msg.x,Msg.y);
        }
        else if(Msg.uMsg==WM_RBUTTONDOWN){
            printf("R");
        }
        for(int i=1;i<20;i++){//行  找Y
            for(int j=1;j<20;j++){//列  找X
                if(abs(Msg.x-j*25)<12&&abs(Msg.y-i*25)<25){//abs为取绝对值，最终要落到交点为圆心的圆范围
                    ChessX=j*25;
                    ChessY=i*25;
                }
            }
        }
        printf("ChessX=%d,ChessY=%d\n",ChessX,ChessY);
        */
        if(Msg.uMsg==WM_LBUTTONDOWN){//判断左键按下绘制棋子   
            if(ChessMap[ChessX][ChessY]!=0){//错误位置
                MessageBox(hwnd,"Error Station","Chess",MB_OK);
                continue;
            }
            
            if(flag%2==0&&(ChessX*25!=0&&ChessX*25!=500&&ChessY*25!=0&&ChessY*25!=500)){//边界排除
                setfillcolor(BLACK);//黑色
                solidcircle(ChessX*25,ChessY*25,10);
                ChessMap[ChessX][ChessY]=1;//黑色标记为1
                flag++;
            }
            else if(flag%2==1&&(ChessX*25!=0&&ChessX*25!=500&&ChessY*25!=0&&ChessY*25!=500)){
                setfillcolor(WHITE);//白色
                solidcircle(ChessX*25,ChessY*25,10);
                ChessMap[ChessX][ChessY]=2;//白色标记为2
                flag++;
            }      
    }  
    
        if(judge(ChessX,ChessY)){
            if(1==flag%2){
                MessageBox(hwnd,"P1:Black win","Game Over",MB_OK);
                return;
            }
            else{
                MessageBox(hwnd,"P2:White win","Game Over",MB_OK);
                return;
            }
        }
}   
}
int main(){
    // mciSendString("open \"D:\\CloudMusic\\bgm.mp3\ ", NULL, 0, NULL);
    // mciSendString("play bgm repeat",NULL,0,NULL);音频播放失败

    initGame();

    PlayGame();

    // //卡屏
    // getchar();

    //关闭界面(有While可以取消卡屏)
    closegraph();
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