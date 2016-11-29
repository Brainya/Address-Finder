#include "ProcessList.h"

ProcessList::ProcessList(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	setWindowFlags(Qt::Tool | Qt::MSWindowsFixedSizeDialogHint);
	ui.twProcessList->setColumnWidth(0, 180);
	ui.twProcessList->setColumnWidth(1, 40);

	RefreshProcessList();
}

ProcessList::~ProcessList()
{

}

void ProcessList::QPushButton_Clicked()
{
	QObject* pSender = sender();

	if (pSender == ui.pbAttach)
	{
		QTreeWidgetItem* pItem = ui.twProcessList->currentItem();

		if (!pItem)
			return;
		
		if (!pAddressFinder->UpdateProcessInfo(pItem->text(0), pItem->text(1).toInt()))
		{
			QMessageBox::critical(this, "Error", "Failed to attach.");
			return;
		}
		
		close();
	}

	else if (pSender == ui.pbRefresh)
	{
		RefreshProcessList();
	}
}

void ProcessList::QTreeWidget_ItemDoubleClicked()
{
	QObject* pSender = sender();

	if (pSender == ui.twProcessList)
	{
		QTreeWidgetItem* pItem = ui.twProcessList->currentItem();

		if (!pItem)
			return;
		
		if (!pAddressFinder->UpdateProcessInfo(pItem->text(0), pItem->text(1).toInt()))
		{
			QMessageBox::critical(this, "Error", "Failed to attach.");
			return;
		}
		
		close();
	}
}

void ProcessList::RefreshProcessList()
{
	ui.twProcessList->clear();

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);

	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
	
		if (Process32First(hSnapshot, &pe))
		{
			do
			{
				QTreeWidgetItem* pItem = new QTreeWidgetItem();
				pItem->setText(0, QString().fromWCharArray(pe.szExeFile));
				pItem->setText(1, QString::number(pe.th32ProcessID));
				ui.twProcessList->addTopLevelItem(pItem);
			}
			while (Process32Next(hSnapshot, &pe));
		}
	}

	CloseHandle(hSnapshot);
}