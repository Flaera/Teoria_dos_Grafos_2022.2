#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(1)
#define INFINITY 100000

int min(int x, int y){return x>y?y:x;}


void bellmanFord(std::vector<std::vector<int>> g, int n, int m, int s, int d[]){
    for (int i=0; i<n; ++i)
    {
        // for (int j=0; j<n; ++j)
        d[i]=INFINITY;
    }
    d[s] = 0;

    DEBUG{std::cout<<"Calling main process...\n";}
    for (int l=0; l<n; ++l){
        for (int k=0; k<n; ++k){
            // for (int i=0; i<n; ++i)
            // {
                // DEBUG{std::cout<<"HERE\n";}
            if (g[l][k]!=INFINITY){d[k] = min(d[k], d[l]+g[l][k]);}
            // }
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
    int dist[n];
    for (int p=0; p<n; ++p){
        dist[p]=0;
    }
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