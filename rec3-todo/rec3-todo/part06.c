#include <stdio.h>
#include <assert.h>
#include "util.h"

void print_in_binary(char);

void part_completed(int);

/*
A bitmask is just a variable that aids you with bitwise operations.

A bitmask can help you turn specific bits on and off or just collect
data from a certain part of a bit vector.

Using the & operator with a mask is the easiest way certain to turn bits off.
*/

int main()
{
    short a = 0b101010101;

    short mask = 0b111;

    print_in_binary( (a & mask) );
    assert((a & mask) == 0b101);

    part_completed(6);

    return 0;
}
