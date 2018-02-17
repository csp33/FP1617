/* Programa que emula una máquina expendedora de bebidas etc. dado un precio y un importe introducido
 calcula la vuelta a devolver en el menor número de monedas de 1euro, 50, 20,10 y 5 ctms.
 version 2. cambio correcto con double (con float) no funciona!!! */

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
const int EURO = 100;
const int CTM50 = 50;
const int CTM20 = 20;
const int CTM10 = 10;
const int CTM5 = 5;

double precio, pago, vueltaReal;

int vueltaEntera, contEuro, contCtm50, contCtm20, contCtm10, contCtm5;
contEuro = contCtm50 = contCtm20 = contCtm10 = contCtm5 = 0;

cout << "Introduzca el precio del articulo: ";
cin >> precio;
cout << "Introduzca el importe :\n(Se admiten 1euro, 50ctm, 20ctm,10ctm, 5ctm) ";
cin >> pago;
if (pago>precio){  //Hay que dar vuelta
	vueltaReal = pago - precio;  // calculo de vuelta total
	contEuro = vueltaReal;
	vueltaEntera = (vueltaReal - contEuro) * EURO; // quitanto los euros
	contCtm50 = vueltaEntera / CTM50;
	vueltaEntera = vueltaEntera % CTM50;
	contCtm20 = vueltaEntera / CTM20;
	vueltaEntera = vueltaEntera % CTM20;
	contCtm10 = vueltaEntera / CTM10;
	vueltaEntera = vueltaEntera % CTM10;
	contCtm5 = vueltaEntera / CTM5;
	vueltaEntera = vueltaEntera % CTM5;
	cout << "Su vuelta :\n"<< contEuro << " Euros,\n" <<  contCtm50 << " monedas de 50ctm,\n" << contCtm20 << 
	" monedas de 20ctm,\n" << contCtm10 << " monedas de 10ctm,\n"<< contCtm5 << " monedas de 5ctm"<< endl;
}
else { //No hay que dar vuelta
	if (pago<precio)
	cout<<"Dinero insuficiente\n";
}
cout << "Gracias "<< endl;
cout<<contEuro*1+contCtm50*0.5+contCtm20*0.2+contCtm10*0.1+contCtm5*0.05;
}

 
