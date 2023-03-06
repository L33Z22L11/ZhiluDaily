// 时间换算。（30分）
// 题目内容：编写程序，实现输入的时间，屏幕显示一秒后的时间。显示格式为HH:MM:SS。

// 程序需要处理以下三种特殊情况：
// (1)若秒数加1后为60，则秒数恢复到0，分钟数增加1；
// (2)若分钟数加1后为60，则分钟数恢复到0，小时数增加1；
// (3)若小时数加1后为24，则小时数恢复到0。

// 输入样例：18:1:2
// 输出样例：18:01:03

// 输入样例：20:12:59
// 输出样例：20:13:00

// 输入样例：23:59:59
// 输出样例：00:00:00

// 时间限制：500ms
// 内存限制：32000kb

#include <stdio.h>

typedef struct
{
    int h;
    int m;
    int s;
} time;

void getT(time *t)
{
    scanf("%d:%d:%d", &t->h, &t->m, &t->s);
}

void printT(time t)
{
    printf("%02d:%02d:%02d", t.h, t.m, t.s);
}

time nextSec(time t)
{
    if (t.s < 59)
        t.s++;
    else if (t.m < 59)
        t.m++, t.s = 0;
    else if (t.h < 23)
        t.h++, t.m = t.s = 0;
    else
        t.h = t.m = t.s = 0;
    return t;
}

time nextSec2(time t)
{
    if (t.s < 59)
        t.s++;
    else
    {
        t.s = 0;
        if (t.m < 59)
            t.m++;
        else
        {
            t.m = 0;
            if (t.h < 23)
                t.h++;
            else
                t.h = 0;
        }
    }
    return t;
}

time nextSec3(time t)
{
    if (t.s == 59)
        if (t.m == 59)
            if (t.h == 23)
                t.h = t.m = t.s = 0;
            else
                t.h++, t.m = t.s = 0;
        else
            t.m++, t.s = 0;
    else
        t.s++;
    return t;
}

time nextSec4(time t)
{
    if (t.s == 59)
    {
        t.s = 0;
        if (t.m == 59)
        {
            t.m = 0;
            if (t.h == 23)
                t.h = 0;
            else
                t.h++;
        }
        else
            t.m++;
    }
    else
        t.s++;
    return t;
}

int main()
{
    time t;
    getT(&t);
    printT(nextSec(t));
}