/* Programa que calcula un factorial y una potencia*/
#include <iostream> 
using namespace std;  
int calculaFactorial(int numero_introducido){
	int contador,factorial=1; //Al inicializar a 1, si calculamos el factorial de 0 no entrará en el bucle y mantendrá su valor 1
	for(contador=1;contador<=numero_introducido;contador++)
	factorial=contador*factorial;
	return factorial;
}
double calculaPotenciaExpNegativo(double base, int exponente){
	const int UNO=1,CAMBIO_SIGNO=-1;
	double potencia;
	int cont;
	exponente=CAMBIO_SIGNO*exponente;   
	potencia=base;
	for (cont=UNO;cont<=exponente; cont++)    
		potencia=potencia*base;
	potencia=UNO/potencia;
	return potencia;
}
double calculaPotenciaExpPositivo(double base, int exponente){
	double potencia=1.0;	//Por si introducimos exponente 0
	int cont;
	for (cont=1;cont<=exponente; cont++)    
		potencia=potencia*base;
	return potencia;
}
int pideExponente(){
	int exp;
	cout<<"Introduzca un exponente (se calculara su factorial):\n";
	cin>>exp;
	return exp;
}
double pideBase(){
	double base;
	cout<<"Introduzca una base :\n";
	cin>>base;
	return base;
}
int main(){    
	double base; 		//Variables de entrada
	int exponente;
	double potencia;   // Variables de salida
	int factorial;
	bool exp_negativo;
	const int NULO=0;
	
	base=pideBase();
	exponente=pideExponente();
	exp_negativo=exponente<NULO;
	
	if(exp_negativo){
		potencia=calculaPotenciaExpNegativo(base,exponente);
		cout<<base<<" elevado a "<<exponente<<" vale "<<potencia<<endl<<"El factorial de "<<exponente<<" no se puede calcular, ya que es negativo.\n";
	} else {
		potencia=calculaPotenciaExpPositivo(base,exponente);
		factorial=calculaFactorial(exponente);
		cout<<base<<" elevado a "<<exponente<<" vale "<<potencia<<endl<<"El factorial de "<<exponente<<" vale "<<factorial<<endl;
	}

}
