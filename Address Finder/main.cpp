#include "addressfinder.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AddressFinder w;
	w.show();
	return a.exec();
}
