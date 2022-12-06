// the US volume unit conversion
// why not ours?
#include <stdio.h>
int main()
{
    double pint, ounce, soupspoon, teaspoon, cup;
    printf("Input the number of cups: ");
    scanf("%lf", &cup);
    pint = cup / 2;
    ounce = cup * 8;
    soupspoon = ounce * 2;
    teaspoon = soupspoon * 3;
    printf("It equals to %.2lf pint, or %.2lf ounce, or %.2lf soupspoons, or %.2lf teaspoons!\n", pint, ounce, soupspoon, teaspoon);
}
