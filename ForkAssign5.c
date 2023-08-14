#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 

int  loop=1;
int cnt=0;
void handle_sigchild(int sig) 
{ 
     printf("Caught signal %d\n\n\n", sig); 
    loop = 0;
} 
void handle_sigintchild(int sig) 
{ 
     printf("Child signal %d\n\n\n", sig); 
     
} 

int main(int argc, char **argv)
{

signal(SIGCHLD, handle_sigchild);
signal(SIGINT, handle_sigintchild);
  int child_status;
  pid_t pid,pid1;
  pid1 = getpid();
  printf("pid %i",pid1);
char buffer[10];
snprintf(buffer, 10, "%d", pid1);
  char *array[3];
   array[0]=buffer;
   array[1] ="13";
  //  sprintf(  array[0], "%d", pid1);
  pid = fork();
   if (pid == 0) {
    printf("process %s -  %s",array[0],array[1]);
    pid= execve("ProcessAssign5",  array, NULL);
     }
 
    
   wait(&child_status);
   return(0);
   }