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
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWindow>
#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include "dtransferencia.h"
#include "dprincipal.h"


  int main(int argc, char *argv[])
  {
    	QApplication app(argc, argv);
    	
	DPrincipal * dPrincipal = new DPrincipal();
    	
    	dPrincipal->show();

  	return app.exec();

 }
 

