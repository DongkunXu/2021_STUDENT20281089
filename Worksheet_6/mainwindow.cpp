#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkDiskSource.h>
#include <vtkArrowSource.h>
#include <vtkConeSource.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <QMessageBox>
#include <QAbstractListModel>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <fstream>
#include <iostream>
#include <QFile>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSTLReader.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );
	
	// Now need to create a VTK render window and link it to the QtVTK widget
	vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    ui->qvtkWidget->SetRenderWindow( renderWindow );			// note that vtkWidget is the name I gave to my QtVTKOpenGLWidget in Qt creator
	
    //connect( this, &MainWindow::statusUpdateMessage, ui->statusBar, &QStatusBar::showMessage );
    ui->saveButton->setIcon(QIcon(":/save.png"));
    ui->openButton->setIcon(QIcon(":/file.png"));

    ui->arrow->setIcon(QIcon(":/arrow.dng"));
    ui->cone->setIcon(QIcon(":/slz.dng"));
    ui->disk->setIcon(QIcon(":/disk.dng"));

    connect( ui->Camera, &QPushButton::released, this, &::MainWindow::handlCamera );

}

void MainWindow::handlCamera() {}

void MainWindow::randerbegan(vtkSmartPointer<vtkActor> actor,vtkSmartPointer<vtkNamedColors> colors){
    // Create a renderer, and render window
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

    actor->GetProperty()->SetDiffuseColor(
          colors->GetColor3d("White").GetData());
    //vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();		// ###### We've already created the renderWindow this time ######
    ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

    // Add the actor to the scene
    renderer->AddActor(actor);
    renderer->SetBackground( colors->GetColor3d("Black").GetData() );

    // Setup the renderers's camera
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    renderer->ResetCameraClippingRange();
}


void MainWindow::on_openButton_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open STL File"), "./", tr("STL Files(*.stl)"));

    vtkNew<vtkSTLReader> reader;
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(reader->GetOutputPort());


      QByteArray ba = fileName.toLocal8Bit();

      const char *c_str2 = ba.data();
      reader->SetFileName(c_str2);
      reader->Update();

      // Visualize

      vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

      vtkNew<vtkActor> actor;

      actor->SetMapper(mapper);
      randerbegan(actor,colors);
}

void MainWindow::on_saveButton_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr(""),"",tr("Text files (*.stl )"));

    QFile file(fileName);
    //currentFile = fileName;
    //setWindowTitle(fileName);
    file.open( QIODevice::ReadWrite );
    QTextStream out(&file);

    file.close();
}

void MainWindow::on_disk_triggered() {
    //--------------------------------------------- Code From Example 1 --------------------------------------------------------------------------
    // Create a cube using a vtkCubeSource
    vtkSmartPointer<vtkDiskSource> cubeSource = vtkSmartPointer<vtkDiskSource>::New();


    // Create a mapper that will hold the cube's geometry in a format suitable for rendering
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputConnection( cubeSource->GetOutputPort() );

    // Create an actor that is used to set the cube's properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

    randerbegan(actor,colors);
}

void MainWindow::on_arrow_triggered() {
    //--------------------------------------------- Code From Example 1 --------------------------------------------------------------------------
    // Create a cube using a vtkCubeSource
    vtkSmartPointer<vtkArrowSource> cubeSource = vtkSmartPointer<vtkArrowSource>::New();

    // Create a mapper that will hold the cube's geometry in a format suitable for rendering
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputConnection( cubeSource->GetOutputPort() );

    // Create an actor that is used to set the cube's properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

    randerbegan(actor,colors);
}

void MainWindow::on_cone_triggered() {
    //--------------------------------------------- Code From Example 1 --------------------------------------------------------------------------
    // Create a cube using a vtkCubeSource
    vtkSmartPointer<vtkConeSource> cubeSource = vtkSmartPointer<vtkConeSource>::New();

    // Create a mapper that will hold the cube's geometry in a format suitable for rendering
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputConnection( cubeSource->GetOutputPort() );

    // Create an actor that is used to set the cube's properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

    randerbegan(actor,colors);
}

MainWindow::~MainWindow()
{
    delete ui;
}
