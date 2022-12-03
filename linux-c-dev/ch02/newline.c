/*
 * ch02/newline.c
 * 2022/05/29
 */

#include <stdio.h>

void newline(void)
{
    printf("\n");
}

int main(void)
{
    printf("First Line.\n");
    newline();
    printf("Second Line.\n");

}