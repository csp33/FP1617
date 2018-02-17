#include <iostream>
using namespace std;
int main () {
	const int PUNTUACION_1=1,PUNTUACION_2=2,PUNTUACION_3=3,SALIR=0;
	int puntuacion;		
		do{
			cout<<"Introduzca una puntuacion (1,2 o 3):\n";
			cin>>puntuacion;
		} while (puntuacion!=PUNTUACION_1 && puntuacion!=PUNTUACION_2 && puntuacion!=PUNTUACION_3 && puntuacion!=SALIR);
	
	
	
}
