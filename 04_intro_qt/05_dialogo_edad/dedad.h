#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>

class DEdad : public QWidget {

Q_OBJECT	

public:

DEdad(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

	QLabel * etiqSup;
	QLabel * etiqInfo;
	QSpinBox * spinBox;
	QPushButton * button;

public slots:	
	void slotIndica (int);
	void slotLimpia ();


};
