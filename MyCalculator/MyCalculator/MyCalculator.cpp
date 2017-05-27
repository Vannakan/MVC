// MyCalculator.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
#include "IView.h"
#include "View.h"
#include "Model.h"
#include "IController.h"
#include "Controller.h"
#include <FreeImagePlus.h>
#include <FreeImage.h>

#pragma comment (lib, "Libs/FreeImagePlusd.lib")
#pragma comment (lib, "Libs/FreeImaged.lib")
#pragma comment (lib, "Libs/fltkd.lib")


int main()
{
	//Create a View object and create a shared pointer to this object
	shared_ptr<IView> c = make_shared<View>();
	//Create a Model object and create a shared pointer to this object
	shared_ptr<IModel> m = make_shared<Model>();
	//Create a Controller object and create a shared pointer to this object
	shared_ptr<Controller> ic = make_shared<Controller>(c, m);
	//Cast the controller as an IClick and store it within a pointer
	shared_ptr<IClick> click = dynamic_pointer_cast<IClick>(ic);
	//Set the controller the view will respond to input events with
	c->setClick(click);
	//Run the program
	ic->Run();
	
	return 1;
}