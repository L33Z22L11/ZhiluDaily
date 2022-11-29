// input a num,
// and output it in serval notations
#include <stdio.h>
int main()
{
    double num;
    printf("Input a floating-point value: ");
    scanf("%lf", &num);
    printf("fixed-point notation: %.6lf\n", num);
    printf("exponential notation: %e\n", num);
    printf("p notation: %a\n", num);
}