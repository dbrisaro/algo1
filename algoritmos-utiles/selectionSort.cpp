#include <iostream>
#include <vector>
using namespace std;

// consiste en in seleccionando los elementos de la lista de a uno en orden
// creciente, ubicando el mínimo en la primera posicion y asi sucesivamente

vector<vector<int>> selectionSort(vector<int> lista){
  for(int i=0; i<lista.size(); i++){      // o(n²)
    seleccionarMinimo(lista,i);
  }
  return lista;
}

void seleccionarMinimo(vector<int> &lista, int i){
  int posMinimo = i;
  for (int j=i; j<lista.size(); j++){           // orden n
    if (lista[posMinimo] > lista[j]){           // orden cosntante
      posMinimo = j;
    }
  }
  swap(lista, i, posMinimo);
}

void swap(vector<int> &lista, int i, int j){      // orden constante
  int k=lista[i];
  lista[i] = lista[j];
  lista[j] = k;
}
