#include <iostream>

using namespace std;

template <class T> class Node {
    public:
        T data; // The object information
        Node* next; // Pointer to the next node element

        void set_data(T new_data){
            this->data = new_data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        } 
        Node<T>* get_next(){ 
            return this->next;
        }
}; 

template <class T> class DNode { 
    public: 
    T data; 
    DNode* next; 
    DNode* prev; 

    void set_data(T new_data){ 
        this->data = new_data;
    } 
    void set_next(DNode* new_next){ 
        this->next = new_next; 
    } 
    void set_prev(DNode* new_prev){ 
        this->prev = new_prev;
    } 
    DNode<T>* get_next(){ 
        return this->next;
    }

    DNode<T>* get_prev(){ 
        return this->prev;
    }
};


template <class T> class CustomLinkedList{
    Node<T> *head;

    public:
        CustomLinkedList(){
            head = NULL;
        }

        ~CustomLinkedList(){

        }

        // Method adds info to the end of the list
        void add_end(T info){
            if(head == NULL){ //if our list is currently empty
                head = new Node<T>; //Create new node of type T
                head->set_data(info); 
                head->set_next(NULL);
            }
            else{ //if not empty add to the end and move the tail
                Node<T>* temp = new Node<T>;
                temp->set_data(info);
                temp->set_next(NULL);

                Node<T>* current_node = this->head;
                while (current_node->next != NULL){
                    current_node = current_node->next;
                }
                
                current_node->next = temp;
            }
        }

        // Method adds info to the begining of the list
        void add_begin(T info){
            Node<T>* temp = new Node<T>;
            temp->set_data(info);
            temp->set_next(head);

            this->head = temp;
        }

        // Method adds info to the begining of the list
        void add_after_node(T value_insert, T value_target){
            /*Implements this part*/ 
           Node<T>* current_node = this->head;

            while(current_node != NULL){ 
                if(current_node->data == value_target){ 
                    cout << "Found " << current_node->data << endl; 
                    Node<T>* newNode = new Node<T>; 
                    newNode->set_data(value_insert); 
                    
                    Node<T>* temp = current_node->get_next();
                    
                    // Intercambiar links, current node -> newNode -> temp 

                    current_node->set_next(newNode); 
                    newNode->set_next(temp);
                    return;
                    // Intercambiados
                }
                current_node = current_node->get_next();
            } 
            cout << "target not found" << endl;
            return;
            
        }


        void delete_node(T value){
            if(!this->head){
                // Empty linked list, no values to delete
                return;
            }
            
            // Check if the node to delete is the head
            if(this->head->data == value){
                this->head = this->head->next;
                return;
            }

            Node<T>* current_node = this->head;
            // Search for the node to delete
            while ( current_node && current_node->next->data != value){
                current_node = current_node->next;
            }

            // current node is empty the node wasn't found 
            if(!current_node){
                return;
            }

            Node<T>* node_to_delete = current_node->next;

            current_node->next = node_to_delete->next;
            delete node_to_delete;
        }

        void print_list(){
            Node<T>* current_node = this->head;
            while (current_node != NULL){
                cout << current_node ->data << " -> ";

                current_node = current_node->next;
            }
            cout << endl;
        } 
        
};

template<class T> class DoublyLinkedList{ 
        DNode<T>* head;
        DNode<T>* tail;

    public:
        DoublyLinkedList(){
            head = NULL; 
            tail = NULL;
        }

        ~DoublyLinkedList(){

        }

        // Method adds info to the end of the list
        void add_end(T info){
            DNode<T>* newNode = new DNode<T>; 
            newNode->set_data(info);
            if(head == NULL ){ 
                // Asignar next y prev 
                head = newNode; 
                tail = head; 
                return; 
            } 
            this->tail->set_next(newNode); 
            this->tail = newNode; 
        }

        // Method adds info to the begining of the list
        void add_begin(T info){
            DNode<T>* newNode = new DNode<T>; 
            newNode->set_data(info);  
            if(head == NULL) { 
                newNode->set_next(NULL); 
                newNode->set_prev(NULL); 
                head = newNode; 
                tail = newNode; 
                return;
            } 
            this->head->set_prev(newNode); 
            newNode->set_next(head); 
            this->head = newNode;
        }

        // Method adds info to the begining of the list
        void add_after_node(T value_xinsert, T value_target){
            /*Implements this part*/ 
           DNode<T>* current_node = this->head;
            while(current_node != NULL){ 
                if(current_node->data == value_target){ 
                    DNode<T>* newNode = new DNode<T>; 
                    newNode->set_data(value_insert);                 
                         
                    DNode<T>* temp = current_node->get_next();
                    
                    // Intercambiar links, current node -> newNode -> temp 
                    current_node->set_next(newNode); 
                    newNode->set_prev(current_node);
                    newNode->set_next(temp); 
                    temp->set_prev(newNode);
                    return;
                    // Intercambiados
                }
                current_node = current_node->get_next();
            } 
            cout << "target not found" << endl;
            return;
        }


        void delete_node(T value){
            if(!this->head){
                // Empty linked list, no values to delete
                return;
            }
            
            // Check if the node to delete is the head
            if(this->head->data == value){
                DNode<T>* temp = this->head; 
                if(!this->head->get_next()) { 
                    this->head = NULL; 
                    this->tail = NULL;
                    return;
                }
                delete temp; 

                this->head = this->head->next; 
                this->head->set_prev(NULL);
                return;
            } 


            DNode<T>* current_node = this->head;
            // Search for the node to delete
            while ( current_node && current_node->next->data != value){
                current_node = current_node->next;
            }

            // current node is empty the node wasn't found 
            if(!current_node){
                return;
            }


            DNode<T>* node_to_delete = current_node->next;
            
            // Reasignar punteros 
            if(!node_to_delete){ 
                current_node->set_next(NULL); 
                return; 
            } 
            DNode<T>* deleteNext = node_to_delete->get_next(); 
            current_node->set_next(deleteNext); 
            deleteNext->set_prev(current_node);
            delete node_to_delete;
        }

        void print_list(){
            DNode<T>* current_node = this->head;
            while (current_node != NULL){
                cout << current_node ->data << " -> ";

                current_node = current_node->next;
            }
            cout << endl;
        } 
        
};

int main(){
    DoublyLinkedList<int> newList; 

    newList.add_begin(1);
    newList.add_begin(2);
    newList.add_begin(3);
    newList.add_begin(6); 

    newList.add_after_node(5,3);

    newList.print_list();

    cout << "Deleting node 3" << endl; 

    newList.delete_node(3); 
    newList.add_end(99);


    newList.print_list();

    return 0;
}