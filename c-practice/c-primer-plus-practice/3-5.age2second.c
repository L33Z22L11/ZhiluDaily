// print my age
#include <stdio.h>
int main()
{
    int age;
    printf("How old r u: ");
    scanf("%d", &age);
    printf("%d years equals to %.0lf seconds!\n", age, 3.156e7* age);
}