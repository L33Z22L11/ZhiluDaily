// ████████
#include <stdio.h>
void chline(char ch, int col, int line)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < line; j++)
            putchar(ch);
        putchar('\n');
    }
}
int main()
{
    int row, col;
    printf("char?: ");
    char ch = getchar();
    printf("cols? lines?: ");
    scanf("%d %d", &row, &col);
    chline(ch, row, col);
}
