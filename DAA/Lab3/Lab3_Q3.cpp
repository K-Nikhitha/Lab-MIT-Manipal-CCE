#include<iostream>
#include<list>
using namespace std;
class Graph
{
  int vertices;
  list<int> *adj;
  bool *reach;
  void DFS(int v);
public:
  Graph(int v);
  void addEdge(int v1, int v2);
  bool isConnected();
};

Graph::Graph(int v)
{
    vertices = v;
    adj = new list<int>[v];
    reach = new bool[v];
}

void Graph::addEdge(int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

void Graph::DFS(int v)
{
    reach[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!reach[*i])
            DFS(*i);
}
bool Graph::isConnected()
{
  DFS(0);
  for(int i=0;i<vertices;i++)
    if(reach[i]==false)
      return false;
    return true;
}

int main()
{
  int v, a, b;
  cout << "Enter no. of  vertices in the graph: ";
  cin >> v;
  Graph g(v);
  cout << "Enter edges of graph (a b) [Enter -1 -1 to exit]: " << endl;
  while(true)
  {
      cin >> a >> b;
      if(a != -1 && b != -1)
          g.addEdge(a, b);
      else
          break;
  }
  if (g.isConnected())
    cout<<"Connected Graph."<<endl;
  else
    cout<<"Disconnected Graph"<<endl;

  return 0;
}
