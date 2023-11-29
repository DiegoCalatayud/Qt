
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;

int main (int argc,char *argv[]){


	int notas[10];
	int notaMedia = 0;
	
	
	for(int i = 0; i<10; i++){
	
		notas[i] = random() % 11;
	}
	
	
	
	for(int i = 0; i<10; i++){
	
		cout << notas[i]<<", ";
		notaMedia = notaMedia + notas[i];
		
	}
	
	cout << endl;
	
	notaMedia = notaMedia/10;
	
	cout << "La media de las notas es: " << notaMedia << "." << endl;
	
	
	
	
	
	
	
	
}

