/******************************************************************************

Ejercicio 04 Labo 01
AED1
Dani Risaro

*******************************************************************************/
#include <iostream>
#include <math.h>   
using namespace std;

bool esPrimo(int n){
    
    int divisor = 0;
    
    for(int i=2; i<sqrt(n); i=i+1){
        
        if (n%i == 0){
            divisor = divisor + 1;
        }
        
        else{
            
        }
    }
    
    if (divisor==0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
    cout << "Ingrese un numero n: " << endl;
    int a = 0;
    cin >> a;
    
    bool Primo = esPrimo(a);

    cout << "El numero " << a;

    if(Primo){
        cout << " es primo" << endl;
    }
    else{
        cout << " no es primo" << endl;
    }
    
    return 0;
}



