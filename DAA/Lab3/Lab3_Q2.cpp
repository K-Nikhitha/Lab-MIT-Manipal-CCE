#include<iostream>
#include<list>
using namespace std;

class Graph
{
  int vertices;
  list<int> *adj;
  bool *reach;
  bool *recStack;
  bool FindIsCyclic(int v);
public:
  Graph(int v);
  void addEdge(int v1, int v2);
  bool isCyclic();
};

Graph::Graph(int v)
{
  vertices = v;
  adj = new list<int>[v];
  reach = new bool[v];
  recStack = new bool[v];
}

void Graph::addEdge(int v1, int v2)
{
    adj[v1].push_back(v2);
}

bool Graph::FindIsCyclic(int v)
{
  if(!reach[v])
  {
    reach[v]=true;
    recStack[v]=true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
      if(!reach[*i] && FindIsCyclic(*i))
        return true;
      else if(recStack[*i])
        return true;
    }
  }
  recStack[v]=false;
  return false;
}

bool Graph:: isCyclic()
{
  for(int i=0;i<vertices;i++)
    if(!reach[i] && FindIsCyclic(i))
      return true;
  return false;
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
  if(g.isCyclic())
    cout<<"Graph Contains a Cycle";
  else
    cout<<"Graph Doesnt Contain a Cycle";
  return 0;
}
