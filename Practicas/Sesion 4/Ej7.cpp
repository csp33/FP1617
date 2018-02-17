/* Programa que */
#include <iostream>
using namespace std;
int main () {
	int num1,num2,num3; //Variables de entrada
	cout<<"Introduzca el primer numero:\n";
	cin>>num1;
	cout<<"Introduzca el segundo numero:\n";
	cin>>num2;
	cout<<"Introduzca el tercer numero:\n";
	cin>>num3;		
	if ((num1>num2)&&(num2)>num3)
		cout<<"La serie "<<num1<<" "<<num2<<" "<<num3<<" esta ordenada de forma descendente.";
		else {
			if ((num1<num2)&&(num2)<num3)
				cout<<"La serie "<<num1<<" "<<num2<<" "<<num3<<" esta ordenada de forma ascendente.";	
			else
				cout<<"La serie "<<num1<<" "<<num2<<" "<<num3<<" no esta ordenada.";	
	
}
}
