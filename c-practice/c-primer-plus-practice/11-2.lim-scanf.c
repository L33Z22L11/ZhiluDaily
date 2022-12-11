// new get n char
#include <stdio.h>
char *gets_len__(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        *(str + i) = getchar();
        if (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\n')
        {
            *(str + i) = '\0';
            break;
        }
    }
    return str;
}
int main()
{
    char str[80];
    int n;
    puts("Read how namy char?");
    scanf("%d", &n);
    puts("Enter some characters:");
    gets_len__(str, 10);
    puts(str);
}