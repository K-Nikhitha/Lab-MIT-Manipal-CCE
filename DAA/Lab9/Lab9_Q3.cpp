#include<bits/stdc++.h>



using namespace std;



class Node{

    public:

        int graph[25], maxVertex = 0, level;

};



bool complete(list<int> graph[], int n, Node v){

    list<int>::iterator iter;

    int flag = 0;

    for(int i = 0; i<n; i++){

        if(v.graph[i]==1){

            for(int j = 0; j<n; j++){

                if(i==j) continue;

                flag = 0;

                if(v.graph[j]!=1) continue;

                else{

                    for(iter = graph[i].begin(); iter!=graph[i].end(); ++iter){

                        if(*iter==(j+1)){

                            flag = 1;

                            break;

                        }

                    }

                }

                if(flag!=1) return false;

            }

        }

    }

    return true;

}



int clique(list<int> graph[], int n){

    queue<Node> Q;

    Node u, v;

    int maxvertex = 0;

    u.level = -1;

    u.maxVertex = 0;

    Q.push(u);

    while(!Q.empty()){

        u = Q.front();

        Q.pop();

        if(u.level==-1) v.level = 0;

        else if(u.level==n-1) continue;

        v.level = u.level+1;

        v.maxVertex = u.maxVertex+1;

        v.graph[v.level] = 1;

        if(complete(graph, n, v) && v.maxVertex>maxvertex) maxvertex = v.maxVertex;

        Q.push(v);

        --v.maxVertex;

        v.graph[v.level] = 1;

        Q.push(v);

    }

    return maxvertex;

}



int main(){

    cout<<"Program to find maximum clique of graph using branch and bound technique.\n";

    cout<<"Enter the number of vertices in graph: ";

    int n, a;

    cin>>n;

    list<int> graph[n];

    cout<<"Enter the adjacency list:\n";

    for(int i = 0; i<n; i++){

        while(1){

            cin>>a;

            if(a!=0) graph[i].push_back(a);

            else break;

        }

    }

    cout<<"The maximum clique value is: "<<clique(graph, n);

    return 1;

}
