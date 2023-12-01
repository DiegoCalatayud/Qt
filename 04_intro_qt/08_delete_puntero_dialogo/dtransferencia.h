#ifndef DTRANSFERENCIA_H
#define DTRANSFERENCIA_H


#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>

class DTranferencia : public QDialog {

Q_OBJECT	

public:

DTranferencia(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

	QLabel * etiq1;
	QLabel * etiq2;
	QLabel * etiq3;
	
	QLineEdit * linea1;
	QLineEdit * linea2;
	
	QPushButton * boto1;
	QPushButton * boto2;



public slots:	
	void slotActualizarBoton (const QString &);
	void slotActualizarComision (const QString &);
	void slotBotonAceptar();



};

#endif
