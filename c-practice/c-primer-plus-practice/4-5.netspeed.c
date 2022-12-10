// what's ur netspeed?
#include <stdio.h>
int main()
{
    float speed, size, time;
    printf("Input the download speed(Mb/s) and the file size(MB):\n");
    scanf("%f %f", &speed, &size);
    time = size * 8 / speed;
    printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds.\n", speed, size, time);
}