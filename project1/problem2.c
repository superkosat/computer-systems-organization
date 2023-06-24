// implement your program here
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* convertToHexadecimal(int decimalNumber) 
{
    //set to size of two chars to accomodate hex values not 
    //greater than 255
    char* hexadecimal = (char*) malloc(2 * sizeof(char));
    int index = 0;

    if (decimalNumber == 0) {
        return "00";
    }
    
    while (decimalNumber != 0) {
        int remainder = decimalNumber % 16;
        
        /*if (remainder == 0) {
            hexadecimal[index] = remainder + '0';
        }else */if (remainder < 10) {
            hexadecimal[index] = remainder + '0';
        } else {
            hexadecimal[index] = remainder + 'a' - 10;
        }
        
        decimalNumber /= 16;
        index++;
    }
    
    //to reverse the sequence into the forwards order
    int i, j;
    for (i = 0, j = index - 1; i < j; i++, j--) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[j];
        hexadecimal[j] = temp;
    }
    
    hexadecimal[index] = '\0';
    
    return hexadecimal;
}

bool isValid(int r, int g, int b) 
{
    return (r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255);
}

int main()
{
    int N;
    scanf("%d", &N);

    int (* colors)[3] = malloc(N * sizeof(int[3]));

    for (int i = 0; i < N; i++) {
        scanf("%d, %d, %d", &colors[i][0], &colors[i][1], &colors[i][2]);
    }

    for (int i = 0; i < N; i++) {
        int r = colors[i][0], g = colors[i][1], b = colors[i][2];
        if (!isValid(r, g, b)) {
            printf("INVALID\n");
        } else {
            printf("#%s%s%s\n",convertToHexadecimal(r), convertToHexadecimal(g), convertToHexadecimal(b));
        }
    }

    return 0;
}