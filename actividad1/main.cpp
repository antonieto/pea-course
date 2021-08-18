#include <iostream> 
using namespace std; 

// Calcula la sumatoria de 1 hasta n con un método iterativo
int sumaIterativa(int n) {   
    int acc = 0;
    for(int i = 1; i <= n ; i++) { 
        acc += i;
    }
    return acc;
 }

// Calcula la sumatoria de 1 hasta n con un método recursivo
int sumaRecursiva(int n) { 

    if(n == 0) return 0;
    if(n == 1) return 1; 
    return sumaRecursiva(n-1) + n;
}

// Calcula la sumatoria de 1 hasta n con un método matemático directo 
int sumaDirecta( int n ) {
    return (n*(n+1)/2); 
}

int main(){ 

    int X = 100;

    cout << sumaIterativa(X) << endl;
    cout << sumaRecursiva(X) << endl;
    cout << sumaDirecta(X) << endl;

    return 0;
}