#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define DEBUG if(1)


bool IsEdge(int v1, int v2, int **g){if(g[v1][v2]==1){return true;}else{return false;}}


void BFS(int len_vertex, int len_edges, int v, int distances[], int **g){

    int depth = 0;
    int pre[len_vertex];
    for (int i=0; i<len_vertex; ++i){
        pre[i]=-1;
        distances[i] = INT_MAX;
    }

    std::queue<int> q;
    pre[v] = depth;
    q.push(v);
    distances[v] = depth;
    while (!q.empty()){
        int curr_vertex = q.front();
        q.pop();
        for (int j = 0; j<len_vertex; ++j){
            // DEBUG{std::cout<<"j=",*j;}
            for (int k=0; k<len_vertex; ++k)
            {
                if (pre[j]==-1 && IsEdge(j,k,g)){
                    DEBUG{std::cout<<"HERE\n";}
                    pre[j]=depth;
                    q.push(j);
                    distances[j]=depth;
                    // g[j][k] = 0;
                    // g[k][j] = 0;
                }
            }
        }
        depth++;
    }

    return;
}


int main(){
    int lenx, leny;
    std::cin >> lenx;
    std::cin >> leny;
    DEBUG{std::cout<<"lenx,leny="<<lenx<<","<<leny<<"\n";}

    int **graph;
    
    graph = new int*[lenx+1];
    for (int k = 0; k<=lenx; ++k){
        graph[k] = new int[lenx+1];
        for (int l = 0; l<=lenx; ++l)
        {
            graph[k][l]=0;
        }
    }
    DEBUG{std::cout<<"HERE\n";}
    for (int i=0; i<leny; ++i){
        int init_vert, end_vert, weight;
        std::cin >> init_vert;
        std::cin >> end_vert;
        std::cin >> weight;
        // std::vector<int>::iterator j = init_vert;
        // std::vector<int>::iterator k = end_vert;
        graph[init_vert][end_vert]=weight;
        graph[end_vert][init_vert]=weight;
    }
    DEBUG{
        for (int l=0; l<=lenx; ++l){
            for (int m=0; m<lenx; ++m){
                std::cout<<"-"<<graph[l][m]<<"-";
            }
            std::cout<<"\n";
        }
    }

    // int vert_init = 1; int vert_end = 2;
    int distances[lenx];
    int v = 1;
    BFS(lenx+1, leny, v, distances, graph);

    for (int m=0; m<lenx+1; m++){
        std::cout << "|" << distances[m]<< "|";
    }
    std::cout<<"\n";
    
    // for (size_t i=0; (int)i<lenx; ++i){delete[] graph[i];}
    // delete[] graph;

    return 0;
}