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
#include "dtransferencia.h"

  int main(int argc, char *argv[])
  {
    	QApplication app(argc, argv);
    	
    	
    	DTranferencia * dTransferencia = new DTranferencia();
    	
    	dTransferencia->show();
    	
    	
  	return app.exec();
  

 }
