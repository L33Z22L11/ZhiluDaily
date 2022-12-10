// end of
#include <stdio.h>
int main()
{
    int count = 0;
    while (getchar() != EOF)
        count++;
    printf("The number of characters is %d\n", count);
}