# 西邮Linux兴趣小组2021纳新面试题题解

> 感谢 [Zhilu](https://github.com/L33Z22L11) 重新录入题目原件。好人一生平安。

> 注:
> - 本题目仅作`西邮Linux兴趣小组`2021纳新面试题的有限参考。
> - 为节省版面本试题的程序源码中省略了`#include`指令。
> - 本试题中的程序源码仅用于考察C语言基础，不应当作为C语言代码风格的范例。
> - 题目难度与序号无关。
> - 所有题目均假设编译并运行`x86_64 GNU/Linux`环境。
> 
> Copyright © 2021 西邮Linux兴趣小组, All Rights Reserved.  
> 本试题使用采用 [知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议](http://creativecommons.org/licenses/by-nc-sa/4.0/) 进行许可。



## 1. 大小和长度竟然不是一个意思

> `sizeof()`和`strlen()`有什么异同之处？
> 
> 他们对于不同参数的结果有什么不同？请试举例子说明。

```c
int main(void) {
    char s[] = "I love Linux\0\0\0";
    int a = sizeof(s);
    int b = strlen(s);
    printf("%d %d\n", a, b);
}
```
## 2. 箱子的大小和装入物品的顺序有关

> `test1`和`test2`都含有：1个`short`、1个`int`、1个`double`，那么`sizeof(t1)`和`sizeof(t2)`是否相等呢？这是为什么呢？

```c
struct test1 {
    int a;
    short b;
    double c;
};
struct test2 {
    short b;
    int a;
    double c;
};
int main(void) {
    struct test1 t1;
    struct test2 t2;
    printf("sizeof(t1): %d\n", sizeof(t1));
    printf("sizeof(t2): %d\n", sizeof(t2));
}
```

## 3. 哦，又是函数
> 想必在高数老师的教导下大家十分熟悉函数这个概念。那么你了解计算机程序设计中的函数吗？请编写一个`func`函数，用来输出二维数组`arr`中每个元素的值。

```c
/*在这里补全func函数的定义*/
int main(void) {
    int arr[10][13];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 13; j++) {
            arr[i][j] = rand();
        }
    }
    func(arr);
}
```

## 4.就不能换个变量名吗？

> - 请结合下面的程序，简要谈谈`传值`和`传址`的区别。
> - 简要谈谈你对C语言中变量的生命周期的认识。

```c
int ver = 123;
void func1(int ver) {
    ver++;
    printf("ver = %d\n", ver);
}
void func2(int *pr) {
    *pr = 1234;
    printf("*pr = %d\n", *pr);
    pr = 5678;
    printf("ver = %d\n", ver);
}
int main() {
    int a = 0;
    int ver = 1025;
    for (int a = 3; a < 4; a++) {
        static int a = 5;
        printf("a = %d\n", a);
        a = ver;
        func1(ver);
        int ver = 7;
        printf("ver = %d\n", ver);
        func2(&ver);
    }
    printf("a = %d\tver = %d\n", a, ver);
}
```

## 5. 套娃真好玩！

> 请说明下面的程序是如何完成求和的？

```c
unsigned sum(unsigned n) { return n ? sum(n - 1) + n : 0; }
int main(void) { printf("%u\n", sum(100)); }
```

## 6. 算不对的算术

```c
void func(void) {
    short a = -2;
    unsigned int b = 1;
    b += a;
    int c = -1;
    unsigned short d = c * 256;
    c <<= 4;
    int e = 2;
    e = ~e | 6;
    d = (d & 0xff) + 0x2022;
    printf("a=0x%hx\tb=0x%x\td=0x%hx\te=0x%x\n", a, b, d, e);
    printf("c=Ox%hhx\t\n", (signed char)c);
}
```
## 7. 指针和数组的恩怨情仇

```c
int main(void) {
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int(*b)[3] = a;
    ++b;
    b[1][1] = 10;
    int *ptr = (int *)(&a + 1);
    printf("%d %d %d \n", a[2][1], **(a + 1), *(ptr - 1));
}
```

## 8. 移形换位之术

> 下面有`a`、`b`、`c`三个变量和4个相似的函数。
> - 你能说出使用这三个变量的值或地址作为参数分别调用这5个函数，在语法上是否正确吗？
> - 请找出下面的代码中的错误。
> - `const int`和`int const`是否有区别？如果有区别，请谈谈他们的区别。
> - `const int *`和`int const *`是否有区别？如果有区别，请谈谈他们的区别。

```c
int a = 1;
int const b = 2;
const int c = 3;
void funco(int n) {
    n += 1;
    n = a;
}
void func1(int *n) {
    *n += 1;
    n = &a;
}
void func2(const int *n) {
    *n += 1;
    n = &a;
}
void func3(int *const n) {
    *n += 1;
    n = &a;
}
void func4(const int *const n) {
    *n += 1;
    n = &a;
}
```

## 9. 听说翻转字母大小写不影响英文的阅读？

> 请编写`convert`函数用来将作为参数的字符串中的大写字母转换为小写字母，将小写字母转换为大写字母。返回转换完成得到的新字符串。
> 

```c
char *convert(const char *s);
int main(void) {
    char *str = "XiyouLinux Group 2022";
    char *temp = convert(str);
    puts(temp);
}
```

## 10. 交换礼物的方式

> - 请判断下面的三种`Swap`的正误，分别分析他们的优缺点。
> - 你知道这里的`do {...} while(0)`的作用吗？
> - 你还有其他的方式实现`Swap`功能吗？

```c
#define Swap1(a, b, t)   \
    do {                 \
        t = a;           \
        a = b;           \
        b = t;           \
    } while (0)
#define Swap2(a, b)      \
    do {                 \
        int t = a;       \
        a = b;           \
        b = t;           \
    } while (0)
void Swap3(int a, int b) {
    int t = a;
    a = b;
    b = t;
}
```

## 11. 据说有个东西叫参数

> 你知道`argc`和`argv`的含义吗？请解释下面的程序。你能在不使用`argc`的前提下，完成对`argv`的遍历吗？

```c
int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
}
```

## 12. 人去楼空

> 这段代码有是否存在错误？谈一谈静态变量与其他变量的异同。

```c
int *func1(void) {
    static int n = 0;
    n = 1;
    return &n;
}
int *func2(void) {
    int *p = (int *)malloc(sizeof(int));
    *p = 3;
    return p;
}
int *func3(void) {
    int n = 4;
    return &n;
}
int main(void) {
    *func1() = 4;
    *func2() = 5;
    *func3() = 6;
}
```

## 13. 奇怪的输出

```c
int main(void) {
    int data[] = {0x636c6557, 0x20656d6f, 0x78206f74,
                  0x756f7969, 0x6e694c20, 0x67207875,
                  0x70756f72, 0x32303220, 0x00000a31};
    puts((const char*)data);
}
```

## 14. 请谈谈对从「C语言文件到可执行文件」的过程的理解

## 15. (选做) 堆和栈

> 你了解程序中的栈和堆吗？它们在使用上有什么区别呢？请简要说明。

## 16. (选做) 多文件

> 一个程序在不使用任何头文件的情况下，如何使用另一个文件中的函数。

## 17. (选做) `GNU/Linux`与文件

> - 你知道如何在 `GNU/Linux`下如何使用命令行创建文件与文件夹吗？
> - 你知道`GNU/Linux`下的命令ls 的每一列的含义吗？
> - 你知道`GNU/Linux`下文件的访问时间、修改时间、创建时间如何查看吗？并简单说说他们的区别。

> 恭喜你做完了整套面试题，快来参加西邮Linux兴趣小组的面试吧！
> 
> 西邮 Linux兴趣小组面试时间：  
> 2021年10月25日至2021年10月31日晚8点。  
> 听说面试来的早一点更能获得学长学姐的好感哦。
>   
> 我们在FZ103等你！
