// print one to three
#include <stdio.h>
void two(void);
void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
}
void two(void)
{
    printf("two\n");
}
int main()
{
    printf("starting now:\n");
    one_three();
    printf("done!");
}