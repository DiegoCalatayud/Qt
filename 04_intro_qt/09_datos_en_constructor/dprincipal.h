#ifndef DPRINCIPAL_H
#define DPRINCIPAL_H
#include <QStringList>
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

	QStringList * listaCuentas;
    	QHBoxLayout * capa;
    	QPushButton * boto;
    	QLabel * etiqResultado;
	QStringList listaCuentas1 = {"111111","222222","333333"};
    	DTranferencia * dTransferencia;
    	
    	
    	
 	

    	





public slots:	
	void lanzarVentana ();
	void aceptado ();
	void cancelado ();



};

#endif
