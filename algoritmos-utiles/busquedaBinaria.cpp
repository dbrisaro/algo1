#include <iostream>
#include <vector>
using namespace std;

bool busquedaBinaria(vector<int> lista, int desde, int hasta, int x){
  bool res = false;
  while (desde <= hasta){
    int medio = desde + (hasta-desde)/2;
    if (lista[medio] == x){
      res = true; //encontre el elemento
    }
    if (lista[medio] < x){
      desde = medio + 1; //esta en la mitad derecha
    }
    else{
      hasta = medio - 1; //esta en la mitad izquierda
    }
  }
  return res;
}

// importante! el vector tiene que estar ordenado.

int main() {
  vector<int> v = {3, 4, 5, 6, 7, 7, 20, 22};
  int numero = 5;
  int desde = 0;
  int hasta = v.size();

  if(busquedaBinaria(v, desde, hasta, numero)){
    cout << numero << " está en la lista" << endl;
  }
  else{
    cout << numero << " no está en la lista" << endl;
  }

  return 0;
}
