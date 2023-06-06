
#include<iostream>
using namespace std;
#define inf 9999
class Graph
{
  int v;
  int** adj;
  bool *reach;
  int min_Dist(int dist[]);
public:
  Graph(int vertices);
  void addEdge(int v1, int v2, int cost);
  void Dijkstra(int src);
};
Graph:: Graph(int vertices)
{
  v = vertices;
  reach = new bool[v];
  adj = new int*[v];
  for(int i=0;i<v; ++i)
      adj[i] = new int[v];
  for(int i=0;i<v;++i)
  {
    for(int j=0;j<v;j++)
              adj[i][j] = inf;
    adj[i][i]=0;
  }

}

void Graph::addEdge(int v1, int v2, int cost)
{
    adj[v1][v2]=cost;
}

int Graph::min_Dist(int dist[])
{
	int min=inf,index;
	for(int i=0;i<v;i++)
	{
		if(reach[i]==false && dist[i]<=min)
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}
void Graph::Dijkstra(int src)
{
  for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
      if(adj[i][j]==0)
        adj[i][j]=inf;
	int dist[v];
	for(int i=0;i<v;i++)
	{
		dist[i]=inf;
	}
	dist[src]=0;
	for(int c=1;c<v;c++)
	{
		int u=min_Dist(dist);
		reach[u]=true;                          //vertex u is now visited
		for(int i=0;i<v;i++)
		{
			if(!reach[i] && adj[u][i] &&dist[u]+adj[u][i]<dist[i])
			dist[i]=dist[u]+adj[u][i];
		}
	}
	cout<<"The shortest path  "<<src<<" to all the other vertices is: \n";
	for(int i=0;i<v;i++)
	{
	   if(i!=src)
	   cout<<"source:"<<src<<"\t destination:"<<i<<"\t MinCost is:"<<dist[i]<<"\n";
	}
}
int main()
{
  int v,a,b,c,s;
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
cout<<"\n Enter the Source Vertex";
cin>>s;
	g.Dijkstra(s);
	return 0;
}

/*
0 1 9
0 3 5
1 0 9
1 2 1
1 3 2
2 1 1
2 3 9
2 4 6
3 0 5
3 1 2
3 2 9
3 4 4
4 2 6
4 3 4
-1 -1 -1
*/
