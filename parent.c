#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

pid_t pid;

void parentSignalHandler(int signum) {
    if (signum == SIGINT) {
        printf("\nYou are allowed no more than 3 extensions \n");
    }
}


int main(int argc, char **argv) {
    int child_status;
    int thispid;
    int i;
    pid = fork();
    if (pid == 0) {
        pid = execve("child", NULL, NULL);
    }

    signal(SIGINT, parentSignalHandler);

    int num;
    int incorrectCounter = 0;
    
    srand(time(NULL));

    printf("What is 2 * 2? \n");
    while (num != 4) {
        if (incorrectCounter >= 4) {
            kill(pid, SIGKILL);
        }
        scanf("%d", &num);
        if (num == 4) {
            printf("correct \n" );
            kill(pid, SIGKILL);

        } else if (num == -1) {
            kill(pid, SIGKILL);
            printf("%i game over \n",num);
            break;

        } else if (num == 0) {
            kill(pid, SIGINT);
        } else {
            printf("%d incorrect \n",num);
            incorrectCounter++;
        }
    }

    return(0);
}