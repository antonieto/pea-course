#include <iostream> 

using namespace std; 

int main(){

    int x = 9000;

    x = abs(x);
        
    string s = to_string(x);
    int n = s.length();
    string reversed = s; 
//         Reversing the string 
    
    for(int i = n-1; i>=0; i--){ 
        cout << s[i] << s[n-i-1] << endl; 
        reversed[n-i-1] = s[i];
    }

    // Trim zeros from reversed 

    int temp = stoi(reversed); 

    reversed = to_string(temp);


    cout << reversed << endl;
    cout << s << endl;


    return 0;
}