// convert one's height from inch to cm
#include <stdio.h>
int main()
{
    double inch;
    printf("Input your height in inch: ");
    scanf("%lf", &inch);
    printf("Your height is %.2lf cm.\n", inch * 2.54);
}