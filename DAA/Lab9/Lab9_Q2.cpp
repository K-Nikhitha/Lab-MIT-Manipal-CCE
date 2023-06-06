#include <iostream>
using namespace std;

class Graph
{
  int v;
  int **adj;
  bool *reach;
public:
  Graph(int v);
  void addEdge(int v1, int v2, int c);
  void tsp(int currPos, int count, int cost, int& ans);
};
Graph::Graph(int n)
{
    v = n;
    reach = new bool[v];
    reach[0]=true;
    adj = new int*[v];
    for(int i=0;i<v; ++i)
        adj[i] = new int[v];
    for(int i=0;i<v;++i)
    {
      adj[i][i]=0;
    }
}
void Graph::addEdge(int v1, int v2, int cost)
{
    adj[v1][v2]=cost;
    adj[v2][v1]=cost;
}
void Graph::tsp(int currPos, int count, int cost, int& ans)
{

    // If last node is reached and it has a link
    // to the starting node i.e the source then
    // keep the minimum value out of the total cost
    // of traversal and "ans"
    // Finally return to check for more possible values
    if (count == v && adj[currPos][0])
    {
        ans = min(ans, cost + adj[currPos][0]);
        return;
    }

    // BACKTRACKING STEP
    // Loop to traverse the adjacency list
    // of currPos node and increasing the count
    // by 1 and cost by graph[currPos][i] value
    for (int i = 0; i < v; i++)
    {
        if (!reach[i] && adj[currPos][i])
        {
            // Mark as visited
            reach[i] = true;
            int x = adj[currPos][i];
            tsp(i, count + 1,cost + x, ans);
            // Mark ith node as unvisited
            reach[i] = false;
        }
    }
}

int main()
{
  int n,a,b,c;
  cout<<"Enter number of vertices:";
  cin>>n;
  Graph g(n);
  cout<<"Enter Edges and Cost (-1 -1 -1 to end):"<<endl;
  while(true)
  {
    cin>>a>>b>>c;
    if(a!=-1 && b!=-1 && c!=-1)
      g.addEdge(a,b,c);
    else
      break;
  }
  int ans = INT_MAX;
  g.tsp(0, 1, 0, ans);
  cout << ans<<endl;
  return 0;
}
