#ifndef DBUSCAR_H
#define DBUSCAR_H


#include <QVector>
#include <QHBoxLayout>
#include <QDialog>
#include "ui_dbuscar.h"




class DBuscar : public QDialog, Ui::DBuscar {
Q_OBJECT

public:

	DBuscar(QWidget * parent = NULL);


public slots:

	void slotBotonBuscar();

signals:
	void senyalBuscar(QString);


};




#endif
