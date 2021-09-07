#include <iostream>

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* next; // Pointer to the next node element
        Node* prev; // Pointer to the previous element

    public:
        Node(T new_data, Node* next_node, Node* prev_node){
            this->data = new_data;
            this->next = next_node;
            this->prev = prev_node;
        }

        Node(T new_data){
            this->data = new_data;
            this->next = NULL;
            this->prev = NULL;
        }

        void set_data(T new_data){
            this->data = new_data;
        }

        T get_data(){
            return this->data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }

        Node* get_next(){
            return this->next;
        }

        void set_prev(Node *prev_node) {
            this->prev = prev_node;
        }

        Node* get_prev() {
            return this->prev;
        }
};


template <class T> class CustomLinkedList{
    public:
    
        Node<T>* head;
        Node<T>* tail;
        
        CustomLinkedList(){
            head = NULL;
            tail = NULL;
        }

        ~CustomLinkedList(){

        }

        // Method adds data to the end of the list
        void add_end(T data){
            if(this->head == NULL) { 
                this->head = new Node<T>(data);
                this-> tail = this->head;
								head->set_next(head);
						    head->set_prev(head);
            }
            else { //if not empty add to the end and move the tail
                Node<T>* temp = new Node<T>(data);
                Node<T>* current_node = this->tail;
                current_node->set_next(temp);
                temp->set_prev(current_node); 
                this->tail = temp;
				        this->tail->set_next(head);
                this->head->set_prev(tail);
            }
        }

        // Method adds data to the begining of the list
        void add_begin(T data) {
            if(this->head == NULL) { 
                this->head = new Node<T>(data);
                this-> tail = this->head;
								head->set_next(head);
						    head->set_prev(head);
            }
            else {
                Node<T>* temp = new Node<T>(data);
				        this->head->set_prev(temp);
                temp->set_next(this->head);
                temp->set_prev(this->tail);
                this->head = temp; 
                this->tail->set_next(head);
            }
        }

        // Method adds info to the begining of the list
        void add_after_node(T value_insert, T value_target) {
            
            Node<T>* current_node = this->head;
            // Search for the node to delete
            while(current_node->get_data() != value_target){
                // current node is empty the node wasn't found 
                if(current_node->get_next()==this->head){
                    return;
                } 
                current_node = current_node->get_next();
            }
            if (current_node == this->tail) {
              this->add_end(value_insert);
            }
            else {
              Node<T>* next_square = current_node->get_next();
              Node<T>* node_insert = new Node<T>(value_insert, next_square, current_node);
              //cout << node_insert->get_prev() << endl;
              next_square->set_prev(node_insert);
              current_node->set_next(node_insert);
            }
	    }


        void delete_node(T value){
            if(!this->head){
                // Empty linked list, no values to delete
                return;
            }
            
            // Check if the node to delete is the head
            if(this->head->get_data() == value){
                this->head = this->head->get_next();
                this->tail->set_next(this->head);
                this->head->set_prev(this->tail); 
                return;
            }

            Node<T>* current_node = this->head;
            // Search for the node to delete
            do{
                if(current_node->get_next()==this->head){
                    return;
                } 
                current_node = current_node->get_next();
            }while(current_node->get_next()->get_data() != value);
            
            Node<T>* node_to_delete = current_node->get_next();
            if (node_to_delete->get_next() == this->head) {
                current_node->set_next(this->head);
                this->tail =current_node;
                this->head->set_prev(tail);
                delete node_to_delete;
            }
            else {
                Node<T>* next_node = node_to_delete->get_next();
                current_node->set_next(next_node);
                next_node->set_prev(current_node);
                delete node_to_delete;
            }
        }

        Node<T>* search_node(T value_target){
            Node<T>* current_node = this->head;
            // Search for the node to delete
            do{
                if(current_node->get_next()==this->head){
                    return NULL;
                } 
                current_node = current_node->get_next();
            }while(current_node->get_next()->get_data() != value_target); 
            return current_node->get_next(); 
        }
		

        void print_list(){
            Node<T>* current_node = this->head;
            do { 
              cout << current_node->get_data() << " -> ";
              current_node = current_node->get_next();  
            }
            while (current_node != this->head);
            cout << endl;
        }
};



int main(){
    CustomLinkedList<int> firstList;

    firstList.add_begin(33);
    firstList.add_end(44);
    firstList.add_end(55);
    firstList.add_end(66);
    firstList.add_end(77);
    firstList.add_end(88);
    firstList.add_end(99);
    firstList.add_after_node(111,99);
    
    //firstList.delete_node(44);
  

    firstList.print_list(); 
    cout << " Borrando " << endl; 
    firstList.delete_node(33); 
    cout << " Borrado :) " << endl; 
    firstList.print_list();
    cout << firstList.tail->get_data() << endl;
    cout << firstList.head->get_data() << endl;
     Node<int>* element = firstList.search_node(99);
    if(element) {
        cout << element->get_data() << endl;
	}
    return 0;
}