#include<iostream>
#include<algorithm>
using namespace std;

int knapsack(int wt[], int val[], int n, int c)
{
  int f[n][c];
  int wMax = min(wt[n]-1,c);
  for(int i=0;i<=wMax;i++)
    f[n][i]=0;
  for(int i =wt[n];i<=c;i++)
    f[n][i]=val[n];
  for(int i=n-1;i>1;i--)
  {
    wMax = min(wt[i]-1,c);
    for(int j=0;j<=wMax;j++)
      f[i][j]=f[i+1][j];
    for(int j=wt[i];j<=c;j++)
      f[i][j]=max(f[i+1][j],f[i+1][j-wt[i]]+val[i]);
  }
  f[1][c]=f[2][c];
  if(c>=wt[1])
    f[1][c]=max(f[1][c],f[2][c-wt[1]]+val[1]);
    return f[n][c];
}

int main()
{
  int n,c;
  cout<<"Enter number of items: ";
  cin>>n;
  int val[n+1],wt[n+1];
  cout<<"Enter Weight and corresponding value of each item:\n";
  for(int i=1;i<=n;i++)
    cin>>wt[i]>>val[i];
  cout<<"Enter Capacity: ";
  cin>>c;
  cout << knapsack(wt,val,n+1,c)<<endl;
  return 0;
}
