#include <iostream>
using namespace std;
const int CAPACIDAD=25;
int main(){
	int v1[CAPACIDAD]={1,3,5,7};
	int util_1=4;
	int v2[CAPACIDAD]={2,3,4,6,8,9};
	int util_2=6;
	//Vamos a crear un vector vr en el que se mezclen v1 y v2
	int i1=0,i2=0;
	int vr[CAPACIDAD];
	int util_r=0;
	int i;
	//i1 apuntará a las posiciones de v1 e i2 a las de v2

	while(i1<util_1&&i2<util_2){
		if(v1[i1]<v2[i2]){
			vr[util_r]=v1[i1];
			i1++;
		}
		else{
			vr[util_r]=v2[i2];
			i2++;
		}
		util_r++;
	}
	if(i1==util_1)
	//Volcamos v2
	for(i=i2;i<util_2;i++){
		vr[util_r]=v2[i];
		util_r++;
	}
	else 
	//Volcamos v1
		for(i=i1;i<util_1;i++){
		vr[util_r]=v1[i];
		util_r++;
	}

	/*Mostramos el vector vr en pantalla*/
	for(i=0;i<util_r;i++)
		cout<<"Posicion "<<i<<": "<<vr[i]<<endl;
}
