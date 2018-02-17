/*Programa que calcula las secuencias de un numero >=1*/
#include <iostream>
using namespace std;
int pideNumero(){
	const int UNO=1;
	int numero;
	do{
		cout<<"Introduzca un numero:\n";
		cin>>numero;
	}while(numero<UNO);
	return numero;
}
void escribeTerminos(int inicio ,int tope,int numero){
	int termino;
	string igual=" = ";
	string espacio=" ";
	cout<<numero<<igual;
	for(termino=inicio;termino<tope;termino++) {
		cout<<termino<<espacio;
	}
	cout<<endl;
}
int pruebaSecuencia(int &suma, int &tope, int numero){
	for(tope;suma<numero;tope++) {	
		suma+=tope;			
	}
}
int main(){

	int numero;								//Variable de entrada
	int suma=0,inicio_secuencia,tope;
	string cadena="Las secuencias posibles son:\n";
	string cadena_secuencias="Numero de secuencias: ";
	int termino,numero_secuencias=0;		//Variables de salida
	const int COMIENZA=1,NULO=0;
	
	numero=pideNumero(); 
	for(inicio_secuencia=COMIENZA;inicio_secuencia<numero;inicio_secuencia++) {	
		tope=inicio_secuencia;
		pruebaSecuencia(suma,tope,numero);
		if(suma==numero) {					//La secuencia es válida
			numero_secuencias++;
			escribeTerminos(inicio_secuencia,tope,numero);
		}
		suma=NULO;						//Reinicializo la suma para probar la secuencia que comienza por el siguiente número.
	}
	if(numero_secuencias==NULO)
		cout<<"El numero "<<numero<<" no es secuenciable (es una potencia de 2)";
	else
		cout<<cadena_secuencias<<numero_secuencias;
}
