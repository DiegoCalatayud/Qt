#include <QApplication>
#include <dialogodesigner.h>
#include <QApplication>





 int main(int argc, char *argv[])
 {
        QApplication app(argc, argv);
    	
	DialogoDesigner * dPrincipal = new DialogoDesigner();
    	
    	dPrincipal->show();

  	return app.exec();
 }
 

