#include <iostream>
using namespace std;
int main () {
	int dorsal,puntos,puntos_equipo1=0,puntos_equipo2=0;
	bool gana_equipo_1,gana_equipo_2,empate;
	string cadena="";
	int contador=0;
	const int FIN=-1,DORSAL_1_EQ1=1,DORSAL_2_EQ1=2,DORSAL_3_EQ1=3,DORSAL_1_EQ2=8,DORSAL_2_EQ2=10,DORSAL_3_EQ2=12;
	do{
		cout<<"Introduzca un dorsal:\n";
		cin>>dorsal;
	}while(dorsal!=FIN && dorsal!=DORSAL_1_EQ1 && dorsal!=DORSAL_2_EQ1 && dorsal!=DORSAL_3_EQ1 && dorsal!=DORSAL_1_EQ2 && dorsal!=DORSAL_2_EQ2 && dorsal!=DORSAL_3_EQ2) ;            
	while(dorsal!=FIN){
		contador++;
		do{
			cout<<"Introduzca el numero de puntos (1,2 o 3)\n";
			cin>>puntos;
			}while(puntos<1 || puntos>3); //!(puntos>=1 && puntos<=3)
		if(dorsal==DORSAL_1_EQ1 || dorsal==DORSAL_2_EQ1 || dorsal==DORSAL_3_EQ1) //Si es del equipo 1
			puntos_equipo1+=puntos;
		else
			puntos_equipo2+=puntos; //puntos_equipo2=puntos_equipo2+puntos
		do{
			cout<<"Introduzca un dorsal:\n";
			cin>>dorsal;
		}while(dorsal!=FIN && dorsal!=DORSAL_1_EQ1 && dorsal!=DORSAL_2_EQ1 && dorsal!=DORSAL_3_EQ1 && dorsal!=DORSAL_1_EQ2 && dorsal!=DORSAL_2_EQ2 && dorsal!=DORSAL_3_EQ2) ;  
		}
	cout<<"\nFin del programa.\n";
	if(contador!=0){
		gana_equipo_1=puntos_equipo1>puntos_equipo2;
		gana_equipo_2=puntos_equipo1<puntos_equipo2;
		empate=puntos_equipo1==puntos_equipo2;
		if(gana_equipo_1)
			cadena="\nGana el equipo 1!!\n";
		else if (gana_equipo_2)
			cadena="\nGana el equipo 2!!\n";
		else
			cadena="\nEMPATE!\n";
	}
	cout<<cadena;
}

