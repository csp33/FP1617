/*Programa que calcula la imagen de un elemento en la funci�n gaussiana a partir de su abscisa*/
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double esperanza,desviacion,abscisa,gaussiana; 
	const float PI=3.1416;		//Declaramos pi como constante por si queremos aproximar m�s su valor en una futura edici�n del programa
	cout<<"Introduzca la esperanza (media) de la funcion gaussiana:\n"; 
	cin>>esperanza;
	cout<<"Introduzca la desviaci�n t�pica de la funcion gaussiana:\n";
	cin>>desviacion;
	cout<<"Introduzca la abscisa cuya imagen desea calcular:\n";
	cin>>abscisa;
	gaussiana=1/(desviacion*sqrt(2*PI))*exp(-0.5*pow((abscisa-esperanza)/desviacion,2));
	cout<<"El valor de la imagen en el punto de abscisa "<<abscisa<<" es de "<<gaussiana<<"";
}
