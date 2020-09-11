#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insertionSort(vector<int> lista){
  for(int i=0; i<lista.size(); i++){      // o(n)
    insertar(lista,i);                    // o(n)
  }
  return lista;
}       // recorro la lista y algo la insercion si es que corresponde, es decir si es mas grande el elemento anterior
// --> complejidada o(n²)
void insertar(vector<int> &lista, int i){
  while(i>0; && lista[i]<lista[i-1]){   // O(n)
    swap(lista, i, i-1);
    i--;
  }
}


void swap(vector<int> &lista, int i, int j){
  int k=lista[i];
  lista[i] = lista[j];
  lista[j] = k;
}
