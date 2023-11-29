
#include <stdio.h>

#include <iostream>

using namespace std;

int main (int argc,char *argv[]){
	int numeroSecreto = 3;
	int numeroUsuario = 0;
	int intentos  = 0;
	
	
	while (numeroSecreto != numeroUsuario){
		intentos ++;
		cout << "dime un número : ";
		cin >> numeroUsuario;
		
		if (numeroSecreto == numeroUsuario) break;
		
		cout << "No has acertado el número" << endl;
			
		if (numeroUsuario < numeroSecreto) 
			cout << "El número introducido es menor que el número secreto"<< endl;
		if (numeroUsuario > numeroSecreto) 
			cout << "El número introducido es mayor que el número secreto"<< endl;
			
		
	}
	
	
	cout << "" << endl;
	cout << "¡Enhorabuena!" << endl;
	cout << "Has acertado el número" << endl;
	cout << "El número secreto es: " << numeroSecreto << endl;
	cout << "El número introducido es: " << numeroUsuario << endl;
	cout << "El número de intentos es: " << intentos << endl;
	
	
	

}

