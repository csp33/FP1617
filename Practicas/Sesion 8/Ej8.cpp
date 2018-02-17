/*Programa que calcula la imagen de un elemento en la función gaussiana a partir de su abscisa. Se añade un menú*/
#include <iostream>
#include <cmath>
using namespace std;
void muestraMenu1(){
	cout<<endl<<"******PROGRAMA QUE CALCULA LA IMAGEN Y EL CDF DE LA FUNCION GAUSSIANA**********"<<endl;
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
double calculaPotencia(double base, int exponente){
	double potencia=1.0;
	int cont;
	for (cont=1;cont<=exponente; cont++)    
		potencia=potencia*base;
	return potencia;
}
double calculaCDF(double gaussiana, double abscisa){
	const double B0=0.2316419,B1=0.319381530,B2=-0.356563782,B3=1.781477937,B4=-1.821255978,B5=1.330274429;
	const int UNO=1,CUADRADO=2,CUBO=3,CUARTA=4,QUINTA=5;
	const double T=UNO/(1+B0*abscisa);
	double acumulada;
	acumulada=UNO-gaussiana*(B1*T+B2*calculaPotencia(T,CUADRADO)+B3*calculaPotencia(T,CUBO)+B4*calculaPotencia(T,CUARTA)+B5*calculaPotencia(T,QUINTA));
	return acumulada;
}
void muestraValoresAbscisa(double min,double max,double incremento,double esperanza,double desviacion){
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
void muestraValoresCDF(double min, double max, double incremento,double media, double desviacion){
	double desviacion_acumulada,gaussiana,abscisa;
	int cont;
	abscisa=min;
	for(cont=0;abscisa<max;cont++){
		abscisa=min+cont*incremento;
		gaussiana=calculaGaussiana(desviacion,media,abscisa);
		desviacion_acumulada=calculaCDF(gaussiana,abscisa);
		cout<<"\nCDF("<<abscisa<<")= "<<desviacion_acumulada<<" \n";
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
				muestraValoresAbscisa(min,max,incremento,esperanza,desviacion);
				muestraValoresCDF(min,max,incremento,esperanza,desviacion);
				muestraMenu2();
				opcion=eligeOpcion();			
				}
		muestraMenu1();
		opcion=eligeOpcion();	
	}
}
