#include <bits/stdc++.h> 

using namespace std; 

// Declare the class
class MaxHeap{
    public:
    vector<int> heap; 
    int len;

    // Complejidad: O(n)
    // Explicacion: hay dos operaciones significativas, el push_back del vector heap, y heapifyUp()
    // la primera tiene una complejidad de O(n), la segunda de O(log(n)) 
    // Por lo que la complejidad total es O(n)
    void push(int _data){
        heap.push_back(_data); 
        heapifyUp();
    }
    // Complejidad: O(log n)
    // La complejidad de este algoritmo corresponde al numero de niveles con respecto al numero de elementos del heap. 
    // El numero de niveles con respecto al numero de elementos del heap es O(log n) 
    void heapifyUp(){
        // Takes the last item and bubbles it up until it's at a right spot
        int current = heap.size() - 1;
        while( hasParent(current) && heap[current] > heap[getParentIndex(current)] ){
            // Swap current and parent 
            swap(getParentIndex(current), current); 
            current = getParentIndex(current);
        }
    }
    // Complejidad: O(log n)
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
    // Complejidad: O(1)
    bool empty(){
        return heap.size() == 0;
    }
    // Complejidad: O(1)
    int getRight(int index){
        return index*2 + 1;
    }
    // Complejidad: O(1)    
    int getLeft(int index){
        return index*2 + 2;
    } 
    // Complejidad: O(1)
    int getParentIndex(int index){
        return ((index - 1) / 2);
    } 
    // Complejidad: O(1)
    bool hasRight(int index){
        return index*2 + 2 <= heap.size();
    }
    // Complejidad: O(1)
    bool hasLeft(int index){
        return index*2 + 1 <= heap.size();
    } 
    // Complejidad: O(1)
    bool hasParent(int index){
        return (index - 1) / 2 >= 0;
    }
    // Complejidad: O(1)
    void swap(int i1, int i2){
        int temp = this->heap[i1]; 
        this->heap[i1] = this->heap[i2]; 
        this->heap[i2] = temp;
    }
    
    // Complejidad: O(n)
    void printHeap(){
        for (int i = 0; i <= heap.size() - 1; i++)
        {
            cout << heap[i] << ", ";
        } 
        cout << "\n";
        
    } 
    // Complejidad: O(log N) 
    // Explicacion: 
    // Hay dos operaciones significativas en esta funcion, el pop_back, y heapify down. 
    // La primera tiene una complejidad de O(1). La segunda una complejidad de O(log n) 
    // Por lo tanto, la complejidad es O(log n)
    void pop(){
        // First, replace root with last item 
        heap[0] = heap[heap.size() - 1];
        // Then, pop last item 
        heap.pop_back(); 
        heapifyDown();
        // Heapify the heap 

    } 
    // Complejidad: O(1)
    int top(){
        if(heap.size() > 0) return heap[0];
        return 0; 
    }
    // Complejidad: O(1)
    int size(){
        return heap.size();
    }

};

int main(){

    MaxHeap myHeap; 

    // Probar método empty 
    if(myHeap.empty()){
        cout << "Heap is empty" << endl;
    }

    // Añadiendo 10 elementos a la fila 
    myHeap.push(60);
    myHeap.push(96);
    myHeap.push(90);

    if(myHeap.empty()){
        cout << "Heap is empty" << endl;
    }

    myHeap.push(66);
    myHeap.push(29);
    myHeap.push(44);
    myHeap.push(85);
    myHeap.push(40);
    myHeap.push(93);
    myHeap.push(35);
    // Heap: 
    myHeap.printHeap();
    // Probar método pop() 
    myHeap.pop();  
    // Probar método top()
    cout << myHeap.top() << endl; 
    // Probar size() 
    cout << myHeap.size() << endl;



}