#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 100000

bool isPrime(int n);

int main() {
    time_t start = time(NULL);
    for (int i = 1; i <= N; i++) {
        if (isPrime(i)) {
            char str[7];
            sprintf(str, "%d", i);
            FILE *fileptr;
            fileptr = fopen("output.txt", "a");
            fprintf(fileptr, str);
            fclose(fileptr);
        }
    }
    time_t end = time(NULL);
    float elapsed = difftime(end, start);
    printf("Time elapsed (No Fork): %.2f", elapsed);
}

bool isPrime (int n) {
    if (n == 1) {
        return false;
    }

    int i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}