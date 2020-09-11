// escribir un programa que ordene una lista sabiendo que
// la distancia entre el menor y el mayor valor nunca supera los 1000

// insertion sort -  selection sort - bubble sort ---> o(n²)

// counting sort ---> o(n)

// tenemos una cota de que a lo sumo va a haber
// 1000 elementos ---> tendremos una complejidad o(1000) + o(n) =


#include <iostream>
#include <vector>
using namespace std;

// consiste en contar la cantidad de apariciones de cada elemento, luego se rearma
// la lista original.
// todos los elementos tienen que estar acotados. asi se puede generar el
// vector de conteo

vector<int> reconstruir(vector<int> &lista, vector<int> conteo, int minimo){
  int indice_conteo = 0;
  for(int i=0; i<lista.size(); i++){
    // ignoro los valores nulos
    while(conteo[indice_conteo]==0){
      indice_conteo++;
    }         // primer elemento no nulo

    lista[i] = indice_conteo + minimo;
    conteo[indice_conteo]--;
  }
}

vector<int> contar(vector<int> &lista, int minimo){
  // creo un vector inicializado en 0
  // cuya longitud sea igual a una cota maxima
  vector<int> conteo(1000+1,0);           // el tamanio de la cota debe ser dado.
  for (int i=0; i<lista.size(); i++){
    conteo[lista[i]-minimo]++;
  }
  return conteo;
}

int minimo(vector<int> &lista){
  int min  = lista[0];
  for (int i=1; i<lista.size(); i++){
    if (min > lista[i]){
      min = lista[i];
    }
  }
  return min
}

vector<vector<int>> countingSort(vector<int> &lista){
  if (lista.size()==0){
    return lista;
  }
  int minimo = minimo(lista);
  vector<int> conteo = contar(lista);
  return reconstruir(lista, conteo);
}
