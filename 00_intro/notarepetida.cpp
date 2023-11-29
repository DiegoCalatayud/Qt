
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;

int main (int argc,char *argv[]){


	int notas[10];
	int notasRepetidas[11];
	
	
	for(int i = 0; i<10; i++){
	
		notas[i] = random() % 11;
	}
	
	
	for(int i = 0; i<11; i++){
	
		notasRepetidas[i] = 0;
		
	}
	

	
	for(int i = 0; i<10; i++){
	
		cout << notas[i]<<", ";
		notasRepetidas [notas[i]]++;
		
	}
	
	cout << endl;
	
	
	
	
	for(int i = 0; i<11; i++){
	
		cout << "La nota "<< i <<" se repite "<< notasRepetidas[i] << " veces. ";
		cout << endl;
	}
	
}

