#include <stdio.h>
int main()
{
  int pages;
  printf("Enter number of pages:");
  scanf("%d",&pages);
  int incomingStream[pages];
  for(int i = 0; i < pages; i++)
  {
      scanf("%d", &incomingStream[i]);
  }
  int pageFaults = 0,frames;
  printf("Enter number of frames:");
  scanf("%d",&frames);
    int m, n, s;
    printf("Incoming \t ");
    for(m = 0; m < frames; m++)
    {
        printf("Frame %d \t",m+1);
    }
    int temp[frames];
    for(m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for(m = 0; m < pages; m++)
    {
        s = 0;

        for(n = 0; n < frames; n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;

        if((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if(s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("\n");
        printf("%d\t\t",incomingStream[m]);
        for(n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t", temp[n]);
            else
                printf(" - \t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
