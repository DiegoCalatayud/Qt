#include "dbuscar.h"



DBuscar::DBuscar (QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags() ) : QDialog(parent) {
	setupUi(this);
		
 }
 
		 


void DBuscar::slotBotonBuscar(){
	emit ssenyalBuscar(QString("hola"));
}


		 
		 
		 
		 
		 
