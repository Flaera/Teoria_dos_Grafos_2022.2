#include <iostream>

#define DEBUG if(1)

using namespace std;


class Node{
    private:
        int key;
        int *left;
        int *right;
    public:
        Node(int key, int *left, int *right){
            DEBUG{cout << "Node created."<<endl;}
            this->key;
            this->left;
            this->right;
        }
        Node(){
            DEBUG{cout << "Node created 2."<<endl;}
            this->key = 0;
            this->left = NULL;
            this->right = NULL;
        }
        int GetKey(){return key;}
        int *GetLeft(){return left;}
        int *GetRight(){return right;}
        void SetKey(int new_key){key = new_key;}
        void SetLeft(Node node){left = node;}
        void SetRight(Node node){right = node}
};


class HeapMax{
    private:
        Node root;
    public:
        HeapMax(){
            DEBUG{cout << "Heap max running..."<<endl;}
        }
        void insert(Node x){
            //S union x
            Node root_copy = root;
            if (root_copy.GetLeft()==NULL){root_copy.SetLeft(x);}
            else if (root_copy.GetRight()==NULL){root_copy.SetRight(x);}
            else{
                insert_aux(root_copy, x);
            }
        }
        void insert_aux(Node root, Node x){

        }
        int extract_max(){
            //Remove and return the big key element
            return 1;
        }
        void increase_key(int key, int plus_key){
            //Increase the value of parameter key with plus_Key parameter
            return;
        }
};


int main(){
    
    HeapMax heap_max = HeapMax();

    return 0;
}