
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

int main (int argc,char *argv[]){
	
	Cuenta c;
	// c = new Cuenta(); no es necesario
	c.saldo = 0;
	c.titular  = "Juan";
	c.ingresar(1000);
	c.retirar(490);
	
	cout << "El saldo de la cuenta de " << c.titular << " es " << c.saldo << endl;
	
	if ( c.retirar(10))
		cout << "He retirado x euros y no debería haber ocurrido" << endl;
	else
		cout << "NO he podido retirar" << endl;
	
}



