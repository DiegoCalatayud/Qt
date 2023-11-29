#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include "dtransferencia.h"
DTranferencia::DTranferencia(QWidget *parent , Qt::WindowFlags f): 
QDialog(parent, f){

	


	QHBoxLayout * layoutPare = new QHBoxLayout();
	QVBoxLayout * layoutIzq = new QVBoxLayout();
	QVBoxLayout * layoutDer = new QVBoxLayout();
	QHBoxLayout * layout1 = new QHBoxLayout();
	QHBoxLayout * layout2 = new QHBoxLayout();
			

	etiq1 = new QLabel("Cuenta destino: ");
	etiq2 = new QLabel("Cantidad ");
	etiq3 = new QLabel("Comisión 0 euros ");


	boto1 = new 	QPushButton("Aceptar");
	boto2 = new 	QPushButton("Cancelar");
	
	linea1= new QLineEdit();
	linea2= new QLineEdit();
	

 	
 	

 		
	


	layoutPare->addLayout(layoutIzq);
	layoutPare->addLayout(layoutDer);
	
	layoutIzq->addLayout(layout1);
	layoutIzq->addLayout(layout2);
	layoutIzq->addWidget(etiq3);

	layout1->addWidget(etiq1);
	layout1->addWidget(linea1);
	
	layout2->addWidget(etiq2);
	layout2->addWidget(linea2);
	
	layoutDer->addWidget(boto1);
	layoutDer->addWidget(boto2);
	
	
	 connect(linea1,SIGNAL(textChanged(const QString & )),
 		this, SLOT(slotActualizarBoton(const QString &)));
 		
 	 connect(linea2,SIGNAL(textChanged(const QString & )),
 		this, SLOT(slotActualizarComision(const QString &)));
 		



	this->setLayout(layoutPare);

}



void DTranferencia::slotActualizarBoton(const QString &){
	
	QString cadena1 = linea1->text();
	QString cadena2 = linea2->text();
	
	QRegularExpression reCadena1("^\\d{6}$");
	QRegularExpression reCadena2("^\\d+$");
	
	QRegularExpressionMatch mLinea1 = reCadena1.match(cadena1);
	QRegularExpressionMatch mLinea2 = reCadena2.match(cadena2);
	
	bool linea1OK = mLinea1.hasMatch();
	bool linea2OK = mLinea2.hasMatch();
	
	if ( linea1OK && linea2OK )
		boto1->setEnabled(true);
	else
		boto1->setEnabled(false);
	
		
}

void DTranferencia::slotActualizarComision(const QString &){
	
	QString cadena1 = linea1->text();
	QString cadena2 = linea2->text();
	
	float cantidad = cadena2.toFloat();
	cantidad = cantidad/10.0;
	
	QString	res = 	QString("La comisión es de: ") + QString::number(cantidad) + QString(" euros");
	
	etiq3->setText(res);
	
	
		
}



