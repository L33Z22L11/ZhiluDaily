// annoying time stolen my youth:
#include <stdio.h>
struct month
{
    char name[10];
    char abbr[4];
    int days;
    int no;
};
struct month year2022[12] = {
    {"Fanuary", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sept", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}};
int main()
{
    int target, result = 0;
    printf("Enter the No. of month: ");
    scanf("%d", &target);
    for (int i = 0; i < target; i++)
    {
        result += year2022[i].days;
    }
    printf("%d days have passed in %s in 2022", result, year2022[target - 1].name);
}