#include <iostream>
#include <vector>
using namespace std;

// consiste en contar la cantidad de apariciones de cada elemento, luego se rearma
// la lista original.
// todos los elementos tienen que estar acotados. asi se puede generar el
// vector de conteo

vector<vector<int>> countingSort(vector<int> &lista){
  vector<int> conteo = contar(lista);
  return reconstruir(lista, conteo);
}

vector<int> contar(vector<int> &lista){
  // creo un vector inicializado en 0
  // cuya longitud sea igual a una cota maxima
  vector<int> conteo(COTA,0);           // el tamanio de la cota debe ser dado.
  for (int i=0; i<lista.size(); i++){
    conteo[lista[i]]++;
  }
}

vector<int> reconstruir(vector<int> &lista, vector<int> conteo){
  int indice_conteo = 0;
  for(int i=0; i<lista.size(); i++){
    // ignoro los valores nulos
    while(conteo[indice_conteo]==0){
      indice_conteo++;
    }         // primer elemento no nulo

    lista[i] = indice_conteo;
    conteo[indice_conteo]--;
  }
}

void swap(vector<int> &lista, int i, int j){      // orden constante
  int k=lista[i];
  lista[i] = lista[j];
  lista[j] = k;
}
