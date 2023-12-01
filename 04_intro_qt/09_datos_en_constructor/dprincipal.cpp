#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QStringList>

#include "dtransferencia.h"
#include "dprincipal.h"
DPrincipal::DPrincipal(QWidget *parent , Qt::WindowFlags f): 
QDialog(parent, f){

	//en qdebug que aparega la cantidad y que has aceptat y de qui, que no se dehabiliten els botons, lleva les tres señals de la clase no dels metodos
	//al posar aceptar  ho fa
	

//	listaCuentas = {"111111","222222","333333"};
	boto = new QPushButton("Lanzar transferencia");
	capa =  new QHBoxLayout();		
	etiqResultado = new QLabel("Este es el texto inicial de la etiqueta");
	capa->addWidget(boto);
	capa->addWidget(etiqResultado);



 	dTransferencia = NULL;
 	

 		

	
	 connect(boto,SIGNAL(clicked()),
 		this, SLOT(lanzarVentana()));
 		

 
 	//connect(dTransferencia,SIGNAL(accepted()),
 	//	this, SLOT(aceptado()));	
 	//connect(dTransferencia,SIGNAL(rejected()),
 	//	this, SLOT(cancelado()));	
 		 		


	

	this->setLayout(capa);

}



void DPrincipal::lanzarVentana(){
	
	if (dTransferencia == NULL){
		dTransferencia = new DTranferencia(listaCuentas1);
		
		
	connect(dTransferencia,SIGNAL(accepted()),
 		this, SLOT(aceptado()));	
 	connect(dTransferencia,SIGNAL(rejected()),
 		this, SLOT(cancelado()));
	}
	dTransferencia->show();
		
}

void DPrincipal::aceptado (){

	etiqResultado->setText(dTransferencia->etiq3->text());
	
};
void DPrincipal::cancelado (){
	etiqResultado->setText("Transferencia cancelada");
};





