#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(0)
#define INFINITY 100000
#define MAX_NODES 1000


class Edge {
    public:
        int origin;
        int destiny;
        int weight;
};


bool bellmanFord(int G[][MAX_NODES], int n, int s, int dist[]){
    Edge* A = NULL;
    A = new Edge[n*MAX_NODES];
    int m = 0;
    // std::cout<<"ESTOU AQUI\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (G[i][j]!=0){
                A[m].origin = i;
                A[m].destiny = j;
                A[m].weight = G[i][j];
                m++;
            }
        }
    }
    // std::cout<<"ESTOU AQUI\n";

    for (int i=0; i<n; i++){
        dist[i]=INFINITY;
    }
    dist[s]=0;
    bool change;

    for (int i=0; i<n; i++){
        change=true;
        for (int j=0; j<m; j++){
            int u = A[i].destiny;
            int v = A[i].origin;
            int w = A[i].weight;
            std::cout<<dist[u]<<" -- "<<dist[v]+w<<"\n";
            if (dist[v]!=INFINITY && dist[u]>dist[v]+w){
                dist[u]=dist[v]+w;
                change = true;
            }
        }
        if (!change){break;}
    }

    for (int i=0; i<m; i++){
        if (dist[A[i].destiny>dist[A[i].origin]+A[i].weight]){
            return false;
        }
    }
    return true;
}


int main(int argv, char* argc[]){
    for (int index_arg=0; index_arg<argv; ++index_arg){
        if (argc[index_arg][0]=='-' && argc[index_arg][1]=='f'){
            FILE* file = fopen(argc[index_arg+1], "r");
            if (file==NULL){
                std::cout<<"File not found.\n";
                return 0;
            }
            int m, n;

            // std::cin >> n >> m;
            fscanf(file, "%d %d\n", &n, &m);
            // std::cout<<"VALUES INICIAIS: "<<n<<" "<<m<<" "<<"\n";
            int graph[n][MAX_NODES];
            for (int i=0; i<n; i++){
                for (int j=0; j<MAX_NODES; j++){
                    graph[i][j]=0;
                }
            }
            for (int i=0; i<m; ++i){
                int init, end, w;
                // std::cin >> init >> end >> w;
                fscanf(file, "%d %d %d\n", &init, &end, &w);
                // std::cout<<init<<" "<<end<<" "<<w<<"\n";
                graph[init-1][end-1] = w;
            }

            int s=0;
            for (int index_arg1=0; index_arg1<argv; ++index_arg1){
                if (argc[index_arg1][0]=='-' && argc[index_arg1][1]=='i'){
                    s = std::stoi(argc[index_arg1+1])-1;
                    break;
                }
            }

            int dist[n];
            bool cycle_negative;
            cycle_negative = bellmanFord(graph, n, s, dist);

            int save = 0;
            FILE* savefile;
            for (int index_arg2=0; index_arg2<argv; ++index_arg2){
                if (argc[index_arg2][0]=='-' && argc[index_arg2][1]=='o'){
                    save=1;
                    savefile = fopen(argc[index_arg2+1], "w");
                    break;
                }
            }
            std::cout << "Dist:\n";
            if (save==1){
                if (cycle_negative){
                    fprintf(savefile, "This graph have cicle negative.\n");
                    std::cout<<"This graph have cicle negative.\n";
                }
                fprintf(savefile, "Dist:\n");
            }
            for (int j=0; j<n; ++j){
                // for (int k=0; k<n; ++k){
                    std::cout<<"="<<dist[j]<<"=";
                    if (save==1){fprintf(savefile, "=%d=\n", dist[j]);}
                // }
                std::cout<<"\n";
            }

            //fclose(savefile);
            //fclose(file);
        }
        if (argc[index_arg][0]=='-' && argc[index_arg][1]=='h'){
            std::cout<<"Para executar um algoritmo esteja branch \"main\", tenha o g++ e execute os seguintes passos:\n\n";
            std::cout<<"1º: Acesse a pasta do algoritmo;\n\n";
            std::cout<<"2º: Digite sem as aspas a palavra \"make\" para compilar.\n\n";
            std::cout<<"3º: Digite sem as aspas a palavra \"./<nome_do_algoritmo> <parametros>\" para executar.\n\n";
            std::cout<<"Em caso de dúvida digite -h como parâmetro.\n\n";
            std::cout<<"Direcione a saída para um arquivo com o parâmetro -o e nome_do_arquivo.dat\n";
            std::cout<<"Indique um arquivo que contém o grafo com o parâmetro -f e nome_do_arquivo.dat\n";
            // std::cout<<"Mostre a solução em ordem crescente com o parâmetro -s\n";
            std::cout<<"Defina o vértice inicial com o parâmetro -i.\n\n";
        }
    }
    
    
    return 0;   
}