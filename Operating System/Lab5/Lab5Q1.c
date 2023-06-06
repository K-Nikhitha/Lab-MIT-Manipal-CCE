#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  if(fork()==0)
  {
    printf("Child Process");
    printf("PID : %d PPID : %d \n",getpid(),getppid());
  }
  else
  {
    printf("Parent Process");
    printf("PID : %d PPID : %d \n",getpid(),getppid());
  }
  return 0;
}
