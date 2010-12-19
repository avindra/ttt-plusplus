/********************************************************************************
** Form generated from reading UI file 'winmain.ui'
**
** Created: Sun Dec 19 18:27:21 2010
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winMainClass
{
public:
    QAction *mnuNewGame;
    QAction *mnuExit;
    QAction *mnuAbout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *grdGame;
    QVBoxLayout *verticalLayout;
    QLabel *lblTurn;
    QGroupBox *grpDificil;
    QRadioButton *radEasy;
    QRadioButton *radNormal;
    QRadioButton *radHard;
    QRadioButton *radDeath;
    QGroupBox *grpOpp;
    QRadioButton *radComputer_3;
    QRadioButton *radHuman_3;
    QVBoxLayout *layBtns;
    QPushButton *btnNew;
    QPushButton *btnExit;
    QMenuBar *mnuMain;
    QMenu *mnuFile;
    QMenu *mnuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *winMainClass)
    {
        if (winMainClass->objectName().isEmpty())
            winMainClass->setObjectName(QString::fromUtf8("winMainClass"));
        winMainClass->setWindowModality(Qt::NonModal);
        winMainClass->resize(615, 572);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(winMainClass->sizePolicy().hasHeightForWidth());
        winMainClass->setSizePolicy(sizePolicy);
        winMainClass->setSizeIncrement(QSize(0, 0));
        winMainClass->setLayoutDirection(Qt::LeftToRight);
        winMainClass->setStyleSheet(QString::fromUtf8(""));
        mnuNewGame = new QAction(winMainClass);
        mnuNewGame->setObjectName(QString::fromUtf8("mnuNewGame"));
        mnuExit = new QAction(winMainClass);
        mnuExit->setObjectName(QString::fromUtf8("mnuExit"));
        mnuAbout = new QAction(winMainClass);
        mnuAbout->setObjectName(QString::fromUtf8("mnuAbout"));
        centralWidget = new QWidget(winMainClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        grdGame = new QGridLayout();
        grdGame->setSpacing(6);
        grdGame->setObjectName(QString::fromUtf8("grdGame"));
        grdGame->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout_3->addLayout(grdGame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblTurn = new QLabel(centralWidget);
        lblTurn->setObjectName(QString::fromUtf8("lblTurn"));
        lblTurn->setMinimumSize(QSize(0, 31));
        lblTurn->setMaximumSize(QSize(16777215, 60));
        lblTurn->setStyleSheet(QString::fromUtf8("background-color:blue;\n"
"color:white;\n"
"font-weight:bold;\n"
"font-size:24px;"));
        lblTurn->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTurn);

        grpDificil = new QGroupBox(centralWidget);
        grpDificil->setObjectName(QString::fromUtf8("grpDificil"));
        grpDificil->setMinimumSize(QSize(199, 116));
        radEasy = new QRadioButton(grpDificil);
        radEasy->setObjectName(QString::fromUtf8("radEasy"));
        radEasy->setGeometry(QRect(10, 20, 82, 17));
        radNormal = new QRadioButton(grpDificil);
        radNormal->setObjectName(QString::fromUtf8("radNormal"));
        radNormal->setGeometry(QRect(10, 40, 82, 17));
        radHard = new QRadioButton(grpDificil);
        radHard->setObjectName(QString::fromUtf8("radHard"));
        radHard->setGeometry(QRect(10, 60, 82, 17));
        radDeath = new QRadioButton(grpDificil);
        radDeath->setObjectName(QString::fromUtf8("radDeath"));
        radDeath->setGeometry(QRect(10, 80, 82, 17));

        verticalLayout->addWidget(grpDificil);

        grpOpp = new QGroupBox(centralWidget);
        grpOpp->setObjectName(QString::fromUtf8("grpOpp"));
        grpOpp->setMinimumSize(QSize(199, 60));
        radComputer_3 = new QRadioButton(grpOpp);
        radComputer_3->setObjectName(QString::fromUtf8("radComputer_3"));
        radComputer_3->setGeometry(QRect(10, 20, 82, 17));
        radHuman_3 = new QRadioButton(grpOpp);
        radHuman_3->setObjectName(QString::fromUtf8("radHuman_3"));
        radHuman_3->setGeometry(QRect(10, 40, 82, 17));
        radComputer_3->raise();
        radHuman_3->raise();

        verticalLayout->addWidget(grpOpp);

        layBtns = new QVBoxLayout();
        layBtns->setSpacing(0);
        layBtns->setObjectName(QString::fromUtf8("layBtns"));
        btnNew = new QPushButton(centralWidget);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        layBtns->addWidget(btnNew);

        btnExit = new QPushButton(centralWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        layBtns->addWidget(btnExit);


        verticalLayout->addLayout(layBtns);


        horizontalLayout_3->addLayout(verticalLayout);

        winMainClass->setCentralWidget(centralWidget);
        mnuMain = new QMenuBar(winMainClass);
        mnuMain->setObjectName(QString::fromUtf8("mnuMain"));
        mnuMain->setGeometry(QRect(0, 0, 615, 21));
        mnuFile = new QMenu(mnuMain);
        mnuFile->setObjectName(QString::fromUtf8("mnuFile"));
        mnuHelp = new QMenu(mnuMain);
        mnuHelp->setObjectName(QString::fromUtf8("mnuHelp"));
        winMainClass->setMenuBar(mnuMain);
        mainToolBar = new QToolBar(winMainClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        winMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
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
        winMainClass->setWindowTitle(QApplication::translate("winMainClass", "Tic-Tac-Toe++ Alpha", 0, QApplication::UnicodeUTF8));
        mnuNewGame->setText(QApplication::translate("winMainClass", "&New Game", 0, QApplication::UnicodeUTF8));
        mnuExit->setText(QApplication::translate("winMainClass", "E&xit", 0, QApplication::UnicodeUTF8));
        mnuAbout->setText(QApplication::translate("winMainClass", "&About", 0, QApplication::UnicodeUTF8));
        lblTurn->setText(QApplication::translate("winMainClass", "X", 0, QApplication::UnicodeUTF8));
        grpDificil->setTitle(QApplication::translate("winMainClass", "Difficulty", 0, QApplication::UnicodeUTF8));
        radEasy->setText(QApplication::translate("winMainClass", "Easy", 0, QApplication::UnicodeUTF8));
        radNormal->setText(QApplication::translate("winMainClass", "Normal", 0, QApplication::UnicodeUTF8));
        radHard->setText(QApplication::translate("winMainClass", "Hard", 0, QApplication::UnicodeUTF8));
        radDeath->setText(QApplication::translate("winMainClass", "Impossible", 0, QApplication::UnicodeUTF8));
        grpOpp->setTitle(QApplication::translate("winMainClass", "Opponent", 0, QApplication::UnicodeUTF8));
        radComputer_3->setText(QApplication::translate("winMainClass", "Computer", 0, QApplication::UnicodeUTF8));
        radHuman_3->setText(QApplication::translate("winMainClass", "Human", 0, QApplication::UnicodeUTF8));
        btnNew->setText(QApplication::translate("winMainClass", "New Game", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("winMainClass", "Exit Game", 0, QApplication::UnicodeUTF8));
        mnuFile->setTitle(QApplication::translate("winMainClass", "&File", 0, QApplication::UnicodeUTF8));
        mnuHelp->setTitle(QApplication::translate("winMainClass", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class winMainClass: public Ui_winMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINMAIN_H
