#include <iostream>
#include <vector>

#define DEBUG if(1)
#define INFINITY 1000000
#define WHITE -1
#define GRIS -2
#define DARK -3

using namespace std;


class HeapMin{
    private:
        int curr;
        int lenght;
        int *heap_min;
    public:
        HeapMin(int vector[], int len){
            DEBUG{cout<<"STEP 3\n";}
            heap_min = vector;
            
            for (int i=0; i<len; ++i){cout << heap_min[i] << " ";}
            cout<<endl;
            
            curr = 0;
            lenght = len;
            DEBUG{cout << "1-Heap min running..."<<endl;}
        }
        int Parent(int i){return i/2;}
        int LeftChild(int i){
            if (i==lenght){return i-1;}
            return 2*i;
            }
        int RightChild(int i){
            if (i==lenght){return i-1;}
            return 2*i+1;
        }
        void Swap(int a, int b){
            if (a==lenght){a-=1;}
            else if(b==lenght){b-=1;}
            DEBUG{cout<<"Swaping with a and b parameter: a="<<a<<", b="<<b<<endl;}
            DEBUG{cout<<heap_min[a]<<" "<<heap_min[b]<<endl;}
            int aux = heap_min[a];
            heap_min[a] = heap_min[b];
            heap_min[b] = aux;
            DEBUG{cout<<heap_min[a]<<" "<<heap_min[b]<<endl;}
        }
        void MaxHeapfy(int i){
            int l = LeftChild(i);
            int r = RightChild(i);
            int max;
            if (l<=lenght && heap_min[l]<=heap_min[i]){
                max = l;
            }
            else{max=i;}
            if (r<=lenght && heap_min[r]<=heap_min[max]){
                max=r;
            }
            if (max!=i){
                Swap(i, max);
                MaxHeapfy(max);
            }
            return;
        }
        void BuildMinHeap(vector<int> heap){
            // DEBUG{cout<<"Build max heap...\n";}
            // DEBUG{cout<<"len="<<lenght<<endl;}
            for (int i=lenght/2; i>=0; i--)
            {
                DEBUG{cout<<"i: "<<i<<endl;}
                MaxHeapfy(i);
            }
        }
        int ExtractMin(){
            //Remove and return the big key element
            if(lenght<1){
                cout << "Heap underflow.\n";
                return 0;
            }
            int min = heap_min[0];
            heap_min[0] = heap_min[lenght-1];
            lenght -= 1;
            MaxHeapfy(0);
            return min;
        }
        void Insert(int element){
            heap_min[lenght] = element;
            lenght+=1;
            MaxHeapfy(0);
        }
        void DecreaseKey(int key, int plus_key){
            //Increase the value of parameter key with plus_Key parameter
            if (key<0 || key>=lenght){
                cout<<"Key or index out range of vector.\n";
                return;
            }
            heap_min[key] += plus_key;
            while(key>0 && heap_min[Parent(key)]>=heap_min[key]){
                Swap(key, Parent(key));
                key = Parent(key);
            }
            return;
        }
        void PrintHeap(){
            for (int i=0; i<lenght; ++i){
                cout <<"Posição: "<<i+1<<", Element: "<< heap_min[i] << "\n";
            }
        }
        bool Empty(){
            if (lenght==0){return true;}
            return false;
        }
};


void BFS(int graph[][2], int pre[], int dist[], int *acc,
 int vertex, int edges, int vert_init, int vert_dest){
    int parents[vertex];
    for (int j=0; j<vertex; ++j){
        pre[j]=WHITE; //Colors
        dist[j]=INFINITY;
        parents[j]=NULL;
    }
    pre[vert_init] = GRIS;
    dist[vert_init] = 0;
    parents[vert_init] = NULL;
    int *vector;
    HeapMin priority_queue(vector, 1);
    priority_queue.Insert(vert_init);
    while(priority_queue.Empty()!=true){
        int vert_init = priority_queue.ExtractMin();
        for (int k=0; k<vertex; ++k){
            for (int l=0; l<edges; ++l){
                if (graph[k][l]!=vert_init && pre[k]==WHITE){
                        pre[l]=GRIS;
                        dist[l] += 1;
                        parents[k] = vert_init;
                        priority_queue.Insert(graph[k][l]);
                    }
                }
            }
        
        pre[vert_init] = DARK;
    }
}


int main(){
    int lenx, leny;
    cin >> lenx;
    // cin.ignore('\n');
    cin >> leny;
    // cin.ignore('\n');
    DEBUG{cout<<"lenx,leny="<<lenx<<","<<leny<<endl;}

    int graph[leny][2];
    int dist[leny];
    
    for (int i=0; i<leny; ++i){
        int init_vert, end_vert, weight;
        cin >> init_vert;
        cin >> end_vert;
        cin >> weight;
        graph[i][0]=init_vert;
        graph[i][1]=end_vert;
        dist[i]=weight;
    }
    DEBUG{
        for (int l=0; l<leny; ++l){
            cout<<"-"<<graph[l][0]<<"-"<<graph[l][1]<<"-"<<dist[l]<<"-\n";
        }
    }

    int pre[lenx];
    int acc = 0;
    int d = 4, b = 1;

    BFS(graph, pre, dist, &acc, lenx, leny, b, d);

    return 0;
}