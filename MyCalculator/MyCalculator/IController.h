#include "IView.h"
#include <FL/Fl.H>
#include <memory>

#pragma once

using namespace std;
class IController
{
public:

	
	virtual ~IController()
	{
	}

	virtual void Run() = 0;


private:

	shared_ptr<IView> View;
	shared_ptr<IView> ThumbView;
};

