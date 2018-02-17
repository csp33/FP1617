/* Programa que incrementa el sueldo base en un 2% y un 3%*/
#include <iostream>
using namespace std;
int main () {
double salario_base;  									   //Variable de entrada.
double salario_aumento1, salario_aumento2; 				  //Variable de salida.
const float AUMENTO_1=2, AUMENTO_2=3; 					 //Declaramos los aumentos como constantes por si deben modificarse posteriormente.El tipo es float para no tener problemas con la división.
cout << "Introduzca el salario base\n";
cin >> salario_base;

/**************************CÁLCULOS**********************************************/
salario_aumento1=salario_base*(1+AUMENTO_1/100);     //Realizamos el primer incremento.
salario_aumento2=salario_aumento1*(1+AUMENTO_2/100); //Realizamos el incremento final.
/********************************************************************************/

cout << "En salario final es de "<<salario_aumento1<<" euros (con una subida del "<<AUMENTO_1<<"%)\n y de "<<salario_aumento2<<  //Mostramos el resultado en pantalla.
" euros si aplicamos otra subida del "<<AUMENTO_2<<"%.";	
}
