/*Ejercicio 4. Vectores*/
#include <iostream>
using namespace std;
struct FrecuenciaCaracter{
	char caracter;
	int frecuencia=0;
};
const int CAPACIDAD=100000;
const char FIN='#';
int main(){
	char caracteres[CAPACIDAD];
	char caracter_actual;
	FrecuenciaCaracter a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	int cont;
	char moda;
	/*Leo los caracteres y almaceno la frecuencia de cada uno*/
	for(cont=0;cont<CAPACIDAD&&caracter_actual!=FIN;cont++){
		caracter_actual=cin.get();
		caracter_actual=tolower(caracter_actual);
		if(caracter_actual=='a')
			a.frecuencia++;
		else if (caracter_actual=='b')
			b.frecuencia++;
		else if (caracter_actual=='c')
			c.frecuencia++;
		else if (caracter_actual=='d')
			d.frecuencia++;
		else if (caracter_actual=='e')
			e.frecuencia++;
		else if (caracter_actual=='f')
			f.frecuencia++;
		else if (caracter_actual=='g')
			g.frecuencia++;
		else if (caracter_actual=='h')
			h.frecuencia++;
		else if (caracter_actual=='i')
			i.frecuencia++;
		else if (caracter_actual=='j')
			j.frecuencia++;
		else if (caracter_actual=='k')
			k.frecuencia++;
		else if (caracter_actual=='l')
			l.frecuencia++;
		else if (caracter_actual=='m')
			m.frecuencia++;		
		else if (caracter_actual=='n')
			n.frecuencia++;
		else if (caracter_actual=='o')
			o.frecuencia++;
		else if (caracter_actual=='p')
			p.frecuencia++;
		else if (caracter_actual=='q')
			q.frecuencia++;
		else if (caracter_actual=='r')
			r.frecuencia++;
		else if (caracter_actual=='s')
			s.frecuencia++;
		else if (caracter_actual=='t')
			t.frecuencia++;
		else if (caracter_actual=='u')
			u.frecuencia++;
		else if (caracter_actual=='v')
			v.frecuencia++;	
		else if (caracter_actual=='w')
			w.frecuencia++;
		else if (caracter_actual=='x')
			x.frecuencia++;
		else if (caracter_actual=='y')
			y.frecuencia++;
		else if (caracter_actual=='z')
			z.frecuencia++;				
	}
	/*Comparo para ver que frecuencia es la mayor*/

	
}
