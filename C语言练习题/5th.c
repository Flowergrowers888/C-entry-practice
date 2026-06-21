//五张百元换成等值50、20、10、5的小钞票，每种至少一张，输出所有可能，程序应适当考虑减少重复次数
#include <stdio.h>

int a,b,c,d;
num=0;
int main()
{
    for (a=1;a<10;a++)
{
    for (b=1;  b< 22; b++)
    {
        for (c = 1; c < 43; c++)
        {
            for (d = 1; d < 85; d++)
            {
                if (a*50+b*20+c*10+d*5==500)
                {
                    printf("%d %d %d %d\n",a,b,c,d);
                    num++;
                }
                
            }
            
        }
        
    }
    
}
    return printf("总共次数：%d\n",num);
}


