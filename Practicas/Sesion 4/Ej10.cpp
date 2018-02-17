/* Programa que calcula la tasa del parking*/
#include <iostream>
using namespace std;
int main () {
	short hora_inicio,min_inicio,seg_inicio; //Declaramos las variables de entrada al programa como short, ya que en ningún caso sus valores serán superiores a 59.
	short hora_fin,min_fin,seg_fin; 
	int instante_minutos; 					     
	const int CONV=60;                      //Declaramos el factor de conversión de minuto a segundo como constante.
	const float TASA_0_30=0.0412,TASA_31_90=0.037,TASA_91_660=0.0493,TASA_MAS_660=31.55; //Tasas según el tiempo en minutos
	float precio;				     		 //Precio segun la tarifa
	/*************CALCULO DEL INSTANTE EN MINUTOS*************************************/
	cout<<"Introduzca la hora inicial, por favor:\n";
	cin>> hora_inicio;
	cout<<"Introduzca los minutos iniciales, por favor:\n";
	cin>> min_inicio;
	cout<<"Introduzca los segundos iniciales, por favor:\n";
	cin>> seg_inicio;
	cout<<"Introduzca la hora final, por favor:\n";
	cin>> hora_fin;
	cout<<"Introduzca los minutos iniciales, por favor:\n";
	cin>> min_fin;
	cout<<"Introduzca los segundos iniciales, por favor:\n";
	cin>> seg_fin;
	instante_minutos=((hora_fin-hora_inicio)*CONV+min_fin-min_inicio+(seg_fin-seg_inicio)/60);
	/*******************************************************************************/
	
	/*******************APLICACION DE LAS TARIFAS********************************/
	if (instante_minutos>660)
		cout<<"La tarifa a pagar es de "<<TASA_MAS_660<<" euros.";
	if (instante_minutos>0 && instante_minutos<30){
		precio=instante_minutos*TASA_0_30;
		cout<<"La tarifa a pagar es de "<<precio<<" euros.";
	}
	if (instante_minutos>31 && instante_minutos<90){
		precio=instante_minutos*TASA_31_90;
		cout<<"La tarifa a pagar es de "<<precio<<" euros.";
	}
	if (instante_minutos>91 && instante_minutos<660){
		precio=instante_minutos*TASA_91_660;
		cout<<"La tarifa a pagar es de "<<precio<<" euros.";
	}			
	/**************************************************************************/
	cout<<"\nGracias.";
}
