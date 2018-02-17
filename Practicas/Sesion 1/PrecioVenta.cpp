/* 
Programa que calcula el PVP de un artículo con una ganancia del 20% y un IVA del 18%
*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std; 
   const float IVA=18;      //Declaramos el IVA y la ganancia como constantes para facilitar su edición en caso de ser necesaria.
   const float ganancia=20; 
int main(){                    // Programa Principal
   float Pinicio,Pganancia,Pfin;  //Declaramos las variables de precio de compra, precio con ganancia y precio final
   cout <<"Este programa calcula el PVP de un producto con una ganancia del "<<ganancia<<"% \ny un IVA del "
	<<IVA<<"%.\nIntroduzca el precio de compra, por favor:\n"; //Damos la bienvenida al programa, informamos del IVA y la ganancia aplicados y solicitamos el precio inicial.
	cin >>Pinicio;                                            
	Pganancia= Pinicio*(1+ganancia/100); //Aplicamos la ganancia
	Pfin=Pganancia*(1+IVA/100);    //Aplicamos el IVA al precio con la ganancia incluida
	cout<<"\nEl precio de venta al publico es de " << Pfin <<" euros \n\n"; //Mostramos el resultado en pantalla
   system("pause");
}
 
