#include <iostream> 
#include <time.h>
using namespace std; 

template <class T> class Node {

    public: 
    T val; 
    Node* right;     
    Node* left;  
    
    Node<T>(T _val){
        this-> right = NULL;
        this-> left = NULL;
		this-> val = _val;
	}
	
    
    int getVal(){
        return this->val;
    }

    void setVal(int val){
        this->val=val;
    }
    
}; 

template <class T> class BinaryTree{ 
    private: 
    Node<T> *root; 
    public: 
    
    BinaryTree(T _val){
    	Node<T>* newNode = new Node<T>(_val);
        this->root = newNode; 
    }
	 
    BinaryTree(){
      this->root = NULL; 
    } 


	

    void insert(T _val){
      	Node<T>* newNode = new Node<T>(_val);

      	if(!this->root){
  	  		this->root = newNode;
	  	  	return;
      	}
     	Node<T>* currentNode = this->root; 

      	while(currentNode->left || currentNode->right){
            if(currentNode->left && !currentNode->right){
                currentNode->right = newNode; 
                return;
			}
		    else if (!currentNode->left && currentNode->right) {
		  	  	currentNode->left = newNode;
			    return;
        	}else { 
				if(this->rightLeft()){
					currentNode = currentNode->left;
				} else { 
					currentNode = currentNode->right;
				}
			} 
        }
		
        if(this->rightLeft()){
            currentNode->left = newNode; 
        } else { 
            currentNode->right = newNode;
        } 
	}
	
    bool rightLeft(){
        srand( (unsigned)time( NULL ) );
       ;
        float valor = (float)rand()/RAND_MAX;
        cout<<valor<<endl;	
        return valor < 0.5;
    } 

};  

int main(){
    BinaryTree<int> arbol(5);
    arbol.insert(5); 
    arbol.insert(6); 
    arbol.insert(8); 
    arbol.insert(10); 
    arbol.insert(11); 
    arbol.insert(20); 
    arbol.insert(199); 
  	return 0;
}