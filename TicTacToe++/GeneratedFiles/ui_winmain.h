/********************************************************************************
** Form generated from reading UI file 'winmain.ui'
**
** Created: Sun Dec 19 12:20:22 2010
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winMainClass
{
public:
    QAction *mnuNewGame;
    QAction *mnuExit;
    QAction *mnuAbout;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *grdGame;
    QPushButton *pushButton;
    QMenuBar *mnuMain;
    QMenu *mnuFile;
    QMenu *mnuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *winMainClass)
    {
        if (winMainClass->objectName().isEmpty())
            winMainClass->setObjectName(QString::fromUtf8("winMainClass"));
        winMainClass->resize(558, 483);
        mnuNewGame = new QAction(winMainClass);
        mnuNewGame->setObjectName(QString::fromUtf8("mnuNewGame"));
        mnuExit = new QAction(winMainClass);
        mnuExit->setObjectName(QString::fromUtf8("mnuExit"));
        mnuAbout = new QAction(winMainClass);
        mnuAbout->setObjectName(QString::fromUtf8("mnuAbout"));
        centralWidget = new QWidget(winMainClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 10, 301, 311));
        grdGame = new QGridLayout(gridLayoutWidget);
        grdGame->setSpacing(6);
        grdGame->setContentsMargins(11, 11, 11, 11);
        grdGame->setObjectName(QString::fromUtf8("grdGame"));
        grdGame->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 300, 75, 23));
        winMainClass->setCentralWidget(centralWidget);
        mnuMain = new QMenuBar(winMainClass);
        mnuMain->setObjectName(QString::fromUtf8("mnuMain"));
        mnuMain->setGeometry(QRect(0, 0, 558, 21));
        mnuFile = new QMenu(mnuMain);
        mnuFile->setObjectName(QString::fromUtf8("mnuFile"));
        mnuHelp = new QMenu(mnuMain);
        mnuHelp->setObjectName(QString::fromUtf8("mnuHelp"));
        winMainClass->setMenuBar(mnuMain);
        mainToolBar = new QToolBar(winMainClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        winMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        winMainClass->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(winMainClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        winMainClass->setStatusBar(statusBar);

        mnuMain->addAction(mnuFile->menuAction());
        mnuMain->addAction(mnuHelp->menuAction());
        mnuFile->addAction(mnuNewGame);
        mnuFile->addAction(mnuExit);
        mnuHelp->addAction(mnuAbout);

        retranslateUi(winMainClass);

        QMetaObject::connectSlotsByName(winMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *winMainClass)
    {
        winMainClass->setWindowTitle(QApplication::translate("winMainClass", "winMain", 0, QApplication::UnicodeUTF8));
        mnuNewGame->setText(QApplication::translate("winMainClass", "&New Game", 0, QApplication::UnicodeUTF8));
        mnuExit->setText(QApplication::translate("winMainClass", "E&xit", 0, QApplication::UnicodeUTF8));
        mnuAbout->setText(QApplication::translate("winMainClass", "&About", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("winMainClass", "New Game", 0, QApplication::UnicodeUTF8));
        mnuFile->setTitle(QApplication::translate("winMainClass", "&File", 0, QApplication::UnicodeUTF8));
        mnuHelp->setTitle(QApplication::translate("winMainClass", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class winMainClass: public Ui_winMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINMAIN_H
