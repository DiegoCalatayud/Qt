#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QAction>
#include <QLabel>
#include <QCloseEvent>
#include <QString>

#include"dbuscar.h"



class VentanaPrincipal : public QMainWindow {
Q_OBJECT

public:
	VentanaPrincipal(QWidget * parent = NULL);

	QTextEdit * editorCentral;
	QMenu *menuArchivo;
	QMenu *menuEditar;
	QAction *accionSalir;
	QAction *accionAbrir;
	QAction *accionGuardar;
	QAction *accionNuevo;
	QAction *accionBuscar;
	QString rutaActual;
	DBuscar * dialogoBuscar;

	
	QLabel *etiqueta;
	
	void createActions();
	void createMenus();
	void createContextMenu();
	void createStatusBar();
	void closeEvent(QCloseEvent *event);
	void showEvent(QShowEvent *event);	
	
	bool documentoModificado;
public slots:

void slotAbrir();
void slotGuardar();
void slotNuevo();
void slotEditado();
void slotDialogoBuscar();
void slotBuscar(QString);





};




#endif
