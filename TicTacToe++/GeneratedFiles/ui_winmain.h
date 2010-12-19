/********************************************************************************
** Form generated from reading UI file 'winmain.ui'
**
** Created: Sun Dec 19 01:04:20 2010
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINMAIN_H
#define UI_WINMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winMainClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *winMainClass)
    {
        if (winMainClass->objectName().isEmpty())
            winMainClass->setObjectName(QString::fromUtf8("winMainClass"));
        winMainClass->resize(600, 400);
        menuBar = new QMenuBar(winMainClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        winMainClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(winMainClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        winMainClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(winMainClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        winMainClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(winMainClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        winMainClass->setStatusBar(statusBar);

        retranslateUi(winMainClass);

        QMetaObject::connectSlotsByName(winMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *winMainClass)
    {
        winMainClass->setWindowTitle(QApplication::translate("winMainClass", "winMain", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class winMainClass: public Ui_winMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINMAIN_H
