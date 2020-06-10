/******************************************************************************

Ejercicio 07 Labo 01
AED1
Dani Risaro

*******************************************************************************/
#include <iostream>
#include <cmath> 

using namespace std;

int minDivisor(int n){
    
    int k = 2;
    
    while(k<=n && n%k != 0){

        k = k+1; 

    }
    
    return k; 
} 

int potMinDivisor(int n){
    int j = 0;
    int k = minDivisor(n);
    
    while(n%k==0){
        j = j+1;
        k = k*minDivisor(n);
    }
    
    return j;
    
}

int sumaDivisores(int n){

    int Sn = 0;
    int min = 0;
    int j = 0;
    
    if(n==1){
        Sn = 1; 
    }
    else{
        min = minDivisor(n);
        j = potMinDivisor(n);
        
        Sn = (pow(min, j+1) - 1)/(min -1) + (sumaDivisores(n/pow(min,j)) - 1) + ((pow(min, j+1) - 1)/(min -1) - 1)*(sumaDivisores(n/pow(min,j)) - 1);
    }
    return Sn;
}


int sumaDivisoresIterativa(int n){
    int Sn = 0; 
  
    for (int i=1; i<=n; i=i+1){
        if(n%i==0){
            Sn = Sn + i;
        }
        
    } 

    return Sn; 
} 


int main(){
	int m = 240;
	int S = 0;

	S = sumaDivisores(m);
    cout << "la suma de los divisores recursiva de " << m << " es " << S << endl;
 
	S = sumaDivisoresIterativa(m);
    cout << "la suma de los divisores Iterativa de " << m << " es " << S << endl;

	return 0;
}

