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