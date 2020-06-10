/******************************************************************************

Ejercicios Labo 03
AED1 
Dani Risaro 


*******************************************************************************/
#include "generador.h"
#include "vectores.h"

using namespace std;

int main() {
    // funcion para generar automaticamente los archivos numericos
    // generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    holaModuloVectores(); // función definida en vectores.cpp
    
    // Pruebo ej 1
    vector<int> vector_uno(4);
    int a = 2;
    bool uno = false;
    uno = divide(vector_uno, a);
    
    cout << uno << endl; 
    
    // Pruebo ej 2
    int dos = 0;
    vector_uno[3] = 10;
    dos = mayor(vector_uno);
    
    cout << dos << endl; 
    
    // Pruebo ej 3

    vector<int> vector_tres_reverso(0);
    
    vector_tres_reverso = reverso(vector_uno);
    
    for (int i=0; i<vector_tres_reverso.size(); i=i+1){
		cout << vector_tres_reverso[i];
	}
	cout << endl;
    

    return 0;
}
