
#include <iostream>
#include <vector> 
#include <fstream> 
#include <string> 
#include <cmath>  
#include <unordered_map>

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
      cout << this->log << endl;
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
          if(leftArray[i].getTime() <= rightArray[j].getTime()){ 
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

int main(){ 
  ofstream sorted;

  sorted.open("sorted.txt");

  vector<Error> ErrorList = getData("bitacora.txt");

  ordenaMerge(ErrorList, 0, ErrorList.size());

  for (int i = 0; i < ErrorList.size(); i++){
    sorted << ErrorList[i].getLog() << endl;
  } 

  // We have the counts map, now we update every object's count atribute 
  for (int i = 0; i < ErrorList.size(); i++)  {
    string key = ErrorList[i].getIp() + " " + to_string(ErrorList[i].getTime()); 
    // cout << counts[key] << endl;
    ErrorList[i].setCount(counts[key]);
  }
  
  // Printing every Errror's count

  for (int i = 0; i < ErrorList.size(); i++)
  {
    if(ErrorList[i].getCount() > 1) ErrorList[i].printLog();
  }  

  return 0;
}