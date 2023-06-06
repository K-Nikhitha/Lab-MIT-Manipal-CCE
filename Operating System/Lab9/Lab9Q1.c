#include<stdio.h>
void firstFit(int blockSize[],int m, int processSize[],int n)
{
  int allocation[n],occupied[m];
  for(int i=0;i<n;i++)
    allocation[i]=-1;
  for(int i=0;i<m;i++)
    occupied[i]=0;
    for (int i=0;i<n;i++)
    {
      for (int j=0;j<m;j++)
      {
        if (!occupied[j] && blockSize[j]>=processSize[i])
        {
          allocation[i] = j;
          occupied[j] = 1;
          break;
        }
      }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[],int m, int processSize[],int n)
{
  int allocation[n],occupied[m];
  for(int i=0;i<n;i++)
    allocation[i]=-1;
  for(int i=0;i<m;i++)
    occupied[i]=0;
  for(int i=0;i<n;i++)
  {
    int ind=-1;
    for(int j=0;j<m;j++)
    {
      if(blockSize[j] >= processSize[i] && !occupied[j])
      {
        if(ind==-1)
          ind = j;
        else if(blockSize[j] < blockSize[ind])
          ind=j;
      }
    }
    if(ind !=-1)
    {
      allocation[i]=ind;
      occupied[ind]=1;
    }
  }
  printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


int main()
{
    int m;
    printf("Enter no. of blocks: ");
    scanf("%d", &m);
    int blockSize1[m], blockSize2[m];
    printf("Enter block sizes:\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &blockSize1[i]);
        blockSize2[i] = blockSize1[i];
    }

    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter process sizes:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    firstFit(blockSize1, m, processSize, n);
    bestFit(blockSize2, m, processSize, n);

    return 0;
}
