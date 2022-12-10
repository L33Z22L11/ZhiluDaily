// value ur time ;D
#include <stdio.h>
#define K 60
int main()
{
    int min = 1;
    while (min > 0)
    {
        printf("Input how many minutes: ");
        scanf("%d", &min);
        printf("%d minutes is %d hours and %d minutes.\n", min, min / K, min % K);
    }
}