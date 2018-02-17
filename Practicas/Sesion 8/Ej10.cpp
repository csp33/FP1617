/*Programa que calcula la población final tras tres años a partir de estadísticos de mortalidad, natalidad y migración*/
#include <iostream>
using namespace std;
int leeIntRango(string valor_pedido){
	const int COTA_INFERIOR=0,COTA_SUPERIOR=1000;
	int tasa;
	do{
		cout<<"Introduzca la tasa de "<<valor_pedido<<":\n";
		cin>>tasa;
	} while(tasa<=COTA_INFERIOR || tasa>=COTA_SUPERIOR);	
	return tasa;	
}
int leePositivo(string valor_pedido){
	const int NULO=0;
	int dato;
	do{
		cout<<"Introduzca "<<valor_pedido<<":\n";
		cin>>dato;
	}while(dato<NULO);
	return dato;
}
long long int calculaPoblacionAnios(long long int poblacion_final,long double tasa_variacion,int anios){
	const int UNO=1;
	int cont;
	for(cont=0;cont<anios;cont++)
		poblacion_final=poblacion_final*(UNO+tasa_variacion);	
	return poblacion_final;														
}
long long int calculaAniosPoblacionDuplicada(long long int poblacion_inicial,long double tasa_variacion){
	int anios_doble;
	const int DOBLE=2,UNO=1;
	long long int poblacion_doble=DOBLE*poblacion_inicial;
	for(anios_doble=0;poblacion_inicial<=poblacion_doble;anios_doble++)
		poblacion_inicial=poblacion_inicial*(UNO+tasa_variacion);
	return anios_doble;
}
int main () {
	unsigned long long int poblacion_inicial;									                         //Declarada como long long int por ser una cantidad considerable y como unsigned por ser siempre positiva.
	double tasa_natalidad,tasa_mortalidad,tasa_migracion; 			                              //Declaradas como "double" porque en ningún caso serán superiores a 1000 y para que la división de entero/real de real.
	unsigned long long int poblacion_final;  													 //Variable de salida y auxiliar para la segunda parte.
	int anios,anios_duplicar;
	string valor_pedido;
	const int DOBLE=2;
	/*****INTRODUCCIÓN DE LAS VARIABLES POR TECLADO*****/ 
	valor_pedido="natalidad";
	tasa_natalidad=leeIntRango(valor_pedido);
	valor_pedido="mortalidad";
	tasa_mortalidad=leeIntRango(valor_pedido);
	valor_pedido="migracion";
	tasa_migracion=leeIntRango(valor_pedido);
	valor_pedido="la poblacion inicial";
	poblacion_inicial=leePositivo(valor_pedido);
	valor_pedido="el numero de anios para mostrar la estadistica";
	anios=leePositivo(valor_pedido);
		

	/*************************************************/
	
	/***********CÁLCULOS***********/
	long double tasa_variacion;
	tasa_variacion=(tasa_natalidad/1000-tasa_mortalidad/1000+tasa_migracion/1000);	
	poblacion_final=calculaPoblacionAnios(poblacion_inicial,tasa_variacion,anios);
	anios_duplicar=calculaAniosPoblacionDuplicada(poblacion_inicial,tasa_variacion);

	/****************************/

	cout<<"La poblacion, tras "<<anios<<" anios sera de "<<poblacion_final<<" habitantes.\n";							 //Muestro el resultado en pantalla.
	cout<<"Para que la poblacion, como minimo, se duplique, tendran que pasar "<<anios_duplicar<<" anios";

	
}
