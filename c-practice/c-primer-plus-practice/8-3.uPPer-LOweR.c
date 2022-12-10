// UppER? loWEr?
#include <stdio.h>
#include <ctype.h>
int main()
{
    int upper = 0, lower = 0;
    char ch;
    printf("Input some letters: \n");
    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            upper++;
        else if (islower(ch))
            lower++;
    }
    printf("upper: %d, lower: %d\n", upper, lower);
}