#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
  int status;
  int i,j,n=argc;
  char str1[argc][20],str2[argc][20];
  printf("\nNumber Of Arguments Passed: %d",argc);
  printf("\nCommand Line Arguments:");
  for(i=1;i<argc;i++)
  {
      strcpy(str1[i],argv[i]);
      strcpy(str2[i],argv[i]);
      printf(" \n arr[%d]= %s \n",i,str1[i]);

  }
  pid_t a,b;
  char temp[20];
  a =fork();
  if(a==0)
  {
    for (i = 0; i < n - 1 ; i++)
    {
      for (j = 0; j < n-i-1; j++)
          {
              if (strcmp(str1[j], str1[j+1]) > 0)
              {
                  strcpy(temp, str1[j]);
                  strcpy(str1[j], str1[j+1]);
                  strcpy(str1[j+1], temp);
              }
          }
    }
    printf("Bubble Sort:\n");
    for(i=0;i<n;i++)
      {
          printf("%s",str1[i]);
            printf("\n");
      }
  }
  else
  {
      wait(&status);
      printf("\nParent \n");

    b=fork();
    if(b==0)
    {
      int p, q, min_idx;
      char temp[20];
      for (p = 0; p < n-1; p++)
      {
          min_idx = p;
          for (q = p+1; q < n; q++)
          {
            if (str2[q] < str2[min_idx])
              min_idx = q;
          }
            strcpy(temp, str2[min_idx]);
            strcpy(str2[min_idx], str2[p]);
            strcpy(str2[p], temp);
      }
      printf("Selection Sort:\n");
      for(i=0;i<n;i++)
      {
           printf("%s",str2[i]);
           printf("\n");
      }


    }
  }
  return 0;
}
