#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

class Complejo {
public:
	float real;
	float imag;
	
	void mostrar(){
		cout << (" ( ") << real << " + " << imag << "i )"<<endl;
	}
	
	float modulo(){
		return sqrtf ( powf(real,2)+powf(imag,2) );
	}
	
	Complejo  operator+( Complejo n2){

	Complejo comFin;
	comFin.real = real+(n2.real);
	comFin.imag = imag+(n2.imag);
	
	return comFin;

	}
	
	Complejo  operator+( int n2){

	
	Complejo comFin;
	comFin.real = real+n2;
	comFin.imag = imag;
	
	return comFin;

	}
	bool operator> (Complejo n2){
		
		Complejo este;
		este.real = real;
		este.imag = imag;

		return este.modulo()>n2.modulo();

	}	
	bool operator< (Complejo n2){
		
		Complejo este;
		este.real = real;
		este.imag = imag;

		return este.modulo()<n2.modulo();

	}	
};

/*Complejo  sumaComplejo(Complejo n1, Complejo n2){

	Complejo comFin;
	comFin.real = (n1.real)+(n2.real);
	comFin.imag = (n1.imag)+(n2.imag);
	
	return comFin;

}*/
/*
Complejo  operator+(Complejo n1, Complejo n2){

	Complejo comFin;
	comFin.real = (n1.real)+(n2.real);
	comFin.imag = (n1.imag)+(n2.imag);
	
	return comFin;

}*/

Complejo  operator+(int n1, Complejo n2){

	Complejo comFin;
	comFin.real = n1 + (n2.real);
	comFin.imag = n2.imag;
	comFin.mostrar();
	return comFin;

}
/*
Complejo  operator+(Complejo n1, int n2){
	
	return n2 + n1;

}*/
/*
bool operator> (Complejo n1, Complejo n2){

	return n1.modulo()>n2.modulo();

}*/
/*
bool operator< (Complejo n1, Complejo n2){

	return n1.modulo()<n2.modulo();

}*/

int main(int argc, char*argv[]){

	Complejo i,j,o;
	
	i.real = 8;
	i.imag =9;
	
	j.real = 2;
	j.imag=4;
	
	j.mostrar();
	i.mostrar();
	
	//o = sumaComplejo(i,j);
	 //(i+j).mostrar();
	
	//o.mostrar();
	//o=10+j;
	
	//o.mostrar();
	//o=i+10;
	
	//o.mostrar();
	
	cout << "suma"; (i+j).mostrar(); cout << endl;
	cout << "suma entero"; (i+10).mostrar(); cout << endl;
	cout << "boleano1 " << (i<j) << endl;
	cout << "boleano2 " << (i<j) << endl;;
	
	
	
}
