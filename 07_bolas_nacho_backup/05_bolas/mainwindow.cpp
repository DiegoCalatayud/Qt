#include "mainwindow.h"
#include <math.h>
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QMenuBar>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDate>


MainWindow::MainWindow(QWidget * parent ) : QMainWindow(parent){


	resize(800,600);
	
	
	QTimer *temporizador = new QTimer();
	temporizador->setInterval(40);
	temporizador->setSingleShot(false);
	temporizador->start();
	
	crearBolas();
	
	connect(temporizador,SIGNAL(timeout()),
				this,SLOT(slotTemporizador()));
				
	crearActions();
	crearMenus();
}

void MainWindow::crearActions(){

	actionGuardarPartida = new QAction("guardar");
	connect(actionGuardarPartida,SIGNAL(triggered()),
					this,SLOT(slotGuardarPartida()));
					
	actionCargarPartida = new QAction("cargar");
	connect(actionCargarPartida,SIGNAL(triggered()),
					this,SLOT(slotCargarPartida()));					

}

void MainWindow::crearMenus(){

	QMenu * menuArchivo = menuBar()->addMenu("Harxibo");
	menuArchivo->addAction(actionGuardarPartida);
	menuArchivo->addAction(actionCargarPartida);


}

void MainWindow::crearBolas(){

    for ( int i= 0; i< NUMBOLAS ; i++) {
   	 Bola *nueva = new Bola();
   	 nueva->posX = random()% width();
   	 nueva->posY = random()% height();
   	 nueva->velX =(float)(rand()%100) / 50 -1;
   	 nueva->velY =(float)(rand()%100) / 50 -1;
   	 
   	 nueva->velX = nueva->velX *3;
   	 nueva->velY = nueva->velY *3;

   	 bolas.append(nueva);
        
    }
    
    bolaJugador = new Bola();
    bolaJugador->especial = true;
    bolaJugador->velX = bolaJugador->velY =0;
    bolaJugador->posX = bolaJugador->posY = 400;
    bolaJugador->color = QColor(0,0,0);
    bolaJugador->vidas = 100;
}



void MainWindow::paintEvent(QPaintEvent * event){
	
	QPainter pintor(this);
	
	for (int i=0; i< bolas.size();i++)
   	 bolas[i]->pintar(pintor);
   	 
 	bolaJugador->pintar(pintor);
}

void MainWindow::slotTemporizador() {
	
	for (int i=0; i< bolas.size();i++)
   	 bolas[i]->mover(width(),height());	
   	 
  bolaJugador->mover(width(),height());
  	 
 	for (int i=0; i< bolas.size();i++)  	 
 		for (int j=0; j< bolas.size();j++) 
 			if ( (i !=j ) && bolas.at(i)->choca(bolas.at(j) )) {
 					qDebug() << "Hay choque " << i << " " << j;
 			bolas.at(i)-> vidas--;
 			bolas.at(j)-> vidas--;
 		}
 	
 	for (int i=0; i< bolas.size();i++)  {	 	
 		if ( bolaJugador->choca(bolas.at(i)) )
			bolaJugador-> vidas--;
 			bolas.at(i)-> vidas--;
 		}
	//posY = posY + 1;
	update();
}


void MainWindow::keyPressEvent( QKeyEvent * evento ){
	int teclaPulsada = evento->key();
	
	

	switch (teclaPulsada) {
		case Qt::Key_Up:
		    bolaJugador->velY -= 0.1;
		    break;
		case Qt::Key_Down:
		    bolaJugador->velY += 0.1;
		    break;
		case Qt::Key_Left:
		    bolaJugador->velX -= 0.1;
		    break;
		case Qt::Key_Right:
		    bolaJugador->velX += 0.1;
		    break;

		default:

		    break;
	}	
	
	
}

void MainWindow::slotCargarPartida(){
 QString ruta = QString("partida.json");
   QFile fichero(ruta);

 if ( ! fichero.open(QIODevice::ReadOnly) )
            return;
            
	QByteArray datosGuardados = fichero.readAll();  

	QJsonDocument documento(QJsonDocument::fromJson(datosGuardados) );

	QJsonObject jsonPrincipal = documento.object();
	
	QStringList listaClaves = jsonPrincipal.keys();
  
  if (listaClaves.contains("autor") ) {
  	QJsonValue valorAutor = jsonPrincipal["autor"];
  	if (valorAutor.isString() ){
  		QString autor = valorAutor.toString();
  		qDebug()<< " autor es " << autor;
  		}
  }
  
  if (listaClaves.contains("bolas") ) {
  	QJsonValue valorBolas = jsonPrincipal["bolas"];
  	if (valorBolas.isArray()) {  // if (valorBolas.isObject();
			QJsonArray arrayBolas = valorBolas.toArray();  
//		QJsonObject objectBolas = valorBolas.toObject();

			int cuantas = arrayBolas.size();
			for (int i = 0 ; i < cuantas; i++){
				float posX,posY,velX,velY ;
				 posX=posY=velX=velY= -9000 ;
				QJsonValue valorBola = arrayBolas[i];
				if (! valorBola.isObject()) {
					qDebug() << "La bola " << i << " datos incorrectos";	
					break;	
				}		
				QJsonObject objetoBola = valorBola.toObject();
				QStringList clavesBola = objetoBola.keys();
				if (clavesBola.contains("posX") &&
						 objetoBola["posX"].isDouble()) {
						 posX = objetoBola["posX"].toDouble();		 
				}		  
				if (clavesBola.contains("posY") &&
						 objetoBola["posY"].isDouble()) {
						 posY = objetoBola["posY"].toDouble();		 
				}		  
				if (clavesBola.contains("velX") &&
						 objetoBola["velX"].isDouble()) {
						 velX = objetoBola["velX"].toDouble();		 
				}		  
				if (clavesBola.contains("velY") &&
						 objetoBola["velY"].isDouble()) {
						 velY = objetoBola["velY"].toDouble();		 
				}		  			
				if (clavesBola.contains("color") &&
							objetoBola["color"].isArray() ) {
						int rojo,verde,azul;
						QJsonArray aC = objetoBola["color"].toArray();
										
						bolas.at(i)->color = QColor(
						 aC[0].toInt(),
						 aC[1].toInt(),
						 aC[2].toInt());
				}
				
				if (clavesBola.contains("color") &&
						objetoBola["color"].isObject() ){
							QJsonObject colores =objetoBola["color"].toObject();
							int rojo = colores["rojo"].toInt();
							int verde = colores["verde"].toInt();						
							int azul = colores["azul"].toInt();			
							bolas.at(i)->color = QColor(rojo,verde,azul);			
						}
				
							
				bolas.at(i)->posX = posX;				
				bolas.at(i)->velX = velX;				
				bolas.at(i)->posY = posY;				
				bolas.at(i)->velY = velY;				
			}
		}
  }
 
}


void MainWindow::slotGuardarPartida(){

        
   QString ruta = QString("partida.json");
   QFile fichero(ruta);
        
    if ( ! fichero.open(QIODevice::WriteOnly) )
            return;
        
   QTextStream flujo(&fichero); 
   /* Anem a generar el json */
   
   QJsonObject jsonPrincipal;
   
   jsonPrincipal["autor"] = QString("Nacho");

/*	version:
			version:numero
			subversion: numero
			sistema operativo: "linux"
			fecha: */
			
			QJsonObject jsonVersion;
			jsonVersion["version"] = 0;
			jsonVersion["subversion"] = 3;
			jsonVersion["sistema operativo"] = "linux";
			jsonVersion["zfecha"] = QDate::currentDate().toString();
				
			jsonPrincipal["version" ] = jsonVersion;
			
			QJsonObject jsonBolaPrimera;
			
			jsonBolaPrimera["posX"] = bolas.at(0)->posX;
			jsonBolaPrimera["posY"] = bolas.at(0)->posY;
			jsonBolaPrimera["velX"] = bolas.at(0)->velX;			
			jsonBolaPrimera["velY"] = bolas.at(0)->velY;
			
			//jsonPrincipal["bolaPrimera"] = jsonBolaPrimera;		
			
			
			QJsonArray arrayJsonBolas;

			
    for ( int i= 0; i< bolas.size() ; i++) {
					QJsonObject jsonEstaBola;
					
				jsonEstaBola["posX"] = bolas.at(i)->posX;
				jsonEstaBola["posY"] = bolas.at(i)->posY;
				jsonEstaBola["velX"] = bolas.at(i)->velX;			
				jsonEstaBola["velY"] = bolas.at(i)->velY;
					
					QJsonArray arrayJsonColores;
					
					int asul = bolas.at(i)->color.blue();
					int bede = bolas.at(i)->color.green();
					int dojo = bolas.at(i)->color.red();
				QJsonArray arrayColores;
				arrayColores.append(dojo);
				arrayColores.append(bede);
				arrayColores.append(asul);
	/* aço es podria fer pero no te sentit			arrayColores.append(jsonBolaPrimera); */
	
/*				jsonColor["rojo"] = dojo;
				jsonColor["verde"] = bede;
				jsonColor["azul"] = asul;*/
				jsonEstaBola["color"] = arrayColores;				
				arrayJsonBolas.append(jsonEstaBola);
			}
			
			jsonPrincipal["bolas"] = arrayJsonBolas;
				
/* ja tinc el objecte json principal to guapo 
i vaig a vomitarlo al disco */
   QJsonDocument docPartida(jsonPrincipal);
     
   fichero.write(docPartida.toJson());
     
   fichero.close();
   
}

