#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};
    
class Set{
    public:
        Node* set_chainning[11]; 

        vector<int> set_quadratic[11];

        void insert_chainning(int insert){
            int index = insert % 11; 
            Node* insertedValue = new Node(insert);
            
            if(!set_chainning[index] && !search(set_chainning[index], insert)) {
                set_chainning[index] =  insertedValue; 
                return;
            } 
            insertToNode(set_chainning[index],insertedValue);
            return;
        }
        
        void printSet_chainning(){
            for(auto &node : set_chainning ){
                printLinkedList(node);
            }
        }
        
        bool chainning_lookup(int target) {
            int index = target % 11; 
            return search(set_chainnning[index], target);
        }

        void insert_cuadratic(int insert){
            int newIndex;
            int index = insert%11; // HashFunction
            if (!set_quadratic[index]){
            	set_quadratic[index] = insert;
        	}else{
              	for(int i = 0; i<11;i++){
                    newIndex = (index + i**2)%11; // nuevo indice calculado con cuadratic probing
                    if(set_quadratic[newIndex]){
                        continue;
                    }else{
                        set_quadratic[newIndex];
                    }
              }
            }	
        }
        
        void printQ(){
            for(int i = 0; i<11; i++){
              cout<<set_quadratic[i]<<"\n";
            }
        }
        
    private: 

        void insertToNode(Node* head, Node* insertedValue){
            Node* current = head;
            while(current->next){
                current = current->next; 
            } 
            current->next = insertedValue; 
            return;
        }
    
        bool search(Node* head, int key){
            Node* current = head;
            while(current){
                if(current->data == key)
                    return true;
                current = current->next;
            }
            return false;
        }
        
        void printLinkedList(Node* head){
            if(!head){
                cout<<"NONE";
                return;
            }
            Node* current=head;
            while(current){
                cout<<current->data<<" ";
                current=current->next;
            }
            return;
        }

}; 

int main() {
    Set s;
    s.insert_chainning(22);
    s.insert_chainning(3);
    s.insert_chainning(4);
    s.insert_chainning(33);
    s.printSet_chainning();

    
}