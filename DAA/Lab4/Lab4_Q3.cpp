#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int vertices;
    list<int>* adj;
    bool *reach;
    void topological(int v, stack<int>& Stack);
public:
    Graph(int v);
    void addEdge(int v1, int v2);
    void topologicalSort();
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

void Graph::topological(int v,stack<int>& Stack)
{
    reach[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!reach[*i])
            topological(*i, Stack);
    Stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> Stack;
    for (int i = 0; i < vertices; i++)
        if (reach[i] == false)
            topological(i, Stack);
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
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
    cout << "Topological Sort:"<<endl;
    g.topologicalSort();
    cout<<endl;
    return 0;
}

/* 5 2
5 0
4 0
4 1
2 3
3 1

5 4 2 3 1 0
*/
