#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(1)
#define INFINITY 100000


int min(int x, int y){return x>y?y:x;}


void bellmanFord(std::vector<std::vector<int>> e, int n, int m, int s, int* d){
    for (int i=0; i<n; ++i)
    {
        d[i]=INFINITY;
    }
    d[s] = 0;

    DEBUG{std::cout<<"Calling main process...\n";}
    int change = 0;
    for (int j=0; j<n-1; j++){
        for (auto iter_e : e){
            int u = iter_e[0];
            int v = iter_e[1];
            int w = iter_e[2];
            if (d[v]>w+d[u]){change=1;}
            d[v] = min(d[v],w+d[u]);
        }
    }
    if (change==1){
        std::cout << "This graph have cicle negative.\n";
    }
}


int main(int agrc, char* argv[]){
    int m, n;

    std::cin >> n >> m;
    std::vector<std::vector<int>> edges;
    for (int i=0; i<m; ++i){
        int init, end, w;
        std::cin >> init >> end >> w;
        // std::cout<<init;
        edges.push_back({init,end,w});
    }
    DEBUG{
        std::cout<<"EDGES OF GRAPH:\n";
        for (int k=0; k<m; ++k){
            std::cout<<"|"<<edges[k][0]<<"|"<<edges[k][1]<<"|"<<edges[k][2]<<"|";
            std::cout<<"\n";
        }
        std::cout<<"Test of function min:"<<min(20,10)<<"\n";
    }

    int s=0;
    int dist[n];
    bellmanFord(edges, n, m, s, dist);

    std::cout << "Dist:\n";
    for (int j=0; j<n; ++j){
        // for (int k=0; k<n; ++k){
            std::cout<<"="<<dist[j]<<"=";
        // }
        std::cout<<"\n";
    }
    
    return 0;   
}