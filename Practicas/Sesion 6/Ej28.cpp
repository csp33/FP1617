/*Programa que hace de filtro de entrada de datos para el Ej11*/
#include <iostream>
using namespace std;
int main () {
	//Variables de entrada.
	double salario_hora;										//Los segundos de atencion se podrian almacenar en una sola variable ya que no se usan en los cálculos.
	short codigo_empleado;										// No obstante, lo dejo así por una posible futura actualización del programa.
	short resuelto_1,resuelto_2,resuelto_3;	
	int segundos_atencion_1,segundos_atencion_2,segundos_atencion_3;
	float satisfaccion_1,satisfaccion_2,satisfaccion_3;			//Tipo float para salvar los decimales al hacer la media
	//Variables para cálculos
	int casos_introducidos=0;									//Contador
	int cont_empleado1=0,cont_empleado2=0,cont_empleado3=0;		//Contadores de cada empleado
	int aux_1=0,aux_2=0,aux_3=0;								//Variables auxiliares para realizar la media. 
	float media_1=0,media_2=0,media_3=0;						//Inicializadas a cero por si no se introduce algún empleado.
	//Variables de salida
	int mejor_empleado;											
	float media_mejor;
	string cadena="";											//Variable para indicar si varios empleados tienen el mayor grado de satisfaccion. Se inicializa vacía por si no se da el caso.
	//Constantes
	const int CODIGO_EMPLEADO_1=1,CODIGO_EMPLEADO_2=2,CODIGO_EMPLEADO_3=3,
	CASO_RESUELTO=1,CASO_NO_RESUELTO=0,SALIR=-1,SATISFACCION_MINIMA=0,SATISFACCION_MAXIMA=5,NULO=0;
	
	do{
		cout<<"Introduzca el salario por hora:\n";	//Filtro de entradad
		cin>>salario_hora;
	}while(salario_hora<=NULO);
	
	cout<<"Introduzca el codigo de empleado:\n";		//Lectura adelantada
	cin>>codigo_empleado;
	while(codigo_empleado!=SALIR){
		/*************EMPLEADO 1*********/
		if(codigo_empleado==CODIGO_EMPLEADO_1){
			cont_empleado1++;
			do{
				cout<<"Introduzca	los segundos de atencion:\n";
				cin>>segundos_atencion_1;
			}while(segundos_atencion_1<NULO);
			
			do {
				cout<<"Introduzca 1 si el caso se resolvio o 0 si no:\n";
				cin>>resuelto_1;	
			}while(resuelto_1!=CASO_RESUELTO && resuelto_1!=CASO_NO_RESUELTO);	//!(resuelto==CASO_RESUELTO || resuelto==CASO_NO_RESUELTO)
			
			do{
				cout<<"Introduzca el grado de satisfaccion:\n";
				cin>>satisfaccion_1;
			}while(satisfaccion_1<SATISFACCION_MINIMA || satisfaccion_1>SATISFACCION_MAXIMA);		//!(satisfaccion_1>=SATISFACCION_MINIMA && satisfaccion_1<=SATISFACCION_MAXIMA)
			satisfaccion_1=aux_1+satisfaccion_1;
			aux_1=satisfaccion_1;				
		}
		/*********************************/
		/*************EMPLEADO 2*********/
		else if(codigo_empleado==CODIGO_EMPLEADO_2){
			cont_empleado2++;
			satisfaccion_2=aux_2;
			do{
				cout<<"Introduzca	los segundos de atencion:\n";
				cin>>segundos_atencion_2;
			}while(segundos_atencion_2<NULO);
				
			do {
				cout<<"Introduzca 1 si el caso se resolvio o 0 si no:\n";
				cin>>resuelto_2;	
			}while(resuelto_2!=CASO_RESUELTO && resuelto_2!=CASO_NO_RESUELTO);
			
			do{
				cout<<"Introduzca el grado de satisfaccion:\n";
				cin>>satisfaccion_2;
			}while(satisfaccion_2<SATISFACCION_MINIMA || satisfaccion_2>SATISFACCION_MAXIMA);
			satisfaccion_2=aux_2+satisfaccion_2;	
			aux_2=satisfaccion_2;				
			
		}
		/*********************************/
		/*************EMPLEADO 3*********/
		else if(codigo_empleado==CODIGO_EMPLEADO_3){
			cont_empleado3++;
			satisfaccion_3=aux_3;
			do{
				cout<<"Introduzca	los segundos de atencion:\n";
				cin>>segundos_atencion_3;
			}while(segundos_atencion_3<NULO);
			
			do {
				cout<<"Introduzca 1 si el caso se resolvio o 0 si no:\n";
				cin>>resuelto_3;	
			}while(resuelto_3!=CASO_RESUELTO && resuelto_3!=CASO_NO_RESUELTO);
			
			do{
				cout<<"Introduzca el grado de satisfaccion:\n";
				cin>>satisfaccion_3;
			}while(satisfaccion_3<SATISFACCION_MINIMA || satisfaccion_3>SATISFACCION_MAXIMA);
			satisfaccion_3=aux_3+satisfaccion_3;	
			aux_3=satisfaccion_3;				
		
		}
			/*********************************/
		else { 			//Si cometemos un error al indicar el empleado
			cout<<"ERROR. No se encuentra al empleado. Pruebe otra vez.\n";
			casos_introducidos--;
		}
		casos_introducidos++;								//Aumento el contador
		cout<<"Introduzca el codigo de empleado:\n";		//Lectura al final del bucle
		cin>>codigo_empleado;
		}
	cout<<"Fin del programa.\n";	
	if(casos_introducidos!=NULO){
		/**********CÁLCULO DE MEDIAS***************/
		if(cont_empleado1!=NULO)
			media_1=satisfaccion_1/cont_empleado1;
		if(cont_empleado2!=NULO)
			media_2=satisfaccion_2/cont_empleado2;
		if(cont_empleado3!=NULO)
			media_3=satisfaccion_3/cont_empleado3;
		/*******************************************/	
		if (media_1==media_2 && media_2==media_3) {	
			mejor_empleado=CODIGO_EMPLEADO_1;
			media_mejor=media_1;
			cadena="Los empleados 1, 2 y 3 comparten el mayor grado de satisfaccion medio.";
		}
		else if (media_1>=media_2&&media_2>=media_3){
				mejor_empleado=CODIGO_EMPLEADO_1;
				media_mejor=media_1;
				if (media_1==media_2)
					cadena="Los empleados 1 y 2 comparten el mayor grado de satisfaccion medio.";
			}
		else if (media_2>=media_3 && media_2>=media_1){
				mejor_empleado=CODIGO_EMPLEADO_2;
				media_mejor=media_2;
				if (media_2==media_3)
					cadena="Los empleados 2 y 3 comparten el mayor grado de satisfaccion medio.";
			}			
		else if (media_3>=media_1&&media_3>=media_2){
				mejor_empleado=CODIGO_EMPLEADO_3;
				media_mejor=media_3;
				if (media_1==media_3)
					cadena="Los empleados 1 y 3 comparten el mayor grado de satisfaccion medio.";
			}
		if(casos_introducidos==NULO)
			cout<<"ERROR. No ha introducido ningun caso.\n";
		else
			cout<<"Casos introducidos: "<<casos_introducidos<<"\nEmpleado con mayor grado de satisfaccion: "<<mejor_empleado<<
			"\nGrado de satisfaccion media del empleado: "<<media_mejor<<".\n"<<cadena;	
	}
}

