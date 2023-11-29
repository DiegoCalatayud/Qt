#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H
#include <QMainWindow>
#include <QPaintEvent>
#include <bola.h>

class MainWindow: public QMainWindow{
Q_OBJECT
public:

	MainWindow(QWidget * parent = NULL);
	void paintEvent(QPaintEvent* evento);
	Bola * bola; 
	static const int NUMBOLAS = 20;
	QVector<Bola*> bolas;
public slots:
void slotTemporizador();
void crearBolas();


};

#endif
