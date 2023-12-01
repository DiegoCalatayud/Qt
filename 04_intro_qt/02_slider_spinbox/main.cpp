#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QString>
#include <QLCDNumber>



  int main(int argc, char *argv[])
  {
  	QApplication app(argc, argv);

  	QWidget *window = new QWidget;
  	
  	window->setWindowTitle("Enter Your Age");



 	QSpinBox *spinBox = new QSpinBox;
 	QSlider *slider = new QSlider(Qt::Horizontal);
 	QComboBox * combobox = new QComboBox();
	QLCDNumber * pantalla = new QLCDNumber();
 	
 	
 	
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
                  	
                  	
 	spinBox->setValue(35);
 	
 	
 	

 	QHBoxLayout *layout = new QHBoxLayout;
 	layout->addWidget(combobox);
 	layout->addWidget(pantalla); 	
 	layout->addWidget(spinBox);
 	layout->addWidget(slider);
 	window->setLayout(layout);



 	window->show();

 	return app.exec();
 }

