/*Programa que calcula la mayor subsecuencia de temperaturas consecutivas así como su posición de inicio*/
#include <iostream>
using namespace std;
int main () {
	float temperatura_entrada;												//Variable de entrada
	float temperatura_maxima;												//Variables auxiliares
	unsigned int posicion_actual=0,posicion_subsecuencia_aux=1,longitud_aux=0,dia_actual=1;
	unsigned int posicion_subsecuencia_mayor=1,longitud_mayor=1;			//Variables de salida								
	const int FIN=-1,INICIO=1,NULA=0;										//Constantes
	
	cout<<"Introduzca una temperatura (-1 para salir):\nDia "<<dia_actual<<endl;
	cin>>temperatura_entrada;							
	temperatura_maxima=temperatura_entrada;									//La temperatura introducida es la máxima hasta que se demuestre lo contrario
	
	while(temperatura_entrada!=FIN && temperatura_maxima!=FIN){
		posicion_actual++;
		dia_actual++;
		if(temperatura_entrada>temperatura_maxima){
			longitud_aux++;
		 	if(longitud_aux>=longitud_mayor){
				longitud_mayor=longitud_aux;
				posicion_subsecuencia_mayor=posicion_subsecuencia_aux;
				}
		}			
		else {
			posicion_subsecuencia_aux=posicion_actual;	
			longitud_aux=INICIO;
		}
		temperatura_maxima=temperatura_entrada;
		cout<<"Introduzca una temperatura:\nDia "<<dia_actual<<endl;
		cin>>temperatura_entrada;
		}
	
	cout<<"Fin del programa\n";
	if(posicion_actual==NULA)
		cout<<"ERROR.No se ha introducido ninguna temperatura.";
	else
		cout<<"La mayor subsecuencia de dias con temperatura creciente comienza el dia "<<posicion_subsecuencia_mayor<<
		"\ny dura "<<longitud_mayor<<" dias.";
	
}

