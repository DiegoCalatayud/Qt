#include "bola.h"
#include <math.h>
#include <QBrush>
#include <QDebug>

Bola::Bola() {
	posX = posY = 300;
	velX = 0.3;
	velY = -1;
	especial = false;
	vidas = 100;
	
	
	color = QColor(rand()%256,rand()%256,rand()%256);
}

void Bola::mover(int anchura, int altura){
  posX = posX + velX ;
	posY= posY + velY ;
		
	if (posX > anchura - diametro) 
		velX = -fabs(velX);
	
	if (posX < 0) 
		velX = fabs(velX);
		
	if (posY > altura- diametro) {
		velY = - fabs(velY);
		}
	
	if (posY < 0) 
		velY = fabs(velY);
}

void Bola::pintar(QPainter &pintor){
	if (especial) {
		pintor.drawEllipse(this->posX-3,this->posY-3,this->diametro+6,this->diametro+6);
	}
	pintor.setBrush(color);
	pintor.drawEllipse(this->posX,posY,diametro,diametro);
	QString texto = QString("vidas: ") + QString::number(vidas);
	pintor.drawText(posX, posY-10, texto);
}

float Bola::distancia(Bola* otra) {
	float dist = sqrtf( powf(posX - otra->posX,2 ) +
											powf(posY - otra->posY,2 ));

	return dist;

}

bool Bola::choca(Bola *otra) {
		bool hayChoque = false; ;
		if ( distancia(otra) > diametro )
				return false;
	 
	 Bola * arriba, *abajo;
	 Bola * izq, *der;
	 
	 /* Posicion horizontal */
	 if (posX < otra->posX) {
	 		izq = this;
	 		der = otra;
	 } else {
	 		der = this;
	 		izq = otra;
	 }
	 
	 if (izq->velX > der->velX) {
	 		float aux = der->velX;
	 		der->velX = izq->velX;
	 		izq->velX = aux;
	 		hayChoque = true;
	 }
	 	
	 	/* posicion Y */
	 	 if (posY < otra->posY) {
	 		arriba = this;
	 		abajo = otra;
	 } else {
	 		abajo = this;
	 		arriba = otra;
	 }
	 
	 if (arriba->velY > abajo->velY) {
	 		float aux = der->velY;
	 		der->velY = izq->velY;
	 		izq->velY = aux;
	 		hayChoque = true;
	 }
	 	

		return hayChoque;
}






