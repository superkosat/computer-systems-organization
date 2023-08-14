#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int limit = 40;
int extensions = 0;

void childSignalHandler(int signum) {
    if (extensions > 2) {
        printf("Too many extensions - game over\n\n");
        kill(getppid(), SIGKILL);
        _exit(0);
    } else if (signum == SIGINT) {
        limit += 4;
        kill(getppid(), SIGINT);
        extensions++;
    }
}

int secs=0;

int main(int argc, char **argv) {
    signal(SIGINT, childSignalHandler);

    printf("\n\n\n");

    while(secs < limit) {

        printf("\033[2K");  // Clear the entire line
        printf("\rTime: %2d", secs);  // Move to the beginning of the line and print the new value
        fflush(0);  // Flush stdout buffer
        sleep(1);
        secs++;
        
    }

    return 0;
}