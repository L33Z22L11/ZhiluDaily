// reproduction
#include <stdio.h>
int main()
{
    char ch;
    int count = 0;
    printf("Enter some characters(# to quit).\n");
    while ((ch = getchar()) != '#')
    {
        printf("%c: %d\t", ch, ch);
        if (++count % 8 == 0)
            printf("\n");
    }
    printf("\n");
}