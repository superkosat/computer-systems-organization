# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Child, Timer Started:\n");
    for (int i = 1; i <= 10; i++) {
        printf("\r");
        printf("%d", i);
        sleep(1);
    }
    return 0;
}