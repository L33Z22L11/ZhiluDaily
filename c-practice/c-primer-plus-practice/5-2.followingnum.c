// 6
#include <stdio.h>
int main()
{
    int num, count;
    printf("Input a integer: ");
    scanf("%d", &num);
    for (int i = 0; i < 10; i++)
        printf("%d\t", num++);
}