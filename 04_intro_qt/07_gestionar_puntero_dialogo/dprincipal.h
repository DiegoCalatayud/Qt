#ifndef DPRINCIPAL_H
#define DPRINCIPAL_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include "dtransferencia.h"

class DPrincipal : public QDialog {

Q_OBJECT	

public:

DPrincipal(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());


    	QHBoxLayout * capa;
    	QPushButton * boto;
    	QLabel * etiqResultado;

    	DTranferencia * dTransferencia;
    	
    	
    	
 	

    	





public slots:	
	void lanzarVentana ();
	void aceptado ();
	void cancelado ();



};

#endif
