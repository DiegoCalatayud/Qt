#include <QApplication>

#include "calculadora.h"



  int main(int argc, char *argv[])
  {
    	QApplication app(argc, argv);
    	
	Calculadora * dialogo = new Calculadora();
    	
    	dialogo->show();

  	return app.exec();

 }
