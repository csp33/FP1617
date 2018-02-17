//NOMBRE: Carlos Sánchez Páez, DNI ------------
//PROBLEMA: tramos
#include <iostream>
using namespace std;
//Declaración de constantes:
const char EMPRESA_1='U',EMPRESA_2='R',EMPRESA_3='V';
const char FIN='Q';
const int NULO=0;
const int COTA_INF_SEG=0,COTA_SUP_SEG=59;
const int TRAMO_1_SUP=60,TRAMO_2_SUP=900,TRAMO_3_SUP=3600;
const int CONV=60;
const float ESTABLECIMIENTO=0.3;
const float PRECIO_TRAMO_1=0.025,PRECIO_TRAMO_2=0.01,PRECIO_TRAMO_3=0.007,PRECIO_TRAMO_4=0.001;
const string MSG_MIN="Introduzca los minutos:",MSG_SEG="Introduzca los segundos:",MSG_EMPRESA="Introduzca la empresa:",MSG_ERROR="No se ha introducido ningun dato.",moneda=" euros.";


double Max(double n1,double n2){ //Maximo de dos valores
	double maximo;
	if(n1>n2)
		maximo=n1;
	else
		maximo=n2;
	return maximo;
}
double Max3(double n1,double n2,double n3){ //Maximo de tres valores (usando la funcion anterior)
	double maximo;
	maximo=Max(Max(n1,n2),n3);
	return maximo;
}

double calculaPrecio(int segundos){
	double facturacion_empresa;
	facturacion_empresa+=ESTABLECIMIENTO;
	if(segundos>=TRAMO_1_SUP)					//Mas de tramo 1
		facturacion_empresa+=TRAMO_1_SUP*PRECIO_TRAMO_1;
	else 												//Pertenecen a tramo 1
		facturacion_empresa+=segundos*PRECIO_TRAMO_1;
	segundos-=TRAMO_1_SUP;		
	if(segundos<TRAMO_2_SUP) 					//Pertenecen a tramo 2
		facturacion_empresa+=segundos*PRECIO_TRAMO_2;
	else												//Mas de tramo 2
		facturacion_empresa+=TRAMO_2_SUP*PRECIO_TRAMO_2;
	segundos-=TRAMO_2_SUP;		
	if(segundos>TRAMO_2_SUP)					//Pertenecen a tramo 3
		facturacion_empresa+=segundos*PRECIO_TRAMO_3;
	segundos-=TRAMO_3_SUP;
	if(segundos>NULO)								//Si hay algún segundo que entre en el último tramo
		facturacion_empresa+=segundos*PRECIO_TRAMO_4;
	return facturacion_empresa;
}
char leeCaracterFiltro(string mensaje,char valor1,char valor2,char valor3,char valor4){
	char caracter;
	do{
		cout<<mensaje<<endl;
		cin>>caracter;
		caracter=toupper(caracter);
	}while(caracter!=valor1&&caracter!=valor2&&caracter!=valor3&&caracter!=valor4); 
	return caracter;
}
int leePositivo(string mensaje){
	int numero;
	do{
		cout<<mensaje<<endl;
		cin>>numero;
	}while(numero<NULO);
	return numero;
}
int leeIntRango(string mensaje,int cota_inf,int cota_sup){
	int numero;
	do{
		cout<<mensaje<<endl;
		cin>>numero;
	}while(numero<cota_inf || numero>cota_sup);
	return numero;
}
	
int main(){
	char empresa;								//Variables de entrada
	int minutos,segundos;
	bool algun_dato=false;   				//Variable para indicar si entramos al bucle.
	double facturacion_total,facturacion_empresa_1=0,facturacion_empresa_2=0,facturacion_empresa_3=0,facturacion_mayor; //Variables de salida. 
																																								//Inicializo a 0 por si no introducimos alguna empresa
	
	empresa=leeCaracterFiltro(MSG_EMPRESA,EMPRESA_1,EMPRESA_2,EMPRESA_3,FIN);	//Lectura adelantada
	while(empresa!=FIN){
		algun_dato=true;			
		minutos=leePositivo(MSG_MIN);
		segundos=leeIntRango(MSG_SEG,COTA_INF_SEG,COTA_SUP_SEG);
		segundos+=minutos*CONV;
		if(empresa==EMPRESA_1)
			facturacion_empresa_1=calculaPrecio(segundos);
		else if (empresa==EMPRESA_2)
			facturacion_empresa_2=calculaPrecio(segundos);
		else
			facturacion_empresa_3=calculaPrecio(segundos);			
		empresa=leeCaracterFiltro(MSG_EMPRESA,EMPRESA_1,EMPRESA_2,EMPRESA_3,FIN);	
	}
	if(algun_dato){
		facturacion_total=facturacion_empresa_1+facturacion_empresa_2+facturacion_empresa_3; //Cálculos dentro del if para no tener que realizarlos si no se introduce ningún dato.
		facturacion_mayor=Max3(facturacion_empresa_1,facturacion_empresa_2,facturacion_empresa_3);
		cout<<"La facturacion total ha sido de "<<facturacion_total<<moneda<<endl;
		cout<<"La empresa "<<EMPRESA_1<<" ha facturado "<<facturacion_empresa_1<<moneda<<endl;
		cout<<"La empresa "<<EMPRESA_2<<" ha facturado "<<facturacion_empresa_2<<moneda<<endl;
		cout<<"La empresa "<<EMPRESA_3<<" ha facturado "<<facturacion_empresa_3<<moneda<<endl;
		cout<<"La maxima factura ha sido de "<<facturacion_mayor<<moneda<<endl;
	}
	else
		cout<<endl<<MSG_ERROR<<endl;
}


