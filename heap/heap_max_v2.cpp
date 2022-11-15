#include <iostream>
#include <vector>

#define DEBUG if(1)
#define DEFAULT_LEN_ARRAY 10
#define INFINITY 50000

using namespace std;

vector<int> heap_max (DEFAULT_LEN_ARRAY);


class HeapMax{
    private:
        int curr;
        int lenght;
    public:
        void MaxHeapfy(int i){
            int l = 2*i;
            int r = 2*i+1;
            int max;
            if (l<=(int)heap_max.size() && heap_max[l]>heap_max[i]){
                max = l;
            }
            else{max=i;}
            if (r<=(int)heap_max.size() && heap_max[r]>heap_max[max]){max=r;}
            if (max!=i){
                int aux = heap_max[i];
                heap_max[i] = heap_max[max];
                heap_max[max] = aux;
                MaxHeapfy(max);
            }
            return;
        }
        void BuildMaxHeap(){
            int size = heap_max.size();
            for (int i=size/2; i>=0; --i){
                DEBUG{cout<<"i="<<i<<endl;}
                MaxHeapfy(i);
            }
            return;
        }
        HeapMax(int root_index, int len){
            DEBUG{cout<<"STEP 3\n";}
            curr = 0;
            lenght = len;
            DEBUG{cout << "1-Heap max running with root in "<<heap_max[root_index]<<endl;}
        }
        void Insert(int x){
            //S union x
            if (curr>=lenght)
            {
                DEBUG{cout<<"Resizing...\n";}
                heap_max.resize(lenght+1);
                lenght += 1;
            }
            DEBUG{cout << "x="<<x<<"curr:"<<curr<<endl;}
            heap_max[curr]=x; //Added to end
            curr++;
        }
        int ExtractMax(){
            //Remove and return the big key element
            if (heap_max.size()<1){
                cout << "Error: underflow research. Vector with only element.\n";
                return 1;
            }
            int max = heap_max[1]; //element children of lenght 2*curr
            heap_max[1] = heap_max[heap_max.size()];
            int size = heap_max.size();
            //DEBUG{cout<<"size:"<<size<<endl;}
            if (size-1>1){
                heap_max.resize(size-1);
            }
            // DEBUG{cout<<"init recurssion in ExtractMax()...\n";}
            MaxHeapfy(1);
            return max;
        }
        void IncreaseKey(int key, int plus_key){
            //Increase the value of parameter key with plus_Key parameter
            return;
        }
};


int main(){
    DEBUG{cout<<"STEP 1\n";}
    HeapMax heap_class = HeapMax(3, DEFAULT_LEN_ARRAY);
    DEBUG{cout<<"STEP 2\n";}

    int x;
    while (x!=-1)
    {
        cin >> x;
        //cin.ignore('\n');
        DEBUG{cout << "Inserting..."<<endl;}
        if (x!=-1)
        {heap_class.Insert(x);}
    }
    heap_class.BuildMaxHeap();
    int removed = heap_class.ExtractMax();
    DEBUG{cout<<"max extracted:"<<removed<<endl;}
    DEBUG{
        cout << "Vector:\n";
        for (int j=0; j<(int)heap_max.size(); ++j)
        {
            cout << heap_max[j] << " ";
        }
    }

    return 0;
}