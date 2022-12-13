// print line with key word
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
int main(int argc, char * argv[])
{
    FILE * fp;
    char words[SIZE];
    fp = fopen(argv[2], "r");
    while (fgets(words, SIZE, fp) != NULL)
    {
        if (strstr(words, argv[1]) != NULL)
            fputs(words, stdout);
    }
    return 0;
}