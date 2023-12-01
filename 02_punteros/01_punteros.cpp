#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void hazNegativo(int * punteroI){
	
	//*punteroI = (*punteroI-*punteroI-*punteroI);
	//*punteroI = (*punteroI-((*punteroI)*2));
	*punteroI = - abs(*punteroI);

}

void hazNegativo2(int & num){
	
	//*punteroI = (*punteroI-*punteroI-*punteroI);
	//*punteroI = (*punteroI-((*punteroI)*2));
	num= - abs(num);

}

int* maximo (int* p1, int* p2){

	
	if( *p1 > *p2 ){
		//*p1 = 100;
		return p1;
	}else{
		//*p2 = 100;
		return p2;
	}

}

int & maximo2 (int & p1, int & p2){

	
	if( p1 > p2 ){
		//*p1 = 100;
		return p1;
	}else{
		//*p2 = 100;
		return p2;
	}

}

int main(int argc, char*argv[]){


	int i= 50;
	int j = 70;
	
	
	
	int &max = maximo2(i,j);
	
	
	cout << " El nuevo valor de max es " << max << endl;
	cout << " El nuevo valor de i es " << i << endl;
	cout << " El nuevo valor de j es " << j << endl;
	
	j = 200;
	
	cout << " El nuevo valor de max es " << max << endl;
	cout << " El nuevo valor de i es " << i << endl;
	cout << " El nuevo valor de j es " << j << endl;
	
	
}
