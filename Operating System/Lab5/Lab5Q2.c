#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int main(int argc,char* argv[])
{
  int status;
    int i,j;
    char str[20][20];
    char temp[20];
    printf("\nNumber Of Arguments Passed: %d",argc);
    printf("\nCommand Line Arguments:");
    for(i=1;i<argc;i++)
    {
        strcpy(str[i],argv[i]);
        printf(" \n arr[%d]= %s \n",i,str[i]);

    }
    pid_t a=fork();
    if(a==0)
    {
      printf("Child Process:\n");
        for (i = 1; i < argc-1; i++)
        {
            for (j = i+1; j < argc; j++)
                {
                     if (strcmp(str[i], str[j]) > 0)
                       {
                        strcpy(temp, str[i]);
                        strcpy(str[i], str[j]);
                        strcpy(str[j], temp);
                          }
                }
        }
        printf("Sorted Array:\n");
          for(i=1;i<argc;i++)
          {
            printf("%s \n",str[i]);
          }
    }
    else
    {
        wait(&status);
        printf("\nParent Process:\n");
        for(i=1;i<argc;i++)
            {
                printf("\n argv[%d]: %s \n ",i,argv[i]);
            }
    }
    return 0;
}
