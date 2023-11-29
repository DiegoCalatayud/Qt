
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;


class Cuenta {

	
	

public:
	
	string numCuenta;
	string titular;
	float saldo;
	
	Cuenta(){}
	Cuenta( string tit, string num, float saldoIn = 0.00f):numCuenta(num), titular(tit) ,saldo(saldoIn) {
		
	}
	
	
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
	
	void transferir(Cuenta * destino){
		destino->ingresar(saldo);
		retirar(saldo);
	}
	

	

	
};

void mostrar(Cuenta c){


	cout << "La cuenta de " << c.titular << " tiene " << c.saldo << " euros " << endl;

};

void procesarIngreso(Cuenta * pc){
	
	float cantidad;

	cout << "Introduce la cantidad a ingresar " ;
	cin >> cantidad;
	Cuenta c1 = *pc;//Esto ha hecho una copia amigo!
	c1.ingresar(cantidad);
	
		cout << "despues del ingreso en la funcion vale " << endl;
		mostrar(c1);
	

};


void procesarRetirada(Cuenta * c){

	float cantidad;

	cout << "Introduce la cantidad a retirar " ;
	cin >> cantidad;
	
	Cuenta c1 = *c;
	c1.retirar(cantidad);

};

void transferir(Cuenta * origen, Cuenta* destino){
		
	(*destino).ingresar( (*origen).saldo );
	(*origen).retirar( (*origen).saldo );
}

int main (int argc,char *argv[]){
	
	Cuenta c1 ("Juanito","001");
	Cuenta c2 ("Pepito", "002",100);
	
	
	cout << "La cuenta de " << c1.titular << " tiene " << c1.saldo << " euros " << endl;
	
	cout << "La cuenta de " << c2.titular << " tiene " << c2.saldo << " euros " << endl;
	
	
	
}



