#include<iostream>
#include<algorithm>
using namespace std;
int store[15], n;
int g[15][15];
bool is_clique(int b)
{
  for (int i = 1; i < b; i++)
  {
    for (int j = i + 1; j < b; j++)
      if (g[store[i]][store[j]] == 0)
        return false;
  }
    return true;
}

int maxC(int i, int l)
{
    int mx = 0;
    for (int j = i + 1; j <= n; j++)
    {
        store[l] = j;
        if (is_clique(l + 1))
        {
          mx = max(mx, l);
          mx = max(mx, maxC(j, l + 1));
        }
    }
    return mx;
}

int main()
{
  int a,b;
  cout<<"Enter the number of vertices:";
  cin>>n;
  cout<<"Enter edges: (-1 -1 to end):"<<endl;
  while(true)
  {
    cin>>a>>b;
    if(a!=-1 && b!=-1)
      {
        g[a][b]=1;
        g[b][a]=1;
      }
    else
      break;
  }
cout<<maxC(0,1)<<endl;
}
