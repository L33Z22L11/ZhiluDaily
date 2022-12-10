// name and height
#include <stdio.h>
int main()
{
    float height;
    char name[40];
    printf("Input your height(cm) and name: ");
    scanf("%f %s", &height, name);
    printf("%s, you are %.3fm tall\n", name, height/ 100);
}