#include <iostream> 

using namespace std; 

template <class T> class Node{ 
    private: 
        T val; 
        Node* next;  
    public:
        void set_val(T new_val){ 
            this->val = new_val; 
        } 
        void set_next(T* new_next){ 
            this->next = new_next;
        }

};

template <class T> class LinkedList{ 
    private: 
        Node<T> head; 
    public: 
        void set_head(T val){ 
            Node<T> temp = new Node<T>; 
            temp.set_val(val); 
            this->head = temp;
        } 
        void add_start(T val){ 
            
            Node<T> node = new Node<T> 
            

        }

};

int main(){ 

    Node<int> head;
    Node<int> iterator;

    cout << "Hello world" << endl;

    
    return 0;
}