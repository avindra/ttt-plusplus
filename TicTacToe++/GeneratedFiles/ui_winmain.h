/********************************************************************************
** Form generated from reading UI file 'winmain.ui'
**
** Created: Sun Dec 19 13:07:02 2010
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
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
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label;
    QMenuBar *mnuMain;
    QMenu *mnuFile;
    QMenu *mnuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *winMainClass)
    {
        if (winMainClass->objectName().isEmpty())
            winMainClass->setObjectName(QString::fromUtf8("winMainClass"));
        winMainClass->resize(517, 389);
        winMainClass->setStyleSheet(QString::fromUtf8(""));
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
        gridLayoutWidget->setGeometry(QRect(10, 10, 301, 311));
        grdGame = new QGridLayout(gridLayoutWidget);
        grdGame->setSpacing(6);
        grdGame->setContentsMargins(11, 11, 11, 11);
        grdGame->setObjectName(QString::fromUtf8("grdGame"));
        grdGame->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 290, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 310, 75, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(370, 159, 120, 111));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 20, 82, 17));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 40, 82, 17));
        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 60, 82, 17));
        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(10, 80, 82, 17));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(370, 60, 120, 80));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 20, 82, 17));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 40, 82, 17));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(390, 10, 91, 41));
        label->setStyleSheet(QString::fromUtf8("background-color:blue;\n"
"color:white;\n"
"font-weight:bold;\n"
"font-size:24px;"));
        label->setAlignment(Qt::AlignCenter);
        winMainClass->setCentralWidget(centralWidget);
        mnuMain = new QMenuBar(winMainClass);
        mnuMain->setObjectName(QString::fromUtf8("mnuMain"));
        mnuMain->setGeometry(QRect(0, 0, 517, 21));
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
        pushButton->setText(QApplication::translate("winMainClass", "New Game", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("winMainClass", "Exit Game", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("winMainClass", "Difficulty", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("winMainClass", "Easy", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("winMainClass", "Normal", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("winMainClass", "Hard", 0, QApplication::UnicodeUTF8));
        radioButton_6->setText(QApplication::translate("winMainClass", "Impossible", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("winMainClass", "Opponent", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("winMainClass", "Computer", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("winMainClass", "Human", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("winMainClass", "X", 0, QApplication::UnicodeUTF8));
        mnuFile->setTitle(QApplication::translate("winMainClass", "&File", 0, QApplication::UnicodeUTF8));
        mnuHelp->setTitle(QApplication::translate("winMainClass", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class winMainClass: public Ui_winMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINMAIN_H
