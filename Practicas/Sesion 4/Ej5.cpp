/*Programa que sube una nómina en función de los casos resueltos*/
#include <iostream>
using namespace std;
int main () {
	float salario_hora,satisfaccion; //Variables de entrada
	int num_horas,casos_resueltos;
	float salario_final;             //Variable de salida
	const float AUMENTO_CASOS=4;					//Porcentajes de aumento 
	/**********INTRODUCCION DE DATOS*****************/
	cout<<"Introduzca el salario por hora:\n";
	cin>>salario_hora;
	cout<<"Introduzca el numero de horas trabajadas:\n";
	cin>>num_horas;
	cout<<"Introduzca el numero de casos resueltos:\n";
	cin>>casos_resueltos;
	cout<<"Introduzca el grado medio de satisfaccion:\n";
	cin>>satisfaccion;
	/************************************************/
	salario_final=salario_hora*num_horas; //Cálculo del salario sin aumentar
	
	if (casos_resueltos>30)
		salario_final=salario_final*(1+AUMENTO_CASOS/100);
	cout<<"El salario final sera de "<<salario_final<<" euros.";
}
