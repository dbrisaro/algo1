#include <iostream>
#include <vector>
using namespace std;

int indicePrimeraAparicion(vector<int>& v, int elem){
  int res = -1;
  for(int i = 0; i < v.size(); i++){
    if(v[i] == elem){
      res = i;
    }
  }
  return res;
}

// tiene que estar! sino devuelve -1

int main(){
  int numero = 1;
  vector <int> v = {10, 6, 7, 9, 1, 2, 1};
  int indice = indicePrimeraAparicion(v, numero);

  cout << "el indice de primera aparicion del " << numero << " es " << indice << endl;

  return 0;
}
