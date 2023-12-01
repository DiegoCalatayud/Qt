#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QVector>
#include <QAction>
#include <QMenu>

#include "bola.h"

class MainWindow : public QMainWindow{
Q_OBJECT

public:
	MainWindow(QWidget *parent =NULL);
	
	QAction *actionGuardarPartida;
	QAction *actionCargarPartida;	
	
	void paintEvent(QPaintEvent * evento);

	Bola * bolaJugador;
	
	QVector<Bola*> bolas;

	static const int NUMBOLAS=10;
	void crearBolas();
	void crearActions();
	void crearMenus();	
	void keyPressEvent( QKeyEvent * evento );
	
public slots:
	void slotTemporizador();
	void slotGuardarPartida();
	void slotCargarPartida();	

};



#endif
