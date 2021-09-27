class Solution {
public:
    int reverse(int x) { 
        int output = 0; 
        int n=x; 
        int sign; 
        int digits = 0;
        if( n < 0){ 
          sign = -1;
        } else{ 
          sign = 1;
        }
        if(x >= 2147483648  or x <= -(2147483648)){
            return 0;
        } 
        n =n*sign;        
        while( n > 0){
          int units = n % 10;  
          n = n - units;
          n = n / 10;
          try{
              if (output>2147483648/10){
                  throw 42;
              }
              
              
          }
          catch(int i){
              return 0;
          }
          
          output = output*10 + units;
        }  
        return output *sign;
    }
};