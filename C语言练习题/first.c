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


