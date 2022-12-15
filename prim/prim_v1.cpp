#include <iostream>
#include <vector>
#include <queue>
#define DEBUG if(1)
#define INFINITY 100000


void prim(std::vector<std::vector<int>> graph, int s, int pre[], int cost[]){
    int len_v = graph[0].size();
    int pas[len_v];
    for (int i=0; i<len_v; ++i){
        cost[i]=INFINITY;
        pre[i]=-1;
        pas[i]=0;
    }
    cost[s]=0;
    pre[s]=s;
    std::priority_queue<std::pair<int, int>> h = std::priority_queue<std::pair<int, int>>();
    h.push({0,s});
    while (!h.empty()){
        // int vert_c = h.top().first;
        int vert_v = h.top().second;
        h.pop();
        if (pas[vert_v]==1){continue;}
        else{pas[vert_v]=1;}
        for (int z=0; z<len_v; ++z){
            if (pas[z]==0 && graph[vert_v][z]!=0 && cost[z]>graph[vert_v][z]){
                // DEBUG{std::cout<<"HERE\n";}
                cost[z]=graph[vert_v][z];
                h.push({-cost[z],z});
                pre[z]=vert_v;
            }
        }
    }
}


int main(int argv, char** argc){
    int n, m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> graph = std::vector<std::vector<int>>(n, std::vector<int>(n,0));
    for (int i=0; i<m; ++i){
        int a, b, w;
        std::cin>>a>>b>>w;
        graph[a][b]=w;
        graph[b][a]=w;
    }
    DEBUG{
        for (int j=0; j<n; ++j){
            for (int k=0; k<n; ++k)
            {std::cout << "|" << graph[j][k]<<"|";}
            std::cout<<"\n";
        }
    }

    int init = 0;
    int previews[n];
    int cost_weight[n];
    prim(graph, init, previews, cost_weight);

    DEBUG{
        std::cout<<"RESULT\n";
        for (int l=0; l<n; ++l){
            std::cout << "|" << cost_weight[l]<<"|"<<previews[l]<<"|";
            std::cout<<"\n";
        }
    }
}