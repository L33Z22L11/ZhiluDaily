// who calls me so many times?
#include <stdio.h>
void call_count();
int count;
int main(void)
{
    int n;
    puts("How many times would you like to call call_count?");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        call_count();
    printf("Hmm... you called call_count %d times!\n", count);
}

void call_count()
{
    printf("Beep\t");
    count++;
}