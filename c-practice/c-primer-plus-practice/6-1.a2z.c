// abcdefg~
#include <stdio.h>
int main()
{
    char letter[26];
    for (int i = 0; i < 26; i++)
    {
        letter[i] = 'a' + i;
        printf("%c ", letter[i]);
    }
    printf("\n");
}
