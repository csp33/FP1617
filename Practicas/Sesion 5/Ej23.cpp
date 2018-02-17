/*Programa que calcula la población final tras tres años a partir de estadísticos de mortalidad, natalidad y migración*/
#include <iostream>
using namespace std;
int main () {
	unsigned long long int poblacion_inicial;									                         //Declarada como long long int por ser una cantidad considerable y como unsigned por ser siempre positiva.
	double tasa_natalidad,tasa_mortalidad,tasa_migracion; 			                              //Declaradas como "double" porque en ningún caso serán superiores a 1000 y para que la división de entero/real de real.
	unsigned long long int poblacion_final,poblacion_final_duplicada;  													 //Variable de salida y auxiliar para la segunda parte.
	int cont=0,cont_doble=0;			//Variables contador
	int anios;
	const int DOBLE=2;
	/*****INTRODUCCIÓN DE LAS VARIABLES POR TECLADO*****/ //Se añadens filtro de entrada.
	do{
		cout<<"Introduzca la poblacion inicial:\n";  //
		cin>>poblacion_inicial;
	} while(poblacion_inicial<0);
	do{
		cout<<"Introduzca la tasa de natalidad:\n";
		cin>>tasa_natalidad;
	} while(tasa_natalidad<=0 || tasa_natalidad>=1000);			//!(tasa_natalidad>0 && tasa_natalidad<1000)--> (tasa_natalidad<=0 || tasa_natalidad >=1000) (De Morgan)
	do{
		cout<<"Introduzca la tasa de mortalidad:\n";
		cin>>tasa_mortalidad;
	} while(tasa_mortalidad<=0 || tasa_mortalidad>=1000);
	do{
		cout<<"Introduzca la tasa de migracion:\n";
		cin>>tasa_migracion;
	} while(tasa_migracion<=0 || tasa_migracion>=1000);
	do{
		cout<<"Introduzca el numero de anios para mostrar la estadistica:\n";
		cin>>anios;
	}while(anios<=0);
	

	/*************************************************/
	
	/***********CÁLCULOS***********/
	long double tasa_variacion;
	tasa_variacion=(tasa_natalidad/1000-tasa_mortalidad/1000+tasa_migracion/1000);		//Estos bucles con contadores deberían ser del tipo for, pero no lo hemos dado aún.
	poblacion_final=poblacion_inicial;
	while(cont!=anios){
		poblacion_final=poblacion_final*(1+tasa_variacion);															
		cont=cont++;
	}
	poblacion_final_duplicada=poblacion_inicial;		//Añado otra variable para no variar el resultado final de la primera parte del programa
	do{
			poblacion_final_duplicada=poblacion_final_duplicada*(1+tasa_variacion);	
			cont_doble=cont_doble++;														
	}while(poblacion_final_duplicada<=DOBLE*poblacion_inicial); 
	/****************************/

	cout<<"La poblacion, tras "<<anios<<" anios sera de "<<poblacion_final<<" habitantes.\n";							 //Muestro el resultado en pantalla.
	cout<<"Para que la poblacion, como minimo, se duplique, tendran que pasar "<<cont_doble<<" anios,\nobteniendose una poblacion de "<<poblacion_final_duplicada<<" habitantes.";

	
}
