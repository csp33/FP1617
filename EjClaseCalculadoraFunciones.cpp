/* Calculadora con menú.*/
#include <iostream>
using namespace std;

//Funciones del menú
void muestraMenu(){
	cout<<"\n************CALCULADORA***************"<<endl<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"1-->Introducir valores \n2-->Sumar\n3-->Multiplicar\n4-->Calcular MCD\n5-->Salir\n";
	cout<<"---------------------------------------"<<endl;
}
float introduceValores(float &valor1,float &valor2,bool &algun_valor){
	cout<<"Introduzca el primer valor:\n";
	cin>>valor1;
	cout<<"Introduzca el segundo valor:\n";
	cin>>valor2;
	algun_valor=true;
	}
short eligeOpcion(){
	const int OPCION_MENOR=1,OPCION_MAYOR=5;
	short opcion;
	do{
		cout<<"Elija una opcion:\n\n";
		cin>>opcion;
		cout<<endl;
	}while(opcion<OPCION_MENOR||opcion>OPCION_MAYOR);
	return opcion;
}

//Funciones de cálculos
int Swap (int &valor1,int &valor2){
	int aux=valor1;
	valor1=valor2;
	valor2=aux;
}
float sumaNumeros(float valor1, float valor2){
	return valor1+valor2;
}
float productoNumeros(float valor1,float valor2){
	return valor1*valor2;
}
int calculaMCD(int valor1,int valor2){
	const int NULO=0;
	int resto, divisor,dividendo; 
	if(valor1<valor2)
		Swap(valor1,valor2);
	else if(valor1==valor2)
		return valor1;
	resto=valor1%valor2;
	if(resto==NULO)
		return valor2;
	else
		dividendo=valor2;
		divisor=resto;
		resto=dividendo%divisor;
		while(resto!=NULO){
				dividendo=divisor;
				divisor=resto;
				resto=dividendo%divisor;
			}
	return divisor;						
}

int main(){
	const short NULO=0,INTRODUCIR=1,SUMA=2,MULTIPLICACION=3,MCD=4,SALIR=5;
	float valor1,valor2;
	bool algun_valor=false;
	short opcion;
	string cadena="\nEl resultado es: ";
	
	muestraMenu();
	opcion=eligeOpcion();
	while(opcion!=SALIR){	
			if(opcion==INTRODUCIR)
				introduceValores(valor1,valor2,algun_valor);
			if(algun_valor){
				if(opcion==SUMA)
					cout<<cadena<<sumaNumeros(valor1,valor2)<<endl;
				else if(opcion==MULTIPLICACION)
					cout<<cadena<<productoNumeros(valor1,valor2)<<endl;
				else if(opcion==MCD)
					cout<<cadena<<calculaMCD(valor1,valor2)<<endl;
				}
			else
				cout<<"No se ha introducido ningun valor.\n\n";				
		muestraMenu();
		opcion=eligeOpcion();																
	}
	
	cout<<"Saliendo del programa...\n";
}

