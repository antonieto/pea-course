#include <iostream> 

using namespace std; 

void add_10( int &x){ 
    x += 10; 
}



int main() { 

    int array[10]; 
    
    for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++) { 
        array[i] = i*2;
        cout << array[i] << " ";
    }
 
    

    return 0;
}