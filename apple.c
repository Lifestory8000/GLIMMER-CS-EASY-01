//如果你想存放单词 “apple”，使用一个char类型的字符变量能实现吗？尝试编程验
// 证你的想法，并思考正确的存储方式应该是什么？
#include <stdio.h>
int main(void)
{
    char name[20];
    strcpy(name, 20, "apple");
    printf("%s", name);



    return 0;
}