#include <stdio.h>

typedef enum type {
    VAR,
    NUM,
    OP,
    ASSIGN
} type;

typedef struct token {
    type t;
    char *name;
    int value;
} token;

int main(int argc, char **argv) {
    FILE *src;
    src = fopen((*argv)[1], "r");
    while () {

    }
}