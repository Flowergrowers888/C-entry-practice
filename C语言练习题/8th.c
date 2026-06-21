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