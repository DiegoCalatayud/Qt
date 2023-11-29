#include <QApplication>
#include <VentanaPrincipal.h>





  int main(int argc, char *argv[])
  {
    	QApplication app(argc, argv);
    	
	VentanaPrincipal * dialogo = new VentanaPrincipal();
    	
    	dialogo->show();

  	return app.exec();

 }
