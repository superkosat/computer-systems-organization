#include <stdio.h>

int bit_wisdom(int n)
{
    // Turn off all bits except for the last four (1, 2, 4, and 8's bit)
    int mask1 = 0b1111;
    n = n & mask1;

    // Flip the last two bits (1 and 2's)
    int mask2 = 0b11;
    n = n ^ mask2;

    // Turn on the second to last two bits (4 and 8's)
    int mask3 = 0b1100;
    n = n | mask3;

    // Return the modified value
    return n;
}

int main() {
    int num = 0b10101010;
    int newNum = bit_wisdom(num);
    printf("%d\n", newNum);
    return 0;
}