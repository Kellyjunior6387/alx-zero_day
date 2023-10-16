#include <stdio.h>
#include "main.h"

void print_number(int number)
{
    if (number <= 0){
        putchar('-');
        number = -number;
    }
    if (number == 0)
    {
        putchar('0');
        return;
    }
    if (number / 10 != 0)
    {
                print_number(number / 10);
    }
    putchar('0' + number % 10);
}
