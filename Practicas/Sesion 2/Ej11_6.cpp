/*Programa que calcula los segundos entre dos instantes de un mismo dia. Se añade el factor de conversión minuto->segundo como constante*/
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	short hora_inicio,min_inicio,seg_inicio; //Declaramos las variables de entrada al programa como short, ya que en ningún caso sus valores serán superiores a 59.
	short hora_fin,min_fin,seg_fin;      
	const short CONV=60;                      //Declaramos el factor de conversión de minuto a segundo como constante.
	int instante;				     		 //Declaramos la variable de salida del programa, tipo int porque puede tener un valor mayor.
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
	instante=(hora_fin-hora_inicio)*CONV*CONV+(min_fin-min_inicio)*CONV+seg_fin-seg_inicio;
	cout<<"El instante transcurrido desde las "<<hora_inicio<<":"<<min_inicio<<":"<<seg_inicio<<" y las "<<hora_fin<<":"<<min_fin<<":"<<seg_fin<<" es de "<<instante<<" segundos.";
}
