/******************************************************************************

Ejercicio 02 Labo 01
AED1
Dani Risaro

*******************************************************************************/
# include <iostream>
using namespace std;

int f(int x, int y){
    return (x + y);
}
int main () {
    int a = 10; 
    int b = -21;
    
    int suma = f(a,b);
    
    cout << " El resultado es : " << suma << endl;
    return 0;
}



