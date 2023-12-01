#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H
#include <QMainWindow>
#include <QPaintEvent>
#include <bola.h>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
class MainWindow: public QMainWindow{
Q_OBJECT
public:

	MainWindow(QWidget * parent = NULL);
	void paintEvent(QPaintEvent* evento);
	Bola * bola; 
	static const int NUMBOLAS = 20;
	QVector<Bola*> bolas;
	void createActions();
	void createMenus(); 
	QMenu *menuArchivo;
	QAction *accionGuardar;
	QAction *accionAbrirPartida;
	
	QAction *quitarColores;
public slots:
void slotTemporizador();
void crearBolas();
void slotGuardar();
void slotAbrirPartida();


};

#endif
