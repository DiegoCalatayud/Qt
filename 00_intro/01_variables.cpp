
#include <stdio.h>

#include <iostream>

using namespace std;

int main (int argc,char *argv[]){
	int numero;
	int numero2 = 0;
	numero = 3;
	cout << "dame un número : ";
	cin >> numero2;
	


	cout << "El número es: " << numero << endl;
	cout << "El número introducido es: " << numero2 << endl;
	if (numero == numero2) {
		cout << "Has acertado el número" << endl;
	} else {
		cout << "No has acertado el número" << endl;
	}
}

