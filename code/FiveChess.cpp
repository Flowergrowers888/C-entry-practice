// //deepseek版本
// #include <graphics.h>
// #include <conio.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define N 20

// // ==================== 键盘宏定义 ====================
// #define UP 72
// #define DOWN 80
// #define LEFT 75
// #define RIGHT 77
// #define ESC 27
// #define ENTER 13
// #define W 119
// #define S 115
// #define A 97
// #define D 100
// #define SPACE 32
// #define Y 121
// #define N_ 110

// int i, j, key;
// struct Sor
// {
//     int x;
//     int y;                // x,y 表示当前光标的位置
//     int yes[N][N];        // 0 表示无棋子，1 表示白色棋子，2 表示黑色棋子
//     int kao;              // 1 表示白棋准备落子，2 表示黑棋准备落子
//     int ok;               // 1 表示白棋胜出，2 表示黑棋胜出
// } sor;

// // ==================== 棋盘绘制 ====================
// void drawqp(void)
// {
//     setcolor(3);
//     for (int i = 50; i <= (N - 1) * 20 + 30; i += 20)
//     {
//         line(50, i, (N - 1) * 20 + 30, i);
//         line(i, 50, i, (N - 1) * 20 + 30);
//     }
//     setcolor(11);
//     for (int i = 1; i < 3; i++)
//     {
//         circle((N - 1) * 10 + 40, (N - 1) * 10 + 40, i);
//         circle(130, 130, i);
//         circle(130, 330, i);
//         circle(330, 130, i);
//         circle(330, 330, i);
//     }
// }

// // ==================== 操作提示 ====================
// void clew(void)
// {
//     setcolor(15);
//     settextstyle(16, 0, "宋体");
//     outtextxy(50, 20, "1P: 方向键移动  Enter落子      2P: WASD移动  Space落子");
//     outtextxy(50, 460, "ESC退出  落子后显示坐标");
// }

// // ==================== 显示标题 ====================
// void showTitle(void)
// {
//     setcolor(13);
//     settextstyle(36, 0, "黑体");
//     outtextxy(460, 60, "五子棋");
// }

// // ==================== 显示光标 ====================
// void place(void)
// {
//     line(sor.x - 10, sor.y - 10, sor.x - 7, sor.y - 10);
//     line(sor.x - 10, sor.y - 10, sor.x - 10, sor.y - 7);
//     line(sor.x - 10, sor.y + 10, sor.x - 10, sor.y + 7);
//     line(sor.x - 10, sor.y + 10, sor.x - 7, sor.y + 10);
//     line(sor.x + 10, sor.y - 10, sor.x + 10, sor.y - 7);
//     line(sor.x + 10, sor.y - 10, sor.x + 7, sor.y - 10);
//     line(sor.x + 10, sor.y + 10, sor.x + 7, sor.y + 10);
//     line(sor.x + 10, sor.y + 10, sor.x + 10, sor.y + 7);
// }

// // ==================== 胜负判定 ====================
// void win(void)
// {
//     for (i = 1; i < N; i++)
//     {
//         for (j = 1; j < N; j++)
//         {
//             if (sor.yes[i][j] == 0)
//                 continue;

//             // 水平
//             if ((j + 4) < N && sor.yes[i][j] == sor.yes[i][j + 1] &&
//                 sor.yes[i][j + 1] == sor.yes[i][j + 2] &&
//                 sor.yes[i][j + 2] == sor.yes[i][j + 3] &&
//                 sor.yes[i][j + 3] == sor.yes[i][j + 4])
//             {
//                 sor.ok = sor.yes[i][j];
//                 return;
//             }
//             // 垂直
//             if ((i + 4) < N && sor.yes[i][j] == sor.yes[i + 1][j] &&
//                 sor.yes[i + 1][j] == sor.yes[i + 2][j] &&
//                 sor.yes[i + 2][j] == sor.yes[i + 3][j] &&
//                 sor.yes[i + 3][j] == sor.yes[i + 4][j])
//             {
//                 sor.ok = sor.yes[i][j];
//                 return;
//             }
//             // 主对角线
//             if ((i + 4) < N && (j + 4) < N &&
//                 sor.yes[i][j] == sor.yes[i + 1][j + 1] &&
//                 sor.yes[i + 1][j + 1] == sor.yes[i + 2][j + 2] &&
//                 sor.yes[i + 2][j + 2] == sor.yes[i + 3][j + 3] &&
//                 sor.yes[i + 3][j + 3] == sor.yes[i + 4][j + 4])
//             {
//                 sor.ok = sor.yes[i][j];
//                 return;
//             }
//             // 副对角线
//             if ((i + 4) < N && j > 4 &&
//                 sor.yes[i][j] == sor.yes[i + 1][j - 1] &&
//                 sor.yes[i + 1][j - 1] == sor.yes[i + 2][j - 2] &&
//                 sor.yes[i + 2][j - 2] == sor.yes[i + 3][j - 3] &&
//                 sor.yes[i + 3][j - 3] == sor.yes[i + 4][j - 4])
//             {
//                 sor.ok = sor.yes[i][j];
//                 return;
//             }
//         }
//     }
// }

// // ==================== 游戏结束画面 ====================
// void gameover(void)
// {
//     settextstyle(30, 0, "黑体");
//     if (sor.ok == 1)
//     {
//         setcolor(15);
//         outtextxy(460, 150, "白方");
//         setcolor(4);
//         outtextxy(540, 150, "获胜！");
//     }
//     else
//     {
//         setcolor(0);
//         outtextxy(460, 150, "黑方");
//         setcolor(4);
//         outtextxy(540, 150, "获胜！");
//     }
// }

// // ==================== 显示光标坐标 ====================
// void xandy(void)
// {
//     char str[30];
//     setfillcolor(7);
//     solidrectangle(50, 440, 220, 470);
//     setcolor(14);
//     settextstyle(20, 0, "宋体");
//     sprintf(str, "X:%d Y:%d", (sor.x - 30) / 20, (sor.y - 30) / 20);
//     outtextxy(60, 445, str);
// }

// // ==================== 游戏主逻辑 ====================
// void gameplay(void)
// {
//     for (i = 1; i < N; i++)
//         for (j = 1; j < N; j++)
//             sor.yes[i][j] = 0;
//     sor.kao = 1;
//     sor.ok = 0;
//     sor.x = (N - 1) * 10 + 40;
//     sor.y = (N - 1) * 10 + 40;

//     setcolor(15);
//     place();

//     while (1)
//     {
//         xandy();
//         key = getch();
//         if (key == ESC)
//             break;

//         // 白棋移动（方向键）
//         else if (key == UP && sor.y > 50 && sor.kao == 1)
//         {
//             setcolor(0);
//             place();
//             sor.y -= 20;
//         }
//         else if (key == DOWN && sor.y < (N - 1) * 20 + 30 && sor.kao == 1)
//         {
//             setcolor(0);
//             place();
//             sor.y += 20;
//         }
//         else if (key == LEFT && sor.x > 50 && sor.kao == 1)
//         {
//             setcolor(0);
//             place();
//             sor.x -= 20;
//         }
//         else if (key == RIGHT && sor.x < (N - 1) * 20 + 30 && sor.kao == 1)
//         {
//             setcolor(0);
//             place();
//             sor.x += 20;
//         }

//         // 黑棋移动（WASD）
//         else if ((key == W || key == 'w') && sor.y > 50 && sor.kao == 2)
//         {
//             setcolor(0);
//             place();
//             sor.y -= 20;
//         }
//         else if ((key == S || key == 's') && sor.y < (N - 1) * 20 + 30 && sor.kao == 2)
//         {
//             setcolor(0);
//             place();
//             sor.y += 20;
//         }
//         else if ((key == A || key == 'a') && sor.x > 50 && sor.kao == 2)
//         {
//             setcolor(0);
//             place();
//             sor.x -= 20;
//         }
//         else if ((key == D || key == 'd') && sor.x < (N - 1) * 20 + 30 && sor.kao == 2)
//         {
//             setcolor(0);
//             place();
//             sor.x += 20;
//         }

//         // 黑棋落子（Space）
//         else if (key == SPACE && sor.yes[(sor.x - 30) / 20][(sor.y - 30) / 20] == 0 && sor.kao == 2)
//         {
//             setcolor(13);
//             for (int k = 1; k <= 9; k++)
//             {
//                 circle(sor.x, sor.y, k);
//                 Sleep(20);
//             }
//             sor.yes[(sor.x - 30) / 20][(sor.y - 30) / 20] = 2;
//             sor.kao = 1;
//             win();
//             if (sor.ok != 0)
//             {
//                 gameover();
//                 break;
//             }
//         }

//         // 白棋落子（Enter）
//         else if (key == ENTER && sor.yes[(sor.x - 30) / 20][(sor.y - 30) / 20] == 0 && sor.kao == 1)
//         {
//             setcolor(15);
//             for (int k = 1; k <= 9; k++)
//             {
//                 circle(sor.x, sor.y, k);
//                 Sleep(20);
//             }
//             sor.yes[(sor.x - 30) / 20][(sor.y - 30) / 20] = 1;
//             sor.kao = 2;
//             win();
//             if (sor.ok != 0)
//             {
//                 gameover();
//                 break;
//             }
//         }
//         else
//             continue;

//         if (sor.ok != 0)
//             break;
//         if (sor.kao == 1)
//             setcolor(15);
//         else
//             setcolor(13);
//         place();
//     }
// }

// // ==================== 主函数 ====================
// int main()
// {
//     initgraph(640, 480);
//     srand((unsigned)time(NULL));

//     while (1)
//     {
//         setbkcolor(WHITE);
//         cleardevice();
//         clew();
//         drawqp();
//         setfillcolor(7);
//         solidrectangle(430, 50, 630, 410);
//         showTitle();
//         gameplay();

//         setcolor(15);
//         settextstyle(20, 0, "宋体");
//         outtextxy(230, 450, "CONTINUE(Y/N)?");

//         while (1)
//         {
//             key = getch();
//             if (key == Y || key == 'y')
//             {
//                 break;
//             }
//             else if (key == N_ || key == 'n')
//             {
//                 closegraph();
//                 return 0;
//             }
//             else if (key == ESC)
//             {
//                 closegraph();
//                 return 0;
//             }
//         }
//     }
// }

// #include <graphics.h>
// #include <stdio.h>

// int main(){
//     //创建界面
//     initgraph(500,500);
//     //插入背景图，贴图三部曲（定义变量，赋值，显示输出）
//     IMAGE img;//定义
//     loadimage(&img,"C:/Users/Gaius Julius Caesar/Downloads/bk.jpg");//加载，注此处未改设置和教程不同用了
//     putimage(0,0,&img);//贴图，前俩参数代表x，y图片位置，第三个就是显示图片的变量
//     //卡屏
//     getchar();
//     return 0;
// }
