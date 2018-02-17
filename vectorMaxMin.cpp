/*lee desde teclado, rellena vector de capacidad 10, vector de enteros. COndiciones de parada:
	rellenar vector con 10 datos / hasta 0 . Mostrar contenido del vector. Hallar el maximo y minimo. Sin funciones*/
#include <iostream>
using namespace std;
const int CAPACIDAD=10,FIN=0;
const string MAX="El maximo del vector es ",MIN="El minimo del vector es ",
ERROR="No se ha introducido ningun valor para rellenar el vector.",PRIMERA_POS="Introduzca un valor para la posicion numero 0 del vector:";

int main(){
	int util=0,i;		 //Variables contador
	int maximo,minimo;
	int vector[CAPACIDAD];
	/********Rellenar el vector*************/
	cout<<PRIMERA_POS<<endl;	//Lectura adelantada
	cin>>vector[0];
	for(i=1;i<CAPACIDAD&&vector[i-1]!=FIN;i++){
		cout<<"Introduzca un valor para la posicion numero "<<i<<" del vector:\n";
		cin>>vector[i];
		util++;
	}		
	if(util==0)	//Si está vacío
		cout<<ERROR<<endl;
	else{	//Si hay más de un elemento
		/******Mostrar el contenido del vector*******/
		for(i=0;i<util;i++)
			cout<<"Posicion "<<i<<" : "<<vector[i]<<endl;
		/*****Hallar máximo y mínimo***************/
		maximo=vector[0];
		minimo=vector[0];
		for(i=0;i<util;i++){
			if(vector[i]<minimo)
				minimo=vector[i];
			else
				maximo=vector[i];
		}
		cout<<MAX<<maximo<<endl;
		cout<<MIN<<minimo<<endl;	
	}
	/*******Insertar*******/
	int insertar,pos;
	cout<<"valor"<<endl;
	cin>>insertar;
	cout<<"posicion"<<endl;
	cin>>pos;
	util++;
	for(i=util-1;i>=util;i--){
		vector[i]=vector[i-1];
		if(i==pos)
			vector[i]=insertar;
	}
	for(i=0;i<util;i++)
		cout<<"Posicion "<<i<<" : "<<vector[i]<<endl;
}
