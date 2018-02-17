/*Programa que calcula días, horas, minutos y segundos en su rango correcto a través de una entrada de teclado*/
#include <iostream>
using namespace std;
int main () {
	const int HORAS_POR_DIA=24,SEGUNDOS_POR_MINUTO=60;  //Factores de conversión entre horas->días y segundos-->minutos.
	int horas_inicial,min_inicial,seg_inicial;       //Variables de entrada
	int aux_min;
	int dias_final,horas_final,min_final,seg_final; //Variables de salida
	
	/****************INTRODUCCIÓN DE DATOS POR TECLADO****************/
	cout<<"Introduzca las horas:\n";
	cin>>horas_inicial;
	cout<<"Introduzca los minutos:\n";
	cin>>min_inicial;
	cout<<"Introduzca los segundos:\n";
	cin>>seg_inicial;
	/****************************************************************/
	
	/***********************CÁLCULOS********************************/
	seg_final=seg_inicial%SEGUNDOS_POR_MINUTO;
	aux_min=min_inicial+seg_inicial/SEGUNDOS_POR_MINUTO;
	min_final=aux_min%60;
	/****************************************************************/
	cout<<horas_inicial<<" horas, "<<min_inicial<<" minutos y "<<seg_inicial<<" equivalen a \n"  //Mostramos el resultado.
	<<dias_final<<" dias, "<<horas_final<<" horas, "<<min_final<<" minutos y "<<seg_final<<" segundos.";

	
}
