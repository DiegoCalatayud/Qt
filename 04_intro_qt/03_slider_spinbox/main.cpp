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

  int main(int argc, char *argv[])
  {
  	QApplication app(argc, argv);

  	QWidget *window = new QWidget;
  	
  	window->setWindowTitle("Enter Your Age");


/*
 	QSpinBox *spinBox = new QSpinBox;
 	QSlider *slider = new QSlider(Qt::Horizontal);
 	QComboBox * combobox = new QComboBox();
 	
	QLCDNumber * pantalla = new QLCDNumber();
*/ 	
 	
	QLineEdit *lineEdit = new QLineEdit();
	QLabel *qlabel = new QLabel();
 	QPushButton *buton = new QPushButton("Limpiar");
 	
 	




 	QObject::connect(lineEdit, SIGNAL(textChanged(QString )),
                  	qlabel, SLOT(setText(QString)));
                  	
         QObject::connect(buton, SIGNAL(clicked()),
                  	lineEdit, SLOT(clear()));       	
                  	
	
 	
 	
 	
 	

 	QVBoxLayout *layout = new QVBoxLayout;
 	layout->addWidget(lineEdit);
 	layout->addWidget(qlabel);
 	layout->addWidget(buton);
 	window->setLayout(layout);



 	window->show();

 	return app.exec();
 }

