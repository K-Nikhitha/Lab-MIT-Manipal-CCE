#include<iostream>
using namespace std;
int r, c;
class SM
{
  public:
    int row, col, val;
    void create_SM(int r, int c, int v);
    void FastTranspose(SM a[], SM b[],);
    void display();
};
void SM :: create_SM(int r, int c, int v)
{
    row = r;
    col = c;
    val = v;
}
void SM :: FastTranspose(SM a[], SM b[])
  int rr[c],start[c];
  int i, j;
  b[0].row = a[0].col;
  b[0].col = a[0].row;
  b[0].val = a[0].val;
  if(a[0].val>0)
  {
    for(i = 0; i<a[0].col; i++)
      rr[i] = 0;
    for(i = 1; i<= a[0].val; i++)
      rr[a[i].col]++;
    start[0]=1;
    for(i = 1; i<a[0].col; i++)
      start[i] = start[i-1] + rr[i-1];
    for(i=1; i<=a[0].val; i++)
    {
      j=start[a[i].col]++;
      b[j].row = a[i].col;
      b[j].col = a[i].row;
      b[j].val = a[i].val;
    }
  }
}
void SM :: display()
{
  cout<<row<<" "<<col<<" "<<val<<" \n";
}

int main()
{
    int count = 0, k=1;
    cout<<"Enter the number of rows: ";
    cin>>r;
    cout<<"Enter the number of columns: ";
    cin>>c;
    int mx[r][c];
    cout<<"Enter the elements of the matrix "<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>mx[i][j];
            if(mx[i][j] != 0)
              count++;
        }
    }
    SM a[count+1];
    a[0].create_SM(r,c,count);
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        if(mx[i][j]!=0)
        {
          a[k++].create_SM(i,j,mx[i][j]);
        }
      }
    }
    cout<<"Matrix before Transposing:\n";
    for(int i=0; i<=count; i++)
    {
      a[i].display();
    }
    SM b[count+1], temp;
    cout<<"Matrix after transposing:\n";
    temp.FastTranspose(a, b);
    for(int i=0; i<=count; i++)
    {
      b[i].display();
    }
}
