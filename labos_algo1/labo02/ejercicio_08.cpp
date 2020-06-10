/******************************************************************************

Ejercicio 08 Labo 02
AED1 
Dani Risaro 

*******************************************************************************/
#include <iostream>

void collatzIterativo(int n, int &cantidad de pasos){
    
    cantidadPasos = cantidadPasos + 1;
    
    while (n!=1){
        if(n%2 == 0){
            n = n/2;
        }
        
        else{
            n = 3*n + 1;
        }
    }
    
    return;
}

void collatzRecursivo(int n, int &cantidad de pasos){
    cantidadPasos = cantidadPasos + 1;
    
    if(n==1){
        return;
    }
    if(n%2 == 0){
        collatzRecursivo((n/2), cantidadPasos);
    }
    else{
        collatzRecursivo((3*n) + 1, cantidadPasos);
    }

}

int main(){
    
    int n = 0;
    int cantidadPasos = 0;
    
    n = 20
    
    
    
    
    printf("Hello World");

    return 0;
}
