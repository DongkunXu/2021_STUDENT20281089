
// exercise2/mainwindow.h --------------------------------------------
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stockitemlistmodel.h"

namespace Ui {
	class MainWindow;
}


class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		explicit MainWindow(QWidget * parent = 0);
		~MainWindow();

	private:
		Ui::MainWindow * ui;
		StockItemListModel stockList;

	public slots:
		void handleAddButton();
		void handleEditButton();
		void handleRemoveButton();
		void on_saveButton_triggered();
		void handleinsertButton();

	signals:
		void statusUpdateMessage( const QString & message, int timeout );
};



#endif // MAINWINDOW_H



