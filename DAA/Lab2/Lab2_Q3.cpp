#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int vertices;
    list<int> *adj;

public:
    bool *reach;
    Graph(int v);
    void addEdge(int v1, int v2);
    void DFS(int v);
    int FindMotherV();
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
}

void Graph::DFS(int v)
{
    reach[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!reach[*i])
            DFS(*i);
}
int Graph ::FindMotherV()
{
  int v=0;
  for(int i=0;i<vertices;i++)
    if (!reach[i])
    {
      DFS(i);
      v=i;
    }
  DFS(v);
  for(int i=0;i<vertices;i++)
    if(!reach[i])
    return -1;
  return v;
}
int main()
{
    int v, a, b;
    cout << "Enter no. of  vertices in the graph: ";
    cin >> v;
    int vert[v],i;
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
    i=g.FindMotherV();
    if(i==-1)
      cout<<"No Mother Vertex."<<endl;
    else
      cout<<"Mother Vertex: "<<i<<endl;
    return 0;
}
