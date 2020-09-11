#include <iostream>
#include <vector>
using namespace std;

// Ejercicio 2

// pair<int, int>  p;   par ordenadp, p.first es la primera coordenada
// make_pair(a,b) -> crea un par ordenado
// i0, j0, coordenadas donde vamos a calcular la vecindad
// Pre: 0 <= i0 < F && 0 <= j0 < C

vector<pair<int, int>> vecinos(int F, int C, int i0, int j0){
  vector<pair<int, int>> res;
  for (int i=max(i0-1,0); i<min(i0+2,F); i++) {
    for (int j=max(j0-1,0); j<min(j0+2,C); j++) {
      if (i!=i0 || j!=j0){
        res.push_back(make_pair(i,j));
      }
    }
  }
  return res;
}


// quiero encontrar algun valle yendo por valores descendientes
// entonces busco los vecinos menores a un cierto numero

vector<pair<int, int>> vecinosMenores(<vector<vector<int>> m, int i0, int j0){
  vector<pair<int, int>> res;
  for (int i=max(i0-1, 0); i<min(i0+2, m.size()); i++) {
    for (int j=max(j0-1, 0); j<min(j0+2, m[0].size()); j++) {
      if ((i!=i0 || j!=j0) && m[i][j] < m[i0][j0]){
        res.push_back(make_pair(i,j));
      }
    }
  }
  return res;
}

pair<int, int> encontrarValle(<vector<vector<int>> m, int i0, int j0){
  pair<int, int> res = make_pair(i0,j0);    // puede que el casillero inicial ya sea un valle
  vector<pair<int, int>> V = vecinosMenores(m, i0, j0);
  while(V.size() > 0) {
    res = V[0];
    V = vecinosMenores(m, res.first, res.second);
  }
  return res;
}     // O ()

// ahora queremos encontrar el valle mas bajo al que se puede llegar desde un punto inicial
// vamos a considerar un casillero inicial y luego una lista de pendientes, de vecinos cercanos

pair<int, int> encontrarValleMinimoRec(<vector<vector<int>> m, int i0, int j0){
  pair<int, int> res = make_pair(i0,j0);    // puede que el casillero inicial ya sea un valle
  vector<pair<int, int>> V = vecinosMenores(m, i0, j0);  // vecinos menores del casillero donde arranque
  for (int i=0; i<V.size(); i++){
    pair<int, int> p = encontrarValleMinimoRec(m, V[i].first, V[i].second);
    if (m[p.first][p.second] < m[res.first][res.second]) {
      res = p;
    }
  }
  return res;
}

pair<int, int> encontrarValleMinimoIt(<vector<vector<int>> m, int i0, int j0){
  pair<int, int> res = make_pair(i0,j0);    // puede que el casillero inicial ya sea un valle
  vector<pair<int, int>> alcanzables;
  alcanzables.push_back(make_pair(i0,j0));
  int proximo = 0;

  while(proximo < alcanzables.size()){
    pair<int, int> p = alcanzables[proximo];
    vector<pair<int,int>> V = vecinosMenores(m, p.first, p.second);
    for (int i=0; i<V.size(); i++){
      if (! pertenece(alcanzables, V[i])) {
        alcanzables.push_back(V[i]);
        if (esValle(m,V[i].first,V[i].second) && m[V[i].first][V[i].second] < m[res.first][res.second]) {
          res = V[i];
        }
      }
    }
    proximo++;
  }
  return res;
}

// O(n^2*m^2)

vector<pair<int,int>> vecionsMenoresCircular(vector<vector<int>> m, int i0, int j0){
  vector<pair<int, int>> res;
  for (int i=i0-1; i<i0+2; i++) {
    for (int j=j0-1; j<j0+2; j++) {
      int im = (i+m.size()) % m.size(), jm = (j+m[0].size()) % m[0].size();
      if ((im != 0 || jm != 0) && m[im][jm] < m[i0][j0] && ! pertenece(res, make_pair(im,jm))) {
        res.push_back(make_pair(im,jm));
      }
    }
  }
  return res;
}

// Ejercicio 3 la matriz tiene filas batidas, o no?

bool sonFilasBatidas(vector<vector<int>> m){
  bool res = true;
  ordenar(m[0]);
  int i = 1;
  while (res && i < M.size()) {
    ordenar(M[i]);
    res = res && M[i] == M[0];
    i = i+1;
  }
  return res;
}
