#include <mainwindow.h>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QTimer>
#include <math.h>
#include <bola.h>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDate>
#include <QTextStream>
#include <QJsonDocument>
#include <QByteArray>
#include <QJsonValue>
#include <QStringList>	
#include <QColor>		


MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent){

resize(800,600);

	bola = new Bola(); 
	
	//bolas = QVector(NUMBOLAS);
	QTimer * temporizador = new QTimer();
	temporizador->setInterval(10);
	temporizador->setSingleShot(false);
	temporizador->start();
	crearBolas();
	createActions();
	createMenus(); 
	connect( temporizador,SIGNAL(timeout()),
		this,SLOT(slotTemporizador()));

};

void MainWindow::createActions(){
				
				 
				 accionGuardar = new QAction("Guardar");
				 //accionGuardar->setIcon(QIcon("./images/icons8-save-50.png"));
				 accionGuardar->setShortcut(QKeySequence("Ctrl+s"));
				 accionGuardar->setStatusTip("Esto es para guardar");
				 accionGuardar->setToolTip("Esto es para guardar");
				 
				 accionAbrirPartida = new QAction("Abrir");
				 //accionAbrirPartida->setIcon(QIcon("./images/icons8-save-50.png"));
				 accionAbrirPartida->setShortcut(QKeySequence("Ctrl+o"));
				 accionAbrirPartida->setStatusTip("Esto es para abrir");
				 accionAbrirPartida->setToolTip("Esto es para abrir");
				 
				 
 				 quitarColores = new QAction("Quitar colores");
				 //accionAbrirPartida->setIcon(QIcon("./images/icons8-save-50.png"));
				 quitarColores->setShortcut(QKeySequence("Ctrl+q"));
				 quitarColores->setStatusTip("Esto es para quitar colores");
				 quitarColores->setToolTip("Esto es para quitar colores");
				 
				 
				 

				 connect(accionGuardar,SIGNAL(triggered()),
				 				this,SLOT(slotGuardar()));
				 				
				 connect(accionAbrirPartida,SIGNAL(triggered()),
				 				this,SLOT(slotAbrirPartida()));				 						
				 				
				 							 								 								 				
}

void MainWindow::createMenus(){


	  menuArchivo = new QMenu("Archivo");



	  menuArchivo->addAction(accionGuardar); 	  	  
	  menuArchivo->addSeparator(); 	  
 	  menuArchivo->addAction(accionAbrirPartida); 	  	  	  
	  menuBar()->addMenu(menuArchivo);

	  
	  /*
	  QToolBar * barraPrincipal;
	barraPrincipal = addToolBar("Principal");
	barraPrincipal->addAction(accionSalir);
	barraPrincipal->addAction(accionAbrir);
	barraPrincipal->addAction(accionGuardar);		
	barraPrincipal->addAction(accionNuevo);		*/	
}
void MainWindow::crearBolas (){
	
	for( int i = 0; i< NUMBOLAS; i++ ){
		Bola *nueva = new Bola();
		nueva->posX = random()%width();
		nueva->posY = random()%width();		
		nueva->velX = (float) (rand()%100) / 50 -1;
		nueva->velY = (float) (rand()%100) / 50 -1;			
		
		nueva->velX = nueva->velX *5;
		nueva->velY = nueva->velY *5;
		
		bolas.append(nueva);
	}
}



void MainWindow::paintEvent (QPaintEvent * event){

	

	QPainter pintor(this);
	
	for(int i = 0; i < bolas.size(); i++){
	bolas[i]->pintar(pintor);
	bolas[i]->mover(width(),height());
	}
	



	
}

void MainWindow::slotTemporizador(){
	/*
	
	for ( int i = 0; i < bolas.size(); i++)
		bolas[i]->mover(width(),height());
	
	*/
	
	for ( int i = 0; i < bolas.size(); i++)	{
		for ( int j = 0; j < bolas.size(); j++)	{
		
			if( (i!=j)  && bolas.at(i)->choca(bolas.at(j)) )
				qDebug() << "Hay choque" << i << " "<< j ;
		}
	}
	
	
	
	
	update();
	
	
	
	
}




void MainWindow::slotGuardar(){
	QString ruta = ("partida.json");
	QFile fichero(	ruta );
	
	if ( !fichero.open(QIODevice::WriteOnly) ) return;
		
	QTextStream flujo(&fichero);
	//Anem a generar el JSON
	
	QJsonObject jsonPrincipal;
	jsonPrincipal["autor"] = QString("Diego");
	
	
	QJsonObject jsonVersion;
	jsonVersion["version"] = 0;
	jsonVersion["subVersion"] = 3;
	jsonVersion["sistemaOperativo"] = QString("Linux");		
	jsonVersion["fecha"] = QDate::currentDate().toString();	
	
	
	QJsonObject bola1;
	bola1["posX"] = bolas.at(0)->posX;
	bola1["posY"] = bolas.at(0)->posY;
	bola1["velX"] = bolas.at(0)->velX;
	bola1["velY"] = bolas.at(0)->velY;	
	
	jsonPrincipal["bola1"] = bola1;		
	jsonPrincipal["version"] = jsonVersion;
	
	QJsonArray arrayJsonBolas;
	
	for ( int i = 0; i < bolas.size(); i++ ){
	
	QJsonObject bolaX;
	bolaX["posX"] = bolas.at(i)->posX;
	bolaX["posY"] = bolas.at(i)->posY;
	bolaX["velX"] = bolas.at(i)->velX;
	bolaX["velY"] = bolas.at(i)->velY;
	
	QJsonObject colores;
	colores["blue"] = bolas.at(i)->color.blue();
	colores["red"] = bolas.at(i)->color.red();
	colores["green"] = bolas.at(i)->color.green();	
	
	bolaX["colores"] = colores;
		
	arrayJsonBolas.append(bolaX);
	}
	
	jsonPrincipal["bolas"] = arrayJsonBolas;
	
	//Ja tinc el objecte json principal vaig a volcarlo en disco
	QJsonDocument docPartida(jsonPrincipal);
	fichero.write(docPartida.toJson());
	//flujo << "Caguen ta tia \n"<< Qt::flush;
	fichero.close();
}


void MainWindow::slotAbrirPartida(){

	QString ruta = ("partida.json");
	QFile fichero(	ruta );
	if ( !fichero.open(QIODevice::ReadOnly) ) return;
	/*
	QTextStream stream (&fichero)	;
	QString linea;
	
	while ( ! stream.atEnd() ){
		linea = stream.readLine();
		qDebug()<<linea;
	}*/
	
	QByteArray datosGuardados = fichero.readAll();
	
	QJsonDocument documento(QJsonDocument::fromJson(datosGuardados));
	
	QJsonObject jsonPrincipal = documento.object();
	qDebug()<<jsonPrincipal;
	
	QStringList listaClaves = jsonPrincipal.keys();
	
	if ( listaClaves.contains("version") ){
		QJsonValue valorVersion = jsonPrincipal["fecha"];
		
		if( valorVersion.isString() ){
			QString fecha = valorVersion.toString();
			qDebug()<<"Fecha obtenida: ";
			qDebug()<<fecha;
		}else{
			qDebug()<<"Fecha no es un string: ";
		}
	}
	
	if ( listaClaves.contains("bolas") ){
		qDebug()<<"Contiene bolas";
		QJsonValue valorBolas = jsonPrincipal["bolas"];
		
		if( valorBolas.isArray() ){//isObject()
			qDebug()<<"Es un array";
			QJsonArray arrayBolas = valorBolas.toArray();
			for(int i = 0; i < arrayBolas.size(); i++ ){
				QJsonValue valorUnaBola = arrayBolas[i];
				
				if (valorUnaBola.isObject()){
					qDebug()<<"el valor una bola es un objeto";				
					QJsonObject objetoBola = valorUnaBola.toObject();
					QStringList clavesBola = objetoBola.keys();
					if(clavesBola.contains("posX")){
						qDebug()<<"clavesBola contiene posX";
					
						if (objetoBola["posX"].isDouble()){
							qDebug()<<"ObjetoBola es float";
							double posX = objetoBola["posX"].toDouble();
							qDebug()<<"ObjetoBola vale: "<< posX;
							bolas.at(i)->posX = posX;
						}else{
							qDebug()<<"ObjetoBola no es float";						
						}									
					}else{
						qDebug()<<"clavesBola no contiene posX";									
					}
					if(clavesBola.contains("posY")){
						qDebug()<<"clavesBola contiene posY";
					
						if (objetoBola["posY"].isDouble()){
							qDebug()<<"ObjetoBola es float";
							double posY = objetoBola["posY"].toDouble();
							qDebug()<<"ObjetoBola vale: "<< posY;
							bolas.at(i)->posY = posY;
						}else{
							qDebug()<<"ObjetoBola no es float";						
						}									
					}else{
						qDebug()<<"clavesBola no contiene posY";									
					}
					if(clavesBola.contains("velX")){
						qDebug()<<"clavesBola contiene velX";
					
						if (objetoBola["velX"].isDouble()){
							qDebug()<<"ObjetoBola es float";
							double velX = objetoBola["velX"].toDouble();
							qDebug()<<"ObjetoBola vale: "<< velX;
							bolas.at(i)->velX = velX;							
						}else{
							qDebug()<<"ObjetoBola no es float";						
						}									
					}else{
						qDebug()<<"clavesBola no contiene velX";									
					}
					if(clavesBola.contains("velY")){
						qDebug()<<"clavesBola contiene velY";
					
						if (objetoBola["velY"].isDouble()){
							qDebug()<<"ObjetoBola es float";
							double velY = objetoBola["velY"].toDouble();
							qDebug()<<"ObjetoBola vale: "<< velY;
							bolas.at(i)->velY = velY;
						}else{
							qDebug()<<"ObjetoBola no es float";						
						}									
					}else{
						qDebug()<<"clavesBola no contiene velY";									
					}	


					if(clavesBola.contains("colores")){
						qDebug()<<"clavesBola contiene colores";
					
						if (objetoBola["colores"].isObject()){
							qDebug()<<"colores es un objeto";
							QJsonObject colorObjeto = objetoBola["colores"].toObject();
							QStringList clavesColor = colorObjeto.keys();							
							double red,green,blue = 0;
							if ( colorObjeto.contains("blue") ){
								qDebug()<<"contiene blue";
								if (colorObjeto["blue"].isDouble()){
									blue = colorObjeto["blue"].toDouble();
									red = colorObjeto["red"].toDouble();
									green = colorObjeto["green"].toDouble();
								}else{
									qDebug()<<"ObjetoBola no es float";						
								}	
								
							}else{
								qDebug()<<"no contiene blue";
							}
							bolas.at(i)->color = QColor(red,green,blue);
							
						}else{
						qDebug()<<"clavesBola no contiene colores";
						}									
					}else{
						qDebug()<<"clavesBola no contiene velY";									
					}										
					
				}else{
					qDebug()<<"el valor una bola no es un objeto";				
				}
			}

			//QJsonObject objectBolas = valorVolas.toObject();
			
			//QJsonValue valorUnaBola = arrayBolas[i] //retorna QJsonValue
			//valorUnaBola.isObject();
			//QStringList clavesBola = valorUnaBola.toObject().keys;
			
		}else{
			qDebug()<<"No es un array";		
		}
	}else{
	
		qDebug()<<"No contiene bolas";
	
	}
	
}



