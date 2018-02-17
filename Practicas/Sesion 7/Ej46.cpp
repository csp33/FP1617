/*Programa que calcula la sumatoria de los factoriales sucesivos de un numero*/
#include <iostream>
using namespace std;
long long int calculaFactorial(int numero_introducido){
	long long int contador,factorial=1;
	for(contador=1;contador<=numero_introducido;contador++)
		factorial=contador*factorial;
	return factorial;
}
long long int calculaFactorialConsecutivo(int numero_introducido){
	long long int cont,aux=0;
	for(cont=1;cont<=numero_introducido;cont++)
		aux=aux+calculaFactorial(cont);
	return aux;
}
int pideNumero(){
	const int NULO=0;
	int numero;
	do{
		cout<<"Introduzca un numero positivo:\n";
		cin>>numero;
	}while(numero<NULO);
	return numero;
}
int main() {
	int numero;
	const int NULO=0,UNO=1;
	string cadena="El valor de la sumatoria de los factoriales consecutivos es ";
	
	numero=pideNumero();
	if(numero==NULO)
		cout<<cadena<<UNO;
	else 
	cout<<cadena<<calculaFactorialConsecutivo(numero);
	
}
