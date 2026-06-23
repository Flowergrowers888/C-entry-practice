//随机产生N个三位自然数输出，然后输出其中同时是3 5 7的倍数的数（设N为100）
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[100];
    srand(time(NULL));
    for(int i=0;i<100;i++)
    {
        a[i]=rand()%900+100;
        printf("%d\n",a[i]);
        if(a[i]%3==0&&a[i]%5==0&&a[i]%7==0)
        {
            printf("此数符合要求%d\n",a[i]);
        }
    } 
    return 0;
}