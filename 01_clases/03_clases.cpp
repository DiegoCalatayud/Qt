
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;


class Cuenta {

	
	

public:
	
	string numCuenta;
	string titular;
	float saldo;
	void ingresar(float cantidad){
		if (cantidad >= 0)
			saldo += cantidad;
	}
	bool retirar(float cantidad){
		if (cantidad <= saldo){
			saldo -= cantidad;
			return true;
		}
		return false;
	}
	
	Cuenta(){}
	
};

void mostrar(Cuenta c){


	cout << "La cuenta de " << c.titular << " tiene " << c.saldo << " euros " << endl;

};

void procesarIngreso(Cuenta c){

	float cantidad;

	cout << "Introduce la cantidad a ingresar " ;
	cin >> cantidad;
	
	c.ingresar(cantidad);

};

bool procesarRetirada(Cuenta c){

	float cantidad;

	cout << "Introduce la cantidad a retirar " ;
	cin >> cantidad;
	
	return c.retirar(cantidad);

};

int main (int argc,char *argv[]){
	
	Cuenta c1,c2;
	
	c1.titular = "Barbie";
	c2.titular = "Ken";
	
	c1.saldo = 100;
	c2.saldo = 200;
	
	//c1 = c2;
	c2.ingresar(500);
	
	mostrar(c1);
	mostrar(c2);
	
	c1.ingresar(100);
	c1.retirar(2);
	
	mostrar(c1);
	mostrar(c2);
	
	
	procesarIngreso(c1);
	procesarRetirada(c1);
	
	mostrar(c1);
	//cout << "La cuenta de " << c1.titular << " tiene " << c1.saldo << " euros " << endl;
	
	//cout << "La cuenta de " << c2.titular << " tiene " << c2.saldo << " euros " << endl;
	
	
	
}



