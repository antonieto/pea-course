#include <bits/stdc++.h> 

using namespace std; 

// Declare the class
class MaxHeap{
    public:
    vector<int> heap; 
    int len;
    void insert(int _data){
        heap.push_back(_data); 
        heapifyUp();
    }
    void heapifyUp(){
        // Takes the last item and bubbles it up until it's at a right spot
        int current = heap.size() - 1;
        while( hasParent(current) && heap[current] > heap[getParentIndex(current)] ){
            // Swap current and parent 
            swap(getParentIndex(current), current); 
            current = getParentIndex(current);
        }
    }
    void heapifyDown(){
        int current = 0; 
        while(hasLeft(current)){
            // smaller is arbitrary, before we check whether there is right child
            int greater = getLeft(current); 
            if(hasRight(current) && heap[getRight(current)] > heap[getLeft(current)]){
                greater = getRight(current);
            } 
            // Swap current and greater 
            swap(current, greater); 
            current = greater; 

        }
    }

    int getRight(int index){
        return index*2 + 1;
    }
    int getLeft(int index){
        return index*2 + 2;
    } 
    int getParentIndex(int index){
        return ((index - 1) / 2);
    } 
    bool hasRight(int index){
        return index*2 + 2 <= heap.size();
    }
    bool hasLeft(int index){
        return index*2 + 1 <= heap.size();
    } 
    bool hasParent(int index){
        return (index - 1) / 2 >= 0;
    }
    void swap(int i1, int i2){
        int temp = this->heap[i1]; 
        this->heap[i1] = this->heap[i2]; 
        this->heap[i2] = temp;
    }
    
    void printHeap(){
        for (int i = 0; i <= heap.size() - 1; i++)
        {
            cout << heap[i] << ", ";
        } 
        cout << "\n";
        
    } 
    void pop(){
        // First, replace root with last item 
        heap[0] = heap[heap.size() - 1];
        // Then, pop last item 
        heap.pop_back(); 
        heapifyDown();
        // Heapify the heap 

    }

};

int main(){

    MaxHeap myHeap; 
    myHeap.insert(40);
    myHeap.insert(10);
    myHeap.insert(15);
    myHeap.insert(20);
    myHeap.insert(30);
    myHeap.insert(8); 
    myHeap.printHeap();
    myHeap.pop(); 
    myHeap.pop(); 
    myHeap.insert(40);
    myHeap.insert(30);
    myHeap.printHeap(); 

}