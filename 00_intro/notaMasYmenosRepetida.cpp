
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;

int main (int argc,char *argv[]){


	int notas[10];
	int notasRepetidas[11];
	int notaMasRepetida = 0;
	int notaMenosRepetida = 0;
	int vecesRepiteMas = 0;
	int vecesRepiteMenos = 0;
	
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
	
	vecesRepiteMas = notasRepetidas[0];
	vecesRepiteMenos = notasRepetidas[0];
		
	for ( int i = 0; i < 11; i++ ){
	
		if ( notasRepetidas[i] != 0 && notasRepetidas[i] < vecesRepiteMenos ){
			vecesRepiteMenos = notasRepetidas[i];
			notaMenosRepetida = i;
		}
		if ( notasRepetidas[i] > vecesRepiteMas ){
			vecesRepiteMas = notasRepetidas[i];
			notaMasRepetida = i;
		}
		
	}
	
	int cantidadMenosRepetidas = 0;
	int cantidadMasRepetidas = 0;
	
	for ( int i = 0; i < 11; i++  ){
		
		if ( notasRepetidas[i] == vecesRepiteMas ) cantidadMasRepetidas++;
		if ( notasRepetidas[i] == vecesRepiteMenos ) cantidadMenosRepetidas++;
	}
	
	cout << "Hay " << cantidadMenosRepetidas << " nota/s que se repiten  menos, siendo "<< vecesRepiteMenos << " la cantidad de veces que se repite. "<< endl;
	cout << "Y esta/s nota/s es/son: ";
	
	for ( int i = 0; i < 11; i++  ){
		
		if ( notasRepetidas[i] == vecesRepiteMenos  ) cout << i << ", ";
	}
	
	cout << endl;
	
	
	cout << "Hay " << cantidadMasRepetidas << " nota/s que se repiten  mas, siendo "<< vecesRepiteMas << " la cantidad de veces que se repite. "<< endl;
	cout << "Y esta/s nota/s es/son: ";
	
	for ( int i = 0; i < 11; i++  ){
		
		if ( notasRepetidas[i] == vecesRepiteMas  ) cout << i << ", ";
	}
	
	cout << endl;
	
	
	
	for(int i = 0; i<11; i++){
	
		cout << "La nota "<< i <<" se repite "<< notasRepetidas[i] << " veces. ";
		cout << endl;
	}
	
}

