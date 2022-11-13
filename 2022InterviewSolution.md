# 西邮Linux兴趣小组2022纳新面试题题解

> Zhilu

## 0. 我的计算器坏了？！

> 2^10=1024

## 1. printf还能这么玩？

> 尝试着解释程序的输出。

## 2. 你好你好你好呀！

> - 程序的输出有点奇怪，请尝试解释一下程序的输出吧。
> - 请谈谈对`sizeof()`及`strlen()`的理解吧。

```c
int main(void)
{
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

p0、p1地址不同，strcmp会从p2开始读到内存中的下一个'\0'

sizeof(p0)是字符数组(含末尾'\0')的大小，sizeof(p1)是指针地址的大小，sizeof(*p2)是字符'H'的大小

## 3. 换个变量名不行吗？

```c
int a = 3;
void test()
{
    int a = 1;
    a += 1;
    {
        int a = a + 1;
        printf("a = %d\n", a);
    }
    printf("a = %d\n", a);
}
int main(void)
{
    test();
    printf("a= %d\n", a);
}
```
代码块作用域内的局部变量a

## 4. 内存对不齐

```c
typedef union
{
    long l;
    int i[5];
    char c;
} UNION;
typedef struct
{
    int like;
    UNION coin;
    double collect;
} STRUCT;
int main(void)
{
    printf("sizeof (UNION) = %zu \n", sizeof(UNION)); 
    printf("sizeof (STRUCT) = %zu \n", sizeof(STRUCT));
}
```
```
union:
    sizeof (long) = 4
    sizeof (int[5]) = 20
    sizeof (char) = 1
```
union中的所有数据成员共享同一个存储空间，其在内存中的大小为最大成员的大小。

```
struct:
    sizeof (int) = 4
    sizeof (UNION) = 20
    sizeof (double) = 8
```
struct中的每个数据成员享有独立的存储空间，其在内存中的大小为所有成员的大小之和。

## 5. Bitwise
