#include <iostream> 
#include <vector>
#include <bits/stdc++.h> 
#include <cmath>


using namespace std; 

int busqSecuencial(vector<int> arr, int target){ 
    int len = arr.size(); 
    for(int i = 0; i<len ; i++){ 
        if(target == arr[i]){ 
            return i;
        }
    }
    return -1;
}

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
        else if( target > arr[mid] ){ 
            r = mid-1;
        } else { 
            l = mid+1;
        } 
    }
    return -1;
}  

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

int main(){ 
    int n = 10;

    vector<int> array(n, 0); 

    srand(time(0));
    generate(array.begin(), array.end(), [](){ 
        return rand() % 20;
    }); 

    cout << busqSecuencial(array, 1) << endl; 

    cout << "desordenado" << endl; 
    printArray(array);
    cout << " Ordenado " << endl;
    
    printArray(ordenaIntercambio(array));  
    
    vector<int> array_ordenado = ordenaBurbuja(array); 

    cout << busqBinaria(array_ordenado, 10) << endl;

    return 0;
}