#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
 {
 
 	//QApplication * app;
 	//app = new QApplication(argc, argv);
 	QApplication app(argc, argv);
 	QApplication * pApp = &app;
 	QPushButton *button = new QPushButton("Quit");
 	QObject::connect(button, SIGNAL(clicked()),
                  	pApp, SLOT(quit()));
 	button->show();
	return app.exec();
 }

