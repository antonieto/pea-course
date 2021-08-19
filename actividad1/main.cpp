#include <iostream> 
using namespace std; 

// Calcula la sumatoria de 1 hasta n con un método iterativo
int sumaIterativa(int n) {   
    int acc = 0;
    for(int i = 1; i <= n ; i++) { //Sumatoria de i desde i = 1 hasta i = n - 1
        acc += i; // Operación básica i 
    } 

    // Sumatoria -> S =  n - 1, que pertenece a O(n)

    return acc;
 }

// Calcula la sumatoria de 1 hasta n con un método recursivo
int sumaRecursiva(int n) { 

    if(n<=1) return n; // Retorna 1 si n = 1, 0 si n = 0.
    return sumaRecursiva(n-1) + n;  // M(n) = M(n-1) + 1 si M es mayor que 1 
    // M(n) = n, por su relación de recursividad, 
    // Por lo tanto, O(n)
}

// Calcula la sumatoria de 1 hasta n con un método matemático directo 
int sumaDirecta( int n ) {
    return (n*(n+1)/2);  //Operación básica 
    // La operacion se realiza una sola vez, por lo que el algoritmo pertenece a 
    // O(1)
}

int main(){ 

    int caso1 = 100; 
    int caso2 = 30; 
    int caso3 = 0; 
    int caso4 = 24;

    // cout << sumaIterativa(caso1) << endl;
    // cout << sumaRecursiva(caso1) << endl;
    // cout << sumaDirecta(caso1) << endl; 
    cout << "sumaIterativa(" << caso1 << "): " << sumaIterativa(caso1) << " "; 
    cout << "sumaRecursiva(" << caso1 << "): " << sumaRecursiva(caso1) << " ";  
    cout << "sumaDirecta(" << caso1 << "): " << sumaDirecta(caso1) << " "; 
    cout << "\n"; 
    cout << "sumaIterativa(" << caso2 << "): " << sumaIterativa(caso2) << " "; 
    cout << "sumaRecursiva(" << caso2 << "): " << sumaRecursiva(caso2) << " ";  
    cout << "sumaDirecta(" << caso2 << "): " << sumaDirecta(caso2) << " "; 
    cout << "\n"; 
    cout << "sumaIterativa(" << caso3 << "): " << sumaIterativa(caso3) << " "; 
    cout << "sumaRecursiva(" << caso3 << "): " << sumaRecursiva(caso3) << " ";  
    cout << "sumaDirecta(" << caso3 << "): " << sumaDirecta(caso3) << " "; 
    cout << "\n"; 
    cout << "sumaIterativa(" << caso4 << "): " << sumaIterativa(caso4) << " "; 
    cout << "sumaRecursiva(" << caso4 << "): " << sumaRecursiva(caso4) << " ";  
    cout << "sumaDirecta(" << caso4 << "): " << sumaDirecta(caso4) << " "; 
    cout << "\n"; 
    return 0;
}