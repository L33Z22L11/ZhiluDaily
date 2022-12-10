// very harmonic, except the func name
#include <stdio.h>
double hmncmn(double num1, double num2)
{
    return 1 / (1 / num1 + 1 / num2);
}
int main()
{
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("The harmonic mean is: %f\n", hmncmn(num1, num2));
}
