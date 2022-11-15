#include <iostream>
#include <queue>

#define DEBUG if(1)


void BFS(int len_vertex, int len_edges, int posx_init, int posy_init, int distances[], int **g){
    int depth = 0;
    bool visiteds[len_vertex];
    for (int i=0; i<len_vertex; ++i){
        visiteds[i] = false;
        distances[i] = 0;
    }
    std::queue<int> q;
    q.push(g[posx_init][posy_init]);
    visiteds[posx_init] = true;
    distances[posx_init] = 1;
    // int posx=posx_init; int posy=posy_init;

    while (!q.empty()){
        int v = q.front();
        q.pop();
        DEBUG{std::cout<<"v:"<<v<<"\n";}
        
        int array_adj[len_vertex][len_vertex];
        int array_adj_visiteds[len_vertex][len_vertex];
        for (int n=0; n<len_vertex; ++n){
            for (int o=0; o<len_vertex; ++o){
                array_adj[n][o]=0;
                array_adj_visiteds[n][o]=0;
            }
        }
        bool on = true;
        for (int i=0; i<len_vertex; ++i){
            for (int j=0; j<len_vertex; ++j){
                if (g[i][j]==1 && array_adj_visiteds[i][j]==0){
                    // posx = i;
                    // posy = j;
                    for (int k=0; k<len_vertex; ++k)
                    {
                        // DEBUG{std::cout<<"k="<<k<<"\n";}
                        if (g[i][k]==1 && k!=j){array_adj[i][k]=1;}
                    }
                    for (int m=0; m<len_vertex; ++m)
                    {
                        if (g[m][j]==1 && m!=i){array_adj[m][j]=1;}
                    }
                    // g[i][j]=0;
                    array_adj_visiteds[i][j] = 1;
                    on = false;
                    break;
                }
            }
            if (on==false){break;}
        }

        DEBUG{
            for (int o=0; o<len_vertex; ++o){
                for (int p=0; p<len_vertex; ++p){std::cout<<"|"<<array_adj[o][p]<<"|";}
                std::cout<<"\n";
            }
        }
        
        for (int j=0; j<len_vertex; ++j){
            for (int l=0; l<len_vertex; ++l){
                if (array_adj[j][l]==1){
                    int adj = g[j][l];
                    DEBUG{std::cout<<"adj:"<<adj<<"\n";}
                    if (visiteds[l]==false){
                        DEBUG{std::cout<<"HERE\n";}
                        visiteds[l]=true;
                        q.push(l);
                        distances[l] = depth;
                    }
                }
            }
        }
        depth++;
        DEBUG{std::cout<<"depth="<<depth<<"\n";}
    }
    return;
}


int main(){
    int lenx, leny;
    std::cin >> lenx;
    // cin.ignore('\n');
    std::cin >> leny;
    // cin.ignore('\n');
    DEBUG{std::cout<<"lenx,leny="<<lenx<<","<<leny<<"\n";}

    int **graph;
    graph = new int*[lenx];
    for (int k=0; k<lenx; ++k){
        graph[k] = new int[lenx];
        for (int l=0; l<lenx; ++l){graph[k][l]=0;}
    }

    for (int i=0; i<leny; ++i){
        int init_vert, end_vert, weight;
        std::cin >> init_vert;
        std::cin >> end_vert;
        std::cin >> weight;
        graph[init_vert][end_vert]=weight;
        graph[end_vert][init_vert]=weight;
    }
    DEBUG{
        for (int l=0; l<lenx; ++l){
            for (int m=0; m<lenx; ++m){
                std::cout<<"-"<<graph[l][m]<<"-";
            }
            std::cout<<"\n";
        }
    }

    int vert_init = 1; int vert_end = 2;
    int distances[lenx];
    BFS(lenx, leny, vert_init, vert_end, distances, graph);

    for (int m=0; m<lenx; m++){
        std::cout << "|" << distances[m]<< "|";
    }
    std::cout<<"\n";
    
    for (size_t i=0; (int)i<lenx; ++i){delete[] graph[i];}
    delete[] graph;

    return 0;
}