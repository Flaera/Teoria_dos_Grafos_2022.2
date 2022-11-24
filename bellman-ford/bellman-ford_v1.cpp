#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(1)
#define INFINITY 100000

int min(int x, int y){return x>y?y:x;}


void bellmanFord(std::vector<std::vector<int>> g, int n, int m, int s, std::vector<std::vector<int>> d){
    for (int i=0; i<n; ++i)
    {
        // for (int j=0; j<n; ++j)
        d[0][i]=INT_MAX;
    }
    // DEBUG{std::cout<<g[3][2]<<"ERROR!!\n";}
    d[0][s] = 0;

    // DEBUG{std::cout<<g[3][2]<<"ERROR!!\n";}

    DEBUG{std::cout<<"Calling main process...\n";}
    for (int l=1; l<n-1; ++l){
        for (int k=1; k<n; ++k){
            // int before = INT_MAX;
            for (int i=0; i<n; ++i)
            {
                d[l][k] = min(d[l-1][k], min(d[l-1][i], d[l-1][i]+g[i][k]));
                // d[l][k] = min(d[l-1][k], d[l-1][i]+g[i][k]);
            }
            // d[l][k] = before;
        }
    }
}


int main(int agrc, char* argv[]){
    int m, n;

    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n,0));
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
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
    DEBUG{std::cout<<"Calling the function\n";}
    bellmanFord(graph, n, m, s, dist);

    std::cout << "Dist:\n";
    for (int j=0; j<n; ++j){
        for (int k=0; k<n; ++k){
            std::cout<<"="<<dist[j][k]<<"=";
        }
        std::cout<<"\n";
    }
    
    return 0;   
}