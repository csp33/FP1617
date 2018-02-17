/*Simulacro VERDADERO de examen */
/* Gimnastas, dorsal positivo Un gimnasta tiene tres notas 0-10 . 0 para terminar. Calcular la nota de cada gimnasta (media)*/
/*GIMNASTA-NOTA-NOTA-NOTA-GIMNASTA si GIMNASTA=0, FIN*/
#include <iostream>
using namespace std;

const int NULO=0,NUMERO_DATOS=3,COTA_INF=0,COTA_SUP=10;
int leePositivo(string msg){
	int dorsal;
	do{
		cout<<"Introduzca un dorsal (0 para salir):\n";
		cin>>dorsal;
	}while(dorsal<NULO);
	return dorsal;
}
int leePuntos(){ 			/*Las tres introducciones en una función no, mejor una función que pide un dato y la llamamos varias veces*/
	int puntuacion;
	do{
		cout<<"Introduzca una puntuacion:\n";
		cin>>puntuacion;
	}while(puntuacion<COTA_INF||puntuacion>COTA_SUP);
	return puntuacion;
}


int main(){
	const string MENSAJE_DORSAL="Introduzca un dorsal (0 para salir):\n";
	int media_mayor=-1,media_actual,dorsal,puntuacion,dorsal_ganador;
	int i;

	dorsal=leePositivo(MENSAJE_DORSAL);
	
	while(dorsal!=NULO){
		media_actual=0;
		for(i=1;i<=NUMERO_DATOS;i++){
			puntuacion=leePuntos();
			media_actual+=puntuacion;
		}
		media_actual/=NUMERO_DATOS;
		if(media_actual>media_mayor){
			dorsal_ganador=dorsal;
			media_mayor=media_actual;
		}
		dorsal=leePositivo(MENSAJE_DORSAL);
	}
	if(media_mayor!=-1)
		cout<<"El ganador tiene el dorsal numero "<<dorsal_ganador<<" con una nota media de "<<media_mayor<<" puntos."<<endl;
	else	
		cout<<"No se ha introducido ningun dorsal";
}
