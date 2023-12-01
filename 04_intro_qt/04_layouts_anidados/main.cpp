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


	//capa 1
	QLineEdit *lineEdit = new QLineEdit();
	QLabel *qlabel = new QLabel();
 	QPushButton *buton = new QPushButton("Limpiar");



	//capa2
 	QSpinBox *spinBox = new QSpinBox;
 	QSlider *slider = new QSlider(Qt::Horizontal);
 	QComboBox * combobox = new QComboBox();
 	
 	//capa3
	QLCDNumber * pantalla = new QLCDNumber();
 	QPushButton *butonOct = new QPushButton("OCT");
 	QPushButton *butonDec = new QPushButton("DEC"); 	
 	
 	
 	for ( int i = 0; i < 131; i++ ){
 	 	QString qstring = QString::number(i);
 		combobox->addItem(qstring);
 	}
 	
 	
 	
 	spinBox->setRange(0, 130);
	slider->setRange(0, 130);



 	QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                  	slider, SLOT(setValue(int)));
 	QObject::connect(slider, SIGNAL(valueChanged(int)),
                  	spinBox, SLOT(setValue(int)));
                  	
                  	
                  	
 	QObject::connect(combobox, SIGNAL(currentIndexChanged(int)),
                  	spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                  	combobox, SLOT(setCurrentIndex(int)));
                  	
                  	
                  	
 	QObject::connect(combobox, SIGNAL(currentIndexChanged(int)),
                  	pantalla, SLOT(display(int)));     
                  	
                  	
        QObject::connect(lineEdit, SIGNAL(textChanged(QString )),
                  	qlabel, SLOT(setText(QString)));
                  	
        QObject::connect(buton, SIGNAL(clicked()),
                  	lineEdit, SLOT(clear()));   
                  	
                  	
        QObject::connect(butonOct, SIGNAL(clicked()),
                  	pantalla, SLOT(setOctMode()));           	
                  	             	
        QObject::connect(butonDec, SIGNAL(clicked()),
                  	pantalla, SLOT(setDecMode()));                     	
                  	
 	spinBox->setValue(35);
 	
 	
 	

 	QVBoxLayout *supIzq = new QVBoxLayout;
 	QVBoxLayout *pare = new QVBoxLayout;
 	
 	QHBoxLayout *superior = new QHBoxLayout;
 	QHBoxLayout *inferior = new QHBoxLayout;
 	QHBoxLayout *supDer = new QHBoxLayout;
 	
 	supIzq->addWidget(lineEdit);
 	supIzq->addWidget(qlabel); 	
 	supIzq->addWidget(buton);
 	
 	supDer->addWidget(spinBox);
 	supDer->addWidget(slider);
 	
 	inferior->addWidget(pantalla);
 	inferior->addWidget(butonOct);
 	inferior->addWidget(butonDec);
 	
 	pare->addLayout(superior);
 	pare->addLayout(inferior);
 	
 	superior->addLayout(supIzq);
 	superior->addLayout(supDer);
 	
 	
 	
 	
 	window->setLayout(pare);



 	window->show();

 	return app.exec();
 }

