// name, name and name
#include <stdio.h>
#include <string.h>
int main()
{
    char firstname[40], lastname[40];
    printf("Input your firstname: ");
    scanf("%s", firstname);
    printf("Input your lastname: ");
    scanf("%s", lastname);
    int len1 = strlen(firstname), len2 = strlen(lastname);
    printf("%s %s\n", firstname, lastname);
    printf("%*d %*d\n", len1, len1, len2, len2);
    printf("%s %s\n", firstname, lastname);
    printf("%*d %*d\n", -len1, len1, -len2, len2);
}