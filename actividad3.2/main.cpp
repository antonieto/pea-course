#include <bits/stdc++.h>
using namespace std;

template <class T> class mHeap { 
    public: 
        vector<T> heap;
        int len;
        
        mHeap(){

        } 
        
        void swap(int i1, int i2){
            T temp = heap[i1];
            heap[i1] = heap[i2];
            heap[i2] = temp;
        }
        
        void heapifyUp(){
            int current = heap.size() - 1; 
            while(hasParent(current) && heap[current] > heap[getParentIndex(current)]){
                swap(current, getParentIndex(current)); 
                current = getParentIndex(current);
            }
        }

        void heapifyDown(){
            int smallest = heap.size() - 1;

            int index = 0;
            heap[index] = heap[smallest];

            while(hasLeft(index)){
                int maxChildIndex = getLeft(index);
                if(hasRight(index) && heap[getRight(index)] > heap[maxChildIndex]){
                    maxChildIndex = heap[getRight(index)];
                }
                if(heap[maxChildIndex] > heap[index]){
                    swap(maxChildIndex, index);
                }else{
                    break;
                }
                index = maxChildIndex;
            }
        }

        void insert(T data){
            // Push to heap 
            len++;
            heap.push_back(data); 
            heapifyUp();
        }
        
        int getParentIndex(int index){
            return (index-1)/2;
        }
        
        int getLeft(int index){
            return index*2 + 1;
        }

        int getRight(int index){
            return index*2 + 2;
        } 

        bool hasRight(int index){
            return index*2 + 2 < this->heap.size();
        }
		
        bool hasLeft(int index) {
			return index*2 + 1 < this->heap.size();
		}
        
        bool hasParent(int index){
            return (index-1)/2 >= 0;
        }
        
        void print(){
            for(auto &it: heap){
                cout<<it<<endl;
            }
        }
         
        int pop(){
            
        }
};

int main() {
    mHeap<int> ourHeap; 
    ourHeap.insert(100);
    ourHeap.insert(50);
    ourHeap.insert(200);
    ourHeap.insert(150);
    ourHeap.insert(38); 
    ourHeap.insert(40); 
    ourHeap.insert(99); 
    ourHeap.print();
    ourHeap.heapifyDown();
    ourHeap.print();
}