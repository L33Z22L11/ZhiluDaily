// - Your index?
// - No, it's your index.
#include <stdio.h>
int dmax(double arr[], int len)
{
    int max = 0;
    for (int i = 1; i < len; i++)
        if (arr[max] < arr[i])
            max = i;
    return max;
}
int main()
{
    double num[] = {1.1, 2.2, 3.3, 4.44, 5.55, 6.66};
    printf("max_index: %d\n", dmax(num, 6));
}
