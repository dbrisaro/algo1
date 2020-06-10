/******************************************************************************

Ejercicio 06 Labo 02
AED1
Dani Risaro

*******************************************************************************/
#include <iostream>
using namespace std; 

int triplicarPorValor(int n){
    
    int m = 0;
    
    m = 3*n;
    
    return m; 
}

int triplicarPorReferencia(int &n){
    
    n = n + n;
}



int main(){
    
    int cuenta = 50;
    
    int cuenta_valor = cuenta;
    
    cuenta_valor = triplicarPorValor(cuenta_valor);
    
    cout << "Triplica por valor" << cuenta_valor << endl;
    cout << "Triplica por referencia" << triplicarPorReferencia(cuenta) << endl;

    return 0;
}
