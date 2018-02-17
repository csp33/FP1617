#include <iostream>
using namespace std;
class Jugador{
	private:
		static const int LIBRE=1,DOBLE=2,TRIPLE=3;
		int dorsal,tiros_libres,tiros_dobles,tiros_triples;
	public:
		Jugador(){	//Constructor sin parámetros
			dorsal=0;
			tiros_libres=0;
			tiros_dobles=0;
			tiros_triples=0;
		}
		void Set_Jugador(int drsal,int simples,int dobles,int triples){
			dorsal=drsal;
			tiros_libres+=simples;
			tiros_dobles+=dobles;
			tiros_triples+=triples;
		}
		int Get_Puntuacion(){
			return LIBRE*tiros_libres+DOBLE*tiros_dobles+TRIPLE*tiros_triples;
		}
		int Get_Tiros(){
			return tiros_libres+tiros_dobles+tiros_triples;
		}
		/*El siguiente método devuelve un dato distinto dependiendo del parámetro que le pasemos. 
			1: Número de tiros libres
			2: Número de tiros dobles
			3: Número de tiros triples
		*/
		int Get_Dato(int dato){
			int devolver;
			if(dato==LIBRE)
				devolver=tiros_libres;
			else if (dato==DOBLE)
				devolver=tiros_dobles;
			else
				devolver=tiros_triples;
			return devolver;
		}
		int Get_Dorsal(){
			return dorsal;
		}
				
};

const int LIBRE=1,DOBLE=2,TRIPLE=3;
const int MAX_JUG=15,FIN=-1;
const string MSG_DORSAL="Introduzca un dorsal:",MSG_L="Introduzca el numero de tiros libres:",MSG_D="Introduzca el numero de tiros dobles",MSG_T="Introduzca el numero de tiros triples:",
MSG_P_TOTAL="Total de puntos conseguidos por el equipo:",MSG_D_MAX="Dorsal del maximo anotador: ",MSG_P_MAX="Puntos obtenidos: ",MSG_MEDIA_T="Media total del equipo: ",
MSG_SUP="Numero de jugadores con puntuacion superior a la media: ",MSG_MEDIA_L="Media de tiros libres del equipo: ";

int main(){
	Jugador equipo[MAX_JUG];
	int dorsal,libres,dobles,triples;
	int i;
	int jugadores=0;
	
	/*Introducción de jugadores por teclado*/
	
	cout<<MSG_DORSAL<<endl;	//Lectura adelantada
	cin>>dorsal;
	
	for(i=0;i<MAX_JUG&&dorsal!=FIN;i++){
		cout<<MSG_L<<endl;
		cin>>libres;
		cout<<MSG_D<<endl;
		cin>>dobles;
		cout<<MSG_T<<endl;
		cin>>triples;
		equipo[i].Set_Jugador(dorsal,libres,dobles,triples);
		jugadores++;			//Jugadores que se introducen
		cout<<MSG_DORSAL<<endl;
		cin>>dorsal;
	}
	
	/*Cálculo de la puntuación total del equipo*/
	double puntuacion_total=0;
	
	for(i=0;i<jugadores;i++)
		puntuacion_total+=equipo[i].Get_Puntuacion();
	
	cout<<MSG_P_TOTAL<<puntuacion_total<<endl;
	
	/*Cálculo de la media de tiros libres del equipo*/
	double tiros_libres_total=0;
	double media_libres;
	
	for(i=0;i<jugadores;i++)	//Calculamos los tiros libres totales del equipo
		tiros_libres_total+=equipo[i].Get_Dato(LIBRE);
		
	media_libres=tiros_libres_total/jugadores;
	cout<<MSG_MEDIA_L<<media_libres<<endl;
	
	/*Cálculo del máximo puntuador*/
	int dorsal_maximo=equipo[0].Get_Dorsal();
	int puntos_maximo=equipo[0].Get_Puntuacion();
	
	for(i=1;i<jugadores;i++)
		if(equipo[i].Get_Puntuacion()>puntos_maximo){
			puntos_maximo=equipo[i].Get_Puntuacion();
			dorsal_maximo=equipo[i].Get_Dorsal();
		}
		
	cout<<MSG_D_MAX<<dorsal_maximo<<endl;
	cout<<MSG_P_MAX<<puntos_maximo<<endl;
	
	/*Cálculo de la media total del equipo*/
	double media_total;
	
	media_total=puntuacion_total/jugadores;
	cout<<MSG_MEDIA_T<<media_total<<endl;
	
	/*Cálculo del número de jugadores con puntuación superior a la media*/
	int jug_sup=0;
	
	for(i=0;i<jugadores;i++)
		if(equipo[i].Get_Puntuacion()>media_total)
			jug_sup++;
			
	cout<<MSG_SUP<<jug_sup<<endl;
	
}
