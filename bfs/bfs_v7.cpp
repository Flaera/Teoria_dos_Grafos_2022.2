#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(1)

int cnt;

void BFS(std::vector<std::vector<int>> g, int pre[], int vertex_init){
    cnt = 0;
    int tam = g.size();
    for (int i=0; i<tam; ++i){
        pre[i]=-1;
    }
    std::queue<int> adj;
    adj.push(vertex_init);
    pre[vertex_init]=cnt++;
    while(!(adj.empty())){
        int v = adj.front();
        adj.pop();
        for (int w=0; w<tam; ++w){
            if (g[v][w]!=0){
                if (pre[w]==-1){
                    pre[w]=cnt++;
                    adj.push(w);
                }
            }
        }
    }
}


int main(){
    int lenx;
    int leny;
    std::cin >> lenx;
    std::cin >> leny;
    DEBUG{std::cout<<"lenx,leny="<<lenx<<","<<leny<<"\n";}
    // lenx++;

    std::vector<std::vector<int>> graph(lenx, std::vector<int>(0));
    // graph = new std::vector<std::vector<int>>;
    
    // graph = new int*[lenx];
    std::cout<<"HERE!\n";
    for (int k = 0; k<lenx; ++k){
        // graph[k] = new int[lenx];
        for (int l = 0; l<lenx; ++l)
        {
            graph[l].push_back(0);
        }
    }
    for (int i=0; i<lenx; ++i){
        int init_vert, end_vert, weight;
        std::cin >> init_vert;
        std::cin >> end_vert;
        std::cin >> weight;
        std::cout<<"HERE\n";
        graph[init_vert][end_vert]=weight;
        graph[end_vert][init_vert]=weight;
    }
    DEBUG{
        std::cout<<"Graph_Vector_Matrix_Adj:\n";
        for (int l=0; l<lenx; ++l){
            for (int m=0; m<lenx; ++m){
                std::cout<<"-"<<graph[l][m]<<"-";
            }
            std::cout<<"\n";
        }
    }

    // int vert_init = 1; int vert_end = 2;
    int v = 0;
    int pre[lenx];
    BFS(graph, pre, v);

    DEBUG{
        std::cout<<"DEBUG graph:\n";
        for (int m=0; m<lenx; ++m){
            for (int n=0; n<lenx; ++n){
                std::cout<<"-"<<graph[m][n]<<"-";
            }
            std::cout<<"\n";
        }
        std::cout<<"DEBUG pre:\n";
        for (int o=0; o<lenx; ++o){
            std::cout<<"-"<<pre[o]<<"\n";
        }
    }

    return 0;
}