#include <iostream> 

using namespace std; 

int max(int a, int b){
  return (a > b) ? a : b;
}

class Node{
  public:
    int key; 
    Node* right; 
    Node* left; 
    int height; 
    Node(){
      key = 0;
      right = NULL; 
      left = NULL;
      height = -1;
    } 
    Node(int _key){
      key = _key; 
      right = NULL;
      left = NULL; 
      height = 1;
    }
};

class AVLTree{
  public:
  Node* root; 
  AVLTree(){
    this->root = NULL; 
  }
  
  int height(Node* node){
    if(!node) return 0; 
    return node->height;
  }

  void insert(int _key){
    if(!this->root) {
      this->root = new Node(_key); 
      return;
    }
    insert(this->root, _key);
  }
  
  int getBalance(Node* node){
    if(node){
      return height(node->left) - height(node->right);
    } else {
      return 0;
    }
  }

  Node* insert(Node* head, int _key){
    
    if(head == nullptr){ 
      head = new Node(_key); 
      return head; 
    } 

    if(_key > head->key){
      head->right = insert(head->right, _key);  
    } else {
      head->left = insert(head->left, _key);
    } 
    head->height = 1 + max(height(head->left), height(head->right)); 

    return balanceTree(head);
    // Do AVL shit here 
  } 

  Node* balanceTree(Node* node){
    int balance = getBalance(node);
    // Cases node has balance of 2 (left rotations)
    if(balance == 2){
      if(getBalance(node->left) == 1){
        // Perform LL Rotation

      } else if(getBalance(node->right) == 1) {
        // Perform LR Rotation
      }
    } else if(balance == 2) {
      if(getBalance(node->left) == 1){
        // Perform RL Rotation
      } else if(getBalance(node->right) == 1){
        // Perform RR Rotation
      }

    } 
    // No rotation needed
    return node;
  }

  Node* rightRotation(Node* node){
    Node* x = node; 
    Node* y = node->right; 


    return node;
  }
  Node* leftRotation(Node* node){
    Node* x = node; 
    Node* y = node->left;
    return node;
  }

  void inorder(){
    inorder(root);
  }
  void inorder(Node* node){
    if(!node){
      return;
    } 
    inorder(node->left); 
    cout << node->key <<  ", Height: " << node->height << endl; 
    inorder(node->right);
  }
};

int main(){
  
  AVLTree myTree; 

  myTree.insert(40);
  myTree.insert(37);
  myTree.insert(39);
  myTree.insert(36);
  myTree.insert(38);
  
  myTree.inorder();
  return 0;
}