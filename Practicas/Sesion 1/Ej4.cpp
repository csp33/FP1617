/*Programa que incrementa el sueldo en un 2%*/
#include <iostream>
using namespace std;
int main () {
	const float INCREMENTO=2; //Declaro el porcentaje de incremento como constante por si se quisiera modificar en un futuro.
	double salario_inicial;   //Dato de entrada.
	double salario_final; //Dato de salida.
	cout <<"Introduzca el salario base:\n";
	cin >>salario_inicial;
	salario_final=salario_inicial*(1+INCREMENTO/100); //Aplicamos el incremento.
	cout<<"El salario final sera de "<<salario_final<<" euros tras incrementarlo en un "<<INCREMENTO<<"%.";
}
