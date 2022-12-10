// totally min.h
#include <stdio.h>
double min(double n1, double n2)
{
    return n1 < n2 ? n1 : n2;
}

int main()
{
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("The smaller one is: %f\n", min(num1, num2));
}
