// let's find the max
#include <stdio.h>
int max(int arr[], int len)
{
    int i, max;

    for (i = 0, max = arr[0]; i < len; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}
int main()
{
    int num[] = {1, 2, 3, 4, 5, 6, 7};
    printf("The biggest number is %d\n", max(num, 7));
}
