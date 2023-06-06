// Banker's Algorithm
#include <stdio.h>
int main()
{
    int n, m;
    printf("Enter the number of proceesses: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m], need[n][m];
    printf("Enter the Allocation matrix: \n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the Max matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &max[i][j]);

    printf("Enter the available resources:\n");
    for(int i=0;i<m;i++)
        scanf("%d", &avail[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int work[m],ind=0,safeseq[n];
    int finish[n];
    for(int i=0;i<n;i++)
        finish[i]=0;
    for(int i=0;i<m;i++)
      work[i]=avail[i];

    int y = 0,k,i,j;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                    {
                        flag = 1;
                        break;
                    }

                if (flag == 0)
                {
                    safeseq[ind++] = i;
                    for (y = 0; y < n; y++)
                        work[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }

    int flag = 1;
    for(int i=0;i<n;i++)
        if(!finish[i])
        {
            flag=0;
            printf("The following system is not safe\n");
            break;
        }

    if(flag==1)
    {
        printf("Following is the Safe Sequence:\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", safeseq[i]);
        printf(" P%d \n", safeseq[n - 1]);
    }

    return 0;
}

/*
{{ 0, 1, 0 } // P0    // Allocation Matrix
 { 2, 0, 0 } // P1
 { 3, 0, 2 } // P2
 { 2, 1, 1 } // P3
 { 0, 0, 2 }} // P4

{{ 7, 5, 3 } // P0    // MAX Matrix
 { 3, 2, 2 } // P1
 { 9, 0, 2 } // P2
 { 2, 2, 2 } // P3
 { 4, 3, 3 }} // P4

{ 3, 3, 2 }

P1 -> P3 -> P4 -> P0 -> P2
*/
