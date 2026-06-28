#include <easyx.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    // 创建窗口 宽640 高480
    initgraph(640, 480);

    // 1. 画线 起点(50,50) 终点(300,200) 红色
    setlinecolor(RED);
    line(50, 50, 300, 200);

    // 2. 空心圆 圆心(400,150) 半径80 蓝色
    setlinecolor(BLUE);
    circle(400, 150, 80);

    // 3. 实心矩形 左上角(50,250) 右下角(250,400) 绿色填充
    setfillcolor(GREEN);
    fillrectangle(50, 250, 250, 400);

    // 文字输出
    settextcolor(WHITE);
    TCHAR s[] = _T("EasyX 基础图形实验");
    outtextxy(320, 300, s);

    // 按任意键关闭窗口
    getch();
    closegraph();
    return 0;
}
