/* 
Programa que calcula el PVP de un art�culo con una ganancia del 20% y un IVA del 18%
*/

#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath>      // Inclusi�n de los recursos matem�ticos

using namespace std; 
 
int main(){                    // Programa Principal
   int v1=1,v2=2,v3=3,v4=4,aux;
   aux=v2;
   v2=v1;
   v1=v4;
   v4=v3;
   v3=aux;
   cout <<v1<<v2<<v3<<v4; 
   system("pause");
}
 
