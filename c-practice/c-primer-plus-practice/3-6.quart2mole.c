// quart of water convert to number of molecules
#include <stdio.h>
int main()
{
    double quart;
    printf("Input the quarts of water: ");
    scanf("%lf", &quart);
    printf("%6lf quarts of water contains %e molecules", quart, quart * 950 / 3e-23);
}