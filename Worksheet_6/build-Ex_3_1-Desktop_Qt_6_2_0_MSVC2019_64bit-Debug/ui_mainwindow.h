/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openButton;
    QAction *saveButton;
    QAction *actionHelp;
    QAction *actionPrint;
    QAction *disk;
    QAction *arrow;
    QAction *cone;
    QAction *actionClip_Filter;
    QAction *actionShrink_Filter;
    QAction *actionDarkMood;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVTKOpenGLWidget *qvtkWidget;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *greenI;
    QPushButton *pinkI;
    QPushButton *blueI;
    QPushButton *orangeI;
    QPushButton *tealI;
    QPushButton *whiteI;
    QPushButton *blackI;
    QLabel *label;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *Camera;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *greenB;
    QPushButton *pinkB;
    QPushButton *blueB;
    QPushButton *orangeB;
    QPushButton *tealB;
    QPushButton *whiteB;
    QPushButton *blackB;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuPreloaded;
    QMenu *menuFilter;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(835, 693);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 185, 185);"));
        openButton = new QAction(MainWindow);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon);
        saveButton = new QAction(MainWindow);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon2);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        disk = new QAction(MainWindow);
        disk->setObjectName(QString::fromUtf8("disk"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/disk.dng"), QSize(), QIcon::Normal, QIcon::Off);
        disk->setIcon(icon4);
        arrow = new QAction(MainWindow);
        arrow->setObjectName(QString::fromUtf8("arrow"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/arrow.dng"), QSize(), QIcon::Normal, QIcon::Off);
        arrow->setIcon(icon5);
        cone = new QAction(MainWindow);
        cone->setObjectName(QString::fromUtf8("cone"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/slz.dng"), QSize(), QIcon::Normal, QIcon::Off);
        cone->setIcon(icon6);
        actionClip_Filter = new QAction(MainWindow);
        actionClip_Filter->setObjectName(QString::fromUtf8("actionClip_Filter"));
        actionShrink_Filter = new QAction(MainWindow);
        actionShrink_Filter->setObjectName(QString::fromUtf8("actionShrink_Filter"));
        actionDarkMood = new QAction(MainWindow);
        actionDarkMood->setObjectName(QString::fromUtf8("actionDarkMood"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icons/dark.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDarkMood->setIcon(icon7);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 690, 534));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        qvtkWidget = new QVTKOpenGLWidget(layoutWidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setMinimumSize(QSize(600, 400));

        horizontalLayout_2->addWidget(qvtkWidget);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(720, 360, 34, 178));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        greenI = new QPushButton(layoutWidget_2);
        greenI->setObjectName(QString::fromUtf8("greenI"));
        greenI->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 205, 50);"));

        verticalLayout_3->addWidget(greenI);

        pinkI = new QPushButton(layoutWidget_2);
        pinkI->setObjectName(QString::fromUtf8("pinkI"));
        pinkI->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 105, 180);"));

        verticalLayout_3->addWidget(pinkI);

        blueI = new QPushButton(layoutWidget_2);
        blueI->setObjectName(QString::fromUtf8("blueI"));
        blueI->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 206, 235);"));

        verticalLayout_3->addWidget(blueI);

        orangeI = new QPushButton(layoutWidget_2);
        orangeI->setObjectName(QString::fromUtf8("orangeI"));
        orangeI->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 165, 0);"));

        verticalLayout_3->addWidget(orangeI);

        tealI = new QPushButton(layoutWidget_2);
        tealI->setObjectName(QString::fromUtf8("tealI"));
        tealI->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 128);"));

        verticalLayout_3->addWidget(tealI);

        whiteI = new QPushButton(layoutWidget_2);
        whiteI->setObjectName(QString::fromUtf8("whiteI"));
        whiteI->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(whiteI);

        blackI = new QPushButton(layoutWidget_2);
        blackI->setObjectName(QString::fromUtf8("blackI"));
        blackI->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(blackI);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(720, 100, 61, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(720, 330, 101, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(500, 570, 251, 31));
        verticalLayout_4 = new QVBoxLayout(horizontalLayoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        Camera = new QPushButton(horizontalLayoutWidget);
        Camera->setObjectName(QString::fromUtf8("Camera"));
        Camera->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_4->addWidget(Camera);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(720, 130, 34, 178));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        greenB = new QPushButton(widget);
        greenB->setObjectName(QString::fromUtf8("greenB"));
        greenB->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 205, 50);"));

        verticalLayout_2->addWidget(greenB);

        pinkB = new QPushButton(widget);
        pinkB->setObjectName(QString::fromUtf8("pinkB"));
        pinkB->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 105, 180);"));

        verticalLayout_2->addWidget(pinkB);

        blueB = new QPushButton(widget);
        blueB->setObjectName(QString::fromUtf8("blueB"));
        blueB->setStyleSheet(QString::fromUtf8("background-color: rgb(135, 206, 235);"));

        verticalLayout_2->addWidget(blueB);

        orangeB = new QPushButton(widget);
        orangeB->setObjectName(QString::fromUtf8("orangeB"));
        orangeB->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 165, 0);"));

        verticalLayout_2->addWidget(orangeB);

        tealB = new QPushButton(widget);
        tealB->setObjectName(QString::fromUtf8("tealB"));
        tealB->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 128);"));

        verticalLayout_2->addWidget(tealB);

        whiteB = new QPushButton(widget);
        whiteB->setObjectName(QString::fromUtf8("whiteB"));
        whiteB->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(whiteB);

        blackB = new QPushButton(widget);
        blackB->setObjectName(QString::fromUtf8("blackB"));
        blackB->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(blackB);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 835, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuPreloaded = new QMenu(menubar);
        menuPreloaded->setObjectName(QString::fromUtf8("menuPreloaded"));
        menuFilter = new QMenu(menubar);
        menuFilter->setObjectName(QString::fromUtf8("menuFilter"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuPreloaded->menuAction());
        menubar->addAction(menuFilter->menuAction());
        menuFile->addAction(openButton);
        menuFile->addAction(saveButton);
        menuPreloaded->addAction(disk);
        menuPreloaded->addAction(arrow);
        menuPreloaded->addAction(cone);
        menuFilter->addAction(actionClip_Filter);
        menuFilter->addAction(actionShrink_Filter);
        toolBar->addAction(openButton);
        toolBar->addAction(saveButton);
        toolBar->addAction(disk);
        toolBar->addAction(arrow);
        toolBar->addAction(cone);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        disk->setText(QCoreApplication::translate("MainWindow", "Disk Item", nullptr));
        arrow->setText(QCoreApplication::translate("MainWindow", "Arrow Item", nullptr));
        cone->setText(QCoreApplication::translate("MainWindow", "Cone Item", nullptr));
        actionClip_Filter->setText(QCoreApplication::translate("MainWindow", "Clip Filter", nullptr));
        actionShrink_Filter->setText(QCoreApplication::translate("MainWindow", "Shrink Filter", nullptr));
        actionDarkMood->setText(QCoreApplication::translate("MainWindow", "DarkMood", nullptr));
        greenI->setText(QString());
        pinkI->setText(QString());
        blueI->setText(QString());
        orangeI->setText(QString());
        tealI->setText(QString());
        whiteI->setText(QString());
        blackI->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Item Color", nullptr));
        Camera->setText(QCoreApplication::translate("MainWindow", "Reset Camera", nullptr));
        greenB->setText(QString());
        pinkB->setText(QString());
        blueB->setText(QString());
        orangeB->setText(QString());
        tealB->setText(QString());
        whiteB->setText(QString());
        blackB->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuPreloaded->setTitle(QCoreApplication::translate("MainWindow", "Preloaded", nullptr));
        menuFilter->setTitle(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
