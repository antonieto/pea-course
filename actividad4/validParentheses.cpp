#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentesis;
        int size = s.length();
        int acc = 0;
        for (int i = 0; i < size; i++){
            char character= s[i];
            if ((character ==')' or character==']' or character=='}') and parentesis.size()==0){
                return false;
            }

            if (character=='('){
                parentesis.push(character);
                acc++;
            }
            else if (character== '{'){
              parentesis.push(character);
              acc++;  
            }
            else if (character== '['){
              parentesis.push(character);
              acc++;  
            }

            if (parentesis.size()!=0){
                if (character==')'){
                    if (parentesis.top()=='('){
                        parentesis.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if (character==']'){
                    if (parentesis.top()=='['){
                        parentesis.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if (character=='}'){
                    if (parentesis.top()=='{'){
                        parentesis.pop();
                    }
                    else{
                        return false;
                    }
                }   
            }    
        }
        return parentesis.size()==0 and acc!=0;

    }
};