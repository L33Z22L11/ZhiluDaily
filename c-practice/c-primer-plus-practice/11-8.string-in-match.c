
#include <stdio.h>
#include <string.h>
#define SIZE 80
char *string_in(char *str1, char *str2)
{
    for (int i = 0; *str1; str1++)
    {
        while (str1[i] == str2[i])
        {
            i++;
            if (!str2[i])
                return str1;
        }
    }
    return NULL;
}
int main()
{
    char str1[SIZE], str2[SIZE];
    char *result;
    while (1) // 输入quit结束
    {
        printf("str1 (:q to quit): ");
        gets(str1);
        if (!strcmp(str1, ":q"))
            break;
        printf("str2: ");
        gets(str2);
        result = string_in(str1, str2);
        if (result)
            printf("%s@%s: %zu\n", str2, str1, result);
        else
            puts("Not found\n");
    }
}
