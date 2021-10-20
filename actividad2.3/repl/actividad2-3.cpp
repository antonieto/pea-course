
#include <iostream>
#include <vector> 
#include <fstream> 
#include <string> 
#include <cmath>  
#include <unordered_map> 
#include "P_Queue.cpp" 

using namespace std;

unordered_map<string, int> counts;

int month2absolute(string month, string day){ 
  if(month == "Jan"){ 
    return (stoi(day));
  }
  if(month == "Feb"){ 
    return (31 + stoi(day));
  }
  if(month == "Mar"){ 
    return (59 + stoi(day));
  }
  if(month == "Apr"){ 
    return (89 + stoi(day));
  }
  if(month == "May"){ 
    return (120 + stoi(day));
  }
  if(month == "Jun"){ 
    return (150 + stoi(day));
  }
  if(month == "Jul"){ 
    return (181 + stoi(day));
  }
  if(month == "Aug"){ 
    return (212 + stoi(day));
  }
  if(month == "Sep"){ 
    return (243 + stoi(day));
  }
  if(month == "Oct"){ 
    return (273 + stoi(day));
  }
  if(month == "Nov"){ 
    return (304 + stoi(day));
  }
  if(month == "Dec"){ 
    return (334 + stoi(day));
  } 
  else{ 
    return -1;
  }
}

float time2float(string time){
  string fields[3];
  int npos = 0;
  int token;
  float timeReturn;
  string split = ":";

  for (int i = 0; i < 3; i++){
      token = time.find(split);
      fields[i] = time.substr(npos,token);
      time.erase(0, token + split.length());
  }
  timeReturn =  stoi(fields[0])*3600 + stoi(fields[1])*60 + stoi(fields[2]);   
  return timeReturn/86400;
}
// Clase Error
class Error{ 
  private:
    // float que representa el tiempo absoluto del año
    float time;
    // string que almacena la entrada registrada en bitácora
    string log; 
    string ip; 
    int count;
  public:
    // Error
    // Descripción: constructor de la clase error, que asigna los atributos time y log respectivamente
    Error(int _time, string _log, string _ip){
      this->time = _time;
      this->log = _log; 
      this->ip =_ip;
    }
    // Error
    // Descripción: constructor de la clase error, que asigna los atributos time y log respectivamente
    Error(){
      time = 0;
      log = "nan";
    }
    void setCount(int _count) {
      this->count = _count;
    } 
    int getCount(){
      return this->count;
    }
    static Error fromTxtLine(string line){
      float returnTime;
      string temp = line;
      string fields[4];
      int npos = 0;
      int token;
      string split = " ";
      for (int i = 0; i < 4; i++){
          token = line.find(split);
          fields[i] = line.substr(npos,token); 
          line.erase(0, token + split.length());
      } 
      string key = fields[3] + " " + to_string(month2absolute(fields[0],fields[1]));
      // Check if key is in map 
      if(!counts.count(key)){
        counts.insert({key, 1}); 
      } else {
        counts[key] = counts[key] + 1;
      }

      Error returnError = Error(month2absolute(fields[0],fields[1]),temp, fields[3]);
      return returnError;
    } 

    void printLog(){ 
      cout << this->log << ": "<< this->count << endl;
    }

    void printTime(){ 
      cout << this->time << endl; 
    } 

    string getLog(){ 
      return this->log;
    }

    int getTime(){
      return this->time;
    }
    string getIp(){
      return this->ip;
    }
};

vector<Error> getData(string route){ 
    vector<Error> returnVector;
    ifstream Data;
    string line;
    Data.open(route);
    while(Data.good()){
      getline(Data, line);
      returnVector.push_back(Error::fromTxtLine(line));
    }
    return returnVector;      
  }

void merge(vector<Error> &arr, int l, int r, int m){ 
      int size1 = m - l + 1;
      int size2 = r - m; 
      vector<Error> leftArray, rightArray; 
      // Copias de los vectores
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
          if(leftArray[i].getCount() <= rightArray[j].getCount()){ 
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

void ordenaMerge(vector<Error> &arr, int l, int r){ 
  if(l < r){ 
    int m = floor((l+r)/2); 
    ordenaMerge(arr, l, m); 
    ordenaMerge(arr,m+1,r); 
    merge(arr,l,r,m);
  } 
} 

P_Queue<Error> vector2queue(vector<Error> input){
    P_Queue<Error> returnQueue;
    for (int i = 0; i < input.size(); i++){
        int date = input[i].getTime();
        Error temp = input[i];
        returnQueue.enqueue(temp,date);
    }
    return returnQueue;
}

vector<Error> queue2vector(P_Queue<Error> input){
  vector<Error> returnVector;
  while (! input.isEmpty() ) {
        returnVector.push_back(input.top()); 
        // if(input.top().getCount() > 1){
        //   input.top().printLog();
        // }
        input.dequeue();
    } 
    cout << returnVector.size() << endl;
  return returnVector;
} 
void printQueue( P_Queue<Error> queue ) {
  Node<Error>* currentNode = queue.head; 
  while(currentNode){ 
    cout << currentNode->data.getCount();
    // if(currentNode->data.getCount() > 1) currentNode->data.printLog();
    currentNode = currentNode->next;
  }
}
// void printQueue(P_Queue<Error> input){
//     while (! input.isEmpty() ) {
//         cout << input.top().getLog()<< "\n";
//         input.dequeue();
//     }
//     if(input.isEmpty()){
//         cout<<"Queue is empty\n";
//     } 

int main(){ 
  
  ofstream sorted;
  sorted.open("sorted.txt");
  vector<Error> ErrorList = getData("test.txt");
  // Se ha contado el número de concurencias y se asigna al atributo correspondiente 
  for (int i = 0; i < ErrorList.size(); i++)  {
    string key = ErrorList[i].getIp() + " " + to_string(ErrorList[i].getTime()); 
    ErrorList[i].setCount(counts[key]);
  } 
  // for (int i = 0; i < ErrorList.size(); i++)
  // {
  //   if(ErrorList[i].getCount() > 1) ErrorList[i].printLog();
  // }
  
  // Se ordena en base al número de concurrencias
  ordenaMerge(ErrorList, 0, ErrorList.size() - 1);
  // Se hace un Priority Queue con la prioridad siendo el día
  P_Queue<Error> ErrorOrdenado = vector2queue(ErrorList);
  
  ErrorList = queue2vector(ErrorOrdenado); 
  for (int i = 0; i < ErrorList.size(); i++){ 
    if(ErrorList[i].getCount() > 1) ErrorList[i].printLog();
  }
  
  

  // printQueue(ErrorOrdenado);

  

  return 0;
}