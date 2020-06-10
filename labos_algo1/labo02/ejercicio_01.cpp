/******************************************************************************

Ejercicio 01 Labo 02 
AED1
Dani Risaro 

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    float nota=0;
    
    float suma = 0;
    
    float promedio = 0;
    
    int i = 1;
    
    while(i<11){

        cout << "Ingrese la nota numero " << i << ": " << endl;
        
        cin >> nota;
        
        if(nota>=0 and nota<=10){
        
            suma = suma + nota;
            
            promedio = suma/i;
            
            i = i+1;
        
        }
        else{
            
            cout << "La nota no está entre 0 y 10!" << endl;
            
            break;

        }
    }
    
    cout << "La suma de las notas es: " << suma << endl;
    cout << "El promedio de las notas es: " << promedio << endl;
    
    return 0;
}
