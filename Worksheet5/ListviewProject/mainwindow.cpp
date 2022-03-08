


// exercise2/mainwindow.cpp ------------------------------------------
#include <QMessageBox>
#include "mainwindow.h"
#include "edititemdialog.h"
#include "ui_mainwindow.h"
#include "stockitem.h"
#include "stockitemlistmodel.h"
#include <QAbstractListModel>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <fstream>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi( this );

    // Link the ListModel to the ListView
    ui->listView->setModel( &stockList );
        // Tell this list view to only accept single selections
    ui->listView->setSelectionBehavior( QAbstractItemView::SelectItems );
        //Connect the released() signal of the addButton object to the handleAddButton slot in this object
    connect( ui->addButton, &QPushButton::released, this, &MainWindow::handleAddButton );
    connect( ui->editButton, &QPushButton::released, this, &MainWindow::handleEditButton );
    connect( ui->removeButton, &QPushButton::released, this, &MainWindow::handleRemoveButton );
    connect( ui->insertButton, &QPushButton::released, this, &MainWindow::handleinsertButton );
    connect( ui->saveButton, &QAction::activate, this, &MainWindow::on_saveButton_triggered );

    connect( this, &MainWindow::statusUpdateMessage, ui->statusBar, &QStatusBar::showMessage );

    ui->saveButton->setIcon(QIcon(":/Save File.ico"));

}

void MainWindow::handleAddButton() {
	StockItem item;
    stockList.addItem( item );
    emit statusUpdateMessage( QString("Add button was clicked"), 0 );
}

void MainWindow::handleinsertButton() {


    QModelIndexList selectedList;
    selectedList = ui->listView->selectionModel()->selectedIndexes();
    StockItem item;
    stockList.insertItem( item,selectedList[0] );
    emit statusUpdateMessage( QString("Insert button was clicked"), 0 );

}

void MainWindow::handleEditButton() {
    EditItemDialog dialog( this );
    QModelIndexList selectedList;

    selectedList = ui->listView->selectionModel()->selectedIndexes();

    if( selectedList.length() == 1 )
        {
            // selectedList is a list of all selected items in the listView. Since we set its
            // behaviour to single selection, were only interested in the first selecteded item.
            StockItem item = stockList.getItem( selectedList[0] );

            if( dialog.runDialog( item ) )
            {
            // user clicked ok, need to update item in list...
            stockList.setItem( item, selectedList[0] );

            }
        }
    else
    {
    emit statusUpdateMessage( QString("No item selected to edit!"), 0 );
    }
}

void MainWindow::handleRemoveButton() {

    //ui->removeButton(0,ui->removeButton);
    QModelIndexList selectedList;
    selectedList = ui->listView->selectionModel()->selectedIndexes();
    QModelIndex item;
    stockList.removeItem( selectedList[0] );

    emit statusUpdateMessage( QString("Remove button was clicked"), 0 );
}

void MainWindow::on_saveButton_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr(""),"",tr("Text files (*.txt )"));

    QFile file(fileName);
    //currentFile = fileName;
    //setWindowTitle(fileName);
    file.open( QIODevice::ReadWrite );
    QTextStream out(&file);

    //out << ui->listView;
    for (int i;i<stockList.Count();i++){
        out << " -> Name: "<<stockList.get_Item(i).getName()
        <<" -> Stock: "<< stockList.get_Item(i).getStockLevel()
        <<" -> Cost: "<< stockList.get_Item(i).getUnitCost()
        <<" -> Reorder?: "<<stockList.get_Item(i).getReorder()
        <<"\n";
    }

    file.close();

}



MainWindow::~MainWindow() {

}// ---------------------------------------------------------------------







