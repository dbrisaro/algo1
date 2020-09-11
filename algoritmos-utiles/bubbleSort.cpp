#include <iostream>
#include <vector>
using namespace std;

// consiste en comparar cada elemento con el siguiente, y se intercambia si
// están en el orden equivocado. Es necesario revisar toda la lista varias veces

vector<vector<int>> bubbleSort(vector<int> lista){
  for(int i=0; i<lista.size(); i++){      // o(n²)
    burbujeo(lista,i);
  }
  return lista;
}

void burbujeo(vector<int> &lista, int i){
  for(int j=lista.size()-1; j>i; j--){      // o(n)
    if (lista[j] < lista[j-1]){           // orden cosntante
      swap(lista, j, j-1);
    }
  }
}

void swap(vector<int> &lista, int i, int j){      // orden constante
  int k=lista[i];
  lista[i] = lista[j];
  lista[j] = k;
}
