/* Programa que muestra los dígitos de un número de tres cifras separados por espacios*/
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	long long int numero;  									//Dato de entrada al programa
	long long int aux1,aux2;								//Variables para los cálculos
	long double cifras=0;									//Double para no tener problemas con pow
	long long int orden;									//Tpo double ara que no haya problemas al hacer el pow
	short digito; 											//Variable de salida 
	string cadena=" ";										//Cadena con un espacio en blanco para separar los dígitos.
	string rango="El rango permitido por su procesador es [-2^63+1,+2^63-1]\n";	//Rango correspondiente a long long int en un procesador x64
	const int QUITAR_UNA_CIFRA=10,CERO=0,BASE_DIEZ=10;		//QUITAR_UNA_CIFRA y BASE_DIEZ tienen el mismo valor, pero se usan en distintas partes con distintos fines.
	
	cout<<"Introduzca el numero:\n"<<rango;						//Lectura del dato
	cin>>numero;
	aux1=numero;											//Backups de la variable de entrada para poder mostrar la E/S en la solución
	aux2=numero;
	do{														//Con este bucle calculamos el número de cifras. 
		aux1=aux1/QUITAR_UNA_CIFRA;
		cifras++;
	}
	while(aux1!=CERO);
	
	cout<<"Las cifras separadas del numero "<<numero<<" serian:\n";
	
	do{													//Con este otro bucle, vamos mostrando dígito a dígito el número. 
		cifras--;
		orden=pow(BASE_DIEZ,cifras);
		digito=aux2/orden;
		aux2=abs(aux2%orden);				//Valor absoluto para que solo salga con el signo - la primera cifra si introducimos un número negativo .
		cout<<digito<<cadena;
	}
	while(aux2!=CERO);
}

