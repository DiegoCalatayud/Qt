#include "calculadora.h"

Calculadora::Calculadora( QWidget * parent ) : QDialog ( parent ) {
	setupUi(this);
	
	estadoActual = PRIMERO;

	
	connect (botonmas, SIGNAL (clicked()), this , SLOT(slotBotonMas()));
	connect (botonigual, SIGNAL (clicked()), this , SLOT(slotBotonIgual()));
	
	/*
	connect (boton1, SIGNAL (clicked()), this , SLOT(slotBoton1()));
	connect (boton2, SIGNAL (clicked()), this , SLOT(slotBoton2()));
	connect (boton3, SIGNAL (clicked()), this , SLOT(slotBoton3()));*/
	
	for ( int i = 0 ; i < layoutbotones->count() ; i++ ){
		
		QLayoutItem * item = layoutbotones-> itemAt(i);
		QWidget * uidchet = item->widget();
		QPushButton * botoncito = qobject_cast<QPushButton*>(uidchet);
	
		connect (botoncito, SIGNAL (clicked()), this , SLOT(slotDigito()));
		//hacer casting
		
		//QWidget * botonX = layoutbotones->itemAt(i);
	
		//connect (layoutbotones->itemAt(i)->widget(), SIGNAL (clicked()), this , SLOT(slotDigito()));
	}
	

}

void Calculadora::slotBoton1(){
	
	display->setText(display->text() + QString("1"));
}
void Calculadora::slotBoton2(){
	display->setText(display->text() + QString("2"));
}
void Calculadora::slotBoton3(){
	display->setText(display->text() + QString("3"));
}

void Calculadora::slotBotonMas(){

	if (estadoActual == PRIMERO){
	sumando1 = display->text().toInt();
	display->setText("");
	estadoActual = SEGUNDO;
	
	}

}

void Calculadora::slotBotonIgual(){

	if (estadoActual == SEGUNDO){
	sumando2 = display->text().toInt();
	int total = sumando2 + sumando1;
	QString text = QString::number(total);
	display->setText( text);
	estadoActual = PRIMERO;
	
	}

}

void Calculadora::slotDigito(){

	QObject * objetoCulpable = sender();
	
	QPushButton * botonCulpable;
	
	botonCulpable = qobject_cast<QPushButton*>(objetoCulpable);
	QString textoboton =  botonCulpable->text();
	
	display->setText(display->text() +textoboton);
}
