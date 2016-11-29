#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include <QtGui/QDialog>
#include "ui_processlist.h"
#include "Include.h"

class ProcessList : public QDialog
{
	Q_OBJECT

public:
	ProcessList(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ProcessList();

private slots:
	void QPushButton_Clicked();
	void QTreeWidget_ItemDoubleClicked();

private:
	Ui::CProcessList ui;

	void RefreshProcessList();
};

#endif // PROCESSLIST_H
