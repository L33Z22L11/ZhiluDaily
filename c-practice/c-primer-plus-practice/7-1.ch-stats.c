// I've got three baskets
#include <stdio.h>
int main()
{
    char ch;
    int space = 0, enter = 0, other = 0;
    printf("Enter some text(# to quit).\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            space++;
        else if (ch == '\n')
            enter++;
        else
            other++;
    }
    printf("Spaces: %d, linebreaks: %d, others: %d\n", space, enter, other);
}