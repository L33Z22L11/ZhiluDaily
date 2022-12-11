#include <stdio.h>
int bin2dec(char *str)
{
    int num = 0;
    while (*str)
        num = (num << 1) + (*str++ - '0');
    return num;
}
int main(int argc, char *argv[])
{
    if (argc == 2)
        printf("%d", bin2dec(argv[1]));
    else
        return;
}
