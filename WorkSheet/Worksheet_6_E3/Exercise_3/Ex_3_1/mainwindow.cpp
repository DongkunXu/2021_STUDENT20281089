#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkDiskSource.h>
#include <vtkArrowSource.h>
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
    ui->saveButton->setIcon(QIcon(":/filesave.png"));
    ui->openButton->setIcon(QIcon(":/fileopen.png"));
    connect( ui->addButton, &QPushButton::released, this, &::MainWindow::handladdButton );
    connect( ui->addButton_2, &QPushButton::released, this, &::MainWindow::handladdButton_2 );
    connect( ui->Camera, &QPushButton::released, this, &::MainWindow::handlCamera );
    connect( ui->Background, &QPushButton::released, this, &::MainWindow::handlBackground );


	// Now use the VTK libraries to render something. To start with you can copy-paste the cube example code, there are comments to show where the code must be modified.

}

void MainWindow::handlCamera() {}
void MainWindow::handlBackground() {}

void MainWindow::randerbegan(vtkSmartPointer<vtkActor> actor,vtkSmartPointer<vtkNamedColors> colors){
    // Create a renderer, and render window
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    //vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();		// ###### We've already created the renderWindow this time ######
    ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

    // Link a renderWindowInteractor to the renderer (this allows you to capture mouse movements etc)  ###### Not needed with Qt ######
    //vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    //renderWindowInteractor->SetRenderWindow( ui->vtkWidget->GetRenderWindow() );

    // Add the actor to the scene
    renderer->AddActor(actor);
    renderer->SetBackground( colors->GetColor3d("Black").GetData() );

    // Setup the renderers's camera
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);
    renderer->ResetCameraClippingRange();
}

void MainWindow::handladdButton() {
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
    actor->GetProperty()->SetColor( colors->GetColor3d("Yellow").GetData() );

    randerbegan(actor,colors);
}

void MainWindow::handladdButton_2() {
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
    actor->GetProperty()->SetColor( colors->GetColor3d("Yellow").GetData() );
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

void MainWindow::on_openButton_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open STL File"), "./", tr("STL Files(*.stl)"));
    //std::string fileName = argv[1];

    //QByteArray ba = fileName.toLocal8Bit();
      // const char *c_str2 = ba.data();

      vtkNew<vtkSTLReader> reader;
      QByteArray ba = fileName.toLocal8Bit();

      const char *c_str2 = ba.data();
      reader->SetFileName(c_str2);
      reader->Update();

      // Visualize
      vtkNew<vtkPolyDataMapper> mapper;
      mapper->SetInputConnection(reader->GetOutputPort());

      vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

      vtkNew<vtkActor> actor;

      actor->SetMapper(mapper);
      actor->GetProperty()->SetDiffuse(0.8);
      actor->GetProperty()->SetDiffuseColor(
            colors->GetColor3d("LightSteelBlue").GetData());
      actor->GetProperty()->SetSpecular(0.3);
      actor->GetProperty()->SetSpecularPower(60.0);

      vtkNew<vtkRenderer> renderer;
      vtkNew<vtkRenderWindow> renderWindow;
      renderWindow->AddRenderer(renderer);
      renderWindow->SetWindowName("ReadSTL");

      vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
      renderWindowInteractor->SetRenderWindow(renderWindow);

      renderer->AddActor(actor);
      renderer->SetBackground(colors->GetColor3d("DarkOliveGreen").GetData());

      renderWindow->Render();
      renderWindowInteractor->Start();

      randerbegan(actor,colors);
}

MainWindow::~MainWindow()
{
    delete ui;
}
