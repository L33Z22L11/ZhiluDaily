// convert inch to cm
#include <stdio.h>
int main()
{
    double inch;
    printf("Input inch: ");
    scanf("%lf", &inch);
    printf("%.6lf inch = %.6lf cm\n", inch, inch * 2.54);
}