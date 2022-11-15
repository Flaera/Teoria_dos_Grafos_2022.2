#include <iostream>
#include <array>
#include <queue>

#define DEBUG if(1)
#define INFINITY 1000000


void BFS(int graph[][2], int pre[], int dist[], int *acc,
 int vertex, int edges, int vert_init, int vert_dest){
    //bool used[vertex];
    for (int j=0; j<vertex; ++j){
        //used[j] = true;
        pre[j]=-1;
        dist[j]=INFINITY;
    }
    
    DEBUG{std::cout<<"STEP 4\n";}
    std::queue<int> q;
    DEBUG{std::cout<<"STEP 5\n";}
    pre[vert_init] = *acc++;
    dist[vert_init] = 0;
    q.push(vert_init);
    while(!q.empty()){
        int v = q.back();
        DEBUG{std::cout<<"vert_init:"<<vert_init<<"\n";}
        q.pop();
        for (int w=0; w<vertex; ++w){
            int adj = graph[w][1];
            //DEBUG{std::cout<<"adj:"<<adj<<"\n";}
            // if (pre[adj]==-1){
            if (pre[adj]==-1){
                //used[w]=true;
                pre[adj] = v;
                q.push(adj);
                dist[adj] = dist[v]+1;
            }
        }
    }
    //q.free();
}


int main(){
    int lenx, leny;
    std::cin >> lenx;
    // cin.ignore('\n');
    std::cin >> leny;
    // cin.ignore('\n');
    DEBUG{std::cout<<"lenx,leny="<<lenx<<","<<leny<<"\n";}

    int graph[leny][2];
    int dist[leny];
    
    for (int i=0; i<leny; ++i){
        int init_vert, end_vert, weight;
        std::cin >> init_vert;
        std::cin >> end_vert;
        std::cin >> weight;
        graph[i][0]=init_vert;
        graph[i][1]=end_vert;
        dist[i]=weight;
    }
    DEBUG{
        for (int l=0; l<leny; ++l){
           std::cout<<"-"<<graph[l][0]<<"-"<<graph[l][1]<<"-"<<dist[l]<<"-\n";
        }
    }

    int pre[lenx];
    int acc = 0;
    int d = 5, b = 1;

    BFS(graph, pre, dist, &acc, lenx, leny, b, d);
    DEBUG{
        for (int m=0; m<leny; m++){
            std::cout << "|" << dist[m]<< "|";
        }
        std::cout<<"\n";
    }
    

    return 0;
}