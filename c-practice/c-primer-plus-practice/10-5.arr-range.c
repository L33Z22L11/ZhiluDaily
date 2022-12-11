// range from...
#include <stdio.h>
double numrange(double arr[], int len)
{
    double max, min;
    max = min = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
            max = arr[i];
        else if (min > arr[i])
            min = arr[i];
    }
    return max - min;
}
int main()
{
    double num[] = {1.1, 2.2, 3.3, 4.44, 5.55, 6.66};
    printf("num_range:\n%g\n", numrange(num, 6));
}
