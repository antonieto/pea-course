#include <bits/stdc++.h>
#include <fstream> 
#include <string> 
#include <cmath> 
using namespace std;
// Clase Nodo
template <class T> class Node {
    public:
        T data; 
        int priority;
        Node* next; 
        // Node
        // Descripción: constructor de la clase NODE, que asigna los atributos data, priority y next
        Node(T new_data,int prio, Node* next_node){
            this->priority = prio;
            this->data = new_data;
            this->next = next_node;
        }
        // Node
        // Descripción: constructor de la clase NODE, que asigna los atributos data, priority y deja next como nulo
        Node(T new_data, int prio){
            this->data = new_data;
            this->priority = prio;
            this->next = NULL;
        }
        // set_data
        // IN: recibe un valor tipo T
        // OUT: N/A
        // Descripción: asigna el valor al atributo data
        void set_data(T new_data){
            this->data = new_data;
        }
         // set_next
        // IN: recibe un apuntaodr a un nodo
        // OUT: N/A
        // Descripción: asigna el apuntador al siguiente Nodo
        void set_next(Node *next_node){
            this->next = next_node;
        }
};
// Clase custom de Priotiy Queue
template <class T> class P_Queue{
    public:
        Node<T>* head;

        P_Queue(){
            head=NULL;
        }
        P_Queue(T data, int prio){
            head = new Node<T>(data,prio);
        }
        void enqueue(T data, int p){
            Node<T>* temp=head;
            Node<T>* insertNode = new Node<T>(data,p);
            if(head){
                if(head->priority>p){
                    insertNode->next = head;
                    head = insertNode;
                }
                //Iterar hasta encontrar el nodo que queremos 
                while (temp->next!=NULL&&temp->next->priority<p){
                    temp = temp->next;
                }
                insertNode->next=temp->next;
                temp->next=insertNode;
            }else{
                head = insertNode;
            }
        }
        T top(){
            return head->data;
        }
        void dequeue(){
            Node<T>*temp = head;
            head = temp->next;
            delete temp;
        }
        bool isEmpty(){
            bool status = head == NULL;
            return status;
        } 
};