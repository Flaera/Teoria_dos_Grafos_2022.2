#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(1)
#define INFINITY 100000

int min(int x, int y){return x>y?y:x;}


std::vector<int> bellmanFord(std::vector<std::vector<int>> g, int n, int m, int s, std::vector<int> d){
    for (int i=0; i<n; ++i){
        d[i]=INFINITY;
    }

    d[s] = 0;

    DEBUG{std::cout<<"Calling main process...\n";}
    
        for (int k=0; k<n; ++k){
            for (int i=0; i<n; ++i)
            {
                if(g[k][i] != INFINITY){
                    d[i] = min(d[i], d[k]+g[k][i]);
                }
            }
        }
    return d;
}


int main(){
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
    std::vector<int> dist(n, 0);
    DEBUG{std::cout<<"Calling the function\n";}
    dist = bellmanFord(graph, n, m, s, dist);

    std::cout << "Dist:\n";
    for (int j=0; j<n; ++j){
        
            std::cout<<"="<<dist[j]<<"=";
        
        std::cout<<"\n";
    }
    
    return 0;   
}