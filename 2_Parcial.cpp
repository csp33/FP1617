//NOMBRE: CARLOS,SANCHEZ PAEZ
//DNI: -------------
//PROBLEMA: llamada
#include <iostream>
#include <cmath>
using namespace std;
struct Tiempo{	//Con este tipo de dato compuesto ahorramos declarar tantas variables, haciendo el código más sencillo y legible.
	int horas;
	int min;
	int seg;	
};
class Llamada{
	private:
		static const int NULO=0;
		static const int CONV=60;	//Factor de conversión
		static const int COTA_INTERNA=100;	
		Tiempo inicio;
		Tiempo fin;
		int emisor;
		int receptor;
		bool interna;
		int Calcula_Segundos(int h,int m,int s){	//Método privado que convierte del formato hh:mm:ss a segundos.
			int seg;
			seg=h*CONV*CONV+m*CONV+s;
			return seg;
		}
	public:	
		Llamada(){	//Constructor sin parámetros. Inicializamos todo a 0
			inicio.horas=0;
			inicio.min=0;
			inicio.seg=0;
			fin.horas=0;
			fin.min=0;
			fin.seg=0;
			emisor=0;
			receptor=0;
			interna=false;
		}
		Llamada(int h_inicio,int m_inicio,int s_inicio, int h_fin, int m_fin, int s_fin,int _emisor,int _receptor){	//Constructor con parámetros
			inicio.horas=h_inicio;
			inicio.min=m_inicio;
			inicio.seg=s_inicio;
			fin.horas=h_fin;
			fin.min=m_fin;
			fin.seg=s_fin;	
			emisor=_emisor;
			receptor=_receptor;
			interna=fabs(emisor-receptor)<=COTA_INTERNA;
		}
		void Set_parametros(int h_inicio,int m_inicio,int s_inicio, int h_fin, int m_fin, int s_fin,int _emisor,int _receptor){
			//Método que inicializa los datos miembro de un objeto a los valores que se le pasen como parámetros. Además, evalúa si la llamada es interna.
			inicio.horas=h_inicio;
			inicio.min=m_inicio;
			inicio.seg=s_inicio;
			fin.horas=h_fin;
			fin.min=m_fin;
			fin.seg=s_fin;	
			emisor=_emisor;
			receptor=_receptor;
			interna=fabs(emisor-receptor)<=COTA_INTERNA;
		}
		int Get_Duracion(){	//Duración de cada llamada
			int seg_inicio,seg_fin,duracion;
			seg_inicio=Calcula_Segundos(inicio.horas,inicio.min,inicio.seg);
			seg_fin=Calcula_Segundos(fin.horas,fin.min,fin.seg);
			duracion=seg_fin-seg_inicio;
			return duracion;
		}
		int Get_Emisor(){		//Número del emisor
			return emisor;
		}
		int Get_Receptor(){	//Número del receptor
			return receptor;
		}
		int Get_Hora_Inicio(){	//Hora a la que comienza la llamada
			return inicio.horas;
		}
		int Get_Min_Inicio(){	//Minutos en los que comienza la llamada
			return inicio.min;
		}
		int Get_Seg_Inicio(){	//Segundos en los que comienza la llamada
			return inicio.seg;
		}
		int Get_Hora_Fin(){		//Hora a la que termina la llamada
			return fin.horas;
		}
		bool Es_Interna(){	//Condición de llamada interna
			return interna;	
		}
		bool En_Tramo(int INICIO, int FIN){
			bool en_tramo;
			//Dos posibilidades: 
			//1.-Que la hora sea la cota inferior (en ese caso no nos importa el valor de los minutos ni de los segundos).
			//2.- Que la hora sea la cota superior, por lo que tenemos que comprobar que minutos y segundos sean 0.
			en_tramo=inicio.horas==INICIO || inicio.horas==FIN && 
						inicio.min==NULO && inicio.seg==NULO;	
			return en_tramo;
	}
};
	/*****************************DECLARACIÓN DE CONSTANTES************************************/
	
/**Enteros**/

const int MAX_LLAMADAS=100,FIN=-1,NULO=0;
const int COTA_HORA_INICIO=9,COTA_HORA_FIN=10;

/**Mensajes**/

const string MSG_IN="Introduzca horas, minutos y segundos del inicio de la llamada:",
MSG_FIN="Introduzca horas, minutos y segundos del fin de la llamada:",MSG_EM="Introduzca el numero del emisor:",
MSG_REC="Introduzca el numero del receptor:",MSG_TOT="Tiempo total (segundos):",MSG_MED="Duracion media:",
MSG_INT="Numero de llamadas internas:",MSG_SUP="Numero de llamadas que superan la media:",
MSG_MAY="Duracion de la llamada mas larga:",MSG_EM_MAY="Emisor de la llamada mas larga:",
MSG_REC_MAY="Receptor de la llamada mas larga:",MSG_TRAM="Numero de llamadas en el tramo ",DOS_PUNTOS=":",GUION="-";

	/**********************************************************************************/

int main(){
	
	/*****************************DECLARACIÓN DE VARIABLES************************************/

	Llamada central[MAX_LLAMADAS];	//Declaramos un vector de objetos-
	int util=0;								//Como lo hemos sobredimensionado, necesitamos una variable que nos indique los datos útiles.
	int h_inicio, m_inicio, s_inicio, h_fin, m_fin, s_fin;	//Variables de entrada
	int emisor,receptor;
	int i;									//Variable contador. 
	int duracion_total=0;
	int media;
	int numero_internas=0;
	int superan_media=0;
	int duracion_mayor;
	int emisor_llamada_mayor;
	int receptor_llamada_mayor;
	int llamadas_tramo=0;
	bool en_tramo;		

	/**********************************************************************************/

	/*****************************INTRODUCCIÓN DE DATOS************************************/
	
	cout<<MSG_EM<<endl;	//Lectura adelantada
	cin>>emisor;
	
	while(emisor!=FIN){
		//Leemos las variables mediante el teclado.
		cout<<MSG_REC<<endl;
		cin>>receptor;
		cout<<MSG_IN<<endl;
		cin>>h_inicio>>m_inicio>>s_inicio;
		cout<<MSG_FIN<<endl;
		cin>>h_fin>>m_fin>>s_fin;
		//Insertamos los valores en el vector de objetos y aumentamos su capacidad útil.
		central[util].Set_parametros(h_inicio, m_inicio, s_inicio, h_fin, m_fin, s_fin,emisor,receptor);
		util++;
		cout<<MSG_EM<<endl;
		cin>>emisor;	
	}
	
	/**********************************************************************************/

		
	/*****************************CÁLCULOS*************************************************/
	
	/*Cálculo del tiempo total de las llamadas*/

	for(i=0;i<util;i++){
		duracion_total+=central[i].Get_Duracion();
	}
	
	/*Cálculo de la duración media de las llamadas*/
	
	media=duracion_total/util;
	
	/*Cálculo del número de llamadas internas*/

	for(i=0;i<util;i++)
		if(central[i].Es_Interna())
			numero_internas++;
			
	/*Cálculo del número de llamadas que superan la media*/

	for(i=0;i<util;i++)
		if(central[i].Get_Duracion()>media)
			superan_media++;
			
	/*Cálculo de la duración de la llamada más larga, así como su emisor y su receptor*/

	
	duracion_mayor=central[0].Get_Duracion();				//Inicializamos los parámetros a los del primer objeto 
	emisor_llamada_mayor=central[0].Get_Emisor(); 		//y comparamos con el resto. Si encontramos un objeto 
	receptor_llamada_mayor=central[0].Get_Receptor(); //con mayor duración, almacenamos sus parámetros.
	
	for(i=1;i<util;i++)	//Como ya hemos inicializado los datos al objeto de la posición 0, comenzamos en la 1
		if(central[i].Get_Duracion()>duracion_mayor){
			duracion_mayor=central[i].Get_Duracion();
			emisor_llamada_mayor=central[i].Get_Emisor();
			receptor_llamada_mayor=central[i].Get_Receptor();
	}
	
	/*Cálculo de las llamadas entre dos tramos indicados*/	

	for(i=0;i<util;i++){
		if(central[i].En_Tramo(COTA_HORA_INICIO,COTA_HORA_FIN))
			llamadas_tramo++;
		}
		
	/**********************************************************************************/

	/*****************************SALIDA DEL PROGRAMA************************************/
	
		cout<<MSG_TOT<<duracion_total<<endl;
		cout<<MSG_MED<<media<<endl;
		cout<<MSG_INT<<numero_internas<<endl;
		cout<<MSG_SUP<<superan_media<<endl;
		cout<<MSG_MAY<<duracion_mayor<<endl;
		cout<<MSG_EM_MAY<<emisor_llamada_mayor<<endl;
		cout<<MSG_REC_MAY<<receptor_llamada_mayor<<endl;
		cout<<MSG_TRAM<<COTA_HORA_INICIO<<GUION<<COTA_HORA_FIN<<DOS_PUNTOS<<llamadas_tramo<<endl;
		
	/**********************************************************************************/

		
}
