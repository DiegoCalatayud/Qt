#include "dedad.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QString>
#include <QLCDNumber>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
DEdad::DEdad(QWidget *parent , Qt::WindowFlags f): 
QWidget(parent, f){

	

	QVBoxLayout * layout = new QVBoxLayout();
	QHBoxLayout * layoutDins = new QHBoxLayout();

	etiqSup = new QLabel("Edad: ");

	etiqInfo = new QLabel("No eres mayor de edad");

	spinBox = new QSpinBox();
	button = new 	QPushButton("Limpiar");
	
 	spinBox->setRange(0, 130);
 	
 	
 	connect(spinBox,SIGNAL(valueChanged(int)),
 		this, SLOT(slotIndica(int)));
 		
 		
 		
 		//esto se tendria wue hacer con un clear y no con un metodo slotlimpia
	 connect(button,SIGNAL(clicked()),
 		this, SLOT(slotLimpia()));
	


	layoutDins->addWidget(etiqSup);
	layoutDins->addWidget(spinBox);
	layoutDins->addWidget(button);

	layout->addLayout(layoutDins);
	layout->addWidget(etiqInfo);


	this->setLayout(layout);

}



void DEdad::slotIndica(int e) {
	if (e>=18)
		etiqInfo->setText("Eres mayor de edad");
	else
		etiqInfo->setText("Eres menor de edad");
}

void DEdad::slotLimpia() {
	etiqInfo->setText("");
}
