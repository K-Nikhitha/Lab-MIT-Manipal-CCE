#include <iostream>
using namespace std;
#define INF 9999
int n;
void floydWarshall(int *mx[n])
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (mx[i][k] + mx[k][j] < mx[i][j])
          mx[i][j] = mx[i][k] + mx[k][j];
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (mx[i][j] == INF)
        cout<<"Inf   ";
      else
        cout<<mx[i][j]<<"      ";
    }
    cout<<endl;
  }
}

int main()
{
  int a,b,c;
  cout<<"Enter the Number of vertices:";
  cin>>n;
  int** mx;
  mx = new int*[n];
  for(int i=0;i<n; ++i)
      mx[i] = new int[n];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      mx[i][j]=INF;
    mx[i][i]=0;
  }

  cout << "Enter edges of graph and cost (a b c) [Enter -1 -1 -1 to exit]: " << endl;
  while(true)
  {
      cin >>a>>b>>c;
      if(a != -1 && b != -1 && c!= -1)
          mx[a][b]=c;
      else
          break;
  }

  floydWarshall(mx);
  return 0;
}

/*
4 vertices

0 1 5
0 3 10
1 2 3
2 3 1
-1 -1 -1

Output:

0      5      8      9
Inf   0      3      4
Inf   Inf   0      1
Inf   Inf   Inf   0
*/
