#include <stdio.h>
#include <limits.h>
int main()
{
    printf("INT_MAX: %d, INT_MAX_overflowed: %d\n", INT_MAX, INT_MAX + 1);
    printf("INT_MIN: %d, INT_MIN_overflowed: %d\n", INT_MIN, INT_MIN - 1);
    printf("DBL_MAX: %lf, DBL_MAX_overflowed: %lf\n", __DBL_MAX__, __DBL_MAX__ + 1);
    printf("DBL_MIN: %lf, DBL_MIN_overflowed: %lf\n", __DBL_MIN__, __DBL_MIN__ - 1);
}