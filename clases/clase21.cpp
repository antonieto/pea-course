#include <bits/stdc++.h>

using namespace std;

class Grafo {
    public: 
    	vector<vector<int>> matrix; 
        int numNodos=0;
        map<string, int> nodos;
        Grafo(){
            numNodos = 0; 
        }
		void insert(string key) {
            vector<int> aux(numNodos + 1, 0);
			matrix.push_back(aux);
            for(int i=0; i<matrix.size();i++){
                matrix[i].push_back(0);
            }
            nodos[key] = numNodos;
            numNodos++; 
        }
        
        void addEdge(string origin, string end, int value){
            // Agregar un 1
            matrix[nodos[origin]][nodos[end]] = value; 
            
        }    

        void printMatrix(){
            // Imprimir keys 
            cout << "  ";
            for(auto key : nodos) {
                cout << key.first << " "; 
            } 
            cout << endl; 
            map<string, int>::iterator ptr = nodos.begin();
            for(int i = 0; i < matrix.size(); i++){
                cout<<ptr->first<< " ";
            	for(int j= 0; j < matrix.size(); j++){
                    cout<<matrix[i][j] << " ";
                }
            	cout << endl;
                ptr++;
			}
			
        }    
}; 

int main(){
    
    Grafo grafoTest; 
    
    grafoTest.insert("A"); 
    grafoTest.insert("B");
    grafoTest.insert("C");
    grafoTest.insert("D");

    grafoTest.addEdge("A","C",2);
    grafoTest.addEdge("B","C",3);
    grafoTest.addEdge("C","D",5);
    grafoTest.addEdge("D","B",8);
    grafoTest.printMatrix();

    return 0;
}
