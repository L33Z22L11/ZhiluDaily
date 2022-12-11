// let's go to the dock and order some french fries!
#include <stdio.h>
char *gets_len(char str[], int len)
{
    int i = 0;
    while (i < len)
        str[i++] = getchar();
    str[i] = '\0';
    return str;
}
int main()
{
    char str[80];
    int n = 0;
    puts("Read how namy char?");
    scanf("%d", &n);
    gets_len(str, n);
    puts(str);
}
