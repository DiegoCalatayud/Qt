#include <QApplication>
#include <QLabel>
#include <unistd.h>
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
 	QApplication app(argc, argv);
 	QLabel *label = new QLabel("<h2><i>Hello</i> "
                       	"<font color=red>Qt!</font></h2>");
 	label->show();
 	sleep(5);
 	cout <<label << endl;
 	sleep(5);
 	return app.exec();
 }

