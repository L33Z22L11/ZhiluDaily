// what day is it
#include <stdio.h>
int main()
{
    int day = 1;
    while (day > 0)
    {
        printf("Input the number of days: ");
        scanf("%d", &day);
        printf("%d days are %d weeks, %d days.\n", day, day / 7, day % 7);
    }
}