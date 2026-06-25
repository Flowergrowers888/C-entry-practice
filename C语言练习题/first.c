#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//bool data(int x);(21题)

int main()
{
/*1.
//逆向输出一个输入的不超过五位数的正整数
//两种方法：数字转字符串逆序输出转数字(考虑5.00为整数但是不能转字符串逆序）；利用取整符号获得参数值再输出。能力有限暂时选第二种
#include <stdio.h>
int main()
{
    int num,rear=0;
    printf("请输入一个不超过五位数的正整数：");
    scanf("%d",&num);//获取输入值
    if(num>0&&num<=99999) //排除输入值不为正整数以及超过五位数的情况
    {
    while (num!=0)
    {
    rear=rear*10+num%10;
    num=num/10;
    }

    }
    else
    {
    printf("输入不合法\n");
    return 0;
    }
    printf("逆序结果为：%d\n",rear);
    return 0;
}


3.
#include <stdio.h>
//从终端读入不超过5个数据进入数组，统计正数的个数并输出所有正数的和
int main()
{
    int arr[5];
    int num=0;
    int sum=0;
    //输入
    for (int i = 0;i < 5;i ++)
    {
        scanf("%d",&arr[i]);
    }
    //判断求和
    for (int i=0;i<5;i++)
    {
        if (arr[i]>0)
        {
            sum+=arr[i];
           // printf("%d",sum);
            num++;
        }
        
        
    }
    printf("%d\n",sum);
    printf("%d\n",num);
    return 0;
}
//过程中出现错误：1.“；”经常丢；2.printf和scanf%和d的顺序以及printf中的\n经常忘掉；3.未声明变量（尤其是i）；
//4.变量未初始化；5.新文件的头文件要导入；6.拼写错误



5.
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


8.
//输入1~5的数字，打印输出对应英文单词
#include <stdio.h>
#include <stdbool.h>
int main(){
char arr[][10]={"","one","two","three","four","five"};
int i;
while (i<=5)
{
    scanf("%d",&i);
    char(*p)[10]=arr;
    printf("%s\n",*(p+i));
}
return printf("输入不合法");

}

11.

用自然语言描述下列程序：
1.设置环境
2.定义变量i flag 和password，并令flag=0，i=0
3.用户回答口令，将其赋予password
4.正确则返回flag=1，转6，否则转5
5.回答三次口令了吗？没有则i加1，转3否则转6
6.根据flag的值输出结果

#include <stdio.h>
#include <string.h>
int main()
{
    char password[15];
    for(int i=0;i<3;i++)
    {
        scanf("%s", password);
        if (strcmp(password, "abcdef")==0)
    {
        int flag=1;
        printf("口令正确\n");
        return 0;
    }
        else
        {
            int flag=0;
            i==2 ? printf("已超三次\n"):printf("请继续输入\n");
        }
    }
    return 0;
    //flag并未使用，只作为标志，运行会有问题但不报错，删掉也无妨
}

12.
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

15.
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

18.
//输入一行字母统计其中大小写共多少个
#include <stdio.h>
int main(){
    char arr[100];
    scanf("%s",arr);
    int a=0,i=0,b=0,c=0;//字母个数,数组下标，大写个数，小写个数
    while(arr[i]!='\0')
    {
        if ((((arr[i]>=65)&&(arr[i]<=90)))||(((arr[i]>=97)&&(arr[i]<=122))))//ascii码大写65-90；小写97-122
        {
            a++;
            if ((arr[i]>=97)&&(arr[i]<=122))
        {
            c++;

        }        
            if((arr[i]>=65)&&(arr[i]<=90))
        {
            b++;
        }
        
        }

        i++;//博主利用断点进行调试，a变量没必要，最后返回b+c即可,且第一个逻辑判断加括号太多
    }

printf("总字母数%d\n大写字母数%d\n小写字母数%d\n",a,b,c);
return 0;
}
*/
//21.要求找出三位自然数中的所有素数，用自定义函数data(x)判断X是否为素数
// int num=0;

// for(int i=100;i<=999;i++)
// {
//     if(data(i)!=0)
//     {
//         num++;
//         printf("%d\n",i);
//     }
// }
// printf("总共有%d个素数\n",num);
// return 0;
// }

// //函数定义
// bool data(int x)
// {
//     for(int i=2;i<x;i++)
//     {
//         if(x%i==0)
//         {
//             return 0;
//             break;
//         }
//     }
//     return 1;
// }

}