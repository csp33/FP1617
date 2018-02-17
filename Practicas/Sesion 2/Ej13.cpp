/* Programa que muestra los dígitos de un número de tres cifras separados por espacios*/
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int numero;  //Dato de entrada al programa
	int centenas,decenas,unidades,aux; //Datos de salida y auxiliar para facilitar los cálculos
	cout<<"Introduzca el numero:\n";
	cin>>numero;
	centenas=numero/100; //Nos quedamos con la primera cifra.
	aux=numero%100;      //Nos quedamos con las dos últimas cifras.
	decenas=aux/10;      //Dividimos las dos últimas cifras de la variable auxiliar
	unidades=aux%10;	 //en decenas y unidades.
	cout<<"El numero "<<numero<<" con sus cifras separadas seria: "<<centenas<<" "<<decenas<<" "<<unidades<<".";	//Mostramos el resultado en pantalla
}
