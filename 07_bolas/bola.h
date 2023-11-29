#ifndef _BOLA_H
#define _BOLA_H
#include <QPainter>
#include <QVector>
#include <QColor>
class Bola {
public:
	Bola();
	float posX,posY,velX,velY;
	int diametro;
	void pintar(QPainter &pintor);
	void mover(float width, float height);
	QColor color;
	QVector<Bola*> bolas;
};

#endif
