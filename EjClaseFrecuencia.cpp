#include <iostream>
using namespace std;
int main () {
	int numero;	//Variable de entrada
	float positivo=0, negativo=0,total=0;	//Variables de conteo
	float frecuencia_positiva,frecuencia_negativa;
	const int SALIR=0,INCREMENTO=1;
	do{
		cout<<"Introduzca un numero (0 para salir):\n";				//MEJOR CON WHILE
		cin>>numero;
		if(numero>0){
			positivo=positivo+INCREMENTO;
			cout<<"\nPositivo\n";}
		else if (numero<0){
			negativo=negativo+INCREMENTO;
			cout<<"\nNegativo\n";}
		if(numero!=SALIR)
			total=total+INCREMENTO;
	 }while(numero!=SALIR);
	frecuencia_positiva=positivo/total;
	frecuencia_negativa=negativo/total;
	cout<<"Numeros introducidos: "<<total<<"\nFrecuencia de positivos: "<<frecuencia_positiva<<"\nFrecuencia de negativos: "<<frecuencia_negativa<<".";
	
	//************CORREGIDO*******/
	cout<<"Introduzca un numero (0 para salir):\n";				
	cin>>numero;
while(numero!=SALIR){
	if(numero>0)
		positivo=positivo+1;
	else
		negativo=negativo+1;
	total=total+1;
	cout<<"Introduzca un numero (0 para salir):\n";				
	cin>>numero;
}
	frecuencia_positiva=positivo/total;
	frecuencia_negativa=negativo/total;
	cout<<"Numeros introducidos: "<<total<<"\nFrecuencia de positivos: "<<frecuencia_positiva<<"\nFrecuencia de negativos: "<<frecuencia_negativa<<".";
	
		
}
