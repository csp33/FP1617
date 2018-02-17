/*Programa que calcula la imagen de un elemento en la función gaussiana a partir de su abscisa. Se añade un menú*/
#include <iostream>
#include <cmath>
using namespace std;
void muestraMenu1(){
	cout<<endl<<"********PROGRAMA QUE CALCULA LA IMAGEN DE LA FUNCION GAUSSIANA***************"<<endl;
	cout<<"1.- Introducir parametros(media y desviacion tipica)"<<endl<<"2.- Salir"<<endl;
}
void muestraMenu2(){
	cout<<endl<<"1.- Introducir un rango de valores y un incremento para calcular la abscisa\nen cada punto"<<endl<<"2.- Volver al menu anterior\n";
}

int eligeOpcion(){
	int opcion;
	const int OPCION_MENOR=1,OPCION_MAYOR=2;
	do{
	cout<<"\nElija una opcion"<<endl;
	cin>>opcion;
	}while(opcion<OPCION_MENOR||opcion>OPCION_MAYOR);
	return opcion;
}
double leePositivo(){
	const int NULO=0;
	double numero;
	do{
		cout<<"Introduzca un numero:\n";
		cin>>numero; 
	}while(numero<NULO);
	return numero;
}
double leeRango(double &min,double &max){
	do{
		cout<<"Introduzca el valor minimo:\n";
		cin>>min;
		cout<<"Introduzca el valor maximo:\n";
		cin>>max;
	}while(min>max);
}
double leeReal(){
	double numero;
	cout<<"Introduzca un numero:\n";
	cin>>numero;
	return numero;
}
double calculaGaussiana(double desviacion,double media, double abscisa){
	const float PI=3.14,UNO=1,MENOS_CERO_COMA_CINCO=-0.5,DOBLE=2;
	double gaussiana;
	gaussiana=UNO/(desviacion*sqrt(DOBLE*PI))*exp(MENOS_CERO_COMA_CINCO*pow((abscisa-media)/desviacion,DOBLE));
	return gaussiana;
}
void muestraValores(double min,double max,double incremento,double esperanza,double desviacion){
	double abscisa;
	double gaussiana;
	int cont;
	abscisa=min;
	for(cont=0;abscisa<max;cont++){			
	abscisa=min+cont*incremento;
	gaussiana=calculaGaussiana(desviacion,esperanza,abscisa);
	cout<<"\nf("<<abscisa<<")= "<<gaussiana<<" \n";
	}		
}
int main () {
	const int PARAMETROS=1,SALIR=2;
	double min,max,incremento;	
	int opcion;
	double esperanza,desviacion; 

	muestraMenu1();
	opcion=eligeOpcion();
		while(opcion!=SALIR){
			cout<<"Esperanza:\n";
			esperanza=leeReal();
			cout<<"Desviacion:\n";
			desviacion=leePositivo();
			muestraMenu2();
			opcion=eligeOpcion();
			while(opcion==PARAMETROS){
				leeRango(min,max);
				cout<<"Incremento:\n";
				incremento=leePositivo();
				muestraValores(min,max,incremento,esperanza,desviacion);
				muestraMenu2();
				opcion=eligeOpcion();			
				}
		muestraMenu1();
		opcion=eligeOpcion();	
	}
}
