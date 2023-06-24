// implement your program here
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void split(int n) 
{
    int bit = 0;
    bool isAn = true;
    int an = 0;
    int bn = 0;

    while (n > 0) {
        if (n & 1) {
            if (isAn)
                an |= (1 << bit);
            else
                bn |= (1 << bit);

            isAn = !isAn;
        }
        n >>= 1;
        bit += 1;
    }

    printf("%d %d\n", an, bn);
}


int main() 
{
    int (*nums) = malloc(sizeof(int));

    int N;
    int i = 0;
    do {
        scanf("%d", &N);
        nums[i] = N;
        i++;
    } while (N != 0);

    for (int j = 0; j < i - 1; j++) {
        split(nums[j]);
    }

    return 0;
}