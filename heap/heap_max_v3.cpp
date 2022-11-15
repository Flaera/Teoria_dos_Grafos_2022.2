#include <iostream>
#include <vector>

#define DEBUG if(0)
#define DEFAULT_LEN_ARRAY 7
#define INFINITY 50000

using namespace std;


class HeapMax{
    private:
        int curr;
        int lenght;
        vector<int> heap_max;
    public:
        HeapMax(vector<int> vector, int len){
            DEBUG{cout<<"STEP 3\n";}
            heap_max = vector;
            
            for (int i=0; i<len; ++i){cout << heap_max[i] << " ";}
            cout<<endl;
            
            curr = 0;
            lenght = len;
            DEBUG{cout << "1-Heap max running..."<<endl;}
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
            DEBUG{cout<<heap_max[a]<<" "<<heap_max[b]<<endl;}
            int aux = heap_max[a];
            heap_max[a] = heap_max[b];
            heap_max[b] = aux;
            DEBUG{cout<<heap_max[a]<<" "<<heap_max[b]<<endl;}
        }
        void MaxHeapfy(int i){
            int l = LeftChild(i);
            int r = RightChild(i);
            int max;
            if (l<=lenght && heap_max[l]>heap_max[i]){
                max = l;
            }
            else{max=i;}
            if (r<=lenght && heap_max[r]>heap_max[max]){
                max=r;
            }
            if (max!=i){
                Swap(i, max);
                MaxHeapfy(max);
            }
            return;
        }
        void BuildMaxHeap(vector<int> heap){
            // DEBUG{cout<<"Build max heap...\n";}
            // DEBUG{cout<<"len="<<lenght<<endl;}
            for (int i=lenght/2; i>=0; i--)
            {
                DEBUG{cout<<"i: "<<i<<endl;}
                MaxHeapfy(i);
            }
        }
        int ExtractMax(){
            //Remove and return the big key element
            if(lenght<1){
                cout << "Heap underflow.\n";
                return 0;
            }
            int max = heap_max[0];
            heap_max[0] = heap_max[lenght-1];
            lenght -= 1;
            MaxHeapfy(0);
            return max;
        }
        void IncreaseKey(int key, int plus_key){
            //Increase the value of parameter key with plus_Key parameter
            if (key<0 || key>=lenght){
                cout<<"Key or index out range of vector.\n";
                return;
            }
            heap_max[key] += plus_key;
            while(key>0 && heap_max[Parent(key)]<heap_max[key]){
                Swap(key, Parent(key));
                key = Parent(key);
            }
            return;
        }
        void PrintHeap(){
            for (int i=0; i<lenght; ++i){
                cout <<"Posição: "<<i+1<<", Element: "<< heap_max[i] << "\n";
            }
        }
};


int main(){
    vector<int> heap_max;
    heap_max.push_back(2);
    heap_max.push_back(6);
    heap_max.push_back(68);
    heap_max.push_back(90);
    heap_max.push_back(87);
    heap_max.push_back(15);
    heap_max.push_back(18);
    
    // heap_max.push_back(4);
    // heap_max.push_back(1);
    // heap_max.push_back(3);
    // heap_max.push_back(2);
    // heap_max.push_back(16);
    // heap_max.push_back(9);
    // heap_max.push_back(10);
    // heap_max.push_back(14);
    // heap_max.push_back(8);
    // heap_max.push_back(7);

    // DEBUG{
    //     for (int i=0; i<(int)heap_max.size(); i++){cout<<heap_max[i]<<" ";}
    //     cout<<endl;
    // }

    DEBUG{cout<<"STEP 1\n";}
    HeapMax heap_class = HeapMax(heap_max, heap_max.size());
    DEBUG{cout<<"STEP 2\n";}

    heap_class.BuildMaxHeap(heap_max);
    int removed = heap_class.ExtractMax();
    DEBUG{cout<<"max extracted:"<<removed<<endl;}
    heap_class.IncreaseKey(5,100);
    heap_class.PrintHeap();

    return 0;
}