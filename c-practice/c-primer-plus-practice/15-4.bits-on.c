// is it 1?
#include <stdio.h>
int isBit1(int num, int bit)
{
    for (int i = 0; i < bit; i++)
        num >>= 1;
    return num & 1;
}
int main()
{
    int num, bit;
    puts("int?");
    scanf("%d", &num);
    puts("pos?");
    scanf("%d", &bit);
    printf("The number in your position is: %d.\n",
        isBit1(num, bit));
}
