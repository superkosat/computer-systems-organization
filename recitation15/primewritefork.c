#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h> // for fork() and getpid()

#define N 100000

bool isPrime(int n);

int main() {
    time_t start = time(NULL);

    return 0;
}

bool isPrime(int n) {
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