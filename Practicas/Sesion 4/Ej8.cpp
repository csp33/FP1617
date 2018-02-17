/* Programa que calcula si un año es bisiesto*/
#include <iostream>
using namespace std;
int main () {
	int anio; //Variable de entrada
	cout<<"Introduzca el anio:\n";
	cin>>anio;
	if ((((anio%4)==0)&&((anio%100)!=0))||((anio%400)==0))
			cout<<"El anio "<<anio<<" es bisiesto.";
		else
			cout<<"El anio "<<anio<<" no es bisiesto.";
}
