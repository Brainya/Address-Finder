/********************************************************************************
** Form generated from reading UI file 'ProcessList.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSLIST_H
#define UI_PROCESSLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_CProcessList
{
public:
    QGridLayout *gridLayout;
    QPushButton *pbRefresh;
    QPushButton *pbAttach;
    QTreeWidget *twProcessList;

    void setupUi(QDialog *CProcessList)
    {
        if (CProcessList->objectName().isEmpty())
            CProcessList->setObjectName(QString::fromUtf8("CProcessList"));
        CProcessList->resize(270, 311);
        gridLayout = new QGridLayout(CProcessList);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pbRefresh = new QPushButton(CProcessList);
        pbRefresh->setObjectName(QString::fromUtf8("pbRefresh"));

        gridLayout->addWidget(pbRefresh, 1, 0, 1, 1);

        pbAttach = new QPushButton(CProcessList);
        pbAttach->setObjectName(QString::fromUtf8("pbAttach"));

        gridLayout->addWidget(pbAttach, 1, 1, 1, 1);

        twProcessList = new QTreeWidget(CProcessList);
        twProcessList->setObjectName(QString::fromUtf8("twProcessList"));
        twProcessList->setAlternatingRowColors(true);
        twProcessList->setIndentation(0);
        twProcessList->setUniformRowHeights(true);
        twProcessList->setSortingEnabled(true);

        gridLayout->addWidget(twProcessList, 0, 0, 1, 2);


        retranslateUi(CProcessList);
        QObject::connect(pbRefresh, SIGNAL(clicked()), CProcessList, SLOT(QPushButton_Clicked()));
        QObject::connect(pbAttach, SIGNAL(clicked()), CProcessList, SLOT(QPushButton_Clicked()));
        QObject::connect(twProcessList, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), CProcessList, SLOT(QTreeWidget_ItemDoubleClicked()));

        QMetaObject::connectSlotsByName(CProcessList);
    } // setupUi

    void retranslateUi(QDialog *CProcessList)
    {
        CProcessList->setWindowTitle(QApplication::translate("CProcessList", "Process List", 0, QApplication::UnicodeUTF8));
        pbRefresh->setText(QApplication::translate("CProcessList", "Refresh", 0, QApplication::UnicodeUTF8));
        pbAttach->setText(QApplication::translate("CProcessList", "Attach", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = twProcessList->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("CProcessList", "PID", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("CProcessList", "Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CProcessList: public Ui_CProcessList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSLIST_H
