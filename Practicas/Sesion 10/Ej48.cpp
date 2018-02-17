/* Ejercicio 48. Clase circunferencia */
#include <iostream>
#include <cmath>
using namespace std;

const string MSG_CENTRO_1="Introduzca la coordenada X del centro de la circuferencia",MSG_CENTRO_2="Introduzca la coordenada Y del centro de la circuferencia",
MSG_RADIO="Introduzca el radio de la circunferencia",MSG_PUNTO_1="Introduzca la coordenada X del punto",
MSG_PUNTO_2="Introduzca la coordenada Y del punto",DENTRO="El punto pertenece a la circunferencia",FUERA="El punto no pertenece a la circunferencia.",
LONGITUD="La longitud de la circunferencia es de ",AREA="El area de la circunferencia es de ",UD=" unidades.",UD_CUAD=" unidades cuadradas.";

const int VALOR_INICIAL=0,DOBLE=2,UNO=1;
const int CUADRADO=2; 
const double PI=3.14159265359;

struct CoordenadasPunto2D{
	double abscisa;
	double ordenada;
};
 
class Circunferencia{
	private:
		CoordenadasPunto2D centro;
		double radio;
	public:
		Circunferencia(){		//Constructor por defecto
			centro.abscisa=VALOR_INICIAL;
			centro.ordenada=VALOR_INICIAL;
			radio=UNO;
		}
		Circunferencia(double x,double y,double r){	//Constructor con parámetros
			SetValores(x,y,r);
		}
		void SetValores(double x,double y,double r){
			centro.abscisa=x;
			centro.ordenada=y;
			radio=r;
		}
		double Get_abscisa(){
			return centro.abscisa;
		}
		double Get_ordenada(){
			return centro.ordenada;
		}
		double Get_radio(){
			return radio;
		}
		void Set_abscisa(double x){
			centro.abscisa=x;
		}
		void Set_ordenada(double y){
			centro.ordenada=y;
		}
		void Set_radio(double r){
			radio=r;
		}
		double Longitud(){
			double longitud;
			longitud=DOBLE*PI*radio;
			return longitud;
		}
		double Area(){
			double area;
			area=PI*pow(radio,CUADRADO);
			return area;
		}
		bool ContieneAlPunto(CoordenadasPunto2D punto){
			bool contiene;
			contiene=pow(centro.abscisa-punto.abscisa,CUADRADO)+pow(centro.ordenada-punto.ordenada,CUADRADO)<=pow(radio,CUADRADO);
			return contiene;
		}
};
double leeReal(string msg){
	double numero;
	cout<<msg<<endl;
	cin>>numero;
	return numero;
}
int main(){
	double centro_x,centro_y,radio; //Variables de entrada
	double punto_x,punto_y;
	CoordenadasPunto2D punto;
	double longitud,area;			//Variables de salida
	bool esta_dentro;
	
	/***Definición de la circunferencia y cálculos***/
	centro_x=leeReal(MSG_CENTRO_1);
	centro_y=leeReal(MSG_CENTRO_2);
	radio=leeReal(MSG_RADIO);
	Circunferencia circ(centro_x,centro_y,radio);
	
	longitud=circ.Longitud();
	area=circ.Area();
	/***Introducción del punto***/
	punto_x=leeReal(MSG_PUNTO_1);
	punto_y=leeReal(MSG_PUNTO_2);
	punto.abscisa=punto_x;
	punto.ordenada=punto_y;
	esta_dentro=circ.ContieneAlPunto(punto);
	
	cout<<AREA<<area<<UD_CUAD<<endl;
	cout<<LONGITUD<<longitud<<UD<<endl;
	
	if(esta_dentro)
		cout<<DENTRO<<endl;
	else
		cout<<FUERA<<endl;
}
