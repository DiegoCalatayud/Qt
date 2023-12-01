#ifndef _BOLA_H_
#define _BOLA_H_

#include <QPainter>
#include <QColor>

class Bola {
public:
	Bola();
	
	float posX,posY;
	float velY,velX;
	
	int vidas;
	
	bool especial;
	
		static const int diametro=50;
	
	QColor color;
	float distancia(Bola* otra);
	void mover(int,int);
	void pintar(QPainter &);
	bool choca(Bola *);
};

#endif
