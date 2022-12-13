// jump and print!
#include <stdio.h>
#include <stdlib.h>
#define LEN 40
int main()
{
    char fname[LEN];
    FILE *fp;
    long offset;
    puts("what file?");
    gets(fname);
    fp = fopen(fname, "r");
    puts("pos? ([-num] or [!num] to quit)");
    while (scanf("%ld", &offset) == 1 && offset > 0)
    {
        char words[LEN];
        getchar();
        fseek(fp, offset, SEEK_SET);
        fscanf(fp, "%40s", words);
        fprintf(stdout, "%s\n", words);
        puts("pos? (-num or !num to quit)");
    }
    fclose(fp);
}
