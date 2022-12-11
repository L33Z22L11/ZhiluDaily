// 1000 rand in a row!
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count[10];
    int seed[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
            count[j] = 0;
        srand(seed[i]);
        printf("@seed %d: \n", seed[i]);
        for (int j = 0; j < 1000; j++)
            count[rand() % 10]++;
        for (int j = 0; j < 10; j++)
            printf("%d: %d\t", j + 1, count[j]);
        printf("\n");
    }
}
  