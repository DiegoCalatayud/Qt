#include <stdio.h>
#include <iostream>
using namespace std;

void hazNegativo(int * punteroI){
	
	//*punteroI = (*punteroI-*punteroI-*punteroI);
	*punteroI = (*punteroI-((*punteroI)*2));

}

int main(int argc, char*argv[]){

	char c;
	int i;
	int j;
	
	i = 8;
	
	int *p = &i;
	
	
	
	hazNegativo( p ); //referencia a i
	
	cout << " El nuevo valor de i es " << i << endl;
}
