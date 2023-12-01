#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "ui_calculadora.h"
#include <QDialog>


class Calculadora  : public QDialog, public Ui::Calculadora{

Q_OBJECT

public: 
	int  sumando1 ;
	int  sumando2 ;
	typedef enum {PRIMERO,SEGUNDO} estadoPosible;
	estadoPosible estadoActual;
	Calculadora ( QWidget * parent = NULL );
public slots:
	void slotBoton1();
	void slotBoton2();
	void slotBoton3();
	void slotBotonMas();
	void slotBotonIgual();
	void slotDigito();

};

#endif
