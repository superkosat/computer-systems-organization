#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv) {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        execve("processes1", NULL, NULL);
    } else {
        printf("parent\n");
    }
    return 0;
}