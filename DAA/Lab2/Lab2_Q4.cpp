#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int v1, int v2)
{
    adj[v1].push_back(v2);
}

void display(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
          cout << i << " "<< adj[i][j] << "  ";
        cout << " ";
    }
}

void transposeG(vector<int> adj[], vector<int> transpose[], int v)
{
    for (int i = 0; i < v; i++)
        for (int j = 0; j < adj[i].size(); j++)
            addEdge(transpose, adj[i][j], i);
}

int main()
{
  int v, a, b;
  cout << "Enter no. of  vertices in the graph: ";
  cin >> v;
  vector<int> adj[v];
  cout << "Enter edges of graph (a b) [Enter -1 -1 to exit]: " << endl;
  while(true)
  {
      cin >> a >> b;
      if(a != -1 && b != -1)
          addEdge(adj, a, b);
      else
          break;
  }
    vector<int> transpose[v];
    transposeG(adj, transpose, v);
    display(transpose, v);

    return 0;
}
