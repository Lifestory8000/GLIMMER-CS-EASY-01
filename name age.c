#include <stdio.h>
int main(void)
{
    int i;
    int a=1;
    for(i=0; a==1; i++){
    printf("请输入您的姓名与年龄：\n");
    int age;
    char name[40];
    scanf_s("%s", &name);
    scanf_s("%d", &age);
    printf("所以您叫%s,今年%d岁,对吗?\n", name, age);
    printf("若您想继续输入您的姓名和年龄，请输入\"1\"以继续\n");
    scanf_s("%d", &a);



                    }
        printf("您一共进行了%d次输入\n", i);
        return 0;
    




return 0;
}