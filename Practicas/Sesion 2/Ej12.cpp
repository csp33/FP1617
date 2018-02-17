/*Programa que calcula la poblaci�n final tras tres a�os a partir de estad�sticos de mortalidad, natalidad y migraci�n*/
#include <iostream>
using namespace std;
int main () {
	unsigned long long int poblacion_inicial;									                         //Declarada como long long int por ser una cantidad considerable y como unsigned por ser siempre positiva.
	double tasa_natalidad,tasa_mortalidad,tasa_migracion; 			                              //Declaradas como "double" porque en ning�n caso ser�n superiores a 1000 y para que la divisi�n de entero/real de real.
	unsigned long long int poblacion_final_ano1,poblacion_final_ano2,poblacion_final_ano3;   //Variables auxiliares y final.
	
	
	/*****INTRODUCCI�N DE LAS VARIABLES POR TECLADO*****/
	cout<<"Introduzca la poblacion inicial:\n";  //
	cin>>poblacion_inicial;
	cout<<"Introduzca la tasa de natalidad:\n";
	cin>>tasa_natalidad;
	cout<<"Introduzca la tasa de mortalidad:\n";
	cin>>tasa_mortalidad;
	cout<<"Introduzca la tasa de migracion:\n";
	cin>>tasa_migracion;
	/*************************************************/
	
	/***********C�LCULOS***********/
	poblacion_final_ano1=poblacion_inicial*(1+tasa_natalidad/1000-tasa_mortalidad/1000+tasa_migracion/1000);  		   												 	  //Estad�stica del primer a�o.
	poblacion_final_ano2=poblacion_final_ano1*(1+tasa_natalidad/1000-tasa_mortalidad/1000+tasa_migracion/1000);															    //Estad�stica del segundo a�o.
	poblacion_final_ano3=poblacion_final_ano2*(1+tasa_natalidad/1000-tasa_mortalidad/1000+tasa_migracion/1000);  														   //Estad�stica del tercer a�o.
	/****************************/

	cout<<"La poblacion, tras tres a�os sera de "<<poblacion_final_ano3<<" habitantes."; 																								 //Muestro el resultado en pantalla.

	
}
