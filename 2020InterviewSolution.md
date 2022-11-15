# 西邮Linux兴趣小组2020纳新试题题解

> 感谢 [Zhilu](https://github.com/L33Z22L11) 重新录入题目原件。好人一生平安。

>注：
> 1. 本题仅作为面试有限参考
> 2. 为节省版面，省去所有`#include`指令
> 3. 题目难度与序号无关
> 4. 若无特殊声明，均假设在`Linux x86_64 GCC`编译器环境下


## 1. 请试着解释其输出。

```c
int main(int argc, char *argv[]) {
    unsigned char a = 255;
    char ch = 128;
    a -= ch;
    printf("a = %d ch = %d\n", a, ch);
}
```

## 2. 下面代码的运行输出结果是什么，并说说你的理解。

```c
int main(int argc, char *argv[]) {
    char *str = "Xi You Linux Group 20";
    printf("%d\n", printf(str));
    return 0;
}
```

## 3. 这段代码的输出结果是什么？为什么会出现这样的结果？

```c
int i = 2;
void func() {
    if(i != 0) {
    static int m = 0;
    int n = 0;
    n++;
    m++;
    printf("m = %d, n = %d\n", m, n);
    i--;
    func();
    } else {
    return;
    }
}
int main(int argc, char *argv[]) {
    func();
    return 0;
}
```

## 4. 下面程序会出现什么结果？为什么会出现这样的结果？

```c
int main(int argc, char * argv[]) {
    char ch = 'A';
    int i = 65;
    unsigned int f = 33554433;
    *(int *)&f >>= 24;
    *(int *)&f = *(int *)&f + '?';
    printf("ch = %c i = %c f = %c\n", ch, i, *(int *)&f);
    return 0;
}
```

## 5. 下面代码的运行输出结果是什么，并说说你的理解。

```c
int main(int argc, char *argv[]) {
    int a[2][2];
    printf("&a = %p\t&a[0] = %p\t&a[0][0] = %p\n", &a, &a[0], &a[0][0]);
    printf("&a+1 = %p\t&a[0]+1 = %p\t&a[0][0]+1= %p\n", &a+1, &a[0]+1, &a[0][0]+1);
    return 0;
}
```

## 6. 下列程序的功能是什么？有什么问题，你能找出问题并解决它吗？

```c
int* get_array() {
    int array[1121]; 
    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        array[i] = i;
    }
    return array;
}
int main(int argc, char *argv[]) { 
    int *p = get_array();
}
```

## 7. 下面代码的运行输出结果是什么，并说说你的理解。

```c
int main(int argc, char *argv[]) {
    char str[] = "XiyouLinuxGroup"; 
    char *p = str; 
    char x[] = "XiyouLinuxGroup\t\106F\bamily";
    printf("%zu %zu %zu %zu\n", sizeof(str), sizeof(p), sizeof(x), strlen(x));
    return 0;
}
```

## 8. 如下程序，根据打印结果，你有什么思考？

```c
int add(int *x, int y) {
    return *x = (*x^y) + ((*x&y)<<1);
}
int a;
int main(int argc, char *argv[]) {
    int b = 2020;
    if(add(&b, 1) || add(&a, 1)) {
        printf("XiyouLinuxGroup%d\n", b);
        printf("Waiting for y%du!\n", a);
    }
    if(add(&b, 1) && a++) {
    printf("XiyouLinuxGroup%d\n", b);
    printf("Waiting for y%du!\n", a);
}
  return 0;
} 
```

## 9. 在下段程序中，我们可以通过第一步打印出`a`的地址，假如在你的机器上面打印结果是`0x7ffd737c6db4`；我们在第二步用`scanf`函数将这个地址值输入变量`c`中；第三步，随机输入一个数字，请问最终输出了什么结果，你知道其中的原理吗？

```c
void func() { 
    int a = 2020;
    unsigned long c;
    printf("%p\n", &a);
    printf("我们想要修改的地址：");
    scanf("%lx", &c);
    printf("请随便输入一个数字：");
    scanf("%d", (int *)c);
    printf("a = %d\n", a);
}
```

## 10. 请问一个C语言程序从源代码到可执行文件中间会进行哪些过程，你能简单描述一下每个环节都做了什么事情吗？


## 11. 请解释一下这行代码做了什么？

```c
puts((char*)(int const[]){
    0X6F796958,0X6E694C75,0X72477875,
    0X3270756F,0X313230,0X00000A
});
```

## 12. 请随机输入一串字符串，你能解释一下输出结果吗？

```c
int main(int argc, char *argv[]) {
    char str[1121];
    int key;
    char t;
    fgets(str, 1121, stdin);
    for(int i = 0; i < strlen(str) - 1; i++) {
        key = i;
        for(int j = i + 1; j < strlen(str); j++) {
            if(str[key] > str[j]) {
                key = j;
            }
        } 
        t = str[key];
        str[key] = str[i];
        str[i] = t;
    } 
    puts(str);
    return 0;
}
```

## 13. 用循环和递归求`Fibonacci`数列，你觉得这两种方式那种更好？说说你的看法。如果让你求`Fibonacci`数列的第100项，你觉得还可以用常规的方法求解吗？请试着求出前100项的值（tip大数运算）。


## 14. Linux 实操题

> 请通过命令创建一个目录，在该目录中创建几个后缀为`.Linux`的文件，然后通过命令查询这几个文件的基本属性信息（如文件大小，文件创建时间等），之后使用命令查看该目录下文件名含有“`.Linux`”的文件的数量（不包括子目录下的文件），把得到的数字写入到一个文件中，最后删除此目录。