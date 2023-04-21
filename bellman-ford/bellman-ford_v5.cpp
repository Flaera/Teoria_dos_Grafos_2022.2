#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(1)
#define INFINITY 100000

int min(int x, int y){return x>y?y:x;}


class Edge{
    public:
        int src;
        int dest;
        int weight;
};


void bellmanFord(std::vector<std::vector<int>> g, int n, int m, int s, int* d){
    for (int i=0; i<n; ++i)
    {
        // for (int j=0; j<n; ++j)
        d[i]=INFINITY;
    }
    d[s] = 0;

    //Construindo o array de edges, já que é necessário navegar pelas edges no Bellman-Ford
    std::vector<Edge> edges = std::vector<Edge>();
    int acc = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            DEBUG{std::cout<<"i="<<i<<"j="<<j<<"\n";}
            if (g[i][j]!=INFINITY){
                edges[acc].src=i;
                edges[acc].dest=j;
                edges[acc].weight=g[i][j];
                acc++;
            }
        }
    }

    DEBUG{std::cout<<"Calling main process...\n";}
    for (int l=1; l<n-1; ++l){
        for (int k=0; k<m; ++k){
            DEBUG{std::cout<<"k="<<k<<"\n";}
            if (d[edges[k].src]!=INFINITY && ((d[edges[k].src]+edges[k].weight)<d[edges[k].dest])){
                d[edges[k].dest] = d[edges[k].src]+edges[k].weight;
            }
        }
    }
}


int main(int agrc, char* argv[]){
    int m, n;

    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n,INFINITY));
    for (int i=0; i<m; ++i){
        int init, end, w;
        std::cin >> init >> end >> w;
        // std::cout<<init;
        graph[init][end]=w;
        graph[end][init]=w;
    }
    DEBUG{
        std::cout<<"MATRIX  GRAPH:\n";
        for (int m=0; m<n; ++m){
            for (int k=0; k<n; ++k){std::cout<<"|"<<graph[m][k]<<"|";}
            std::cout<<"\n";
        }
        std::cout<<"Test of function min:"<<min(20,10)<<"\n";
    }

    int s=0;
    int dist[INFINITY];
    DEBUG{std::cout<<"Calling the function...\n";}
    bellmanFord(graph, n, m, s, dist);

    std::cout << "Dist:\n";
    for (int j=0; j<n; ++j){
        // for (int k=0; k<n; ++k){
            std::cout<<"="<<dist[j]<<"=";
        // }
        std::cout<<"\n";
    }
    
    return 0;   
}