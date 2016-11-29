#ifndef ADDRESSFINDER_H
#define ADDRESSFINDER_H

#include <QtGui/QMainWindow>
#include "ui_addressfinder.h"
#include "Include.h"

class AddressFinder : public QMainWindow
{
	Q_OBJECT

public:
	AddressFinder(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AddressFinder();

	QString qstrProcessName;
	DWORD dwPID;
	DWORD dwImageBase, dwImageSize;

	QLabel* pqlProcess;
	QLabel* pqlImageInfo;

	bool UpdateProcessInfo(QString process, DWORD pid);

private slots:
	void QAction_Triggered();
	void QPushButton_Clicked();

private:
	Ui::CAddressFinder ui;

	void SaveList();
	void OpenList();
};

extern AddressFinder* pAddressFinder;

#endif // ADDRESSFINDER_H
