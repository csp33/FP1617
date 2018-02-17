/* Programa que calcula si un año es bisiesto*/
#include <iostream>
using namespace std;
int main () {
	int anio; //Variable de entrada
	bool bisiesto; //Variable de comprobacion
	string cadena; //Variable de salida
	cout<<"Introduzca el anio:\n";
	cin>>anio;
	bisiesto=(anio%4==0&&anio%100!=0||anio%400==0);
	if (bisiesto==true)
			cadena="El anio es bisiesto.";
		else
			cadena="El anio no es bisiesto.";
	cout<<cadena;
}
