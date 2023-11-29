#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include "dtransferencia.h"
#include "dprincipal.h"
DPrincipal::DPrincipal(QWidget *parent , Qt::WindowFlags f): 
QDialog(parent, f){

	


	
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
		dTransferencia = new DTranferencia();
		//dTransferencia->setAttribute(Qt::WA_DeleteOnClose);
		
		
	connect(dTransferencia,SIGNAL(accepted()),
 		this, SLOT(aceptado()));	
 	connect(dTransferencia,SIGNAL(rejected()),
 		this, SLOT(cancelado()));
	}
	dTransferencia->show();
		
}

void DPrincipal::aceptado (){

	etiqResultado->setText(dTransferencia->etiq3->text());
	delete dTransferencia;
	dTransferencia = NULL;
	
};
void DPrincipal::cancelado (){
	etiqResultado->setText("Transferencia cancelada");
	delete dTransferencia;
	dTransferencia = NULL;
};





