#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int vertices;
    list<int> *adj;
    bool *reach;

public:
    Graph(int v);
    void addEdge(int v1, int v2);
    void DFS(int v);
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
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!reach[*i])
            DFS(*i);
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
    cout << "Enter root node for DFS: ";
    cin >> rn;
    g.DFS(rn);
    return 0;
}
