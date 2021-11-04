#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int source;
    int destination;
    int weight;
};

bool compare(Edge a,Edge b){
    return a.weight < b.weight;
}

int getParent(int v,int parent[]){
    if(parent[v]==v){
        return v;
    }
    return getParent(parent[v],parent);
}

void kruskal_tempo(Edge edges[], int n , int E){
    int edgeCount = 0;
    sort(edges,edges+E,compare);
    Edge output[n-1];
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count < n-1){
        int p1=getParent(edges[i].source,parent);
        int p2=getParent(edges[i].destination,parent);
        if(p1!=p2){
            output[count]=edges[i];
            count++;
            parent[p2]=p1;
        }
        i++;
    }
    for(int i=0;i<n-1;i++){
        edgeCount = edgeCount+output[i].weight;
        cout<<output[i].source<<" "<<output[i].destination<<endl;
    }
    cout<<"Sum of edge : "<<edgeCount;
}

int main()
{
    int V = 4, E = 5;
    int edges[E][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Edge edge[E];
    for(int i = 0;i<E;i++){
        edge[i] = {edges[i][0],edges[i][1],edges[i][2]};
    }

    kruskal_tempo(edge,V,E);
    return 0;
}
