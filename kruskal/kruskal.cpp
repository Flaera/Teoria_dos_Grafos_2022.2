#include <bits/stdc++.h>
#include <iostream>
#define DEBUG if(0)
using namespace std;
 

class Edge {
public:
    int src, dest, weight;
};


class Graph {
public: 
    int V, E;
    Edge* edge;
};
 

Graph* createGraph(int V, int E)
{
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
 
    graph->edge = new Edge[E];
 
    return graph;
}
 
class subset {
public:
    int parent;
    int rank;
};
 
int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent
            = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);


    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int myComp(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight;
}
 

void KruskalMST(Graph* graph, int argv, char* argc[])
{
    int V = graph->V;
    int e = 0;
    int i = 0;
    Edge result[V];

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
        myComp);

    // Allocate memory for creating V ssubsets
    subset* subsets = new subset[(V * sizeof(subset))];
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    FILE* savefile;
    int save = 0;
    for (int index_arg1=0; index_arg1<argv; ++index_arg1){
        if (argc[index_arg1][0]=='-' && argc[index_arg1][1]=='o'){
            savefile = fopen(argc[index_arg1+1], "w");
            save=1;
            break;
        }
    }

    int minimumCost = 0;
    for (i = 0; i < e; ++i)
    {
        cout << result[i].src << "|" << result[i].dest
            << " == " << result[i].weight << endl;
        if (save==1){
            fprintf(savefile, "%d|%d == %d\n", result[i].src, result[i].dest, result[i].weight);
        }
        minimumCost = minimumCost + result[i].weight;
    }
    
    cout << "Custo minimo: " << minimumCost
        << endl;
    if (save==1){
        fprintf(savefile, "Custo minimo: %d", minimumCost);
        fclose(savefile);
    }

    //Free memory:
    delete subsets;
}
 

int main(int argv, char* argc[])
{
    for (int index_arg=0; index_arg<argv; ++index_arg){
        if (argc[index_arg][0]=='-' && argc[index_arg][1]=='f'){
            FILE* file = fopen(argc[index_arg+1],"r");
            if (file==NULL){std::cout<<"File not founded.\n";return 0;}
            int V;
            int E;
            // cin>>V>>E;
            fscanf(file, "%d %d",&V, &E);
            Graph* graph = createGraph(V, E);
        
            for (int i=0; i<E; ++i){
                int s,t,w;
                // cin>>s>>t>>w;
                fscanf(file, "%d %d %d", &s, &t, &w);
                graph->edge[i].src=s;
                graph->edge[i].dest=t;
                graph->edge[i].weight=w;
            }
            KruskalMST(graph, argv, argc);
            
            fclose(file);
            // Deleting/Free the memory of graph:
            delete graph;

        }
        if (argc[index_arg][0]=='-' && argc[index_arg][1]=='h'){
            std::cout<<"Para executar um algoritmo esteja branch \"main\", tenha o g++ e execute os seguintes passos:\n\n";
            std::cout<<"1º: Acesse a pasta do algoritmo;\n\n";
            std::cout<<"2º: Digite sem as aspas a palavra \"make\" para compilar.\n\n";
            std::cout<<"3º: Digite sem as aspas a palavra \"./<nome_do_algoritmo> <parametros>\" para executar.\n\n";
            std::cout<<"Em caso de dúvida digite -h como parâmetro.\n\n";
            std::cout<<"Direcione a saída para um arquivo com o parâmetro -o e nome_do_arquivo.dat\n";
            std::cout<<"Indique um arquivo que contém o grafo com o parâmetro -f e nome_do_arquivo.dat\n\n";
            // std::cout<<"Mostre a solução em ordem crescente com o parâmetro -s\n";
            // std::cout<<"Defina o vértice inicial com o parâmetro -i.\n\n";
        }
    }
    return 0;
}