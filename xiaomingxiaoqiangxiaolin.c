#include <stdio.h>
#include <stdlib.h>
int add(int a, int b, int c) 
{
    return a + b + c;
}
int x(int a)
{
    return a*a;
}
int average(int a, int b, int c)
{
    return (a + b + c)/3;
}
int dean(int a, int b)
{
    return 3*a-b/3;
}
int conf(int a, int b, int c, int d)
{
    return ((d - a) * (d - a) + (d - b) * (d - b) + (d - c) * (d - c)) / 3;
}
int check(int a)
{
    if (a > 0)
        return 1;
    else if (a < 0)
        return -1;
    else
        return 0;
}
int peak(int a, int b)
{
    if (a >= b)
        return 1;
    else 
        return -1;
}
void rank(int a,int b,int c)
{
    printf("a>b>c\n");

}
int main(void)
{
    int x1, x2, x3;
    int y1, y2, y3;
    int z1, z2, z3;


    printf("请输入小明的三项成绩(顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &x1, &x2, &x3);
    printf("请输入小强的三项成绩(顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &y1, &y2, &y3);
    printf("请输入小林的三项成绩(顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &z1, &z2, &z3);
     int p1 =average(x1, x2, x3);
     int f1 =conf(x1, x2, x3, p1);
     int zh1 = dean(p1, f1);

     int p2 =average(y1, y2, y3);
     int f2 =conf(y1, y2, y3, p2);
     int zh2 = dean(p2, f2);

     int p3 =average(z1, z2, z3);
     int f3 =conf(z1, z2, z3, p3);
     int zh3 = dean(p3, f3);
    int a, b, c;
    int xiaoming=-(peak(zh1, zh2)+peak(zh1, zh3))/2+1;
    int xiaoqiang=-(peak(zh2, zh1)+peak(zh2, zh3))/2+1;
    int xiaolin=-(peak(zh3, zh2)+peak(zh3, zh1))/2+1;
    char *ranking[3]={NULL, NULL, NULL};//这个没学过，咨询的ai

    for(int i=0; i<=2; i++){
        if(xiaoming==i){
            ranking[i] = "小明";
        }
        if(xiaoqiang==i){
            ranking[i] = "小强";
        }
        if(xiaolin==i){
            ranking[i] = "小林";
        }

    }
    for (int i = 0; i < 3; i++) {
        printf("%s>", ranking[i]);
    }
    




    


    return 0;//部分使用AI工具检查报错
}