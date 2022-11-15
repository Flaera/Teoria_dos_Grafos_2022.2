#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <string.h>
#define DEBUG if(1)


void Dijkstra(std::vector<std::vector<int>> graph, int s, int dist[], int pre[]){
    int len = graph.size();
    for (int u=0; u<len; ++u){
        dist[u] = INT_MAX;
        pre[u] = -1;
    }
    dist[s] = 0;
    std::priority_queue<std::pair<int, int>> h;
    h.push({s, dist[0]});
    while(!h.empty()){
        int i = h.top().first;
        // int j = h.top().second;
        h.pop();
        for (int v=0; v<len; ++v){
            if (graph[i][v]!=0){
                if (pre[v]==-1){
                    if (dist[v]>dist[i]+graph[i][v]){
                        dist[v]=dist[i]+graph[i][v];
                        pre[v] = i;
                        h.push({v, dist[v]});
                        std::cout<<"UMA VEZ\n";
                    }
                }
            }
        }
    }
}


int main(int argc, char** argv){

    int lenx, leny;
    std::cin >> lenx >> leny;

    std::vector<std::vector<int>> graph(lenx, std::vector<int>(lenx, 0));
    
    for (int i=0; i<lenx; i++){
        int vertex_init, vertex_end, weight;
        std::cin >> vertex_init >> vertex_end >> weight;
        graph[vertex_init][vertex_end] = weight;
        graph[vertex_end][vertex_init] = weight;
    }

    int dist[lenx];
    int pre[lenx];

    Dijkstra(graph, 0, dist, pre);

    DEBUG{
        std::cout << "Dist e pre:\n";
        for (int j=0; j<lenx; ++j){
            std::cout<<"dist="<<dist[j]<<",pre="<<pre[j]<<"\n";
        }
    }

}