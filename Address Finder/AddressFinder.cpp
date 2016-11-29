#include "AddressFinder.h"

AddressFinder* pAddressFinder;

AddressFinder::AddressFinder(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	pAddressFinder = this;
	pCScan = new CScan();

	ui.setupUi(this);
	ui.twAddressFinder->setColumnWidth(0, 150);
	ui.twAddressFinder->setColumnWidth(1, 80);
	ui.twAddressFinder->setColumnWidth(2, 45);
	ui.twAddressFinder->setColumnWidth(3, 45);

	ui.twAddressFinder->addAction(ui.actionCopyAddressNameSelectedItem);
	ui.twAddressFinder->addAction(ui.actionCopyResultSelectedItem);
	ui.twAddressFinder->addAction(ui.actionCopyAOBSelectedItem);
	ui.twAddressFinder->addAction(ui.actionDeleteSelectedItem);
	ui.twAddressFinder->addAction(ui.actionClearSelectedItem);

	pqlProcess = new QLabel();
	pqlImageInfo = new QLabel();
	ui.statusBar->addWidget(pqlProcess, 0);
	ui.statusBar->addWidget(pqlImageInfo, 1);
	ui.statusBar->addPermanentWidget(new QLabel("1.0 by Meso615134"));

	UpdateProcessInfo(NULL, 0);
}

AddressFinder::~AddressFinder()
{

}

void AddressFinder::QAction_Triggered()
{
	QObject* pSender = sender();

	if (pSender == ui.actionClearSelectedItem)
	{
		ui.twAddressFinder->clear();
	}

	else if (pSender == ui.actionDeleteSelectedItem)
	{
		QTreeWidgetItem* pItem = ui.twAddressFinder->currentItem();

		if (pItem)
			delete pItem;
	}

	else if (pSender == ui.actionCopyAddressNameSelectedItem)
	{
		QTreeWidgetItem* pItem = ui.twAddressFinder->currentItem();

		if (pItem)
		{
			QClipboard* pClipboard = QApplication::clipboard();
			pClipboard->setText(pItem->text(0));
		}
	}

	else if (pSender == ui.actionCopyResultSelectedItem)
	{
		QTreeWidgetItem* pItem = ui.twAddressFinder->currentItem();

		if (pItem)
		{
			QClipboard* pClipboard = QApplication::clipboard();
			pClipboard->setText(pItem->text(1));
		}
	}

	else if (pSender == ui.actionCopyAOBSelectedItem)
	{
		QTreeWidgetItem* pItem = ui.twAddressFinder->currentItem();

		if (pItem)
		{
			QClipboard* pClipboard = QApplication::clipboard();
			pClipboard->setText(pItem->text(4));
		}
	}
}

void AddressFinder::QPushButton_Clicked()
{
	QObject* pSender = sender();

	if (pSender == ui.pbAttach)
	{
		ProcessList Dialog(this);
		Dialog.exec();
	}

	else if (pSender == ui.pbScan)
	{
		if (!UpdateProcessInfo(qstrProcessName, dwPID))
		{
			QMessageBox::critical(this, "Error", "Failed to scan.\nPlease attach to process.");
			return;
		}

		QTreeWidget* pTree = ui.twAddressFinder;

		if (!pTree->topLevelItemCount())
		{
			QMessageBox::critical(this, "Error", "Please add items to list.");
			return;
		}

		for (int i = 0; i <= pTree->topLevelItemCount()-1; i++)
		{
			DWORD dwAddress = reinterpret_cast<DWORD>(pCScan->FindMemoryPattern(qstrProcessName.toStdString(), dwPID, pTree->topLevelItem(i)->text(4).replace("?", "??").replace("*", "**").remove(" ").toUtf8().data(), pTree->topLevelItem(i)->text(2).toInt(), pTree->topLevelItem(i)->text(3).toInt()));

			if (dwAddress)
			{
				pTree->topLevelItem(i)->setTextColor(1, (QColor)Qt::darkGreen);
				pTree->topLevelItem(i)->setText(1, QString().sprintf("%08X", dwAddress));
			}
			else
			{
				pTree->topLevelItem(i)->setTextColor(1, (QColor)Qt::red);
				pTree->topLevelItem(i)->setText(1, "Not Found");
			}
		}

		QMessageBox::information(this, "Message", "The scan completed successfully.");
	}

	else if (pSender == ui.pbAddItem)
	{
		if (ui.leAddressName->text().trimmed().isEmpty() || ui.leAOB->text().trimmed().isEmpty())
			return;
			
		QTreeWidgetItem* pItem = new QTreeWidgetItem();
		pItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsSelectable);
		pItem->setText(0, ui.leAddressName->text().trimmed());
		pItem->setText(2, QString::number(ui.sbOffset->value()));
		pItem->setText(3, QString::number(ui.sbSize->value()));
		pItem->setText(4, ui.leAOB->text().trimmed().replace("??", "?").replace("**", "*").toUpper());

		ui.twAddressFinder->addTopLevelItem(pItem);
	}

	else if (pSender == ui.pbSaveList)
	{
		if (!ui.twAddressFinder->topLevelItemCount())
		{
			QMessageBox::critical(this, "Error", "Please add items to list.");
			return;
		}

		SaveList();
	}

	else if (pSender == ui.pbOpenList)
	{
		OpenList();
	}
}

bool AddressFinder::UpdateProcessInfo(QString process, DWORD pid)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	MODULEENTRY32 mod;

	mod.dwSize = sizeof(mod);

	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		if (Module32First(hSnapshot, &mod))
		{
			do
			{
				if (QString().fromWCharArray(mod.szModule) == process)
				{
					qstrProcessName = process;
					dwPID = pid;
					dwImageBase = reinterpret_cast<DWORD>(mod.modBaseAddr);
					dwImageSize = mod.modBaseSize;

					pqlProcess->setStyleSheet("color:green;");
					pqlProcess->setText(qstrProcessName + " - " + QString::number(dwPID) + " ");
					pqlImageInfo->setText("Image Base : " + QString().sprintf("%08X", dwImageBase) + " Image Size : " + QString().sprintf("%08X", dwImageSize));

					CloseHandle(hSnapshot);
					return true;
				}
			}
			while (Module32Next(hSnapshot, &mod));
		}
	}

	qstrProcessName.clear();
	SecureZeroMemory(&dwPID, sizeof(DWORD));
	SecureZeroMemory(&dwImageBase, sizeof(DWORD));
	SecureZeroMemory(&dwImageSize, sizeof(DWORD));

	pqlProcess->setStyleSheet("color:red;");
	pqlProcess->setText("None");
	pqlImageInfo->setText("Image Base : None" + QString(" Image Size : None"));

	CloseHandle(hSnapshot);
	return false;
}

void AddressFinder::SaveList()
{
	QString qstrFile = QFileDialog::getSaveFileName(this, "Save File", ".", "Text File(*.txt)");
	QFile file(qstrFile);
	
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

    QTextStream out(&file);
	QString qstrOut;

	for (int i = 0; i <= ui.twAddressFinder->topLevelItemCount()-1; i++)
	{
		QTreeWidgetItem* pItem = ui.twAddressFinder->topLevelItem(i);

		if (pItem->text(1).isEmpty() || pItem->text(1) == "Not Found")
			pItem->setText(1, "00000000");

		qstrOut.append(pItem->text(0) + " = " + pItem->text(1) + " #" + pItem->text(2) + "#" + pItem->text(3) + "# //" + pItem->text(4) + "\n");
	}

	out << qstrOut;
	file.close();
}

void AddressFinder::OpenList()
{
	QString qstrFile = QFileDialog::getOpenFileName(this, "Open File", ".", "Text File(*.txt)");
	QFile file(qstrFile);
	
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	ui.twAddressFinder->clear();
	QTextStream in(&file);

	while (!in.atEnd())
	{
		QString qstrLine = in.readLine();

		QString qstrFirst = qstrLine.mid(0, qstrLine.indexOf("//")-1).trimmed();
		QString qstrSecond = qstrLine.mid(qstrLine.indexOf("//")+2).trimmed();

		QString qstrAddressName = qstrFirst.mid(0, qstrFirst.indexOf("=")).trimmed();
		QString qstrResult = qstrFirst.mid(qstrFirst.indexOf("=")+1, qstrFirst.indexOf("#")-2-qstrFirst.indexOf("=")+1).trimmed();
		QString qstrOffset = qstrFirst.mid(qstrFirst.indexOf("#")+1, 1);
		QString qstrSize = qstrFirst.mid(qstrFirst.indexOf("#", 1)+1, 1);

		QTreeWidgetItem* pItem = new QTreeWidgetItem();
		pItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsSelectable);
		pItem->setText(0, qstrAddressName);
		pItem->setText(1, qstrResult);
		pItem->setText(2, qstrOffset);
		pItem->setText(3, qstrSize);
		pItem->setText(4, qstrSecond);
		ui.twAddressFinder->addTopLevelItem(pItem);
	}

	file.close();
}