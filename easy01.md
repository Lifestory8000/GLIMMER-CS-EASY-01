# <span style="color:#e74c3c">H</span><span style="color:#e67e22">e</span><span style="color:#f1c40f">l</span><span style="color:#2ecc71">l</span><span style="color:#1abc9c">o</span><span style="color:#3498db">,</span> <span style="color:#9b59b6">w</span><span style="color:#e84393">o</span><span style="color:#c0392b">r</span><span style="color:#2980b9">l</span><span style="color:#8e44ad">d</span>
# Part 1
### 1.什么是GCC，什么是MinGW？它的作用是什么？
- GCC的全称是<u>GNU Compiler Collection（GNU 编译器集合）</u>，它的作用是把``C语言``代码或者``C++``代码等等高级语言转化为电脑能直接执行的***可执行命令***之编译器
- MinGW之全称是``Minimalist GNU for Windows``,GCC一开始没法在``windows``上面用（面向``Linux``），所以MinGW应运而生，就是把GCC的作用挪到了windows系统之上，这样子产出的就是windows的可运行文件————**exe**
---
### 2.c_cpp_properties.json launch.json tasks.json这三个文件分别有什么作用？
- ``c_cpp_properties.json``这个文件的作用如下：可以为编辑器指明``gcc.exe``的方向，要是compilerPath指向了错误的gccexe方向，可能会导致编辑器找不到编译器而报错~~这个我没试过~~，与此同时，里面还有*智能提示模式*（是这么翻译吗？）``intelliSenseMode``可能负责了检验语法错误提示。``includePath``则指示了头文件该去哪里找。
-  ``launch.json``这个文件作用："type": "cppdbg"：指定了cppdbg为调试器。``"externalConsole": false``这一串则可以选择是外部终端还是内部终端（改成true变成外部），总而言之，它的工作是**调试**。
-  ``tasks.json``最后一个文件的作用是：``"command": "C:省略/gcc.exe"``这一段，指定要执行的编译器（gcc）。这个文件主要是起**编译**作用的，要是没有什么差池，就会成功生成对应的可执行命令exe文件。
### 3.为什么要在编译器内下载C语言的插件，插件的作用又是什么？
- 因为单纯地下载VScode事实上它是没有C语言的环境的（只有个编辑器的架子），就连运行``python``也要下载插件，如果没有插件其实该软件**看不懂C语言和python**。因此，下载插件的作用就是让VScode可以理解C语言，知道从哪里找像``stdio.h``这样的头文件。插件的作用，诸如：给函数以不同的颜色，还有自动补全这种高级功能，错误提示等等，插件也让它能够使用gcc这样的编译程序，把C语言转化为计算机看得懂的东西。

#### 下面我把题目中的launch给复制下来，并且直接在这上面完成每一步的批注
````
  {
    // 使⽤ IntelliSense 了解相关属性。
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387     "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc.exe - ⽣成和调试活动⽂件",  // 该调试任务的名字，启动调试时会在待选列表中显⽰
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",            "args": [],
            "stopAtEntry": false,  //是否要在main那里（程序入口）暂停一下，这里表示不暂停
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,  //是否使用外部终端运行，这里false是不使用，会在VScode内置的终端里运行
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\mingw64\\bin\\gdb.exe",  //指示gdb调试器的具体位置，否则不知道哪里调试
            "setupCommands": [
                {
                    "description": "为 gdb 启⽤整⻬打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: gcc.exe build active file"  // 调试前的预执⾏任务，这⾥的值是tasks.json⽂件中对应的编译任务，也就是调试前需要先编译
        }
    ]
}
````
#### hello，world截图附下
内部终端
<img src="assets/4c95e09f5c90424be019a98fc0e0973a.png" width="1801" height="851" alt="image">
外部终端

<img src="assets/3580ff1f08b874c20734f971cde147d1.png" width="1666" height="907" alt="image">
<u>github上传的是没有getchar和scanf的版本</u>

# Part 2
### 变量类型： 什么是变量的类型？它为什么重要？如果你想存放你的年龄（比如 18），应该选择哪种基本变量类型（如整数、浮点数）？如果你想存放单词 “apple”，使用一个char类型的字符变量能实现吗？尝试编程验证你的想法，并思考正确的存储方式应该是什么？
- 变量的类型就是给所有出现的变量整一个类别//有如``int float char``之类，它的作用很大，能让读者一目了然地了解某变量大概是什么以及起什么作用，它规定了变量的取值范围以及变量占用的内存大小，比如``float``就比``double``占用的内存大小更加小，运行速度也更快//年龄（18）一般使用``int``，但是如果想表示18.？岁则需要使用``float``//如果我想存放一个单词，我会用``char name[40]="apple";``来表示，然后转换说明用``%s``(这个需要整个c吗？)//
附上图片
<img src="assets/80f1d28132d2e93dc813531728c2e00b.png" width="1012" height="910" alt="image">

### 数组的起始与边界： 数组的第一个元素下标通常是从 0 还是 1 开始？访问数组元素时，下标超出其有效范围（例如，长度为 5 的数组访问 arr[5] 或 arr[-1]）会导致什么问题？为什么数组越界是一个常见的、危险的错误？
- 从0开始；因为你没有定义数组``arr[5]`` 或 ``arr[-1]``到底是什么，于是它会把系统里的垃圾数据等毫无意义的数据调出来；危险在于你无法通过报错得知自己调用了定义数组外的数据，这样可能会导致你计算机内部的某些数据被改变引发危险的崩溃（？）
### 流程控制 - 循环结构： 循环结构（如 for, while）是如何控制代码块重复执行的？请分别简述它们的基本结构。for 循环的初始化、条件判断和迭代部分各自的作用是什么？while 循环和 do…while 循环在首次执行条件判断上有何关键区别？尝试用两种不同的循环结构实现同一个任务（例如，计算 1 到 10 的和），体会它们的异同。
通过判断当前变量是否满足条件来执行，若否则终止执行，结构上``for(初始条件，可执行条件，迭代任务)``，``while(条件)``，初始条件在之前已经规定好了；初始化：确定初始变量   条件判断：每次执行完成后返回到最初检查是否符合条件，若是则继续执行 迭代：每次执行完后，条件判断之前会让变量做出变化；dowhile相比while来说特点是一定会执行一次再去查看是否符合while（里面的执行要求），而while则会先判断是否符合执行要求，不会**必有一执**；
截图附下
``while``
<img src="assets/ceadf527fd21d447838fb9b197560721.png" width="982" height="870" alt="image">
``do while``
<img src="assets/3f462bfecd8bc5bea0a9b6b81037c8bf.png" width="735" height="903" alt="image">(while后面少了个分号，现在已经补上)

### 流程控制 - 逻辑表达式：在条件判断（如 if, else if）和循环条件中使用的逻辑表达式（如age > 18 && score >= 60）与算术表达式（如a + b * c）有何本质区别(尝试从运算对象和运算结果分析)？运算逻辑符&&,||,!的含义分别是什么？尝试编写包含多个条件的逻辑表达式并预测其输出结果。
- 逻辑表达式是判断真假（1/0，是否执行）运算的对象是布尔值，结果是1/0，而算术表达式常常用于赋值，迭代变量之类，运算对象是数值，运算结果还是数值；&&类似于``python``里的and~~这里用python只是因为高中讲过基础的python~~,只有两者（多者）全对是才判定为真，||为或，即只要有一者正确即判为真，!为非，即输出对象的反面（真为假，假为真）
截图附下
<img src="assets/6cb1dcca25d9e88996d68be8f77bc4c3.png" width="1145" height="941" alt="image">

编程题截图如下(输入姓名与年龄)
<img src="assets/d2980ec8c6676d76156f53267bc4f0e9.png" width="1162" height="967" alt="image">
# Part3
代码附下
````
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
````
#### 猜猜下列函数的效果(你可以自行运行，看看结果怎么样)，尝试从值传递的角度入手，说说为什么会这样
````
#include <stdio.h>
void swap(int a, int b){
  int temp = a;
  a = b;
  b = temp;
}

int main(){
  int a = 10;
  int b = 20;
  swap(a, b);
  printf("%d, %d", a, b);
  return 0;
}
````
- 我猜会交换ab的值（但是不会有任何输出，因为没有返回值）。但是事实上**转移并没有发生**
- 于是我再调整了一下
````
#include <stdio.h>
void swap(int a, int b){
  int temp = a;
  a = b;
  b = temp;
  printf("%d, %d\n", a, b);
}

int main(){
  int a = 10;
  int b = 20;
  swap(a, b);
  int temp=0;
  printf("%d, %d\n", a, b);
  return 0;
}
````
- 发现输出的值是不一样的？难道定义swap中的ab其实是虚构的值？实际上是不存在的？但是如果是虚构的值？为什么会输出``20 10``呢?难道是因为使用的是两套ab，它们初始的时候都被定义成10,20；然后swap使用的是一套，printf使用的是另外一套？
- 通过学习了解到*C 语言做了一件事：把 main 里 a 和 b 的值，复制一份，传给 swap*，swap中的ab是副本，交换了副本，但是main中的ab没有变。当程序进行到swap这一步的时候，系统没有把真正的a，b传过去，只是**把ab的值给传过去了**，所以如果想真正地更改ab'的值，则需要输入ab的**地址**，``int *a``用指针表示a的地址。
#### 怎么修改函数才能真正实现值交换的效果呢？请你初步了解指针。我们会在下一个题中系统学习指针和初步的数据结构。
- 如上，已经初步了解。





















