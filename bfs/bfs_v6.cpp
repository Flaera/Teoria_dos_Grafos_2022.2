#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(1)

int cnt;

void BFS(Vector<Vector<int>> g, int pre[], int vertex_init){
    cnt = 0;
    g.size()
}


int main(){
    int lenx, leny;
    std::cin >> lenx;
    std::cin >> leny;
    DEBUG{std::cout<<"lenx,leny="<<lenx<<","<<leny<<"\n";}
    // lenx++;

    Vector<Vector<int>> graph = new Vector<Vector<int>>;
    
    // graph = new int*[lenx];
    for (int k = 0; k<lenx; ++k){
        // graph[k] = new int[lenx];
        for (int l = 0; l<lenx; ++l)
        {
            graph[k][l]=0;
        }
    }
    DEBUG{std::cout<<"HERE\n";}
    for (int i=0; i<lenx; ++i){
        int init_vert, end_vert, weight;
        std::cin >> init_vert;
        getchar();
        std::cin >> end_vert;
        getchar();
        std::cin >> weight;
        getchar();
        DEBUG{std::cout << "FOI UM!\n";}
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

    for (size_t i=0; (int)i<lenx; ++i){delete[] graph[i];}
    delete[] graph;

    return 0;
}