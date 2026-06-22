//输入正整数x，定义逆数y与中间变量digit
#include <stdio.h>
int digit=0,x=0,y=0;
int main()
{
    printf("请输入一个正整数\n");
    scanf("%d",&x);
    while (x!=0)
    {
        digit=x%10;
        y=y*10+digit;
        x=x/10;
    }
    printf("逆数为%d\n",y);
    return 0;
}