/*
 * ch02/print_time.c
 * 2022/05/29
 */

#include <stdio.h>

void print_time(int hour, int minute)
{
    printf("%d:%d\n", hour, minute);
}

int main(void)
{
    print_time(23, 59);
    return 0;
}