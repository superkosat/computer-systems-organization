#include <stdio.h>
#include <assert.h>
#include "util.h"

void print_in_binary(char);

void part_completed(int);

/*
The bitwise not operator (~a) just flips all of
the bits in a single number.
*/

int main()
{
    /*
      For positive numbers, this is equivalent to
      adding one to the number and making it negative
      in decimal.
    */
    print_in_binary(~0b1111); // Binary 15
    print_in_binary(~0b0000); // Binary 0

    /*
      For negative numbers, this is equivalent to
      adding one to the number and making it positive
      in decimal.
    */
    print_in_binary(  2);
    print_in_binary(~-2);
    print_in_binary( 4);
    print_in_binary(~-4);

    char x = 0b11111110;
    assert(~1 == x);
    char y = 0b00000000;
    assert(~-1 == y);

    part_completed(5);

    return 0;
}
