// match() but with dichotomy
#include <stdio.h>
#define SIZE 11
int find(int *arr, int size, int target)
{
    int head = 0;
    int end = size - 1;
    while (head <= end)
    {
        int mid = (head + end) / 2;
        if (target < arr[mid])
            end = mid - 1;
        else if (target > arr[mid])
            head = mid + 1;
        else
            return 1;
    }
    return 0;
}
int main()
{
    int n;
    int array[SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    puts("Look up for what, guy?");
    scanf("%d", &n);
    if (find(array, SIZE, n))
        printf("Yeah, it exists.\n");
    else
        printf("No, not here.\n");
}
