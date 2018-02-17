/* Programa que dice si una serie de números ha sido introducida en orden */
#include <iostream>
#include <string>
using namespace std;
int main () {
	int num1,num2,num3; //Variables de entrada
	enum TipoOrden {ascendente,descendente,desordenada};		//Declaro el tipo para el orden.
	TipoOrden orden;	//Variable de orden
	bool creciente,decreciente,desorden;	//Variables de comprobación de orden
	cout<<"Introduzca el primer numero:\n";
	cin>>num1;
	cout<<"Introduzca el segundo numero:\n";
	cin>>num2;
	cout<<"Introduzca el tercer numero:\n";
	cin>>num3;
	
	creciente=(num1<num2 && num2<num3);		//Compruebo el orden mediante las expresiones booleanas.
	decreciente=(num1>num2 && num2>num3);
	desorden=(!ascendente && !descendente);
	
	string cadena;
	cadena="La serie esta ordenada de forma";
	
	if (decreciente==true)
		orden=descendente;
		else 	
			if (creciente==true)
			orden=ascendente;
			else {
				orden=desordenada;				
			}
	if (orden==ascendente)
		cout<<cadena<<" ascendente";
		else
			if(orden==descendente)
				cout<<cadena<<" descendente";
				else
					cout<<"La serie esta desordenada";

		}
