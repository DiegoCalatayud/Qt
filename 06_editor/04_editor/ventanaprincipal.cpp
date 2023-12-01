#include "ventanaprincipal.h"
#include <QIcon>
#include <QToolBar>
#include <QMenuBar>
#include <QLabel>
#include <QComboBox>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QTextStream>

#include <QTextBlock>
#include <QTextDocument>
#include <QTextStream>









VentanaPrincipal::VentanaPrincipal (QWidget * parent) :

		
		 QMainWindow(parent) {
		 etiqueta = new QLabel("Editor Listo");
		 editorCentral = new QTextEdit();
		 setCentralWidget(editorCentral);
		  documentoModificado = false;
		 setWindowIcon(QIcon("./images/icono.png"));
		 dialogoBuscar = NULL;
		 resize (800,600);
			
		createActions();
		createMenus(); 
		
		createContextMenu();
		createStatusBar();
 }
		 
		 
void VentanaPrincipal::createActions(){
				 accionSalir = new QAction("Salir");
				 accionSalir->setIcon(QIcon("./images/icons8-exit-50.png"));
				 accionSalir->setShortcut(QKeySequence("Ctrl+q"));
				 accionSalir->setStatusTip("Sal y vete a tomar por c..");
				 accionSalir->setToolTip("Sal y vete a tomar por c..");	
				 
				 
				 accionAbrir = new QAction("Abrir");
				 accionAbrir->setIcon(QIcon("./images/icons8-open-64.png"));
				 accionAbrir->setShortcut(QKeySequence("Ctrl+t"));
				 accionAbrir->setStatusTip("Esto es para abrir");
				 accionAbrir->setToolTip("Esto es para abrir");	
				 
				 
				 
				 accionGuardar = new QAction("Guardar");
				 accionGuardar->setIcon(QIcon("./images/icons8-save-50.png"));
				 accionGuardar->setShortcut(QKeySequence("Ctrl+l"));
				 accionGuardar->setStatusTip("Esto es para guardar");
				 accionGuardar->setToolTip("Esto es para guardar");
				 
				 accionNuevo = new QAction("Nuevo");
				 accionNuevo->setIcon(QIcon("./images/icons8-clear-80.png"));
				 accionNuevo->setShortcut(QKeySequence("Ctrl+p"));
				 accionNuevo->setStatusTip("Esto es para borrar");
				 accionNuevo->setToolTip("Esto es para borrar");	
				 
				 
				 
				 
				 
				 //p2
				 accionBuscar = new QAction("buscar");
				 accionBuscar->setIcon(QIcon("./images/icons8-clear-80.png"));
				 accionBuscar->setShortcut(QKeySequence("Ctrl+f"));
				 accionBuscar->setStatusTip("Esto es para buscar");
				 accionBuscar->setToolTip("Esto es para buscar");	
				 
				 
				 	 
				 	 
				 connect(accionSalir,SIGNAL(triggered()),
				 				this,SLOT(close()));
				 connect(accionAbrir,SIGNAL(triggered()),
				 				this,SLOT(slotAbrir()));
				 connect(accionGuardar,SIGNAL(triggered()),
				 				this,SLOT(slotGuardar()));
				 connect(accionNuevo,SIGNAL(triggered()),
				 				this,SLOT(slotNuevo()));
				 connect(editorCentral,SIGNAL(textChanged()),
				 				this,SLOT(slotEditado()));
				 				
				 				
				 				
//p2

				 connect(accionBuscar,SIGNAL(textChanged()),
				 				this,SLOT(slotBuscar()));				 				
				 				
				 				
				 							 								 								 				
}

void VentanaPrincipal::createMenus(){
	  menuEditar = new QMenu("Editar");
	  menuEditar->addAction(slotBuscar);



	  menuArchivo = new QMenu("Archivo");
	  menuArchivo->addAction(accionSalir); 
	  menuArchivo->addSeparator(); 	  
	  menuArchivo->addAction(accionAbrir); 
	  menuArchivo->addAction(accionGuardar); 	  	  
	  menuArchivo->addAction(accionNuevo); 	  	  	  
		 	  
	  menuBar()->addMenu(menuArchivo);
	  
	  
	  
	  QToolBar * barraPrincipal;
	barraPrincipal = addToolBar("Principal");
	barraPrincipal->addAction(accionSalir);
	barraPrincipal->addAction(accionAbrir);
	barraPrincipal->addAction(accionGuardar);		
	barraPrincipal->addAction(accionNuevo);			
}		 

void VentanaPrincipal::createContextMenu(){
	editorCentral->addAction(accionSalir);
	editorCentral->addAction(accionAbrir);
	editorCentral->addAction(accionGuardar);
	editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);
	
}
void VentanaPrincipal::createStatusBar(){
//	QLabel *etiqueta = new QLabel("Editor Listo");
	QComboBox *combobox = new QComboBox ();
	combobox->addItem("1");
	combobox->addItem("2");
	
	statusBar()->addWidget(etiqueta);
	statusBar()->addWidget(combobox);		
	
}


void VentanaPrincipal::showEvent(QShowEvent *event){

	editorCentral->selectAll();

}

void VentanaPrincipal::closeEvent(QCloseEvent *event){

	if(documentoModificado){
		int respuesta;
		respuesta = QMessageBox::question(this,"Estás cerrando","¿Quieres continuar?", QMessageBox::Ok | QMessageBox::Cancel);
		
		if ( respuesta == QMessageBox::Cancel ){
			event->ignore();
		}
	}
}

void VentanaPrincipal::slotAbrir(){


	

	if(!documentoModificado){
	
		etiqueta->setText("Abriendo...");
	}else{
		int respuesta;
		respuesta = QMessageBox::warning(this,"Fichero Modificado","¿Quieres continuar?", QMessageBox::Ok | QMessageBox::Cancel);
		etiqueta->setText("MOdificado...");
		if(respuesta == QMessageBox::Ok ){
			editorCentral->setText("");
			documentoModificado=false;
			
		}
	}
	

	QString ruta;

	ruta = QFileDialog::getOpenFileName(this, QString("abrir archivo para editar"),QString("Ficheros de texto (*.txt)"));
	rutaActual = ruta;
	if ( ruta.isEmpty() ) return;
	QFile fichero(ruta);
	
	
	
	if (! fichero.open(QIODevice::ReadOnly) ) return;
	
	QTextStream stream (&fichero);
	
	qDebug() << "El dialogo responde: " << ruta;
	
	QString linea;
			editorCentral -> clear();
	while ( ( linea = stream.readLine() ) != NULL ){
	
		editorCentral -> append(linea);
	}

}
void VentanaPrincipal::slotGuardar(){

	if(documentoModificado){
		documentoModificado=false;
		etiqueta->setText("Guardando...");
	}else{
		etiqueta->setText("MOdificado...");
	}
	
	
	QFile fichero(	rutaActual );
	
	QTextStream flujo(&fichero);
	
	for ( int i = 0; i < editorCentral->document()->blockCount(); i++ ){
	
		QString cadena;
		cadena = editorCentral->document()->findBlockByNumber(i).text();
		flujo << cadena << '\n' << Qt::flush;
		
	
	}
	
	fichero.close();
	
}

void VentanaPrincipal::slotNuevo(){





	


	if(!documentoModificado){
		editorCentral->setText("");
		etiqueta->setText("noMOdificado...");
	}else{
		int respuesta;
		respuesta = QMessageBox::warning(this,"Fichero Modificado","¿Quieres continuar?", QMessageBox::Ok | QMessageBox::Cancel);
		etiqueta->setText("MOdificado...");
		if(respuesta == QMessageBox::Ok ){
			editorCentral->clear();
				documentoModificado=false;
			
		}
	}
	
}
void VentanaPrincipal::slotEditado(){
	documentoModificado=true;
}


void VentanaPrincipal::slotBuscar(){

	if( dialogoBuscar== NULL ) dialogoBuscar = new DBuscar();
	
	dialogoBuscar->show();
	
}






		 
		 
		 
		 
		 
