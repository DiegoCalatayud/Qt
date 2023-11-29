#include <mainwindow.h>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QTimer>
#include <math.h>
#include <bola.h>


MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent){

resize(800,600);

	bola = new Bola(); 
	
	//bolas = QVector(NUMBOLAS);
	QTimer * temporizador = new QTimer();
	temporizador->setInterval(10);
	temporizador->setSingleShot(false);
	temporizador->start();
	crearBolas();
	connect( temporizador,SIGNAL(timeout()),
		this,SLOT(slotTemporizador()));

};
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
	//qDebug()<<"Me están pulsando";
	
	update();/*
	
	if(bola->posX>=(width()-20))bola->velX = -fabs(bola->velX);
	
	if(bola->posX<=0)bola->velX = +fabs(bola->velX);;
	
	if(bola->posY>=(height()-20))bola->velY = -fabs(bola->velY);
	
	if(bola->posY<=0)bola->velY = +fabs(bola->velY);;
	

	bola->posX = bola->posX + bola->velX;
	bola->posY = bola->posY + bola->velY;
	
	/*
	
	if(posX>=(width()-20))finalX =  true;
	
	if(posX<=0)finalX =  false;
	
	if(posY>=(height()-20))finalY =  true;
	
	if(posY<=0)finalY =  false;
	*/
	
	
	/*
	if(finalX){
				posX = posX - 4;
	}else{
				posX = posX + 4;
	}
	
	if(finalY){
				posY = posY - 4;
	}else{
				posY = posY + 4;
	}
	
	
	class Bola {
	public:
		Bola();
		float posX,posY,velX,velY;
	};
*/
	

}
