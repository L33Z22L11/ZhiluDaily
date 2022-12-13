// how many bits on?
#include <stdio.h>
#include <limits.h>
int getBitsOn(int num)
{
    int result = 0;
    int size = __CHAR_BIT__ * sizeof(int);
    for (int i = 0; i < size; i++)
    {
        if (num & 1)
            result++;
        num >>= 1;
    }
    return result;
}
int main()
{
    int num;
    printf("intarg:\n");
    scanf("%d", &num);
    printf("%d bits on.\n", getBitsOn(num));
}
