/*Programa que calcula la imagen de varios elementos en la función gaussiana en un intervalo*/
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	double esperanza,desviacion,abscisa,gaussiana; 
	float maximo,minimo,incremento;		//Variables para dar los saltos correspondientes
	const float PI=3.1416, MENOS_CERO_CINCO=-0.5;
	int cont=0;		//Variable contador
	cout<<"Introduzca la esperanza (media) de la funcion gaussiana:\n"; 
	cin>>esperanza;
	do{
		cout<<"Introduzca la desviacion tipica de la funcion gaussiana:\n";
		cin>>desviacion;
	}
	while(desviacion<=0);
	
/*************INTRODUCCIÓN DE VARIABLES******************/
cout<<"Introduzca el valor minimo de la abscisa para comenzar a mostrar valores:\n";
cin>>minimo;
do{
	cout<<"Introduzca el valor maximo donde terminar el programa (debe ser mayor que el minimo):\n";
	cin>>maximo;
}
while(maximo<minimo);

cout<<"Introduzca el valor del incremento para ir de un valor de abscisa a otro:\n";
cin>>incremento;

	while(abscisa!=maximo){			//Este tipo de ejercicio (con contadores) se suele resolver con un bucle for, pero como no lo hemos dado, lo he transformado en un while
	abscisa=minimo+cont*incremento;	//														(do while sería igual de válido).
	gaussiana=1/(desviacion*sqrt(2*PI))*exp(MENOS_CERO_CINCO*pow((abscisa-esperanza)/desviacion,2));
	cout<<gaussiana<<" ";
	cont=cont++;
	}		
}
