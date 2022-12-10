// too many characters @_@*
#include <stdio.h>
int main()
{
    char ch;
    int count = 0;
    while ((ch = getchar()) != EOF)
    {
        count++;
        if (ch >= ' ')
            printf("%c ", ch);
        else if (ch == '\n' || ch == '\t')
            printf("%s", ch - '\t' ? "\\n" : "\\t");
        else
            printf("^%c", ch + 64);
        printf(": %d\t", ch);
        if (ch == '\n')
            count = 0;
        if (count % 10 == 0)
            printf("\n");
    }
}
