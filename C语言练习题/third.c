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
