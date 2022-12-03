/*
 * ch05/solution.c
 * 2022/05/30
 */

#include <stdio.h>

int is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100) || (year % 400 == 0)) {
        return 1;
    } 
    return 0;
}


int main(void)
{
    int a = 2021, b = 2022;
    printf("%d is leap year ? %d\n", a, is_leap_year(a));
    printf("%d is leap year ? %d\n", b, is_leap_year(b));

    return 0;
}