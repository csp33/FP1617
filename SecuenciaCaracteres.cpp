/*Secuencia de Caracteres. Vector en una clase*/
#include <iostream>
using namespace std;
class SecuenciaCaracteres{
	private:
		static const int CAPACIDAD=100;
		char vector_privado[CAPACIDAD];
		int util;
	public:
		SecuenciaCaracteres(){
			util=0;
		}
		int Utilizados(){
			return util;
		}
		void Aniade(char elemento){
			if(util<CAPACIDAD){
				vector_privado[util]=elemento;
				util++;
				}
			}
		int Buscar(char elemento){
			int i,posicion=-1;
			for(i=0;i<util&&vector_privado[i]!=elemento;i++)
				;
			if(i<util)
				posicion=i;
			return posicion;
		}
		char Elemento(int pos){
			return vector_privado[pos];
		}
		void BorrarTodosIgual(char elemento){
			int posicion,i;
			posicion=Buscar(elemento);	//Lectura adelantada
			while(posicion!=-1){			//Si la posicion es -1, ya se habrán borrado todos los elementos
				for(i=posicion;i<util-1;i++)	//Reemplazamos cada elemento con su siguiente y decrementamos el valor de util.
					vector_privado[i]=vector_privado[i+1];
				util--;
				posicion=Buscar(elemento);	

			}
		}
};
const int TOPE=10;
const string MSG_RELLENAR="Introduzca valores para rellenar el vector (hasta un maximo de 10).",MSG_MOSTRAR="Mostrando el contenido del vector:",MSG_BORRAR="Introduzca el elemento a borrar del vector:";
int main(){
	SecuenciaCaracteres cadena;
	int i;
	char ch,borrado;
	/**Llenar el vector**/
	cout<<MSG_RELLENAR<<endl;
	for(i=0;i<TOPE;i++){
		ch=cin.get();
		cadena.Aniade(ch);
	}
	/**Mostrar el vector**/
	cout<<MSG_MOSTRAR<<endl;
	for(i=0;i<cadena.Utilizados();i++){
		cout<<"Posicion "<<i<<": "<<cadena.Elemento(i)<<endl;
	}
	/**Borrar caracteres**/
	cout<<MSG_BORRAR<<endl;
	cin>>borrado;
	cadena.BorrarTodosIgual(borrado);
	/**Mostrar el vector**/
	cout<<MSG_MOSTRAR<<endl;
	for(i=0;i<cadena.Utilizados();i++){
		cout<<"Posicion "<<i<<": "<<cadena.Elemento(i)<<endl;
	}
}
