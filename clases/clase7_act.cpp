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



int main(){
    CustomLinkedList<int> firstList;

    firstList.add_end(32);
    //Pause the program until input is received
    
    firstList.add_end(33);
    firstList.add_end(34);
    cout << "Before add_after" << endl;

    firstList.print_list();

    firstList.add_after_node(20,33);
    cout << " After add_after" << endl;
    firstList.print_list();

    // firstList.delete_node(34);
    return 0;
}