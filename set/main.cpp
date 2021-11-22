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
        vector<Node*> set_chainning = vector<Node*>(11); 
        vector<int> set_quadratic = vector<int>(11);
        // Coomplejidad O(m) 
        // m = numero de colisiones del elemento a insertar
        void insert_chainning(int insert){
            int index = insert % 11; 
            Node* insertedValue= new Node(insert);
            
            if(!set_chainning[index] && !search(set_chainning[index], insert)) {
                set_chainning[index] = insertedValue; 
                return;
            } 
            insertToNode(set_chainning[index],insertedValue);
            return;
        }
        // Complejidad O(n) 
        void printSet_chainning(){
            for(auto node : set_chainning ){
                printLinkedList(node);
            } 
            cout << "\n";
        }
        // Complejidad O(m)
        // m = numero de colisiones del elemento buscado 

        bool chainning_lookup(int target) {
            int index = target % 11; 
            return search(set_chainning[index], target);
        }
        // Complejidad O(m)
        // m = numero de colisiones del elemento insertado  
        void insert_quadratic(int insert){
            int newIndex;
            int index = insert%11; // HashFunction
            if (!set_quadratic[index]){
            	set_quadratic[index] = insert;
        	}else{
              	for(int i = 0; i<11;i++){
                    newIndex = (index + (int)pow(i,2))%11; // nuevo indice calculado con cuadratic probing
                    if(set_quadratic[newIndex]){
                        continue;
                        
                    }else{
                        set_quadratic[newIndex]=insert;
                        break;

                    }
              }
            }
        }
        // Complejidad O(n)
        void printQ(){
            for(int i = 0; i<11; i++){
              if(set_quadratic[i]){
                cout<<set_quadratic[i]<<" ";
              }
            } 
            cout << "\n";
        }
        
    private: 
        // Complejidad O(n)
        void insertToNode(Node* head, Node* insertedValue){
            Node* current = head;
            while(current->next){
                current = current->next; 
            } 
            current->next = insertedValue; 
            return;
        }
        // Complejidad O(n)
        bool search(Node* head, int key){
            Node* current = head;
            while(current){
                if(current->data == key)
                    return true;
                current = current->next;
            }
            return false;
        }
        // Complejidad O(n)
        void printLinkedList(Node* head){
            if(!head){
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
     Set s1, s2, s3, s4;
    // Generar los casos de prueba
    vector<Set> test = {s1, s2, s3, s4};
    vector<vector<int>> testCases ={{22,33,3,4,44,20},{2,24,12,60,5,6},{23,1,36,3,9,99},{22,55,6,7,8,33}};
    for (int i = 0; i<4;i++){
        Set test_i = test[i];
        for(int number: testCases[i]){
            test_i.insert_chainning(number);
            test_i.insert_quadratic(number);
        }
        cout<<"---CASO PRUEBA "<<i<<"---\n";
        cout<<"++Chainning++ \n";
        test_i.printSet_chainning();
        cout<<"----------------------\n";
        cout<<"++Quadratic++\n";
        test_i.printQ();
        cout<<"############################\n";
    }
    
}