#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


//Ejercicio
bool divide(vector<int> v, int a){
	// Dados un vector v y un int a, decide si a divide a todos los numeros de v.
	
	int contador = 0;
	int valor = 0;
	
	for(int i=0; i<v.size(); i=i+1){
	    
	    valor = v[i];
	    
	    if(valor%a == 0){
	        
	        contador = contador + 1;
	        
	    }
	    
	}
	
	if (contador == v.size()){
	    return true;
	}
	else
	    return false;
	
}

//Ejercicio
int mayor(vector<int> v){
	// Dado un vector v, devuelve el valor maximo encontrado.
	
	int vaux = 0;
	vaux = v[0];
	
	for(int i=0; i<v.size(); i=i+1){
	    int valor = 0;
	    valor = v[i];
	    
	    if(valor>vaux){
	        
	        vaux = valor;
	    }
	}
	
	return vaux;
	
}

//Ejercicio
vector<int> reverso(vector<int> v){
	// Dado un vector v, devuelve el reverso.
	
	vector<int> rever;

	for(int i=0; i<v.size(); i=i+1){

        int size = 0;
        size = v.size();
        int m = size - i;
        
        rever[i] = v[m];
	    
	}
	
	return rever;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k){
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].
}

//Ejercicio
vector<int> factoresPrimos(int n){
	//que dado un entero devuelve un vector con los factores primos del mismo
}

//Ejercicio
void mostrarVector(vector<int> v){
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
}
