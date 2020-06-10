/******************************************************************************

Ejercicio 04 Labo 02
AED1
Dani Risaro 

*******************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int
esBinario (int n)
{
  int divi = 0;

  while (n != 0)
    {

      divi = n % 10;

      if (divi > 1)

	return 0;

      n = n / 10;

    }
  return 1;
}



int main (){
  int n = 0;
  
  cout << "Ingrese un numero binario" << endl;
  
  cin >> n;
  
  int v = 0;
  int n_decimal = 0;
  
  v = esBinario(n);

  if (v==1){
      int i = 0;
      int r = 0;
      
      while (n!=0){
          
          r = n % 10;
          n = n / 10;

          
          n_decimal = n_decimal + r * pow(2, i);
          
          i = i+1;
      
      }    
      
      cout << "El equivalente decimal es " << n_decimal << endl;
   }

   else{
       
       cout << "El numero " << n << " no es binario" << endl;
    }
    
  return 0;
}
