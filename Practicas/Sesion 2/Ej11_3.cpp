/* Programa que calcula el �rea del c�rculo y la longitud de la circunferencia correspondiente. Se incluye la declaraci�n de pi como constante*/
#include <iostream>
#include <cmath>
using namespace std;
int main () {
	float radio,area,longitud;
	const float PI=3.1416; //Declaramos el n�mero pi como constante por si queremos tomar un valor m�s aproximado
	cout <<"Introduzca la longitud del radio en metros:\n";
	cin >> radio;
	area=PI*pow(radio,2); //Usamos la funci�n pow para elevar el radio al cuadrado
	longitud=2*PI*radio;
	cout<<"La longitud de la circunferencia con un radio de "<<radio<<" metros es de "<<longitud<<" metros \ny su area es de "<<area<<" metros cuadrados."; //Mostramos el resultado en pantalla
}
