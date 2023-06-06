#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
  int vertices;
  list<int> *adj;
  bool *reach;

public:
  Graph(int v);
  void addEdge(int v1, int v2);
  void BFS(int rn);
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

  void Graph::BFS(int rn)
{

  queue<int> q;
  reach[rn]=true;
  q.push(rn);
  list<int>::iterator i;
  while(!q.empty())
  {
    int w = q.front();
    cout<<w<<" ";
    q.pop();
    for(i = adj[w].begin(); i != adj[w].end(); ++i)
    {
      if(!reach[*i])
      {
        reach[*i]=true;
        q.push(*i);
      }
    }
  }
}
int main(){
    int v, a, b, rn;
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
    cout << "Enter root node for BFS: ";
    cin >> rn;
    g.BFS(rn);
    return 0;
}
