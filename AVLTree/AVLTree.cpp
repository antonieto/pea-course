#include <iostream> 
#include <queue>
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
  int len;
  AVLTree(){
    this->root = NULL; 
    this->len = 0;
  }

  // Retorna altura del nodo, si existe. 
  // O(1)
  int height(Node* node){
    if(!node) return 0;
    return node->height;
  }
  // Retorna balance del nodo, si existe
  // O(1)
  int getBalance(Node* node){ 
    if(!node) return 0;
    return height(node->left) - height(node->right);
  }

  // Metodos de inserción 
  
  // insert
  // Inserta un nodo en el árbol
  // Llamadas significativas: balanceTree ( O(1) )
  // O(log(n)) : La complejidad temporal corresponde al 
  // numero de niveles del arbol
  Node* insert(Node* current, int k){
    if(!current){
      return new Node(k);
    }
    if( k > current->key){
      current->right = insert(current->right, k);
    } else {
      current->left = insert(current->left, k);
    } 
    current->height = 1 + max(height(current->left), height(current->right)); 
    return balanceTree(current);

  }

  void insert(int key){
    this->len++;
    this -> root = insert(this->root, key);

  }

  // Metodos delete 
  // Busca y elimina un nodo del arbol. 
  // Complejidad: O(log(n))
  Node* del(Node* node, int k){
    
    if(node == NULL){
          return NULL;
    }
    if(k < node-> key){
        node -> left = del(node->left, k);
    }
    else if( k > node -> key){
        node -> right = del(node -> right, k);
    }
    else{
         // Case
          if( (node -> left == NULL) && (node -> right = NULL)){
            delete node;
          }
          //Node with one Child
          else if(node -> left == NULL){
            Node* temp = node -> right;
            delete node;
            return temp;
          }
          else if(node -> right == NULL){
            Node* temp = node -> left;
            delete node;
            return temp;
          }
          // Node with 2 Childs
          else{
            Node* temp = leftRightMost(node -> right);
            node -> key = temp -> key;
            node -> right = del(node -> right, temp -> key);
          }
    }
    // Actualizamos altura del ancestro
    node->height = 1 + max(height(node->left),height(node->right));
    // Balanceamos el árbol
    return balanceTree(node);
    
  }
  
  void del(int k){
    if(find(k)) len--;
    this->del(this->root, k);
  }

  // Metodo find 
  // Complejidad: O(log(n))
  Node* find(Node* current, int k){

    if(!current) return NULL; 
    if(current->key == k) return current; 
    
    if(k > current->key){
      current = find(current->right, k);
    } else {
      current = find(current->left, k); 
    } 
    return current;

  }

  Node* find(int k){
    return find(this->root, k);
  }

  // Rotations and balancing
  // Complejidad: O(1)
  Node* rRotate(Node* node){
    
    Node* n1 = node->right; 
    Node* n2 = n1->left;
  
    n1->left = node;
    node->right = n2; 

    node->height = 1 + max(height(node->left), height(node->right));
    n1->height = 1 + max(height(n1->left), height(n1->right));
    return n1;
  }
  // Complejidad: O(1)
  Node* lRotate(Node* node){
    
    Node* n1 = node->left; 
    Node* n2 = n1->right; 
    
    n1->right = node; 
    node->left = n2; 
    
    node->height = 1 + max(height(node->left), height(node->right));
    n1->height = 1 + max(height(n1->left), height(n1->right));

    return n1; 
  }
  // Complejidad: O(1)
  Node* balanceTree(Node* node){
    int bf = getBalance(node);
    // Case LL rotation 
    if(bf > 1 && getBalance(node->left) == 1){
      return lRotate(node);
    }
    // Case LR rotation 
    if(bf > 1 && getBalance(node->left) == -1){
      node->left = lRotate(node->left); 
      return rRotate(node);
    } 
    // RR Rotation 
    if(bf < -1 && getBalance(node->right) == -1) {
      return rRotate(node);
    } 
    // RL Rotation
    if(bf < -1 && getBalance(node->right) == 1){
      node->right = rRotate(node->right); 
      return lRotate(node);
    }
    // Case no rotation is needed 
    return node;
  }

  // Size method
  int size(){
    return this->len;
  }

  // Traversal prints

  void inorder(){
    inorder(root);
  }
  
  void inorder(Node* node){
    if(!node){
      return;
    } 
    inorder(node->left); 
    cout << node->key <<  ", Height: " << node->height << "balance: " << getBalance(node) << endl; 
    inorder(node->right);
  }

  void levelOrder(Node* node){
    for(int i = 0; i <= node->height; i++){
      printLevel(node, i); 
      cout << endl;
    }
  }

  void levelOrder(){
    for(int i = 1; i <= this->root->height; i++){
      printLevel(this->root, i); 
      cout << endl;
    }
  }

  void printLevel(Node* node, int level){
    if(!node) return; 
    if(level == 1){
      cout << node->key << " ";
    } else if(level > 1){
      printLevel(node->left, (level - 1));
      printLevel(node->right, (level - 1));
    }

  } 

  // Helpers
  bool isLeaf(Node* node){
    return node && !node->left && !node->right;
  }
  bool onlyLeft(Node* node){
    return node && node->left && !node->right;
  } 
  bool onlyRight(Node* node){
    return node && !node->left && node->right;
  } 
  bool hasTwo(Node* node){
    return node && node->left && node->right;
  }

  Node* successor(Node* node){
    if(!node) return NULL; 
    if(!node->right) return NULL;
    
    node = node->right; 

    // Find left-most 
    while(node->left){
      node = node->left;
    }
    return node;

  }

  Node* leftRightMost(Node* node){
    if(!node || !node->right) return NULL; 

    node = node->right; 

    while(node->right){
      node = node->right;
    } 
    return node;
  }

};

int main(){
  
  AVLTree myTree1; 

  myTree1.insert(40);
  myTree1.insert(41); 
  myTree1.insert(42);
  myTree1.insert(43);
  myTree1.insert(44);
  myTree1.insert(45);
  myTree1.insert(46);
  myTree1.insert(47);
  myTree1.insert(48);

  cout << "Printing level order" << endl;
  myTree1.levelOrder(); 

  cout << "Size: " << myTree1.size() << endl;

  cout << "\n" ;

  cout << "Deleting 43" << endl; 

  cout << "\n";

  myTree1.del(43);

  myTree1.levelOrder(); 

  cout << "Size: " << myTree1.size() << endl;

  cout << "\n ------- \n" << endl;
 
  cout << " Case 2" << endl;
  AVLTree tree2; 

  tree2.insert(20);
  tree2.insert(23);
  tree2.insert(24);
  tree2.insert(15);
  tree2.insert(30);

  tree2.levelOrder();
  cout << " Finding 30 " << endl;
  tree2.find(30) ? cout << "30 \n" : cout << "Not found" << endl;  
  
  cout << " Finding 31 " << endl;
  tree2.find(31) ? cout << "31 \n" : cout << "Not found" << endl;  
  cout << "Size: " << tree2.size() << endl;
  cout << "\n";
  cout << "Deleting 23" << endl; 
  tree2.del(23); 
  cout << "\n";
  tree2.levelOrder();
  cout << "Size: " << tree2.size() << endl;
  
  cout << "\n ------- \n" << endl;
  
  cout << " Case 3" << endl;
  AVLTree tree3; 

  tree3.insert(50);
  tree3.insert(40);
  tree3.insert(30);
  tree3.insert(100);
  tree3.insert(105);

  tree3.levelOrder();
  cout << " Finding 30 " << endl;
  tree3.find(30) ? cout << "30 \n" : cout << "Not found" << endl;  
  
  cout << " Finding 31 " << endl;
  tree3.find(31) ? cout << "31 \n" : cout << "Not found" << endl;  
  cout << "Size: " << tree3.size() << endl;
  cout << "\n";
  cout << "Deleting 50" << endl; 
  tree3.del(50); 
  cout << "\n";
  tree3.levelOrder();
  cout << "Size: " << tree3.size() << endl;
  cout << "\n ------- \n" << endl;
  cout << " Case 4" << endl;
  AVLTree tree4; 

  tree4.insert(100);
  tree4.insert(200);
  tree4.insert(300);
  tree4.insert(150);
  tree4.insert(400);

  tree4.levelOrder();
  cout << " Finding 300 " << endl;
  tree4.find(300) ? cout << "300 \n" : cout << "Not found" << endl;  
  
  cout << " Finding 350 " << endl;
  tree4.find(350) ? cout << "350 \n" : cout << "Not found" << endl;  
  cout << "Size: " << tree4.size() << endl;
  cout << "\n";
  cout << "Deleting 200" << endl; 
  tree4.del(200); 
  cout << "\n";
  tree4.levelOrder();
  cout << "Size: " << tree4.size() << endl;
  
  return 0;
}