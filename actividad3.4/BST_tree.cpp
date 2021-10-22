// Actividad 3.4: Actividad Integral de BST
// Fecha: 22/10/2021
// Autores:
// Pablo Agustín Ortega Kral A00344664
// Jose Antonio Chaires Monroy A0160114
// Adrian Becerra Meza A01639813

#include <bits/stdc++.h>
#include <fstream> 
#include <string> 
#include <cmath> 
using namespace std;
// Clase Nodo
template <class T> class Node{
  public: 
    T data;
    int key;
    Node<T>* left;
    Node<T>* right;
    // Node
    // Descripción: constructor de la clase NODE, que asigna los atributos
    // data, key y los apuntadores a left y right
    Node(T new_data, int key){
        this -> data = new_data;
        this -> key = key;
        this -> left = NULL;
        this -> right = NULL;
    }
    // Node
    // Descripción: Constructor default
    Node(){
        this->left, this->right = NULL;
    }
};
// Clase BST
template <class T> class BST{
  public:
  Node<T>* root; 
  // BST
  // Constructor default
  BST(){
    this->root = NULL; 
  }
  // Search
  // Encuentra el nodo con respecto a la llave
  // Complejidad: O(N)
  Node<T>* search(Node<T>* head, int search_key){
      if(!head || search_key == head -> key){
          return head;
      }

      if(search_key < head -> key){
          return search(head -> left, search_key);
      }
      return search(head -> right, search_key);
  }
  // Search
  // Sobrecarga de la busqueda utilizando otros parametros
  Node<T>* search(int search_key){
      return this -> search(this -> root, search_key);
  }
  // Insert
  // Inserta los elementos en el arbol binario
  // Complejidad: O(logN)
  Node<T>* insert_helper(Node<T>* head, T data, int key){
    if(!head){
      Node<T>*  node_insert = new Node<T>(data, key);
      return node_insert;
    }  
    if(key > head->key){
      head->right = insert_helper(head->right, data, key); 
    }
    else{
      head->left = insert_helper(head->left, data, key);
    } 
    return head;
  } 
  // Insert
  // Sobrecarga de insert utilizando otros parametros
  void insert(T data, int key){
      this->root = insert_helper(this->root, data, key);
  }
  // Inorder
  // Recorre todo el arbol binario, imprimiendo sus valores
  void inorder_helper(Node<T>* head){
      if(head){
          inorder_helper(head -> right);
          cout <<"IP: "<<head->data<<" "<<"Ocurrence: "<< head -> key << endl;
          inorder_helper(head -> left);
          
      }
      if(this -> root == head){
          cout << endl;
      }
  }
  // Inorder
  // Sobrecarga de inorder utilizando otros parametros
  void inorder(){
      inorder_helper(this->root);
  } 
  // inorderVector
  // Convertir el arbol binario a vector
  void inorderVector(Node<T>* head, vector<T> &array){
      if(head){
        inorderVector(head->right,array);
        array.push_back(head->data);
        inorderVector(head->left,array);
      } 
    }
  };
