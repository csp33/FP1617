/*Programa que calcula la sumatoria de los factoriales sucesivos de un numero*/
#include <iostream>
using namespace std;

long long int calculaFactorialConsecutivo(int numero_introducido){
	long long int cont,aux=0,factorial=1;
	for(cont=1;cont<=numero_introducido;cont++){
		factorial=factorial*cont;
		aux=aux+factorial;
		}
	return aux;
}
int leeIntRango(){
	const int COTA_SUPERIOR=20,COTA_INFERIOR=1;
	int numero;
	do{
		cout<<"Introduzca un numero entre 1 y 20:\n";
		cin>>numero;
	}while(numero<COTA_INFERIOR||numero>COTA_SUPERIOR);
	return numero;
}
int main() {
	int numero;
	string cadena="El valor de la sumatoria de los factoriales consecutivos es ";
	
	numero=leeIntRango();

	cout<<cadena<<calculaFactorialConsecutivo(numero);
	
}
