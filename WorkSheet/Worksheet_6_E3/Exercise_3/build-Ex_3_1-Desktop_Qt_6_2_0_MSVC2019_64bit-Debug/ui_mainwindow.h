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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QAction *actionDisk_Iterm;
    QAction *actionArrow_Item;
    QAction *actionCone_Item;
    QAction *actionClip_Filter;
    QAction *actionShrink_Filter;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QVTKOpenGLWidget *qvtkWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *addButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Camera;
    QPushButton *Background;
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
        MainWindow->resize(936, 664);
        openButton = new QAction(MainWindow);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon);
        saveButton = new QAction(MainWindow);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        actionDisk_Iterm = new QAction(MainWindow);
        actionDisk_Iterm->setObjectName(QString::fromUtf8("actionDisk_Iterm"));
        actionArrow_Item = new QAction(MainWindow);
        actionArrow_Item->setObjectName(QString::fromUtf8("actionArrow_Item"));
        actionCone_Item = new QAction(MainWindow);
        actionCone_Item->setObjectName(QString::fromUtf8("actionCone_Item"));
        actionClip_Filter = new QAction(MainWindow);
        actionClip_Filter->setObjectName(QString::fromUtf8("actionClip_Filter"));
        actionShrink_Filter = new QAction(MainWindow);
        actionShrink_Filter->setObjectName(QString::fromUtf8("actionShrink_Filter"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 602, 433));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        qvtkWidget = new QVTKOpenGLWidget(layoutWidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setMinimumSize(QSize(600, 400));

        verticalLayout->addWidget(qvtkWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);

        addButton_2 = new QPushButton(layoutWidget);
        addButton_2->setObjectName(QString::fromUtf8("addButton_2"));

        horizontalLayout->addWidget(addButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Camera = new QPushButton(layoutWidget);
        Camera->setObjectName(QString::fromUtf8("Camera"));

        horizontalLayout->addWidget(Camera);

        Background = new QPushButton(layoutWidget);
        Background->setObjectName(QString::fromUtf8("Background"));

        horizontalLayout->addWidget(Background);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 936, 23));
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
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuPreloaded->menuAction());
        menubar->addAction(menuFilter->menuAction());
        menuFile->addAction(openButton);
        menuFile->addAction(saveButton);
        menuPreloaded->addAction(actionDisk_Iterm);
        menuPreloaded->addAction(actionArrow_Item);
        menuPreloaded->addAction(actionCone_Item);
        menuFilter->addAction(actionClip_Filter);
        menuFilter->addAction(actionShrink_Filter);
        toolBar->addAction(openButton);
        toolBar->addAction(saveButton);
        toolBar->addAction(actionHelp);
        toolBar->addAction(actionPrint);

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
        actionDisk_Iterm->setText(QCoreApplication::translate("MainWindow", "Disk Item", nullptr));
        actionArrow_Item->setText(QCoreApplication::translate("MainWindow", "Arrow Item", nullptr));
        actionCone_Item->setText(QCoreApplication::translate("MainWindow", "Cone Item", nullptr));
        actionClip_Filter->setText(QCoreApplication::translate("MainWindow", "Clip Filter", nullptr));
        actionShrink_Filter->setText(QCoreApplication::translate("MainWindow", "Shrink Filter", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Disk Item", nullptr));
        addButton_2->setText(QCoreApplication::translate("MainWindow", "Arrow Item", nullptr));
        Camera->setText(QCoreApplication::translate("MainWindow", "Camera", nullptr));
        Background->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
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
