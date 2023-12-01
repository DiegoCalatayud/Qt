#include "dbuscar.h"



DBuscar::DBuscar (QWidget *parent ) : QDialog(parent) {
	setupUi(this);
	
	
	 connect(pushButton,SIGNAL(clicked()),
 				this,SLOT(slotBotonBuscar()));
	
		
 }
 
		 


void DBuscar::slotBotonBuscar(){
	emit senyalBuscar(lineEdit_2->text());
	label->setText("Pulsado y undido");
}


		 
		 
		 
		 
		 
