#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
 const int MIN = 1, MAX=100, NUM_VALORES = MAX-MIN+1;
 int incognita; 	// Valor a adivinar (se genera aleatoriamente) 
 int valor=0; 		//Valor introducido por teclado
 time_t t;
 char caracter;
 const int FIN=-1;
 srand ((int) time(&t)); // Inicializa el generador, solo 1 vez
			    // con el reloj del sistema
do{
 	incognita = (rand() % NUM_VALORES) + MIN; // MIN <= incognita <= MAX
 	cout<<"\nAdivine el numero generado aleatoriamente entre "<<MIN<<" y "<<MAX<<" !\nIntroduzca -1 para salir\n";
 		while(valor!=FIN){
 			cout<<"Introduzca un numero:\n";
 			cin>>valor;
 			if(valor!=FIN){
 			 	if(valor<incognita)
 					cout<<"Demasiado pequeno! Prueba otra vez!\n";
 				else if (valor>incognita)
 					cout<<"Demasiado grande! Prueba otra vez!\n";
 					}
}
	if(valor==FIN)
		cout<<"Casi acierta! El numero era "<<incognita;
		else
			cout<<"\n\nEnhorabuena! El numero era "<<incognita;
	cout<<"\nQuiere jugar otra vez?\nIntroduzca S para continuar o N para salir\n";
	cin>>caracter;
	caracter=toupper(caracter);
	}
while(caracter=='S');
	
	
}



