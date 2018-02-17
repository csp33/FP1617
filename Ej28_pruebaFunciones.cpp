/*Programa que hace de filtro de entrada de datos para el Ej11*/
#include <iostream>
using namespace std;
const int CODIGO_EMPLEADO_1=1,CODIGO_EMPLEADO_2=2,CODIGO_EMPLEADO_3=3,
CASO_RESUELTO=1,CASO_NO_RESUELTO=0,SALIR=-1,SATISFACCION_MINIMA=0,SATISFACCION_MAXIMA=5,NULO=0;

int filtroSalario(){
	int salario_hora;
	do{
		cout<<"Introduzca el salario por hora:\n";	//Filtro de entradad
		cin>>salario_hora;
	}while(salario_hora<=0);
	return salario_hora;
}
	int segundosAtencion(){
		int segundos_atencion;
		do{
				cout<<"Introduzca	los segundos de atencion:\n";
				cin>>segundos_atencion;
			}while(segundos_atencion<NULO);
			return segundos_atencion;
	}
	short casoResuelto(){
		short resuelto;
			do {
				cout<<"Introduzca 1 si el caso se resolvio o 0 si no:\n";
				cin>>resuelto;	
			}while(resuelto!=CASO_RESUELTO && resuelto!=CASO_NO_RESUELTO);	
			return resuelto;
	}
	float satisfaccionEmpleado(){
		float satisfaccion;
		do{
				cout<<"Introduzca el grado de satisfaccion:\n";
				cin>>satisfaccion;
		}while(satisfaccion<SATISFACCION_MINIMA || satisfaccion>SATISFACCION_MAXIMA);		//!(satisfaccion_1>=SATISFACCION_MINIMA && satisfaccion_1<=SATISFACCION_MAXIMA)
		return satisfaccion;	
	}
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

	
	
	salario_hora=filtroSalario();
	cout<<"Introduzca el codigo de empleado:\n";		//Lectura adelantada
	cin>>codigo_empleado;
	while(codigo_empleado!=SALIR){
		/*************EMPLEADO 1*********/
		if(codigo_empleado==CODIGO_EMPLEADO_1){
			cont_empleado1++;
			segundos_atencion_1=segundosAtencion();
			resuelto_1=casoResuelto();
			satisfaccion_1=satisfaccionEmpleado();
			satisfaccion_1=aux_1+satisfaccion_1;
			aux_1=satisfaccion_1;				
		}
		/*********************************/
		/*************EMPLEADO 2*********/
		else if(codigo_empleado==CODIGO_EMPLEADO_2){
			cont_empleado2++;
			segundos_atencion_2=segundosAtencion();
			resuelto_2=casoResuelto();
			satisfaccion_2=satisfaccionEmpleado();
			satisfaccion_2=aux_2+satisfaccion_2;
			aux_2=satisfaccion_2;		
		}
		/*********************************/
		/*************EMPLEADO 3*********/
		else if(codigo_empleado==CODIGO_EMPLEADO_3){
			cont_empleado3++;
			segundos_atencion_3=segundosAtencion();
			resuelto_3=casoResuelto();
			satisfaccion_3=satisfaccionEmpleado();
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
/****************CÁLCULO DE SATISFACCIONES MEDIAS**************/		
	if(cont_empleado1!=NULO)
		media_1=satisfaccion_1/cont_empleado1;
	if(cont_empleado2!=NULO)
		media_2=satisfaccion_2/cont_empleado2;
	if(cont_empleado3!=NULO)
		media_3=satisfaccion_3/cont_empleado3;
/************************************************************/		
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

