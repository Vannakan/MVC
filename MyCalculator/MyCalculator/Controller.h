
#include "IController.h"
#include "IClick.h"
#include "IModel.h"

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Light_Button.H>

#include <string>
#pragma once
using namespace std;
class Controller : public IController, public IClick
{
public:
	Controller(shared_ptr<IView> view,shared_ptr<IModel> model);
	~Controller();

	void IController::Run();

	void IClick::handleClick(double val1,double val2, char op);

	//FOR IMAGES
	void IClick::requestLoad(vector<string> filenames);


	void IClick::requestImage(int index);


private :

		//shared_ptr<Calculator> _calc;
		shared_ptr<IView> _view;
		shared_ptr<IModel>_model;
};

