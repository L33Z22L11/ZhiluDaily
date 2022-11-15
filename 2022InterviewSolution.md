# 西邮Linux兴趣小组2022纳新面试题题解

> 感谢 [Zhilu](https://github.com/L33Z22L11) 重新录入题目原件。好人一生平安。

> - 本题目只作为`Xiyou Linux兴趣小组`2022纳新面试的有限参考。
> - 为节省版面，本试题的程序源码省去了`#include`指令。
> - 本试题中的程序源码仅用于考察C语言基础，不应当作为C语言「代码风格」的范例。
> - 题目难度随机排列。
>  所有题目编译并运行于`x86_64 GNU/Linux`环境。
> 
> 学长寄语：
> 长期以来，西邮Linux兴趣小组的面试题以难度之高名扬西邮校内。我们作为出题人也清楚的知道这份试题略有难度。请别担心。**若有同学能完成一半的题目，就已经十分优秀。** 其次，相比于题目的答案，我们对你的思路和过程更感兴趣，或许你的答案略有瑕疵，但你正确的思路和对知识的理解足以为你赢得绝大多数的分数。最后，做题的过程也是学习和成长的过程，相信本试题对你更加熟悉的掌握C语言的一定有所帮助。祝你好运。我们FZ103见！
> 
> Copyright © 2022 西邮Linux兴趣小组, All Rights Reserved.  
> 本试题使用采用 [知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议](http://creativecommons.org/licenses/by-nc-sa/4.0/) 进行许可。


## 0. 我的计算器坏了？！

> `2^10=1024`对应于十进制的4位，那么`2^10000`对应于十进制的多少位呢?

## 1. printf还能这么玩？

> 尝试着解释程序的输出。

```c
int main(void) {
    if ((3 + 2 < 2) > (3 + 2 > 2))
        printf("Welcome to Xiyou Linux Group\n");
    else
        printf("%d\n", printf("Xiyou Linux Group - 2%d", printf("")));
}
```

## 2. 你好你好你好呀！

> - 程序的输出有点奇怪，请尝试解释一下程序的输出吧。
> - 请谈谈对`sizeof()`及`strlen()`的理解吧。

```c
int main(void) {
    char p0[] = "Hello,Linux";
    char *p1 = "Hello,Linux";
    char p2[11] = "Hello,Linux";
    printf("p0==p1: %d, strcmp(p0,p2): %d\n", p0 == p1, strcmp(p0, p2));
    printf("sizeof(p0): %zu, sizeof(p1): %zu, sizeof(*p2): %zu \n",
           sizeof(p0), sizeof(p1), sizeof(*p2));
    printf("strlen(p0): %zu, strlen(p1): %zu\n", strlen(p0), strlen(p1));
}
```
字符数组  
字符指针

`p0`、`p1`地址不同，`strcmp()`会从`p2`开始读到内存中的下一个`'\0'`

`sizeof(p0)`是字符数组(含末尾`'\0'`)的大小，`sizeof(p1)`是指针地址的大小，`sizeof(*p2)`是字符`'H'`的大小

## 3. 换个变量名不行吗？

> 请结合本题，分别谈谈你对C语言中「全局变量」和「局部变量」的「生命周期」理解。

```c
int a = 3;
void test() {
    int a = 1;
    a += 1;
    {
        int a = a + 1;
        printf("a = %d\n", a);
    }
    printf("a = %d\n", a);
}
int main(void) {
    test();
    printf("a= %d\n", a);
}
```
代码块作用域内的局部变量a

## 4. 内存对不齐

> `union`与`struct`各有什么特点呢，你了解他们的内存分配模式吗。

```c
typedef union {
    long l;
    int i[5];
    char c;
} UNION;
typedef struct {
    int like;
    UNION coin;
    double collect;
} STRUCT;
int main(void) {
    printf("sizeof (UNION) = %zu\n", sizeof(UNION)); 
    printf("sizeof (STRUCT) = %zu\n", sizeof(STRUCT));
}
```
```
union:
    sizeof (long) = 4
    sizeof (int[5]) = 20
    sizeof (char) = 1
```
`union`中的所有数据成员共享同一个存储空间，其在内存中的大小为最大成员的大小。

```
struct:
    sizeof (int) = 4
    sizeof (UNION) = 20
    sizeof (double) = 8
```
`struct`中的每个数据成员享有独立的存储空间，其在内存中的大小为所有成员的大小之和。

## 5. Bitwise

> - 请使用纸笔推导出程序的输出结果。
> - 请谈谈你对位运算的理解。

```c
int main(void) {
    unsigned char a = 4 | 7;
    a <<= 3;
    unsigned char b = 5 & 7;
    b >>= 3;
    unsigned char c = 6 ^ 7;
    c = ~c;
    unsigned short d = (a ^ c) << 3;
    signed char e = -63;
    e <<= 2;
    printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, (char)d);
    printf("e: %#x\n", e);
}
```
```
a = 0000 0010 | 0000 0111 = 0000 0111 => 7
a = 0011 1000 = 28
b = 0000 0101 & 0000 0111 = 0000 0111 => 7
b = 0000 0000 = 0
c = 0000 0110 ^ 0000 0111 = 0000 0001 => 1
c = 1111 1110 => (unsigned) 254
补码存储，按位取反
d = (0011 1000 ^ 1111 1110) << 3
  = 1100 0110 << 3
  = 110 0011 0000 => 1584
e = 1100 0001
e = 0000 0100
(char)d = 0011 0000 => 48
```

## 6. 英译汉

> 请说说下面数据类型的含义，谈谈`const`的作用。
> 1. `char *const p`。
> 2. `char const *p`。
> 3. `const char *p`。

## 7. 汉译英

> 请用变量`p`给出下面的定义:
> 1. 含有10个指向`int`的指针的数组。
> 2. 指向含有10个`int`数组的指针。
> 3. 含有3个「指向函数的指针」的数组，被指向的函数有1个`int`参数并返回`int`。

## 8. 混乱中建立秩序

> 你对排序算法了解多少呢?  
> 请谈谈你所了解的排序算法的思想、稳定性、时间复杂度、空间复杂度。
> 
> 提示：动动你的小手敲出来更好哦~

## 9. 手脑并用

> 请实现ConvertAndMerge函数：  
> 拼接输入的两个字符串，并翻转拼接后得到的新字符串中所有字母的大小写。
> 
> 提示:你需要为新字符串分配空间。

```c
char* convertAndMerge(/*补全签名*/);
int main(void) {
    char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    char *str = convertAndMerge(words);
    printf("str = %s\n", str);
    free(str);
}
```

## 10. 给你我的指针，访问我的心声

>　程序的输出有点奇怪，请尝试解释一下程序的输出吧。

```c
int main(int argc, char **argv) {
    int arr[5][5];
    int a = 0;
    for (int i = 0; i < 5; i++) {
        int *temp = *(arr + i);
        for (; temp < arr[5]; temp++) *temp = a++;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", arr[i][j]);
        }
    }
}
```

## 11. 奇怪的参数

> 你了解argc和argv吗？  
> 直接运行程序argc的值为什么是1？  
> 程序会出现死循环吗？

```c
#include <stdio.h>
int main(int argc, char **argv) {
    printf("argc = %d\n", argc);
    while (1) {
        argc++;
        if (argc < 0) {
            printf("%s\n", (char *)argv[0]);
            break;
        }
    }
}
```
```
argument count
自增到溢出
argument vector
```

## 12. 奇怪的字符

> 程序的输出有点奇怪，请尝试解释一下程序的输出吧。

```c
int main(int argc, char **argv)
{
    int data1[2][3] = {{0x636c6557, 0x20656d6f, 0x58206f74},
                       {0x756f7969, 0x6e694c20, 0x00000000}};
    int data2[] = {0x47207875, 0x70756f72, 0x32303220, 0x00000a32};
    char *a = (char *)data1;
    char *b = (char *)data2;
    char buf[1024];
    strcpy(buf, a);
    strcat(buf, b);
    printf("%s \n", buf);
    if(*buf='W') printf("LE");
    else printf("BE");
}
```
```c
//                     c l e W       e m o     X   o t
int data1[2][3] = {{0x636c6557, 0x20656d6f, 0x58206f74},
                   //  u o y i     n i L            \0
                   {0x756f7969, 0x6e694c20, 0x00000000}};
//                G   x u     p u o r     2 0 2             2
int data2[] = {0x47207875, 0x70756f72, 0x32303220, 0x00000a32};
// unsigned char buf[33] = {
//     0x57, 0x65, 0x6C, 0x63, 0x6F, 0x6D, 0x65, 0x20, 0x74, 0x6F, 0x20, 0x58,
//     0x69, 0x79, 0x6F, 0x75, 0x20, 0x4C, 0x69, 0x6E, 0x75, 0x78, 0x20, 0x47,
//     0x72, 0x6F, 0x75, 0x70, 0x20, 0x32, 0x30, 0x32, 0x32};
```

## 13. 小试宏刀

> - 请谈谈你对`#define`的理解。
> - 请尝试着解释程序的输出。

```c
#include <stdio.h>
#define SWAP(a, b, t) t = a; a = b; b = t
#define SQUARE(a) a *a
#define SWAPWHEN(a, b, t, cond) if (cond) SWAP(a, b, t)
int main() {
    int tmp;
    int x = 1;
    int y = 2;
    int z = 3;
    int w = 3;
    SWAP(x, y, tmp);
    printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
    if (x > y) SWAP(x, y, tmp);
    printf("x = %d, y = %d, tmp = %d\n", x, y, tmp);
    SWAPWHEN(x, y, tmp, SQUARE(1 + 2 + z++ + ++w) == 100);
    printf("x = %d, y = %d,tmp=%d\n", x, y, tmp);
    printf("z = %d, w = %d ,tmp = %d\n", z, w, tmp);
}
```

## 14. GNU/Linux命令 (选做)

> 你知道以下命令的含义和用法吗：
> 
> 注：
> > 嘿！你或许对Linux命令不是很熟悉，甚至你没听说过Linux。  
> > 但别担心，这是选做题，不会对你的面试产生很大的影响！  
> > 了解Linux是加分项，但不了解也不扣分哦！
> - `ls`
> - `rm`
> - `whoami`
> 
> 请问你还了解哪些GNU/Linux的命令呢。

> 恭喜你做到这里！你的坚持战胜了绝大多数看到这份试题的同学。  
> 或许你自己对答题的表现不满意,但别担心，请自信一点呐。  
> 坚持到达这里已经证明了你的优秀。  
> 还在等什么,快带上你的笔记本电脑，来FZ103面试吧!
