#include <unistd.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include<signal.h> 
int secs=0;
  
int main(int argc, char **argv)
{

   
 int limit = atoi(argv[1]);
  kill(processnum,SIGINT);
  while(secs < limit) {
     printf("Time:%i\n",secs);
     fflush(0);
     sleep(1);
     secs++;
      
  }
  
 
  printf("DONE");
  return 0;
}
 
  