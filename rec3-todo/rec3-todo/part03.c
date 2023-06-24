#include <stdio.h>
#include <assert.h>
#include "util.h"

void print_in_binary(char);

void part_completed(int);

/*
The bitwise OR (a|b) operator compares two numbers on
a bit level and returns a number where the bits of that
number are turned on if either of the corresponding bits
of a and b are 1.

 a:  00101010   42
 b:  00001111   15
===============
a|b: 00101111   47

So remember for every given bit in a and b
  0 | 0 = 0
  0 | 1 = 1
  0 | 1 = 1
  1 | 1 = 1
*/

int main()
{
    char bits = 0b1000; // Binary 8

    char a = 0b0000;
    char b = 0b0101;
    char c = 0b0111;

    assert((a | bits) == 0b1000);
    assert((b | bits) == 0b1101);
    assert((c | bits) == 0b1111);

    //Encounters an issue when calling part_completed(3)
    part_completed(3);

    return 0;
}