/******************************************************************************

Ejercicio 06 Labo 01
AED1
Dani Risaro

*******************************************************************************/
#include <iostream>
using namespace std;

int esImpar(int n){

    int divisor = 2;
    int g = 0;
    
    if (n%divisor == 0){
        return g = 1;
    }
    else{
        return g = 0;
    }
}


int SumaImpar(int n){

    int Sn = 0;
    
    if(n==1){
        Sn = n-1; 
    }
    else{
        
        Sn = SumaImpar(n-1) + esImpar(n)*(n-1);

    }
    return Sn;
}

int SumaImparIterativa(int n){
    
    int Sn = 0;
    
    for(int i=n-1; i>0; i=i-1){
        
        if(esImpar(i)==0){
            
            Sn = i + Sn;
        }
        else{
            
        }
    }
    
    return Sn;
}

int main(){
    
    int a = 10;
    int s = 0;
    
    s = SumaImpar(a);
    
    cout << "la suma recursiva de los impares menores a " << a << " es " << s << endl;
    
    s = SumaImparIterativa(a);
    
    cout << "la suma iterativa de los impares menores a " << a << " es " << s << endl;    
    
    return 0;
    
}



