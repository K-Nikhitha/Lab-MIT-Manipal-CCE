#include <iostream>
using namespace std;
#define inf 9999

class Graph
{
  int v;
  int** adj;
  int minKey(int key[], bool mstSet[]);

public:
  Graph(int vertices);
  void addEdge(int v1, int v2, int cost);
  void primMST();
};

Graph:: Graph(int vertices)
{
  v = vertices;
  adj = new int*[v];
  for(int i=0;i<v; ++i)
      adj[i] = new int[v];
}

void Graph::addEdge(int v1, int v2, int cost)
{
    adj[v1][v2]=cost;
    adj[v2][v1]=cost;
}
int Graph::minKey(int key[], bool mstSet[])
{
    int min = inf, min_index;
    for (int i = 0; i < v; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;
    return min_index;
}
void Graph::primMST()
{
    int parent[v];
    int key[v];
    bool mstSet[v];
    for (int i = 0; i < v; i++)
        key[i] = inf;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < v - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int j = 0; j < v; j++)
            if (adj[u][j] && mstSet[j] == false && adj[u][j] < key[j])
                {
                  parent[j] = u;
                  key[j] = adj[u][j];
                }
    }
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < v; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<adj[i][parent[i]]<<" \n";
}
int main()
{
  int v,a,b,c;
  cout<<"Enter the Number of vertices:";
  cin>>v;
  Graph g(v);
  cout << "Enter edges of graph and cost (a b c) [Enter -1 -1 -1 to exit]: " << endl;
  while(true)
  {
      cin >> a >> b>>c;
      if(a != -1 && b != -1 && c!= -1)
          g.addEdge(a, b,c);
      else
          break;
  }
  g.primMST();
    return 0;
}

/*
0 1 4
0 2 3
1 2 1
1 3 2
2 3 4
3 4 2
4 5 6
*/
