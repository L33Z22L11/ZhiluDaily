// tenet
#include <stdio.h>
int main()
{
    char current = 'A', target;
    printf("Input your target letter:");
    scanf("%c", &target);
    int LINE = target - current + 1;
    for (int i = 1; i <= LINE; i++)
    {
        for (int j = 1; j <= LINE - i; j++)
            printf(" ");
        for (int j = 0; j < i; j++)
            printf("%c", current + j);
        for (int j = i - 2; j >= 0; j--)
            printf("%c", current + j);
        printf("\n");
    }
}