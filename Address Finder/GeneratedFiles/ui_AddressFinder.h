/********************************************************************************
** Form generated from reading UI file 'AddressFinder.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSFINDER_H
#define UI_ADDRESSFINDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAddressFinder
{
public:
    QAction *actionDeleteSelectedItem;
    QAction *actionCopyAddressNameSelectedItem;
    QAction *actionCopyResultSelectedItem;
    QAction *actionCopyAOBSelectedItem;
    QAction *actionClearSelectedItem;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QLineEdit *leAOB;
    QLabel *label;
    QLineEdit *leAddressName;
    QLabel *label_5;
    QLabel *label_4;
    QSpinBox *sbSize;
    QLabel *label_3;
    QSpinBox *sbOffset;
    QPushButton *pbAddItem;
    QPushButton *pbAttach;
    QPushButton *pbScan;
    QPushButton *pbSaveList;
    QPushButton *pbOpenList;
    QTreeWidget *twAddressFinder;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CAddressFinder)
    {
        if (CAddressFinder->objectName().isEmpty())
            CAddressFinder->setObjectName(QString::fromUtf8("CAddressFinder"));
        CAddressFinder->resize(776, 502);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AddressFinder/Resources/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        CAddressFinder->setWindowIcon(icon);
        actionDeleteSelectedItem = new QAction(CAddressFinder);
        actionDeleteSelectedItem->setObjectName(QString::fromUtf8("actionDeleteSelectedItem"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/AddressFinder/Resources/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteSelectedItem->setIcon(icon1);
        actionCopyAddressNameSelectedItem = new QAction(CAddressFinder);
        actionCopyAddressNameSelectedItem->setObjectName(QString::fromUtf8("actionCopyAddressNameSelectedItem"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/AddressFinder/Resources/Clipboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopyAddressNameSelectedItem->setIcon(icon2);
        actionCopyResultSelectedItem = new QAction(CAddressFinder);
        actionCopyResultSelectedItem->setObjectName(QString::fromUtf8("actionCopyResultSelectedItem"));
        actionCopyResultSelectedItem->setIcon(icon2);
        actionCopyAOBSelectedItem = new QAction(CAddressFinder);
        actionCopyAOBSelectedItem->setObjectName(QString::fromUtf8("actionCopyAOBSelectedItem"));
        actionCopyAOBSelectedItem->setIcon(icon2);
        actionClearSelectedItem = new QAction(CAddressFinder);
        actionClearSelectedItem->setObjectName(QString::fromUtf8("actionClearSelectedItem"));
        actionClearSelectedItem->setIcon(icon1);
        centralWidget = new QWidget(CAddressFinder);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 6, -1, -1);
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        leAOB = new QLineEdit(widget);
        leAOB->setObjectName(QString::fromUtf8("leAOB"));

        gridLayout_4->addWidget(leAOB, 0, 4, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        leAddressName = new QLineEdit(widget);
        leAddressName->setObjectName(QString::fromUtf8("leAddressName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leAddressName->sizePolicy().hasHeightForWidth());
        leAddressName->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(leAddressName, 0, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_5, 0, 2, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 4, 1, 1);

        sbSize = new QSpinBox(groupBox);
        sbSize->setObjectName(QString::fromUtf8("sbSize"));
        sbSize->setMaximum(4);

        gridLayout_2->addWidget(sbSize, 0, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        sbOffset = new QSpinBox(groupBox);
        sbOffset->setObjectName(QString::fromUtf8("sbOffset"));
        sbOffset->setMaximum(10);

        gridLayout_2->addWidget(sbOffset, 0, 3, 1, 1);

        pbAddItem = new QPushButton(groupBox);
        pbAddItem->setObjectName(QString::fromUtf8("pbAddItem"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/AddressFinder/Resources/Create.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbAddItem->setIcon(icon3);

        gridLayout_2->addWidget(pbAddItem, 0, 6, 1, 1);


        gridLayout->addWidget(groupBox, 0, 2, 2, 2);

        pbAttach = new QPushButton(centralWidget);
        pbAttach->setObjectName(QString::fromUtf8("pbAttach"));
        sizePolicy.setHeightForWidth(pbAttach->sizePolicy().hasHeightForWidth());
        pbAttach->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/AddressFinder/Resources/Computer 16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbAttach->setIcon(icon4);

        gridLayout->addWidget(pbAttach, 0, 0, 1, 1);

        pbScan = new QPushButton(centralWidget);
        pbScan->setObjectName(QString::fromUtf8("pbScan"));
        sizePolicy.setHeightForWidth(pbScan->sizePolicy().hasHeightForWidth());
        pbScan->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/AddressFinder/Resources/Find.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbScan->setIcon(icon5);

        gridLayout->addWidget(pbScan, 0, 1, 1, 1);

        pbSaveList = new QPushButton(centralWidget);
        pbSaveList->setObjectName(QString::fromUtf8("pbSaveList"));
        sizePolicy.setHeightForWidth(pbSaveList->sizePolicy().hasHeightForWidth());
        pbSaveList->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/AddressFinder/Resources/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSaveList->setIcon(icon6);

        gridLayout->addWidget(pbSaveList, 1, 0, 1, 1);

        pbOpenList = new QPushButton(centralWidget);
        pbOpenList->setObjectName(QString::fromUtf8("pbOpenList"));
        sizePolicy.setHeightForWidth(pbOpenList->sizePolicy().hasHeightForWidth());
        pbOpenList->setSizePolicy(sizePolicy);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/AddressFinder/Resources/Folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbOpenList->setIcon(icon7);

        gridLayout->addWidget(pbOpenList, 1, 1, 1, 1);

        twAddressFinder = new QTreeWidget(centralWidget);
        twAddressFinder->setObjectName(QString::fromUtf8("twAddressFinder"));
        twAddressFinder->setContextMenuPolicy(Qt::ActionsContextMenu);
        twAddressFinder->setAlternatingRowColors(true);
        twAddressFinder->setIndentation(0);
        twAddressFinder->setUniformRowHeights(true);
        twAddressFinder->setSortingEnabled(true);

        gridLayout->addWidget(twAddressFinder, 2, 0, 1, 4);

        CAddressFinder->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CAddressFinder);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("QStatusBar::item {border: none;}"));
        CAddressFinder->setStatusBar(statusBar);

        retranslateUi(CAddressFinder);
        QObject::connect(pbAttach, SIGNAL(clicked()), CAddressFinder, SLOT(QPushButton_Clicked()));
        QObject::connect(pbScan, SIGNAL(clicked()), CAddressFinder, SLOT(QPushButton_Clicked()));
        QObject::connect(pbSaveList, SIGNAL(clicked()), CAddressFinder, SLOT(QPushButton_Clicked()));
        QObject::connect(pbOpenList, SIGNAL(clicked()), CAddressFinder, SLOT(QPushButton_Clicked()));
        QObject::connect(pbAddItem, SIGNAL(clicked()), CAddressFinder, SLOT(QPushButton_Clicked()));
        QObject::connect(actionClearSelectedItem, SIGNAL(triggered()), CAddressFinder, SLOT(QAction_Triggered()));
        QObject::connect(actionCopyAOBSelectedItem, SIGNAL(triggered()), CAddressFinder, SLOT(QAction_Triggered()));
        QObject::connect(actionCopyAddressNameSelectedItem, SIGNAL(triggered()), CAddressFinder, SLOT(QAction_Triggered()));
        QObject::connect(actionDeleteSelectedItem, SIGNAL(triggered()), CAddressFinder, SLOT(QAction_Triggered()));
        QObject::connect(actionCopyResultSelectedItem, SIGNAL(triggered()), CAddressFinder, SLOT(QAction_Triggered()));

        QMetaObject::connectSlotsByName(CAddressFinder);
    } // setupUi

    void retranslateUi(QMainWindow *CAddressFinder)
    {
        CAddressFinder->setWindowTitle(QApplication::translate("CAddressFinder", "Address Finder", 0, QApplication::UnicodeUTF8));
        actionDeleteSelectedItem->setText(QApplication::translate("CAddressFinder", "Delete", 0, QApplication::UnicodeUTF8));
        actionCopyAddressNameSelectedItem->setText(QApplication::translate("CAddressFinder", "Copy Name", 0, QApplication::UnicodeUTF8));
        actionCopyResultSelectedItem->setText(QApplication::translate("CAddressFinder", "Copy Result", 0, QApplication::UnicodeUTF8));
        actionCopyAOBSelectedItem->setText(QApplication::translate("CAddressFinder", "Copy AOB", 0, QApplication::UnicodeUTF8));
        actionClearSelectedItem->setText(QApplication::translate("CAddressFinder", "Clear All", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CAddressFinder", "Add Item", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CAddressFinder", "Name", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CAddressFinder", "AOB", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CAddressFinder", "Size", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CAddressFinder", "Offset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbAddItem->setToolTip(QApplication::translate("CAddressFinder", "Add", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbAddItem->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbAttach->setToolTip(QApplication::translate("CAddressFinder", "Attach", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbAttach->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbScan->setToolTip(QApplication::translate("CAddressFinder", "Scan", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbScan->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbSaveList->setToolTip(QApplication::translate("CAddressFinder", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbSaveList->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbOpenList->setToolTip(QApplication::translate("CAddressFinder", "Open", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbOpenList->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = twAddressFinder->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("CAddressFinder", "AOB", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("CAddressFinder", "Size", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("CAddressFinder", "Offset", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("CAddressFinder", "Result", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("CAddressFinder", "Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CAddressFinder: public Ui_CAddressFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSFINDER_H
