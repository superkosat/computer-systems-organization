#include <stdio.h>
#include <stdlib.h>

void printLine();

typedef enum type {
    VAR,
    NUM,
    OP,
    ASSIGN,
    PRINT
} type;

typedef struct token {
    type t;
    char *name;
    int value;
} token;

int main(int argc, char **argv) {
    FILE *src;
    src = fopen((argv)[1], "r");
    char *mode = argv[2];

    printf("%s\n", mode);
    char *str = (char*)malloc(20 * sizeof(char));
    printf("%s", fgets(str, 1024, src));

    
    //While has next line
    while (fgets(str, 1024, src)) {
        printLine(&str);
    }

}

void printLine(char **str) {
    printf("%s", *str);
}