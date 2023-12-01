
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;

int main (int argc,char *argv[]){


	int notas[10];
	int notaMinima = 0;
	int notaMaxima = 0;
	
	
	for(int i = 0; i<10; i++){
	
		notas[i] = random() % 11;
	}
	
	
	
	
	notaMinima = notas[0];
	notaMaxima = notas[0];
	
	for(int i = 0; i<10; i++){
	
		cout << notas[i]<<", ";
		
		if ( notas[i] < notaMinima ) notaMinima = notas[i];
		if ( notas[i] > notaMaxima ) notaMaxima = notas[i];
		
	}
	
	cout << endl;
	
	
	cout << "La nota más baja es: " << notaMinima << "." << endl;
	cout << "La nota mas alta es: " << notaMaxima << "." << endl;
	
}

