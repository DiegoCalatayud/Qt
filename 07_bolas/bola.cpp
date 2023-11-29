#include <bola.h>
#include <math.h>
Bola::Bola(){

	posX = 10;
	posY = 10;
	velX = 3;
	velY = 1.3;
	diametro = 20;
	color = QColor(rand()%256,rand()%256,rand()%256);
}

void Bola::pintar(QPainter &pintor){

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

