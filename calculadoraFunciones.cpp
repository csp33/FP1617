/* Suma, resta, producto y división implementando funciones*/
#include <iostream>
using namespace std;
float sumaNumeros(float sumando1, float sumando2){
	float suma;
	suma=sumando1+sumando2;
	return suma;
}
float productoNumeros(float multiplicando, float multiplicador){
	float producto;
	producto=multiplicando*multiplicador;
	return producto;
}
float restaNumeros (float mayor, float menor){
	float resta;
	resta=mayor-menor;
	return resta;
}
float divideReal(float dividendo, float divisor){
	float cociente;
	cociente=dividendo/divisor;
	return cociente;
}
float divideEntero(float dividendo, float divisor){
	int cociente;
	cociente=dividendo/divisor;
	return cociente;
}
void muestraMenu(){
	cout<<"1.-Sumar\n2.-Restar\n3.-Multiplicar\n4.-Division Real\n5.-Division Entera\n\n";
}
float leeValor(){
	float valor;
	cout<<"Introduzca un valor:\n";
	cin>>valor;
	return valor;
}
short eligeOpcion(){
	short opcion;
	do{
		cout<<"Elija una opcion:\n\n";
		cin>>opcion;
	}while(opcion<1||opcion>5);
	return opcion;
}
	
int main(){
	const short SUMA=1,RESTA=2,MULTIPLICACION=3,DIVISION_REAL=4,DIVISION_ENTERA=5;
	const char SEGUIR='S';
	float valor1,valor2;
	short opcion;
	char continuar;
	do{
		valor1=leeValor();
		valor2=leeValor();
		muestraMenu();
		opcion=eligeOpcion();
		cout<<"\n\nEl resultado es:\n";
		if(opcion==SUMA)
			cout<<sumaNumeros(valor1,valor2)<<endl;
		else if(opcion==RESTA)
			cout<<restaNumeros(valor1,valor2)<<endl;
		else if(opcion==MULTIPLICACION)
			cout<<productoNumeros(valor1,valor2)<<endl;
		else if(opcion==DIVISION_REAL)
			cout<<divideReal(valor1,valor2)<<endl;
		else if(opcion==DIVISION_ENTERA)
			cout<<divideEntero(valor1,valor2)<<endl;
		cout<<"\n\nPara volver a iniciar al programa, pulse S\n";
		cin>>continuar;
		continuar=toupper(continuar);
	}while(continuar==SEGUIR);
	
}
