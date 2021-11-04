#include <bits/stdc++.h>
using namespace std;


struct Edge
{
    int source;
    int destination;
    int weight;
};

bool compare(Edge a,Edge b)
{
    return a.source < b.source;
}

int minimumDist(int dist[], bool Tset[],int V)
{
    int min =INT_MAX,index;

    for(int i=0; i<V; i++)
    {
        if(Tset[i]==false && dist[i]<=min)
        {
            min=dist[i];
            index=i;
        }
    }
    return index;
}


int main()
{
    int V = 9, E = 14;
    int edges[E][3] =
    {
        {0, 1, 10},
        {0, 2, 12},
        {1, 2, 9},
        {1, 3, 8},
        {2, 4, 4},
        {2, 5, 1},
        {3, 4, 7},
        {3, 6, 8},
        {3, 7, 5},
        {4, 5, 3},
        {5, 7, 6},
        {6, 7, 9},
        {6, 8, 2},
        {7, 8, 11}
    };

    int s=1;
    Edge edge[E];
    for(int i = 0; i<E; i++)
    {
        edge[i] = {edges[i][0],edges[i][1],edges[i][2]};
    }
    sort(edge,edge+E,compare);

    int arr[V][V];
    int xpo = 0;
    while(xpo!=E)
    {
        arr[edge[xpo].source][edge[xpo].destination] = edge[xpo].weight;
        xpo++;
    }

    int arr2[V][V];
    for(int i = 0; i<V; i++)
    {
        for(int j = 0; j<V; j++)
        {
            if(arr[i][j] > 100 || arr[i][j] < 0)
            {
                arr2[i][j] = 0;
            }
            else
            {
                arr2[i][j] = arr[i][j];
            }
        }
    }

    int dist[V];
    bool Tset[V];
    for(int i = 0; i<V; i++)
    {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }

    dist[s] = 0;

    for(int i = 0; i<V; i++)
    {
        int m=minimumDist(dist,Tset,V);
        Tset[m]=true;
        for(int i = 0; i<V; i++)
        {

            if(!Tset[i] && arr2[m][i] && dist[m]!=INT_MAX && dist[m]+arr2[m][i]<dist[i])
                dist[i]=dist[m]+arr2[m][i];
        }
    }

    for(int i = 0; i<V; i++)
    {
        if(dist[i] == INT_MAX){
            cout<<"No path from "<<s<<" to "<<i<<endl;
        }

        else if(i == s){
            cout<<"sp from "<<i<<" to "<<i<<": "<<i<<", length: 0"<<endl;
        }

        else{
            cout<<"sp from "<<s<<" to"<<i<<": "<<s<<"-->"<<i<<", length: "<<dist[i]<<endl;
        }
    }
    return 0;
}
