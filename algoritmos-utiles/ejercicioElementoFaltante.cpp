// se tiene una secuencia ordenada donde falta un elemento y hay que encontrarlo
// en o(log n) ---> busqueda binaria

#include <iostream>
#include <vector>
using namespace std;

// si hay un elemento faltante, hago una busqueda binaria
int busquedaBinaria(vector<int> &sec){
  int desde = 0, hasta = sec.size();
  while (desde < hasta){
    int mitad = (desde + hasta)/2;
    if (sec[mitad] == mitad){
      desde = mitad + 1;
    } else {
      hasta = mitad;
    }
  }
  return desde;
}

// si hay mas de un elemento faltante necesitamos un programa que devuelva todos
// no es necesario que sea log (n). otra cosa: los que faltan no es ni el primero ni el ultimo

vector<int> dameFaltantes(vector<int> &sec){
  vector<int> faltantes;
  int actual = 0;
  for (int i=0; i<sec.size(); i++){
    if (sec[i] != actual){
      while (actual < sec[i]){
        faltantes.push_back(actual);
        actual ++;
      }
    }
    actual ++;
  }
  return faltantes;
}

// ahora queremos devolver el k-esimo elemento faltante.

vector<int> dameFaltantesK(vector<int> &sec, int k){
  vector<int> faltantes;

  if (k==0){
    return faltantes
  }

  int actual = 0;
  for (int i=0; i<sec.size(); i++){
    if (sec[i] != actual){
      while (actual < sec[i]){
        faltantes.push_back(actual);
        actual ++;
        k --;
        if (k==0){
          return faltantes;
        }
      }
    }
    actual ++;
  }
  return faltantes;
}

// y ahora le queremos bajar la complejidad
// hay m < n elementos faltantes, entonces devolver los faltantes
// en complejidad O (m log(n)) ---> M veces una busqueda binaria




int main() {

    vector<int> v = {0,1,2,4,6,7,8,9};
    vector<int> faltantes;

    faltantes = dameFaltantes(v);

    for (int x : faltantes)
        cout << x << " ";

    return 0;
}
