/*Programa que sube una nómina en función de los casos resueltos y el grado de satisfacción*/
#include <iostream>
using namespace std;
int main () {
	float salario_hora,satisfaccion; //Variables de entrada
	int num_horas,casos_resueltos;
	float salario_final;             //Variable de salida
	const float AUMENTO_CASOS_MAS_30=4,AUMENTO_SATISFACCION=2,AUMENTO_CASOS_20_30=3,SATISFACCION_INCREMENTO=4,CASOS_RESUELTOS_AUMENTO_4=30,CASOS_RESUELTOS_AUMENTO_3=20;					//Constantes de aumentos e intervalos 
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
	
	if (satisfaccion>=SATISFACCION_INCREMENTO)
		salario_final=salario_final*(1+AUMENTO_SATISFACCION/100);
	if (casos_resueltos>CASOS_RESUELTOS_AUMENTO_4)
		salario_final=salario_final*(1+AUMENTO_CASOS_MAS_30/100);
		else if(casos_resueltos>=CASOS_RESUELTOS_AUMENTO_3)
			salario_final=salario_final*(1+AUMENTO_CASOS_20_30/100);


	cout<<"El salario final sera de "<<salario_final<<" euros.";
}
