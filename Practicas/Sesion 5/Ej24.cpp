#include <iostream>
using namespace std;
int main () {
	int max,min,numero;		//Variables de entrada
	int cont=0;				//Variable contador
	int intentos;			//Variable auxiliar para separar cómputos
	const int INTENTOS_MAXIMO=3;
	do{
		cout<<"Introduzca el minimo:\n";
		cin>>min;	
	} while(min==0);
	do{
		cout<<"Introduzca el maximo:\n";
		cin>>max;
	} while(max<min);
	do{
		cout<<"Introduzca un numero entre el maximo y el minimo.\nPuede cometer tres errores como maximo\n";
		cin>>numero;
		if(numero<min || numero>max) {	//!(numero>=min && numero<=max)
			cont=cont++;
			intentos=INTENTOS_MAXIMO-cont;	
			cout<<"Ha cometido un error! Le quedan "<<intentos<<" intentos.\n";
		}else {
			do{
				cout<<"Introduzca el minimo:\n";
				cin>>min;	
			} while(min==0);
			do{
				cout<<"Introduzca el maximo:\n";
				cin>>max;
			} while(max<min);	
			}
	}while(cont!=INTENTOS_MAXIMO);
	cout<<"Ha cometido tres errores! Fin del programa.";
}
