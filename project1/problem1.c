// implement your program here
#include <stdio.h>
#include <stdlib.h>

int convertIntsToBits(int month, int day, int hour, int minute, int second) 
{
    if (month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        return 0;
    }

    int bits = 0;

    //isolate one and tens place for each period,
    //then bitwise or with bits variable
    bits |= (second % 10) | ((second / 10) % 6) << 4;
    bits |= (minute % 10) << 7 | ((minute / 10) % 6) << 11;
    bits |= (hour % 10) << 14 | ((hour / 10) % 3) << 18;
    bits |= (day % 10) << 20 | ((day / 10) % 4) << 24;
    bits |= (month % 10) << 26 | ((month / 10) % 2) << 30;

    return bits;
}

int main()
{
    int N;
    scanf("%d", &N);

    int (*input)[5] = malloc(N * sizeof(int[5]));

    for (int i = 0; i < N; i++) {
        scanf("%d/%d %d:%d:%d", &input[i][0], &input[i][1], &input[i][2], &input[i][3], &input[i][4]);
    }
    
    for (int i = 0; i < N; i++) {
        int result = convertIntsToBits(input[i][0], input[i][1], input[i][2], input[i][3], input[i][4]);
        if (result == 0) {
            printf("INVALID\n");
        } else {
            printf("%d\n", result);
        }
    }

    free(input);
    return 0;
}