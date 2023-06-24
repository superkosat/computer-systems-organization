#include <stdio.h>
#include <assert.h>
#include "util.h"

void print_in_binary(char);

void part_completed(int);

/*
Using the or operator is good for turning designated bits on.
*/

int main()
{
    short a = 0b1010000; // Binary 80

    short mask = 0b111;
    assert((a | mask) == 0b1010111);

    
    short decimal_result = 87;
    assert((a | mask) == decimal_result);

    part_completed(7);

    return 0;
}
