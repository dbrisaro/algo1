/******************************************************************************

Ejercicio 03 Labo 02
AED1
Dani Risaro

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    float nota = 0;
    
    int i = 0; // cantidad de alumnos
    
    int aprobados = 0;
    
    int desaprobados = 0;
    
    float centinela = 0;
    
    while(centinela != -1){
        
        cout << "Ingrese la nota (-1 para terminar): "  << endl;
        
        cin >> nota;
        
        if(nota>=6){
            
            aprobados = aprobados + 1;
        }
        if(nota>=0 and nota<6){
            
            desaprobados = desaprobados + 1;
        }
        if(nota!=-1 and nota<0){
            cout << "La nota no está entre 0 y 10!" << endl;
            break;
        }        
        
        i = i+1;

        centinela = nota;
        
    }
    
    float numeroTotal = i;
    
    if (numeroTotal>=6){
        
        cout << "Cantidad de aprobados " << aprobados << " de " << i << endl;
        cout << "Cantidad de desaprobados " << desaprobados << " de " << i << endl;
    
        float porcentajeAprobados = aprobados/numeroTotal;
        float dosTercios = 2.0/3.0;


        cout << "Porcentaje de aprobados " << porcentajeAprobados << ". Dos tercios " << dosTercios << endl;

        if(porcentajeAprobados > dosTercios){
            cout << "Se puede incrementar el cupo del curso" << endl;
        }
        
    }
    else{
        
        cout << "El total de alumnos es menor a 6!" << endl;
    }
        
    
    return 0;
}



