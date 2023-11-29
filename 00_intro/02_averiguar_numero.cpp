
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



using namespace std;


void inicializar(int notasPasadas[10]){
	for(int i = 0; i<10; i++){
	
		notasPasadas[i] = random() % 101;
	}
	notasPasadas[0] = 5;
	notasPasadas[1] = 3;
	notasPasadas[2] = 4;
}

void mostrar(int notasPasadas[10]){
	for(int i = 0; i<10; i++){
	
		cout << notasPasadas[i]<<", ";
	}
	
	cout << endl;
	
}

int buscaMax(int notasPasadas[10]){
	int notaAlta = notasPasadas[0];
	int iMax = 0;
	for(int i = 0; i<10; i++){
	
		if ( notaAlta < notasPasadas[i] ){ 
			notaAlta = notasPasadas[i];
			iMax = i;
		}
	}
	return notasPasadas[iMax];
}

int cuantos (int notasPasadas[10], int nota);
bool existe (int notasPasadas[10], int nota){
	/*for(int i = 0; i<10; i++){
	
		if ( notasPasadas[i] == nota ){ 
			return true;
		}
	}
	
	return false;*/
	
	return cuantos(notasPasadas, nota)>0;
	 
}

int cuantos (int notasPasadas[10], int nota){
	int cantidad = 0;
	for(int i = 0; i<10; i++){
	
	if (notasPasadas[i] == nota) cantidad++;
		
	}
	return cantidad;
}




bool repite (int notasPasadas[10], int nota){

	bool iguales = false;
	
	for(int i = 0; i<10; i++){
	
		if (iguales == true && notasPasadas[i] == nota) return true;
		if (notasPasadas[i]== nota) iguales = true;
		if (notasPasadas[i]!= nota) iguales =false;
		
	}
	
	return iguales;


}

bool seRepite(int notasPasadas[10]){
	
	int notasClon [10];
	for(int i = 0; i<10; i++){

		notasClon[i] = notasPasadas[i];
		
	}
	
	for(int i = 0; i<10; i++){
	
	
		for( int j = i+1 ; j<10; j++){
			
			if (notasPasadas[i] == notasPasadas[j]/*&& i != j*/) {
			
				return true;
			}
		}
	}
	
	return false;
	
	
}

int diferencia(int notasPasadas[10]){

	int altas[4];
	
	for(int i=0; i<4;i++) altas[i] = 0;

	for(int i= 0; i<10; i++){
	
		for (int j=0; j<4; j++){
			
			if( notasPasadas[i] > altas[j]){
				altas[j] = notasPasadas[i];
				break;
			}
		}
	}
	
	return (altas[0]+altas[1]+altas[2]+altas[3])/4;

}

int main (int argc,char *argv[]){
	int notas[10];
	notas[0]=9;
	notas[1]=8;
	

	inicializar(notas);
	mostrar(notas);
	int max;
	max = buscaMax(notas);
	

	cout << "La nota mas alta es "<<max << endl;
	
	if(existe(notas,5)){
	cout << "El alumno ha sacado un 5" << endl;
	}
	cout<< "El alumno ha sacado " << cuantos(notas,5)<< " cincos" << endl;
	
	if (repite(notas,4)){
		cout << "El alumno ha sacado dos 4 seguidos"<<endl;
	}
	
	if (seRepite(notas)){ cout << "Se repite"<< endl;}
	
	cout << "La media de las altas es: "<< diferencia(notas);
	
	
}



