/*Programa que hace la multiplicación rusa*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int cont=0;																//Numero de iteraciones
	int multiplicando, multiplicador;										//Variables de entrada
	unsigned int multiplicando_abs,multiplicador_abs;						//No necesitan signo, ya que serán positivos forzosamente
	int	multiplicando_bucle,multiplicador_bucle;
	int aux=0;																//Variable auxiliar para ir sumando los multiplicadores impares
	bool multiplicando_impar,alguno_negativo,ambos_negativos,alguno_nulo;	//Variables booleanas para hacer comprobaciones
	int resultado;															//Variable de salida
	const int UNO=1,DOS=2,NULO=0,CAMBIO_SIGNO=-1;							//Constantes
	
	cout<<"Introduzca el multiplicando:\n";
	cin>>multiplicando;
	cout<<"Introduzca el multiplicador:\n";
	cin>>multiplicador;
	
	multiplicando_abs=abs(multiplicando);	//Hago ambos positivos para no tener problemas en el bucle.
	multiplicador_abs=abs(multiplicador);	//Más adelante cambiaré el resultado de signo si alguno es negativo
	alguno_negativo=multiplicando<NULO||multiplicador<NULO;
	ambos_negativos=multiplicando<NULO&&multiplicador<NULO;
	alguno_nulo=multiplicando==NULO||multiplicador==NULO;
	if(alguno_nulo)		//Casos en los que este algoritmo no funciona correctamente.
		cout<<"El producto de "<<multiplicando<<" y "<<multiplicador<<" no se podria hacer mediante la multiplicacion rusa.\nNo obstante, su resultado es "<<NULO;
	else if(multiplicando==UNO)  // Se podría añadir el caso multiplicador==1 para simplificar cálculos, pero la operación es compatible con la multiplicación rusa).
		cout<<"El producto de "<<multiplicando<<" y "<<multiplicador<<" (en ese orden) no se podria hacer mediante la\nmultiplicacion rusa.\nNo obstante, su resultado es "<<multiplicador;
	else{				//Resto de casos
		cont++;
		multiplicando_impar=multiplicando%DOS!=NULO;
		if(multiplicando_impar)
			aux=multiplicador_abs;
		multiplicando_bucle=multiplicando_abs;
		multiplicador_bucle=multiplicador_abs;
		while(multiplicando_bucle!=UNO){
			multiplicando_bucle=multiplicando_bucle/DOS;
			multiplicador_bucle=multiplicador_bucle*DOS;
			multiplicando_impar=multiplicando_bucle%DOS!=NULO;
			if(multiplicando_impar){
				resultado=multiplicador_bucle+aux;
				aux=resultado;
			}
			cont++;
		}
		if(alguno_negativo&&!ambos_negativos)
			resultado=CAMBIO_SIGNO*resultado;
			
		cout<<"Mediante la multiplicacion rusa, el producto de "<<multiplicando<<" y "<<multiplicador<<" es "<<resultado<<"\nNumero de iteraciones: "<<cont;
	}
}

