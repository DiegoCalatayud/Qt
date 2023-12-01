#include "bola.h"
//#include <math.h>
#include <math.h>
#include <QDebug>

Bola::Bola(){

	posX = 10;
	posY = 10;
	velX = 3;
	velY = 1.3;
	diametro = 20;
	color = QColor(rand()%256,rand()%256,rand()%256);
}

void Bola::pintar(QPainter &pintor){

	if (especial) {
		pintor.drawEllipse(this->posX-3,this->posY-3,this->diametro+6,this->diametro+6);
	}

	pintor.setBrush(color);
	pintor.drawEllipse(this->posX,this->posY,this->diametro,this->diametro);
	
}


void Bola::mover(float width, float height){

	if(this->posX>=(width-20))this->velX = -fabs(this->velX);
	
	if(this->posX<=0)this->velX = +fabs(this->velX);;
	
	if(this->posY>=(height-20))this->velY = -fabs(this->velY);
	
	if(this->posY<=0)this->velY = +fabs(this->velY);;
	

	this->posX = this->posX + this->velX;
	this->posY = this->posY + this->velY;

}

float Bola::distancia(Bola *otra){

	float dist = sqrtf( powf(posX - otra->posX,2) )+
			    powf(posY - otra->posY,2);
	return dist;			    
	

}
bool Bola::choca(Bola *otra){

	bool hayChoque;
	Bola * izq;
	Bola * der;
	
	if ( this->posX < otra->posX ){ izq = this; der = otra;}else{  izq = otra; der = this; }


	if( distancia(otra) > diametro ){
		return false;
	}
	
	if (izq->VelX > der->velX){
		
		hayChoque = true;
		float aux = izq->velX;
		izq->velX = der->velX;
		der->velX = aux;
	}
	
	qDebug()<<"Dos bolitas están tocandose";
	
	return hayChoque;

}

