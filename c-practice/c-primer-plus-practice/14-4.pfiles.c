// oooooutput fiiiiiles
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
    char ch;
    FILE * fp;
    for (int i = 1; i < argc; i++)
    {
        printf("[%d] %s:\n", i, argv[i]);
        fp = fopen(argv[i], "r");
        while ((ch = getc(fp)) != EOF)
            putchar(ch);
        printf("\n");
    }
}