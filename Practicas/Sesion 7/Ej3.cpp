/* Programa que dice el máximo de tres números*/
#include <iostream>
using namespace std;
int Max (int num1,int num2){
	if(num1>num2)
		return num1;
	else
		return num2;
}
int Max3 (int num1,int num2, int num3){
	int aux,maximo;
	aux=Max(num1,num2);
	maximo=Max(aux,num3);
	return maximo;
}
void muestraMenu (){
	cout<<"************PROGRAMA QUE CALCULA EL MAXIMO DE 3 NUMEROS******************"<<endl<<endl;
}
int introduceNumero(int &numero){
	cout<<"Introduzca un numero:\n";
	cin>>numero;
}
int main(){
	int numero1,numero2,numero3;	//Variables de entrada
	int maximo;						//Variable de salida
	bool son_iguales;
	string cadena="El maximo es: ";
	
	muestraMenu();
	introduceNumero(numero1);
	introduceNumero(numero2);
	introduceNumero(numero3);
	son_iguales=numero1==numero2&&numero2==numero3;
	if(son_iguales){
		maximo=numero1;
		cadena="Los numeros son iguales: ";
	}
	else
		maximo=Max3(numero1,numero2,numero3);
		
	cout<<cadena<<maximo<<endl;
	
}
