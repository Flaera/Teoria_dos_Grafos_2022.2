#include <iostream>
#include <vector>
#define DEBUG if(1)


int acc = 0;


void DFSrec(std::vector<std::vector<int>> g, int pre[], int vertex){
    pre[vertex]=acc++;
    int lenght = g.size();
    for (int w=0; w<lenght; ++w){
        if (pre[w]==-1)
        {DFSrec(g, pre, w);}
    }
}


void DFS(std::vector<std::vector<int>> g, int pre[], int vert_init){
    int lenght = g.size();
    for (int i=0; i<lenght; ++i){
        pre[i]=-1;
    }
    for (int j=0; j<lenght; ++j){
        if (pre[j]==-1){
            DFSrec(g, pre, j);
        }
    }
}

int main(){
    int lenx, leny;
    std::cin >> lenx;
    std::cin >> leny;

    std::vector<std::vector<int>> graph(lenx, std::vector<int>(lenx, 0));

    for (int i=0; i<lenx; ++i){
        graph[i].push_back(0);
    }
    for (int j=0; j<lenx; ++j){
        for (int k=0; k<lenx; ++k){
            int weight, vert_init, vert_end;
            std::cin>>weight;
            std::cin>>vert_end;
            std::cin>>vert_init;
            graph[vert_end][vert_init]=weight;
            graph[vert_init][vert_end]=weight;
        }
    }
    DEBUG{
        for (int l=0; l<lenx; ++l){
            for (int m=0; m<lenx; ++m){
                std::cout<<"-"<<graph[l][m];
            }
            std::cout<<"\n";
        }
    }

    int v = 0;
    int pre[lenx];
    DFS(graph, pre, v);

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

