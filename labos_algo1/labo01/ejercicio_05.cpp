/******************************************************************************

Ejercicio 05 Labo 01
AED1
Dani Risaro 

*******************************************************************************/
#include <iostream>
using namespace std;

int Fibonacci(int n){

    int fn = 0;
    
    if(n==0 || n==1){
        fn = n; 
    } 
    else{
        fn = Fibonacci(n-1) + Fibonacci(n-2);
    }
    return fn;
}

int FibonacciIterativo(int n){
    int fAnteriorAnterior = 0;
    int fAnterior = 0;
    int f = 1;
    
    for(int i=1;i<n;i=i+1){
        
        fAnteriorAnterior = fAnterior;
        
        fAnterior = f;
            
        f = fAnteriorAnterior + fAnterior;
    }
    
    return f;
}

int main(){
    int m = 4;
    int fibo = 0;
    
    fibo = Fibonacci(m);
    
    cout << "Fibo recursivo en posición " << m << " nos da " << fibo << endl;
    
    fibo = FibonacciIterativo(m);
    
    cout << "Fibo iterativo en posición " << m << " nos da " << fibo << endl;
        
    return 0;
}


