#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotacion(vector<vector <int>> m, int f, int c){
  vector<vector <int>> res = m;       // copio la matriz m

  for(int i=0; i<m.size(); i++){      // m.size = cantidad de filas
    for(int j=0; j<m[0].size; j++){   //m[0].size = cantidad de columnas

      res[i][j] = m[(i+f) % m.size()][(j+c) % m[0].size()];

    }
  }

  return res;
}
