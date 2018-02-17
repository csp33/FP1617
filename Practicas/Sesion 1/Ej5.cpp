/*Programa que calcula el capital final a partir del inicial y el interés*/
#include <iostream>
using namespace std;
int main () {
	double capital_inicial, interes;  //Datos de entrada
	double capital_final; 				//Dato de salida
	cout <<"Introduzca el capital a depositar:\n";
	cin >>capital_inicial;
	cout <<"Introduzca el porcentaje de interes a aplicar:\n";
	cin >>interes;
	capital_final=capital_inicial*(1+interes/100);  //Aplicamos el interés.
	cout <<"Tras depositar "<<capital_inicial<<" euros, el capital final sera de "<<capital_final<<
	" euros con un interes del "<<interes<<"%.\n";
}
