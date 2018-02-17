/* Ejercicio 3. Vectores*/
#include <iostream>
using namespace std;
const int CAPACIDAD=100,FIN=-1;
const string MSG_RELLENAR="Introduzca valores para rellenar el vector.",MSG_REFERENCIA="Introduzca el parametro de referencia:";
int main(){
	int i,j,util_m=0,util_v=0;		//Contadores
	int aux;				//Variable auxiliar
	int referencia;		//Variable de entrada
	double vector[CAPACIDAD],mayores_que[CAPACIDAD];
	/**Rellenar el vector***/
	cout<<MSG_RELLENAR<<endl;
	for(i=0;i<CAPACIDAD&&vector[i-1]!=FIN;i++){
		cout<<"Posicion numero "<<i<<endl;
		cin>>vector[i];
		util_v++;
	}
	/***Leemos el parametro de referencia**/
	cout<<MSG_REFERENCIA<<endl;
	cin>>referencia;
	/****Recorremos el vector y vamos creando mayores_que****/
	for(i=0;i<util_v;i++){
		if(vector[i]>=referencia){
			mayores_que[util_m]=vector[i];
			util_m++;
		}
	}
	/****Ordenamos el vector mayores_que mediante el método de la Burbuja****/
	for(i=0;i<util_m-1;i++)
		for(j=0;j<util_m-i-1;j++)
			if(mayores_que[j]>mayores_que[j+1]){
				aux=mayores_que[j];
				mayores_que[j]=mayores_que[j+1];
				mayores_que[j+1]=aux;
			}
	/****Mostramos el contenido del vector mayores_que*****/
	for(i=0;i<util_m;i++)
		cout<<"Posicion "<<i<<": "<<mayores_que[i]<<endl;

	
	
}
