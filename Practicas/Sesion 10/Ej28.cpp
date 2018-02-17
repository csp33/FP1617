/*Programa que calcula la población final tras tres años a partir de estadísticos de mortalidad, natalidad y migración. Se añade una clase*/
#include <iostream>
using namespace std;

const int DOBLE=2,UNO=1,MIL=1000;
const int COTA_INFERIOR=0,COTA_SUPERIOR=1000;

int leeIntRango(string valor_pedido){
	int tasa;
	do{
		cout<<"Introduzca la tasa de "<<valor_pedido<<":\n";
		cin>>tasa;
	} while(tasa<=COTA_INFERIOR || tasa>=COTA_SUPERIOR);	
	return tasa;	
}
int leePositivo(string valor_pedido){
	int dato;
	do{
		cout<<"Introduzca "<<valor_pedido<<":\n";
		cin>>dato;
	}while(dato<COTA_INFERIOR);
	return dato;
}


class Poblacion{
	private:
		long double poblacion_inicial;
		double tasa_natalidad,tasa_mortalidad,tasa_migracion;
	public:
		Poblacion(){
			poblacion_inicial=COTA_INFERIOR;
			tasa_natalidad=COTA_INFERIOR;
			tasa_mortalidad=COTA_INFERIOR;
			tasa_migracion=COTA_INFERIOR;
		}
		Poblacion(double inicial,double natalidad,double mortalidad,double migracion){
			poblacion_inicial=inicial;
			tasa_natalidad=natalidad;
			tasa_mortalidad=mortalidad;
			tasa_migracion=migracion;
		}
		double calculaTasaVariacion(){
			double tasa_var;
			tasa_var=(tasa_natalidad/MIL-tasa_mortalidad/MIL+tasa_migracion/MIL);	
			return tasa_var;
		}
		void setParametros(double inicial,double natalidad,double mortalidad,double migracion){
			poblacion_inicial=inicial;
			tasa_natalidad=natalidad;
			tasa_mortalidad=mortalidad;
			tasa_migracion=migracion;
		}
		long long int calculaAniosPoblacionDuplicada(double tasa_variacion){
			int anios_doble;
			long long int poblacion_doble=DOBLE*poblacion_inicial;
			for(anios_doble=0;poblacion_inicial<=poblacion_doble;anios_doble++)
				poblacion_inicial=poblacion_inicial*(UNO+tasa_variacion);
			return anios_doble;
		}
		long long int calculaPoblacionAnios(long double tasa_variacion,int anios){
			int cont;
			long long int poblacion_final;
			poblacion_final=poblacion_inicial;
			for(cont=0;cont<anios;cont++)
				poblacion_final=poblacion_final*(UNO+tasa_variacion);	
			return poblacion_final;														
		}		
};
int main () {
	unsigned long long int poblacion_inicial;	       		 //Declarada como long long int por ser una cantidad considerable y como unsigned por ser siempre positiva.
	double tasa_natalidad,tasa_mortalidad,tasa_migracion; 	//Declaradas como "double" porque en ningún caso serán superiores a 1000 y para que la división de entero/real de real.
	unsigned long long int poblacion_final;  				//Variable de salida y auxiliar para la segunda parte.
	int anios,anios_duplicar;
	string valor_pedido;
	Poblacion china;
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
	china.setParametros(poblacion_inicial,tasa_natalidad,tasa_mortalidad,tasa_migracion);


	/*************************************************/
	
	/***********CÁLCULOS***********/
	long double tasa_variacion;
	tasa_variacion=china.calculaTasaVariacion();	
	poblacion_final=china.calculaPoblacionAnios(tasa_variacion,anios);
	anios_duplicar=china.calculaAniosPoblacionDuplicada(tasa_variacion);

	/****************************/

	cout<<"La poblacion, tras "<<anios<<" anios sera de "<<poblacion_final<<" habitantes.\n";							 //Muestro el resultado en pantalla.
	cout<<"Para que la poblacion, como minimo, se duplique, tendran que pasar "<<anios_duplicar<<" anios";

	
}
