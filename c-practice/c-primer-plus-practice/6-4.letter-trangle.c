// sing, dance and rap: abcdefg
#include <stdio.h>
int main()
{
    char ch = 'A';
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j < i; j++)
            printf("%c", ch++);
        printf("\n");
    }
}