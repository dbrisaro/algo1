/******************************************************************************

Ejercicio 03 Labo 01
AED1
Dani Risaro

*******************************************************************************/
# include <iostream>
using namespace std;

int f(int x, int y){
    int res=0;
    
    if(x>y){
        res = x+y;
    }
    else{
        res = x*y;
    }
    
    return res;
}

int main () {
    int a = -10; 
    int b = -1;
    
    int c = f(a,b);
    
    cout << " El resultado es : " << c << endl;
    return 0;
}


