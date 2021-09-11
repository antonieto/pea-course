#include <iostream> 
#include <vector>
#include <bits/stdc++.h> 
#include <cmath>


using namespace std; 
// Complejidad: 
// Una operación se realiza n veces, 
// Complejidad: O(n)
int busqSecuencial(vector<int> arr, int target){ 
    int len = arr.size(); 
    for(int i = 0; i<len ; i++){ 
        if(target == arr[i]){ 
            return i;
        }
    }
    return -1;
}

// El problema se divide en dos en cada iteracion, 
// Complejidad: O(log(n))
int busqBinaria(vector<int> arr, int target){ 
    
    int n = arr.size(); 
    int l = 0; 
    int r = n - 1; 
    int mid;
    while(l <= r){ 
        mid = floor((l+r) / 2); 
        if( target == arr[mid] ){ 
            return mid;
        } 
        else if( target < arr[mid] ){ 
            r = mid-1;
        } else { 
            l = mid+1;
        } 
    }
    return -1;
}  

// Análisis de complejidad 
// While con complejidad O(n) anidado a un for con complejidad O(n) 
// Complejidad: O(n^2)
vector<int> ordenaIntercambio(vector<int> array){ 
    int n = array.size(); 
    int key, j; 
    for(int i = 1; i < n; i++){ 
        key = array[i]; 
        j = i-1; 
        while(j >= 0 && array[j] > key){ 
            array[j + 1] = array[j]; 
            j--;
        }
        array[j + 1] = key; 
    } 
    return array;


}
// for itera n veces dentro de otro for 
// Complejidad: O(n^2) 
vector<int> ordenaBurbuja(vector<int> arr){ 
    int n = arr.size();
    for(int i = 0; i<n; i++){ 
        for(int j = 0; j < n-i-1; j++){ 
            if(arr[j] > arr[j+1]){ 
                // Intercambiar 
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp;
            }
        }
    } 
    return arr;
}

void printArray(vector<int> array){ 
    for(int i =0 ; i < array.size();  i++){ 
        cout << array[i] << " ";
    } 
    cout << endl;
}

// Complejidad O(n)
void merge(vector<int> &arr, int l, int r, int m){ 
    int size1 = m - l + 1;
    int size2 = r - m; 
    vector<int> leftArray, rightArray; 
    for(int i = 0; i < size1; i++){ 
        leftArray.push_back(arr[l+i]);
    } 
    for(int j = 0; j < size2; j++){ 
        rightArray.push_back(arr[m+j+1]); 
    }  
    // Merge 
    int i = 0; 
    int j = 0; 
    int k = l;
    while(i < size1 && j < size2){ 
        if(leftArray[i] <= rightArray[j]){ 
            arr[k] = leftArray[i]; 
            i++;
        } else { 
            arr[k] = rightArray[j]; 
            j++; 
        } 
        k++;
    }  
    // Agregar elementos restantes
    while(j < size2){ 
        arr[k] = rightArray[j]; 
        j++; 
        k++;
    }
    while(i < size1){ 
        arr[k] = leftArray[i]; 
        i++; 
        k++;
    }  
}

// En cada operación se llama a merge, que es O(n) 
// Complejidad por teorema maestro: O(n log(n))
void ordenaMerge(vector<int> &arr, int l, int r){ 
    if(l < r){ 
        int m = floor((l+r)/2); 
        ordenaMerge(arr, l, m); 
        ordenaMerge(arr,m+1,r); 
        merge(arr,l,r,m);
    } 
}

int main(){ 
    int n = 10;

    // vector<int> array1(n), array2(n), array, array3(n); 

    srand(time(0));
    // generate(array1.begin(), array1.end(), [](){ 
    //     return rand() % 20;
    // }); 
    // generate(array2.begin(), array2.end(), [](){ 
    //     return rand() % 20;
    // }); 
    // generate(array3.begin(), array3.end(), [](){ 
    //     return rand() % 20;
    // }); 

    // array1 = ordenaIntercambio(array1); 
    // array2 = ordenaIntercambio(array2); 
    // printArray(array3);
    // ordenaMerge(array3, 0, array3.size() - 1);
    // printArray(array3);
    cout << " Probando algoritmos de busqueda" << endl;
    cout << " busqSecuencial: " <<endl;
    for(int i =0; i < 4; i++){
        cout << "Arreglo: " << endl; 
        vector<int> array1(n); 
        generate(array1.begin(), array1.end(), [](){ 
            return rand() % 20;
        });  

        int target = rand() % 20;
        printArray(array1);
        cout << "Buscando " << target << endl; 
        cout << busqSecuencial(array1, target) << endl;

    } 
    cout << "-------------" << endl;
    cout << "busqBinaria() " << endl; 
    for(int i =0; i < 4; i++){
        cout << "Arreglo: " << endl; 
        vector<int> array1(n); 
        generate(array1.begin(), array1.end(), [](){ 
            return rand() % 20;
        });  
        ordenaMerge(array1,0,array1.size());
        int target = rand() % 20;
        printArray(array1);
        cout << "Buscando " << target << endl; 
        cout << busqBinaria(array1, target) << endl;

    }  
    cout << "---------------" << endl; 
    cout << endl;
    cout << endl; 
    cout << " Probando algoritmos de ordenamiento " << endl; 
    cout << "-----" << endl;
    cout << " ordenaIntercambio() " << endl;
    for(int i =0; i < 4; i++){
        vector<int> array1(n);  
        generate(array1.begin(), array1.end(), [](){ 
            return rand() % 20;
        });  
        cout << " Arreglo inicial: "; 
        printArray(array1);
        cout << " Arreglo ordenado: "; 
        array1 = ordenaIntercambio(array1);
        printArray(array1); 
        cout << endl;
    }  
    cout << "-----" << endl;
    cout << " ordenaBurbuja() " << endl;
    for(int i =0; i < 4; i++){
        vector<int> array1(n);  
        generate(array1.begin(), array1.end(), [](){ 
            return rand() % 20;
        });  
        cout << " Arreglo inicial: "; 
        printArray(array1);
        cout << " Arreglo ordenado: "; 
        array1 = ordenaBurbuja(array1);
        printArray(array1); 
        cout << endl;
    }  
    cout << "-----" << endl;
    cout << " ordenaMerge() " << endl;
    for(int i =0; i < 4; i++){
        vector<int> array1(n);  
        generate(array1.begin(), array1.end(), [](){ 
            return rand() % 20;
        });  
        cout << " Arreglo inicial: "; 
        printArray(array1);
        cout << " Arreglo ordenado: "; 
        ordenaMerge(array1, 0, array1.size());
        printArray(array1); 
        cout << endl;
    }  

    return 0;
}