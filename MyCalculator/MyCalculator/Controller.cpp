#include "stdafx.h"
#include "Controller.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include "IEventListener.h"
#include "IEventPublisher.h"



Controller::Controller(shared_ptr<IView> view, shared_ptr<IModel>model)
{
	//Set the reference of the view
	_view = view;
	//Set the reference of the model
	_model = model;
	//Cast the view as an event listener type and store this in a shared ptr
	shared_ptr<IEventListener> eventlis = dynamic_pointer_cast<IEventListener>(_view);
	//Cast the model as an event publisher type and store this in a shared ptr
	shared_ptr<IEventPublisher> eventpub = dynamic_pointer_cast<IEventPublisher>(_model);


	//Subscribe the listener to the publisher
	eventpub->subscribe(eventlis);
}



Controller::~Controller()
{
	
}

void Controller::handleClick(double val1, double val2, char op)
{
}



//Make a call to the model to load a series of images based off of the given vector of strings
void Controller::requestLoad(vector<string> fileNames)
{
	_model->LoadImages(fileNames);
		
}

//Request a preloaded image based off of the index (If the index doesnt exist, it wont return anything)
void Controller::requestImage(int index)
{
	_model->ReturnImage(index);
}

//Call Fl to run
void Controller::Run()
{

	Fl::run();
}
