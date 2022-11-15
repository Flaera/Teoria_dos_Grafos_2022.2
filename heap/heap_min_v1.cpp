#include <iostream>
#include <vector>

#define DEBUG if(0)
#define DEFAULT_LEN_ARRAY 7
#define INFINITY 50000

using namespace std;


class HeapMin{
    private:
        int curr;
        int lenght;
        vector<int> heap_min;
    public:
        HeapMin(vector<int> vector, int len){
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
            heap_min.push_back(element);
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
};


int main(){
    vector<int> heap_min;
    heap_min.push_back(2);
    heap_min.push_back(6);
    heap_min.push_back(68);
    heap_min.push_back(90);
    heap_min.push_back(87);
    heap_min.push_back(15);
    heap_min.push_back(18);
    
    // heap_min.push_back(4);
    // heap_min.push_back(1);
    // heap_min.push_back(3);
    // heap_min.push_back(2);
    // heap_min.push_back(16);
    // heap_min.push_back(9);
    // heap_min.push_back(10);
    // heap_min.push_back(14);
    // heap_min.push_back(8);
    // heap_min.push_back(7);

    // DEBUG{
    //     for (int i=0; i<(int)heap_min.size(); i++){cout<<heap_min[i]<<" ";}
    //     cout<<endl;
    // }

    DEBUG{cout<<"STEP 1\n";}
    HeapMin heap_class = HeapMin(heap_min, heap_min.size());
    DEBUG{cout<<"STEP 2\n";}

    heap_class.BuildMinHeap(heap_min);
    int removed = heap_class.ExtractMin();
    DEBUG{cout<<"min extracted:"<<removed<<endl;}
    heap_class.DecreaseKey(5,-100);
    // heap_class.ExtractMin();
    heap_class.Insert(30);
    heap_class.PrintHeap();

    return 0;
}