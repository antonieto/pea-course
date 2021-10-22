// Actividad 2.3: Integracion de Concpetos
// Fecha: 22/12/2021
// Autores:
// Pablo Agustín Ortega Kral A00344664
// Jose Antonio Chaires Monroy A0160114
// Adrian Becerra Meza A01639813
#include <iostream>
#include <vector> 
#include <fstream> 
#include <string> 
#include <cmath>  
#include <unordered_map>
#include "BST_tree.cpp"
using namespace std;
unordered_map<string, int> counts;
// month2absolute
// IN: Recibe dos strings, correspondiente al mes y dia
// OUT: Un float
// Descripción: convierte el mes y día recibidos al número del año total al que corresponde utilizando condicionales
// de este modo, tiene un rango de salida de 1 (1 Enero) a 365 (31 Diciembre).
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
// time2float
// IN: Recibe un string, correspondiente a la hora en formato hr:min:sec
// OUT: Un float
// Descripción: se divide el string utilizando como referencia ":" y se guardan los valores en un array
// de esta forma, se tiene la hora, minutos y segundos separados. Posteriormente se convierte todo a segundos y 
// se regresa un flot correspondiente a la fracción del día que representan.
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
    // Descripción: constructor default
    Error(){
    }
    // setCount
    // IN: int correspondiente al número de ocurencias.
    // OUT: No hay.
    void setCount(int _count) {
      this->count = _count;
    } 
    // getCount
    // IN: No tiene argumentos.
    // OUT: int con el número de ocurencias.
    int getCount(){
      return this->count;
    }
    // fromTxtLine
    // IN: recibe un string, correspondiente a el error registando en formato: "Mes Dia IP hr:min:seg Razón"
    // OUT: un objeto Error
    // Descripción: función estática que toma un string y lo divide basado en el char " ", generando un array 
    // almacenando separadamente Mes, Día, Fecha. Con los valores separados, se llama la función month2absolute y la función
    // time2float para tener un float correspondiente al tiempo. Finalmente, se genera un objeto Error, utilizando el tiempo
    // en float y el string en sí para constuir el objeto.
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
      string key = fields[3];
      // Check if key is in map 
      if(!counts.count(key)){
        counts.insert({key, 1}); 
      } else {
        counts[key] = counts[key] + 1;
      }

      Error returnError = Error(month2absolute(fields[0],fields[1]),temp, fields[3]);
      return returnError;
    } 
    // printLog
    // IN: No tiene argumentos.
    // OUT: No hay.
    // Descripción: imprime el atributo log a consola.
    void printLog(){ 
      cout << this->log << endl;
    }
    // printTime
    // IN: No tiene argumentos.
    // OUT: No hay.
    // Descripción: imprime el atributo time a consola. 
    void printTime(){ 
      cout << this->time << endl; 
    } 
    // getLog
    // IN: No tiene argumenAdded files via uploadtos.
    // OUT: String correspondiente al valor log.
    // Descripción: retorna el valor de log.
    string getLog(){ 
      return this->log;
    }
    // getTime
    // IN: No tiene argumentos.
    // OUT: Float correspondiente al valor de time.
    // Descripción: retorna el valor del atributo time.
    int getTime(){
      return this->time;
    }
    string getIp(){
      return this->ip;
    }
};
// getData
// IN: Recibe un string, correspondiente al nombre del archivo
// OUT: un vector de objetos de Error.
// Descripción: utilizando fstream, se abre el archivo del nombre del string pasado y se utiliza la función predefinida getline
// para leer cada línea del archivo y guardar su valor en un string, el cual se pasa a la función fromTxtLine para generar un 
// objeto Error, el cuál se almacena en un vector.
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
// merge
// IN: Recibe un vector de objetos Error(arr) por referencia, y tres enteros.
// OUT: No hay salida.
// Descripción: toma un vector y crea subarrays, los cuales combina nuevamente en el mismo vector.
// Complejidad: O(N), lineal.
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
// ordenaMerge
// IN: Recibe un vector de objetos Eror(arr) por referencia, y tres enteros
// OUT: No hay salida
// Descripción: algoritmo recursivo que divide el vector tomado por referencia para mandar los subconjuntos 
// creados a merge, donde se ordenan y juntan.
void ordenaMerge(vector<Error> &arr, int l, int r){ 
  if(l < r){ 
    int m = floor((l+r)/2); 
    ordenaMerge(arr, l, m); 
    ordenaMerge(arr,m+1,r); 
    merge(arr,l,r,m);
  } 
}
// map2BST
// IN: Recibe un hashmap
// OUT: un BST
// Descripción: pasa los valores del hasmap al BST, donde el "key de mapa" es el dato y las ocurrencias el key del BST
// Complejidad: O(n log(n))
BST<string> map2BST(unordered_map<string, int> input){
    BST<string> output;

    for(auto k : input){
      output.insert(k.first,k.second);
    }
    return output;
}
int main(){ 
  ofstream sorted;
  sorted.open("sorted.txt");
  vector<Error> ErrorList = getData("bitacoraTest.txt");
  ordenaMerge(ErrorList, 0, ErrorList.size() - 1);
  for (int i = 0; i < ErrorList.size(); i++){
    sorted << ErrorList[i].getLog() << endl;
  } 

  // We have the counts map, now we update every object's count atribute 
  for (int i = 0; i < ErrorList.size(); i++)  {
    string key = ErrorList[i].getIp(); 
    // cout << counts[key] << endl;
    ErrorList[i].setCount(counts[key]);
  }
  // Crear el árbol de las IP y sus concurrencias
  BST<string> BTS = map2BST(counts);
  vector<string> btsArray;
  // Pasar las concurrencias a un array para desplegarlo.
  BTS.inorderVector(BTS.root, btsArray);
  // Printing every Error's count
  cout<<"IP-Recurrencia:"<<endl;
  BTS.inorder();
  cout<<endl;
  cout<<"5 IP con más consultas:"<<endl;
  // Imprimir los 5 primeros elementos correspondiente a las IP más concurridas
  for (int i = 0; i < 5; i++){
     cout << btsArray[i] << " Consultas: " << counts[btsArray[i]] <<endl;
  }
  return 0;
}