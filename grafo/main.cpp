#include <bits/stdc++.h>

using namespace std; 

template<class T> class Node {
  public:
  T data; 
  int key;
  vector<Node*> adj;
  Node(T _data, int _key){
    this->data = _data; 
    this->key = _key;
  } 
  // O(n)
  void connect(Node<T>* child){
    // Verificar si el nodo a conectar no está conectado ya 
    for(auto iterator : this->adj ){
      if(iterator == child) {
        cout << " Edge already exists " << endl; 
        return;
      }
    }
    this->adj.push_back(child);
  }

};

template<class T> class Grafo{
  public:
  int v; 
  int e; 
  vector< Node<T>*> nodes;
  unordered_map<T, int> keymap; 

  Grafo(){
    v = 0;
    e = 0;
  }
  // O(n) 
  // La inserción al vector de nodos es LINEAL
  void insert(T key) {
    if(keymap.count(key) > 0){
      cout << "key already exists" << endl;
      return;
    }
    nodes.push_back(new Node<T>(key, v));
    keymap[key] = v; 
    v++;
  }
  // O(n) 
  // La función connect() es O(n)
  // Todas las demás operaciones son O(1)
  void addEdge(T origin, T end){
    if(!nodeExists(origin) || !nodeExists(end)){
      cout << "origin node or end node do not exist" << endl;      
      return;
    } 
    Node<T>* originNode = nodes[keymap[origin]]; 
    Node<T>* endNode = nodes[keymap[end]]; 
    originNode->connect(endNode);

  }   

  // O(m) 
  // Donde:
  //  m = numero de nodos conectados con el nodo origen   
  // El ciclo recorre el numero de nodos conectados con el nodo origen 
  // Verifica si el arco especificado ya existe en el grafo 
  bool edgeExists(T origin, T end){
    if(!nodeExists(origin) || !nodeExists(end)) {
      cout << "origin node or end node do not exist" << endl;
    }
    
    for(auto neighbor : nodes[keymap[origin]]->adj){
      if(neighbor->data == end){
        return true;
      }
    }

    return false; 
  } 
  // O(1) 
  // Funcion de la libreria estandar de c++
  bool nodeExists(T key){
    return keymap.count(key) > 0;
  }
  // O(nm)
  // Funcion que imprime las listas de adyacencia  
  void printList(){
    for(auto n : nodes){
      cout << n->data << ": ";
      for(auto k : n->adj){
        cout << k->data << " ";
      } 
      cout << endl;
    } 
  } 
  // O(n + m) 
  // n = numero de nodos 
  // m = numero de arcos 
  // La complejidad corresponde a la de un Depth First Search traversal
  bool isTree(){
    
    bool *visited = new bool[v];
    bool *recStack = new bool[v]; 
    
    for (int i = 0; i < v; i++){
      visited[i] = false; 
      recStack[i] = false;
    } 
    
    for (int i = 0; i < v; i++){
      if(isTreeUtil(i, visited, recStack)){
        return false; 
      };
    }
    return true;    
    
  
  }
  bool isTreeUtil(int v, bool visited[], bool *recStack) { 
    if(visited[v] == false){ 
      visited[v] = true; 
      recStack[v] = true; 

      for (int i = 0; i < nodes[v]->adj.size(); i++){
        int node = nodes[v]->adj[i]->key; 
        if(!visited[node] && isTreeUtil(node, visited, recStack)) {
          return true; 
        } 
        else if (recStack[node]) return true;
      }

    }
    recStack[v] = false; 
    return false;
  } 

  // O(n + m)
  // Se ejecutan dos ciclos correspondientes a los inputs
  void loadGraph(int n, int m){

    bool error; 
    cout << "Introduce " <<n<< " nodos" << endl;
    for(int i = 0; i < n; i++){
      error = true; 
      while(error){
        cout << "Introduce el dato del nodo "<< i+1 <<": "; 
        T temp; 
        cin >> temp; 
        if(this->nodeExists(temp)) {
          cout << "Ese nodo ya existe, introduce otro " << endl;
        } else {
          error = false;
          this->insert(temp); 
        }
      }
    }

    cout << "Introduce " << m << " arcos" << endl; 
    for (int i = 0; i < m; i++){
      error = true; 
      while(error){
        T temp1, temp2;
        cout << "Introduce el nodo de origen "; 
        cin >> temp1; 
        cout << "Introduce el nodo final ";  
        cin >> temp2;  

        if(this->edgeExists(temp1,temp2)){
          cout << "Ese arco ya existe, intenta de nuevo" << endl; 
        } else if(!nodeExists(temp1) || !nodeExists(temp2)) {
          cout << "Uno de los nodos no existe, intenta de nuevo" << endl;
        } else { 
          this->addEdge(temp1,temp2);
          error = false;
        }
      }
    }
     
  }

};

int main(){
  Grafo<string> test1;
  test1.insert("A");
  test1.insert("B");
  test1.insert("C");
  test1.insert("D");

  test1.addEdge("A","B");
  test1.addEdge("B","D");
  test1.addEdge("B","C");
  test1.addEdge("D","A");
  test1.addEdge("C","A");
  test1.addEdge("C","D"); 
  
  cout << "Grafo 1:" << endl;
  test1.printList(); 
  cout << ( test1.isTree() ? "Grafo 1 es arbol\n" : "Grafo 1 no es arbol\n" ); 

  cout << "----------" << endl;  
  
  Grafo<string> test2;
  cout << "Grafo 2:" << endl; 
  test2.loadGraph(5, 6); 
  test2.printList();
  cout << ( test2.isTree() ? "Grafo 2 es arbol\n" : "Grafo 2 no es arbol\n" ); 

  cout << "----------" << endl;  

  Grafo<string> test3; 
  cout << "Grafo 3" << endl;
  test3.loadGraph(3,2);
  test3.printList();
  cout << ( test3.isTree() ? "Grafo 3 es arbol\n" : "Grafo 3 no es arbol\n" ); 


  cout << "----------" << endl;  

  Grafo<string> test4; 
  cout << "Grafo 4" << endl; 

  test4.insert("A");
  test4.insert("B");
  test4.insert("C");
  test4.insert("D");
  test4.insert("E");

  test4.addEdge("A", "B");
  test4.addEdge("B", "D");
  test4.addEdge("D", "A");
  test4.addEdge("C", "E");
  

  test4.printList(); 

  cout << (test4.isTree() ? "Grafo 4 es arbol\n" : "Grafo 4 no es arbol \n");
  

}