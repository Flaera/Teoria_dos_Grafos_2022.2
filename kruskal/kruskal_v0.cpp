#include <iostream>
#include <vector>
#define DEBUG if(1)
#define INFINITY 100000


void make_set(std::vector<int>& pre, std::vector<int>&  rank, int x){
    std::cout<<"fala menor\n";
    pre[x]=x;
    rank[x]=0;
}


int find(std::vector<int> pre, int x){
    if (pre[x]!=x){pre[x]=find(pre, pre[x]);}
    return pre[x];
}


void union0(std::vector<int> pre, std::vector<int>  rank, int x, int y){
    if (rank[x]>=rank[y]){
        pre[y]=x;
        if (rank[x]==rank[y]){
            rank[x]++;
        }
    }
    else{pre[x]=y;}
}


void kruskal(int tree_w, std::vector<std::vector<int>> graph, int n, std::vector<int> pre){
    std::cout << "opa\n";
    std::cout << pre[0];
    std::vector<int> rank(n,1);
    std::vector<std::vector<int>> tree(n, std::vector<int>(n,0));
    std::cout << "falai\n";
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){std::cout<<"oi ";}
    }
    std::cout << "\nola\n";
    for (int i=0; i<n; ++i){
        make_set(pre, rank, i);
    }

    for (int j=0; j<n; ++j){
        for (int k=0; k<n; ++k){
            std::cout<<"find\n";
            int u = find(pre, graph[j][k]);
            int v = find(pre, graph[k][j]);
            if (u!=v){
                std::cout<<"\tentrou\n";
                tree[j][k]=graph[j][k];
                tree[k][j]=graph[k][j];
                union0(pre, rank, u, v);
            }
        }
    }
    std::cout << "fim\n";
}


int main(int argc, char* argv[]){
    std::cout << "opa\n";
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> graph (n, std::vector<int>(n,0));
    for (int i=0; i<m; ++i){
        int init, end, w;
        std::cin>>init>>end>>w;
        graph[init][end]=w;
        graph[end][init]=w;
    }
    DEBUG{
        std::cout<<"INPUT:\n";
        for (int j=0; j<n; ++j){
            for (int h=0; h<n; ++h){
                std::cout<<"|"<<graph[j][h]<<"|";
            }
            std::cout<<"\n";
        }
    }
    std::cout << "leu\n";
    std::vector<int> pre(n,-1);
    int tree_w = 0;
    kruskal(tree_w, graph, n, pre);
    //std::cout<<"Total: "<<tree_w<<"\n";
    
    return 0;
}