#include <unordered_map> 
#include <string>
#include <iostream>

using namespace std;


int main(){
  unordered_map<char, int> dic;

  string test = "Unordered map is an associative container that contains key-value pairs with unique keys. Search, insertion, and removal of elements have average constant-time complexity.";

  for(int i = 0; i < test.size() ; i++){
    if(!dic.count(test[i])){
      dic.insert({test[i], 1});
    } else {
      dic[test[i]] = dic[test[i]] + 1;
    }

  }

  unordered_map<char, int>::iterator itr;

  for(itr = dic.begin(); itr != dic.end(); ++itr){
    cout << itr->first << ": " << itr->second << endl; 
  }


}