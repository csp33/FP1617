#include <iostream>
using namespace std;
int main (){
	int filas, columnas;
	for(columnas=0;columnas<5;columnas++){
		for(filas=0;filas<5;filas++){
			if(columnas==0||columnas==4||filas==0||filas==4)
				cout<<"*";
			else
				cout<<" ";
			}
			cout<<endl;
		}
	}

