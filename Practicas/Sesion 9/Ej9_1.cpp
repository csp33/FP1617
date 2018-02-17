/* Ejercicio Recta */
#include <iostream>
using namespace std;
const string COEF_1="Introduzca el coeficiente A:",COEF_2="Introduzca el coeficiente B:",COEF_3="Introduzca el coeficiente C:",RECTA="La recta viene definida por Ax+By+C=0",
RECTA_1="Introduccion de parametros de la recta 1:",RECTA_2="Introduccion de parametros de la recta 2:";
const int CAMBIA_SIGNO=-1,CERO=0;
class Recta{
	public:
		double a,b,c;
};
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
	cout<<RECTA<<endl;
	leeCoeficientes(a_1,b_1,c_1,COEF_1,COEF_2,COEF_3,RECTA_1);
	leeCoeficientes(a_2,b_2,c_2,COEF_1,COEF_2,COEF_3,RECTA_2);
	
	Recta recta_1,recta_2;	//Definimos los objetos y asignamos sus valores.
	
	recta_1.a=a_1;
	recta_1.b=b_1;
	recta_1.c=c_1;
	
	recta_2.a=a_2;
	recta_2.b=b_2;
	recta_2.c=c_2;
	
	double pendiente_1,pendiente_2;		//Declaramos y calculamos las pendientes
	if(recta_1.b!=CERO){
		pendiente_1=CAMBIA_SIGNO*recta_1.a/recta_1.b;
		cout<<"La pendiente de la recta 1 es "<<pendiente_1<<endl;
	}
	else 
		cout<<"La pendiente de la recta 1 no se puede calcular"<<endl;
	
	if(recta_2.b!=CERO){
		pendiente_2=CAMBIA_SIGNO*recta_2.a/recta_2.b;
		cout<<"La pendiente de la recta 2 es "<<pendiente_2<<endl;
	}
	else
		cout<<"La pendiente de la recta 2 no se puede calcular"<<endl;

	
}
