#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char*argv[]){

	char c;
	int i;
	int j;
	
	int* p; // p es un puntero que contiene un entero
	p = &i; // p = al numero exadecimal al que apunta i
	
	*p = 3;// es lo mismo que i = 3;
	
	
	j = *p+2; // j es igual a 2 + el valor del puntero p
	
	
	
	
	cout << " i vale " << i << endl;
	
	cout << " i está en la posicion\t\t"  << &i << endl;
	
		
	cout << " j vale " << j << endl;
}
