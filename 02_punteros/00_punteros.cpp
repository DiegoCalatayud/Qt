#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char*argv[]){

	char c;
	int i;
	int j;
	
	int* p;
	
	i = 3;
	j = i+2;
	
	p = &i;
	
	
	cout << " i vale " << i << endl;
	
	cout << " i está en la posicion\t\t"  << &i << endl;
}
