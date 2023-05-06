#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#define DEBUG if(0)
#define INFINITY 100000


int min(int x, int y){return x>y?y:x;}


int bellmanFord(std::vector<std::vector<int>> e, int n, int m, int s, int* d){
    for (int i=0; i<n; ++i)
    {
        d[i]=INFINITY;
    }
    d[s] = 0;

    DEBUG{std::cout<<"Calling main process...\n";}
    int change = 0;
    for (int j=0; j<n-1; j++){
        for (auto iter_e : e){
            int u = iter_e[0];
            int v = iter_e[1];
            int w = iter_e[2];
            if (d[v]>w+d[u]){change=1;}
            d[v] = min(d[v],w+d[u]);
        }
    }
    if (change==1){
        std::cout << "This graph have cicle negative.\n";
    }
    return change;
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
            fscanf(file, "%d %d", &n, &m);
            std::vector<std::vector<int>> edges;
            for (int i=0; i<m; ++i){
                int init, end, w;
                // std::cin >> init >> end >> w;
                fscanf(file, "%d %d %d", &init, &end, &w);
                // std::cout<<init;
                edges.push_back({init,end,w});
            }
            DEBUG{
                std::cout<<"EDGES OF GRAPH:\n";
                for (int k=0; k<m; ++k){
                    std::cout<<"|"<<edges[k][0]<<"|"<<edges[k][1]<<"|"<<edges[k][2]<<"|";
                    std::cout<<"\n";
                }
                std::cout<<"Test of function min:"<<min(20,10)<<"\n";
            }

            int s=0;
            for (int index_arg1=0; index_arg1<argv; ++index_arg1){
                if (argc[index_arg1][0]=='-' && argc[index_arg1][1]=='i'){
                    s = std::stoi(argc[index_arg1+1])-1;
                    break;
                }
            }
            int dist[n];
            int cycle_negative = 0;
            cycle_negative = bellmanFord(edges, n, m, s, dist);

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
                if (cycle_negative==1){fprintf(savefile, "This graph have cicle negative.\n");}
                fprintf(savefile, "Dist:\n");
            }
            for (int j=0; j<n; ++j){
                // for (int k=0; k<n; ++k){
                    std::cout<<"="<<dist[j]<<"=";
                    if (save==1){fprintf(savefile, "=%d=\n", dist[j]);}
                // }
                std::cout<<"\n";
            }

            fclose(savefile);
            fclose(file);
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