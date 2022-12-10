// count odds and evens
#include <stdio.h>
int main()
{
    int num;
    int n_even = 0, n_odd = 0;
    float sum_even = 0, sum_odd = 0;
    printf("Enter some integers(0 to quit):\n");
    scanf("%d", &num);
    while (num)
    {
        if (num % 2)
            n_odd++, sum_odd += num;
        else
            n_even++, sum_even += num;
        scanf("%d", &num);
    }
    printf("%d evens, averaging %.2f\n", n_even, n_even ? sum_even / n_even : 0);
    printf("and %d odds, averaging %.2f\n", n_odd, n_odd ? sum_odd / n_odd : 0);
}