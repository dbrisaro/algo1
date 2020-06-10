/******************************************************************************

Ejercicio 08 Labo 01
AED1
Dani Risaro

*******************************************************************************/
#include <iostream>
using namespace std;

int Combinatorio(int n, int k){
    int Cm = 0;
    
    if(n==k || k==0){
        Cm = 1;
    }
    else{
        Cm = Combinatorio(n-1, k) + Combinatorio(n-1, k-1);
        
    }
    
    return Cm;

}

int CombinatorioIterativo(int n, int k){
    int Cm = 1;
    
    for(int i=0; i<k; i=i+1){
        
        Cm = Cm * (n-i)/(i+1);
        
    }
    
    return Cm;
    
}

int main(){
    int m = 4;
    int h = 2;
    int C;
    
    C = Combinatorio(m,h);
    
    cout << "El combinatorio recursivo de " << m << " con " << h << " es "<< C << endl;
    
    C = CombinatorioIterativo(m,h);
    
    cout << "El combinatorio iterativo de " << m << " con " << h << " es "<< C << endl;    

    return 0;
}
