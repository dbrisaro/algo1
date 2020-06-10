/******************************************************************************

Ejercicio 07 Labo 02
AED1
Dani Risaro

*******************************************************************************/
#include <iostream>
using namespace std;


void swap(int &x, int &y){
    int temp;
    temp = x; 
    x = y;    
    y = temp;
    
    return;
}
   
   
int main(){
    
    int a=10;
    int b=15;
    
    swap(a, b);
    
    cout << "valor de a es " << a << endl;
    cout << "valor de b es " << b << endl;

    return 0;
}