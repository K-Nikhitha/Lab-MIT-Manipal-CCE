#include<iostream>
#include<list>
using namespace std;

class Graph
{
  int vertices;
  list<int> *adj;
  bool *reach;
  void PrintPath(int s, int d, int path[], int index);
public:
  Graph(int v);
  bool PathExists;
  void addEdge(int s, int d);
  void PathFinder(int s, int d);
};

Graph::Graph(int v)
{
    vertices = v;
    adj = new list<int>[v];
    reach = new bool[v];
}

void Graph::addEdge(int s, int d)
{
    adj[s].push_back(d);
}
void Graph::PrintPath(int s, int d, int path[], int index)
{
  reach[s]=true;
  path[index]=s;
  index++;
  if(s==d)
  {
    int i;
    if(!PathExists)
      cout<<"Path: "<<endl;
    PathExists = true;
    for(i=0;i<index-1;i++)
      cout<<path[i]<<"-->";
    cout<<path[i]<<endl;
  }
  else
  {
    list<int>::iterator i;
    for(i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!reach[*i])
            PrintPath(*i,d,path,index);
  }
  index--;
  reach[s]=false;

}
void Graph::PathFinder(int s, int d)
  {
    int *path = new int[vertices];
    int index = 0;
    PathExists = false;
    PrintPath(s,d,path,index);
  }

int main()
{
  int v, a, b, s, d;
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
  cout<<"Enter Source Node: ";
  cin>>s;
  cout<<"Enter Destination Node: ";
  cin>>d;
  g.PathFinder(s,d);
  if(!g.PathExists)
  {
    cout<<"Path DNE."<<endl;
  }
  return 0;
}
