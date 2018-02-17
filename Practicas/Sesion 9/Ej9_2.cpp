/* Ejercicio Recta */
#include <iostream>
using namespace std;
const string COEF_1="Introduzca el coeficiente A:",COEF_2="Introduzca el coeficiente B:",COEF_3="Introduzca el coeficiente C:",RECTA="La recta viene definida por Ax+By+C=0",
RECTA_1="Introduccion de parametros de la recta 1:",RECTA_2="Introduccion de parametros de la recta 2:",ABSCISA="Introduzca un valor de abscisa:",ORDENADA="Introduzca un valor de ordenada:",
R_1="Recta 1:",R_2="Recta 2:";
const int CAMBIA_SIGNO=-1,CERO=0;
class Recta{
	public:
		double a,b,c;
	double calculaPendiente(){	/*Pendiente no se añade como dato miembro ya que si actualizamos los datos de la recta, la pendiente será errónea. 
									Al ser una función, tendremos que calcularla forzosamente cada vez que queramos usarla.  */
		double pendiente;
		pendiente=CAMBIA_SIGNO*a/b;
		return pendiente;
	}
	double calculaOrdenada(double x){
		double ordenada;
		ordenada=(CAMBIA_SIGNO*c-x*a)/b;
		return ordenada;
	}
	double calculaAbscisa(double y){
		double abscisa;
		abscisa=(CAMBIA_SIGNO*c-y*b)/a;
		return abscisa;
	}
};
double leeReal(string msg,string recta){
	cout<<recta<<endl;
	double numero;
	cout<<msg<<endl;
	cin>>numero;
	return numero;
}
double leeCoeficientes(double &a,double &b,double &c,string coef_1,string coef_2,string coef_3,string recta){
	cout<<recta<<endl;
	cout<<coef_1<<endl;
	cin>>a;
	cout<<coef_2<<endl;
	cin>>b;
	cout<<coef_3<<endl;
	cin>>c;
}
int main (){
	double a_1,b_1,c_1;		//Coeficientes de la recta 1
	double a_2,b_2,c_2;		//Coeficientes de la recta 2

	/******Lectura de los datos de la recta******/	
	cout<<RECTA<<endl;
	leeCoeficientes(a_1,b_1,c_1,COEF_1,COEF_2,COEF_3,RECTA_1);
	leeCoeficientes(a_2,b_2,c_2,COEF_1,COEF_2,COEF_3,RECTA_2);
	
	/*****Definición de objetos y asignación de valores*****/
	Recta recta_1,recta_2;
	
	recta_1.a=a_1;
	recta_1.b=b_1;
	recta_1.c=c_1;
	
	recta_2.a=a_2;
	recta_2.b=b_2;
	recta_2.c=c_2;
	
	double pendiente_1,pendiente_2;	
	double abscisa_introducida,ordenada_introducida;
	double abscisa_calculada,ordenada_calculada;	
			/****RECTA 1****/
	if(recta_1.b!=CERO){
		/****Cálculo de la pendiente****/
		pendiente_1=recta_1.calculaPendiente();
		cout<<"La pendiente de la recta 1 es "<<pendiente_1<<endl;
		/******Cálculo de ordenada a partir de la abscisa******/
		abscisa_introducida=leeReal(ABSCISA,R_1);
		ordenada_calculada=recta_1.calculaOrdenada(abscisa_introducida);
		cout<<"La ordenada de la abscisa "<<abscisa_introducida<<" es "<<ordenada_calculada<<endl;
	}
	else{
		cout<<"La pendiente de la recta 1 no se puede calcular"<<endl;
		cout<<"No se puede calcular una ordenada a partir de una abscisa en la recta 1"<<endl;
	}
		/******Cálculo de abscisa a partir de la ordenada******/
	if(recta_1.a!=CERO){
		ordenada_introducida=leeReal(ORDENADA,R_1);
		abscisa_calculada=recta_1.calculaAbscisa(ordenada_introducida);
		cout<<"La abscisa de la ordenada "<<ordenada_introducida<<" es "<<abscisa_calculada<<endl;
	}
	else
		cout<<"No se puede calcular una abscisa a partir de una ordenada en la recta 1"<<endl;
		
			/****RECTA 2****/
	if(recta_2.b!=CERO){
			/****Cálculo de la pendiente****/
		pendiente_2=recta_2.calculaPendiente();
		cout<<"La pendiente de la recta 2 es "<<pendiente_2<<endl;
	}
	else
		cout<<"La pendiente de la recta 2 no se puede calcular"<<endl;
}
