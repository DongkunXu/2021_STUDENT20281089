#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );
	
	// Now need to create a VTK render window and link it to the QtVTK widget
	vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
	ui->qvtkWidget->SetRenderWindow( renderWindow );			// note that vtkWidget is the name I gave to my QtVTKOpenGLWidget in Qt creator
	
	// Now use the VTK libraries to render something. To start with you can copy-paste the cube example code, there are comments to show where the code must be modified.
	//--------------------------------------------- Code From Example 1 --------------------------------------------------------------------------
	/*// Create a cube using a vtkCubeSource
	vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();

	// Create a mapper that will hold the cube's geometry in a format suitable for rendering
	vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
	mapper->SetInputConnection( cubeSource->GetOutputPort() );

	// Create an actor that is used to set the cube's properties for rendering and place it in the window
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor( colors->GetColor3d("Red").GetData() );

	// Create a renderer, and render window
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	//vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();		// ###### We've already created the renderWindow this time ######
	ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

	// Link a renderWindowInteractor to the renderer (this allows you to capture mouse movements etc)  ###### Not needed with Qt ######
	//vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//renderWindowInteractor->SetRenderWindow( ui->vtkWidget->GetRenderWindow() );				

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground( colors->GetColor3d("Silver").GetData() );

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();

	// Render and interact
	//renderWindow->Render();					// ###### Not needed with Qt ######
	//renderWindowInteractor->Start();			// ###### Not needed with Qt ######
	//--------------------------------------------- /Code From Example 1 -------------------------------------------------------------------------*/

    vtkSmartPointer<vtkNamedColors> colors =
        vtkSmartPointer<vtkNamedColors>::New();

    // Set the background color.
    std::array<unsigned char, 4> bkg{ {51, 77, 102, 255} };
    colors->SetColor("BkgColor", bkg.data());

    // Create container to hold the 3D object generators (sources)
    std::vector<vtkSmartPointer<vtkPolyDataAlgorithm>> geometricObjectSources;

    // Populate the container with the various object sources to be demonstrated
    geometricObjectSources.push_back(vtkSmartPointer<vtkArrowSource>::New());
    geometricObjectSources.push_back(vtkSmartPointer<vtkConeSource>::New());
    geometricObjectSources.push_back(vtkSmartPointer<vtkCubeSource>::New());
    geometricObjectSources.push_back(vtkSmartPointer<vtkCylinderSource>::New());
    geometricObjectSources.push_back(vtkSmartPointer<vtkDiskSource>::New());
    geometricObjectSources.push_back(vtkSmartPointer<vtkLineSource>::New());
    geometricObjectSources.push_back(
        vtkSmartPointer<vtkRegularPolygonSource>::New());
    geometricObjectSources.push_back(vtkSmartPointer<vtkSphereSource>::New());

    // Create containers for the remaining nodes of each pipeline
    std::vector<vtkSmartPointer<vtkPolyDataMapper>> mappers;
    std::vector<vtkSmartPointer<vtkActor>> actors;
    std::vector<vtkSmartPointer<vtkTextMapper>> textmappers;
    std::vector<vtkSmartPointer<vtkActor2D>> textactors;

    // Create a common text property.
    vtkNew<vtkTextProperty> textProperty;
    textProperty->SetFontSize(16);
    textProperty->SetJustificationToCentered();
    textProperty->SetColor(colors->GetColor3d("LightGoldenrodYellow").GetData());

    // Create a mapper and actor for each object and the corresponding text label
    for (unsigned int i = 0; i < geometricObjectSources.size(); i++)
    {
        geometricObjectSources[i]->Update();

        mappers.push_back(vtkSmartPointer<vtkPolyDataMapper>::New());
        mappers[i]->SetInputConnection(geometricObjectSources[i]->GetOutputPort());

        actors.push_back(vtkSmartPointer<vtkActor>::New());
        actors[i]->SetMapper(mappers[i]);
        actors[i]->GetProperty()->SetColor(
            colors->GetColor3d("PeachPuff").GetData());

        textmappers.push_back(vtkSmartPointer<vtkTextMapper>::New());
        textmappers[i]->SetInput(
            geometricObjectSources[i]->GetClassName()); // set text label to the
                                                        // name of the object source
        textmappers[i]->SetTextProperty(textProperty);

        textactors.push_back(vtkSmartPointer<vtkActor2D>::New());
        textactors[i]->SetMapper(textmappers[i]);
        textactors[i]->SetPosition(120, 16); // Note: the position of an Actor2D is
                                             // specified in display coordinates
    }

    // Define size of the grid that will hold the objects
    int gridCols = 3;
    int gridRows = 3;
    // Define side length (in pixels) of each renderer square
    int rendererSize = 300;

    renderWindow->SetSize(rendererSize * gridCols, rendererSize * gridRows);

    // Set up a grid of viewports for each renderer
    for (double row = 0; row < gridRows; row++)
    {
        for (double col = 0; col < gridCols; col++)
        {
            double index = row * gridCols + col;

            // Create a renderer for this grid cell
            vtkSmartPointer<vtkRenderer> renderer =
                vtkSmartPointer<vtkRenderer>::New();
            renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());

            // Set the renderer's viewport dimensions (xmin, ymin, xmax, ymax) within
            // the render window. Note that for the Y values, we need to subtract the
            // row index from gridRows because the viewport Y axis points upwards, but
            // we want to draw the grid from top to down
            double viewport[4] = { static_cast<double>(col) / gridCols,
                                  static_cast<double>(gridRows - row - 1) / gridRows,
                                  static_cast<double>(col + 1) / gridCols,
                                  static_cast<double>(gridRows - row) / gridRows };
            renderer->SetViewport(viewport);

            // Add the corresponding actor and label for this grid cell, if they exist
            if (index < geometricObjectSources.size())
            {
                renderer->AddActor(actors[index]);
                renderer->AddActor(textactors[index]);
                renderer->ResetCameraClippingRange();
            }

            //renderWindow->AddRenderer(renderer);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
