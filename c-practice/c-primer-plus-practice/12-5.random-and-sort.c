// Turn on the faucet
// and open the water outlet,
// a new problem is set
#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>
#define SIZE 100
void arrout(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%4d", arr[i]);
        if (i % 10 == 9 || i == len - 1)
            printf("\n");
    }
}
int main()
{
    int digit[SIZE];
    srand((unsigned int)time(0));
    for (int i = 0; i < SIZE; i++)
    {
        digit[i] = rand() % 10 + 1;
    }
    printf("Random:\n");
    arrout(digit, SIZE);
    for (int i = 0, tmp; i < SIZE - 1; i++)
        for (int j = i + 1; j < SIZE; j++)
            if (digit[i] < digit[j])
            {
                tmp = digit[j];
                digit[j] = digit[i];
                digit[i] = tmp;
            }
    printf("Sorted:\n");
    arrout(digit, SIZE);
}
