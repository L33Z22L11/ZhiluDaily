#include <stdio.h>
#include <string.h>
char *convertAndMerge(char strs[2][20])
{
    int len = strlen(strs[0]) + strlen(strs[1]);
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(result, strs[0]);
    strcat(result, strs[1]);
    for (int i = 0; i < len; i++)
    {
        if (result[i] >= 'A' && result[i] <= 'Z')
            result[i] += 32;
        else if (result[i] >= 'a' && result[i] <= 'z')
            result[i] -= 32;
    }
    return result;
}
int main(void)
{
    char words[2][20] = {"Welcome to Xiyou ", "Linux Group 2022"};
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
    char *str = convertAndMerge(words);
    printf("str = %s\n", str);
    free(str);
}