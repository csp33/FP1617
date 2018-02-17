/*Ejercicio 10. Vectores*/
#include <iostream>
using namespace std;
struct Frecuencia{	//Declaramos el tipo de dato
	char caracter;
	int frecuencia;
};
class SecuenciaCaracteres{
	private:
		static const int CARACTERES=256,NOT_FOUND=-1;
		Frecuencia letras[CARACTERES];
		int util;
		int Busqueda(char caracter){
			int posicion=NOT_FOUND;
			int i;
			for(i=0;i<util&&letras[i].caracter!=caracter;i++)
				;
			if(i<util)
				posicion=i;
			return posicion;
		}
		void AniadeCaracter(char caracter){
			letras[util].caracter=caracter;
			letras[util].frecuencia=1;
			util++;
		}
		void AumentaFrecuencia(char caracter,int posicion){
			letras[posicion].frecuencia++;
		}
	public:
		SecuenciaCaracteres(){
			util=0;
		}
		void RellenaVector(char caracter){
			if(util<CARACTERES){
				int posicion;
				posicion=Busqueda(caracter);
				if(posicion==NOT_FOUND)
					AniadeCaracter(caracter);
				else
					AumentaFrecuencia(caracter,posicion);
			}
		}
		Frecuencia CalculaModa(){
			int i;
			Frecuencia moda;
			moda.caracter=letras[0].caracter;
			moda.frecuencia=letras[0].frecuencia;
			for(i=1;i<util;i++)
				if(letras[i].frecuencia>moda.frecuencia){
					moda.frecuencia=letras[i].frecuencia;
					moda.caracter=letras[i].caracter;
				}
			return moda;		
		}
};
const char FIN='#';
const string MSG_INICIO="Introduzca el texto (# para terminar la entrada)",MSG_MODA_1="La moda en el texto introducido es '",MSG_MODA_2="' con un total de ";
int main () {
	char caracter;						//Variable de entrada
	SecuenciaCaracteres secuencia;
	
	cout<<MSG_INICIO<<endl;
	/***Lectura y almacenamiento de cada letra en el vector***/
	caracter=cin.get();
	while(caracter!=FIN){
		secuencia.RellenaVector(caracter);
		caracter=cin.get();					
	}
	/***Búsqueda de la moda***/
	Frecuencia moda;
	moda=secuencia.CalculaModa();
	/***Salida por pantalla***/
	cout<<MSG_MODA_1<<moda.caracter<<MSG_MODA_2<<moda.frecuencia<<" apariciones."<<endl;
	
	
}
