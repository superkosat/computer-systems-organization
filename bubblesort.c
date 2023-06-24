#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int bubblesort(int *arr, int size) {
    int count = 0;
    int *ptr1, *ptr2, temp;
    for (int i = 0; i < size - 1; i++) {
        for (ptr1 = arr; ptr1 < arr + size - i - 1; ptr1++) {
            ptr2 = ptr1++;
            count++;
            if (*ptr1 > *ptr2) {
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
            }
        }
    }
    return count;
}


int main() {
    int a[10] = {1, 4, 5, 2, 78, 4, 7, 8, 5, 9};
    int *pa = &a[0];
    printf("%d\n", bubblesort(pa, 10));
    return 0;
}