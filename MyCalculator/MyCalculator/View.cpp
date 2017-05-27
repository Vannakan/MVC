#include "stdafx.h"
#include "View.h"
#include <iostream>
#include <algorithm>



using namespace std;
View::View() :  Fl_Double_Window(800,680, "MyCalculator"){
{
	user_data((void*)(this));
	{

		int loadPosnX = (int)((boxWidth + leftPadding + rightPadding - loadWidth)*0.5);
		int loadPosnY = boxHeight + lowerPadding - loadHeight - upperPadding;
		
			loadButton = make_shared<Fl_Button>(loadPosnX, loadPosnY, 68, 20, "LOAD");
			loadButton->callback(PushFileNames , this);

			fwdsButton = make_shared<Fl_Button>(loadPosnX + loadWidth + loadWidth, loadPosnY, 68, 20, "NEXT");
			fwdsButton->callback(fwdsButton_cb, this);
			bwdsButton = make_shared<Fl_Button>(loadPosnX - loadWidth - loadWidth, loadPosnY, 68, 20, "PREV");
			bwdsButton->callback(bwdsButton_cb, this);

			saveButton = make_shared<Fl_Button>(loadPosnX, loadPosnY + 25, 68, 20, "SAVE");
			saveButton->callback(saveButton_cb, this);


			flipButtonUp = make_shared<Fl_Button>(loadPosnX + 100, loadPosnY, 68, 20, "Flip VERT");
			flipButtonUp->callback(flipButtonUp_cb, this);

			flipButtonDown = make_shared<Fl_Button>(loadPosnX + 100, loadPosnY - 50, 68, 20, "Flip HORI");
			flipButtonDown->callback(flipButtonDown_cb, this);

			rotateButton = make_shared<Fl_Button>(loadPosnX - 100, loadPosnY, 68, 20, "Rotate");
			rotateButton->callback(rotateButton_cb, this);
			upButton = make_shared<Fl_Button>(loadPosnX , loadPosnY - 50, 68, 20, "ScaleUp");
			upButton->callback(scaleButtonUp_cb, this);
			downButton = make_shared<Fl_Button>(loadPosnX + 100, loadPosnY - 50, 68, 20, "ScaleDown");
			downButton->callback(scaleButtonDown_cb, this);




		
		imageBox = shared_ptr<Fl_Box>(new Fl_Box(leftPadding, upperPadding, boxWidth, boxHeight));
		imageBox->box(FL_FLAT_BOX);

		resizeWindow();
	}
	end();
}

show();
}

//DECLARE: Method callback to get a string of items to load
void View::PushFileNames(Fl_Widget *w, void *data)
{
	View *t = (View*)data;
	t->ImageSelect();
}

//DECLARE:: Method callback for forwards button
void View::fwdsButton_cb(Fl_Widget *w, void *data)
{

	View *t = (View*)data;
	
	if (t->index + 1 != t->stack)
	{
		t->index++;
		t->requestImage();
	}

}

//DECLARE:: Method callback for backwards button
void View::bwdsButton_cb(Fl_Widget *w, void *data)
{
	View *t = (View*)data;
	if (t->index - 1 >= 0)
	{
		t->index--;
		t->requestImage();
	}
	
}

//DECLARE Method callback for save button
void View::saveButton_cb(Fl_Widget *w, void *data)
{
	View *t = (View*)data;
	t->saveImage();

}

//DECLARE Method callback for flip Horizontal button
void View::flipButtonUp_cb(Fl_Widget *w, void *data)
{
	View *t = (View*)data;
	t->flipImage(1);
}

//DECLARE: Method callback for flip vertical button
void View::flipButtonDown_cb(Fl_Widget *w, void *data)
{
	View *t = (View*)data;
	t->flipImage(0);
}

//DECLARE: Method callback for scale up button
void View::scaleButtonUp_cb(Fl_Widget *w, void *data)
{
	View *t = (View*)data;
	t->scaleImage(20);

}

//DECLARE: Method callback for scale down button
void View::scaleButtonDown_cb(Fl_Widget *w, void *data)
{
	View *t = (View*)data;
	t->scaleImage(-20);

}

//DECLARE: Method callback for rotation button
void View::rotateButton_cb(Fl_Widget *w, void *data)
{
	View *t = (View*)data;
	t->rotateImage(30);

}



View::~View()
{
}

bool View::acceptsThumbnails()
{
	return false;
}


//METHOD: Set the handler
void View::setClick(shared_ptr<IClick> c)
{	
	handler = c;
}


//METHOD: Get the operand values and the selected operator and pass it through to the controller
void View::requestImage()
{
	if (stack > 0)
	handler->requestImage(index);

}

//METHOD: Gets a vector of strings and requests the handler to load these images
void View::ImageSelect()
{
	vector<string> fileNames = getInput("Please Choose your Image");
	stack = fileNames.size();
	if(stack > 0)
	handler->requestLoad(fileNames);
	index = 0;
}
//FOR IMAGES
void View::receiveImage(shared_ptr<IMedia> mediaWrapper)
{
	currentImage = dynamic_pointer_cast<Image>(mediaWrapper);
	FREE_IMAGE_FILTER x = FREE_IMAGE_FILTER();
	currentImage->image->rescale(currentImage->image->getWidth(), currentImage->image->getHeight(),x);
	if(currentImage->image->getWidth() > windowWidth || currentImage->image->getHeight() > windowHeight)
		currentImage->image->rescale(windowWidth, windowHeight, x);


	displayImage();
}

void View::displayImage()
{
	if (currentImage != NULL)
	{
		boxWidth = (currentImage->image->getWidth() < minBoxWidth) ? minBoxWidth : currentImage->image->getWidth();
		boxHeight = currentImage->image->getHeight();

		resizeWindow();
		imageBox->image(new Fl_RGB_Image(currentImage->image->accessPixels(), currentImage->image->getWidth(), currentImage->image->getHeight(), currentImage->numberOfChannels(), 0));
		imageBox->hide();
		imageBox->show();
	}


}

void View::flipImage(int type)
{
	if (currentImage != NULL)
	{
		if (type == 0)
			currentImage->image->flipHorizontal();
		else if (type == 1)
			currentImage->image->flipVertical();

		receiveImage(currentImage);
	}
}

void View::resizeWindow()
{


	size(boxWidth + leftPadding + rightPadding, boxHeight + upperPadding + lowerPadding);

	// MOVE loadButton to bottom of topWindow:
	int loadPosnX = (int)((boxWidth + leftPadding + rightPadding - loadWidth)*0.5);
	int loadPosnY = boxHeight + lowerPadding - loadHeight - upperPadding;
	loadButton->position(loadPosnX, loadPosnY);
	saveButton->position(loadPosnX, loadPosnY + 25);
	fwdsButton->position(loadPosnX + loadWidth + loadWidth, loadPosnY);
	bwdsButton->position(loadPosnX - loadWidth - loadWidth, loadPosnY);
	flipButtonUp->position(loadPosnX + 100, loadPosnY);
	flipButtonDown->position(loadPosnX + 100, loadPosnY + 25);

	rotateButton->position(loadPosnX - 100, loadPosnY);
	upButton->position(loadPosnX- 100, loadPosnY - 50);
	downButton->position(loadPosnX + 100, loadPosnY - 50);
	imageBox->size(boxWidth, boxHeight);
}

void View::saveImage()
{
	

	fipImage test = *currentImage->image;
	test.flipVertical();
	string savePath;

	//Fl_NATIVE_FILE_CHOOSER
	Fl_Native_File_Chooser nInpu = Fl_Native_File_Chooser(1);
	nInpu.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
	
	string fname;
	string direct;
	switch (nInpu.show())
	{
	case -1: break;
	case 1: break;
	default:
		if (nInpu.filename()) fname = nInpu.filename();
		break;
	}


	std::replace(fname.begin(), fname.end(), '\\', '/');




	fname.append(".png");

	test.save(fname.c_str());

}


//Thumbnails
//Combining Images  

// Open a file chooser and select image file:
vector<string> View::getInput(string prompt)
{
	// CREATE a vector<string> to hold the return value, call it rtnVal:
	vector<string> rtnVal;

	//Fl_NATIVE_FILE_CHOOSER
	Fl_Native_File_Chooser nInpu = Fl_Native_File_Chooser(1);
	nInpu.type(Fl_Native_File_Chooser::BROWSE_MULTI_FILE);
	nInpu.filter("*.{png,jpg,jpeg}");

	switch (nInpu.show())
	{
	case -1: break;
	case 1: break;
	default:
		break;
	}

	cout << nInpu.filename(1) << endl;

	if ((NULL != nInpu.filename() && (0 < nInpu.count())))
	{
		for (int i = 0; i < nInpu.count(); i++)
		{
			// Convert each filename to a string and push onto rtnVal:
			string rtn;
			rtn.assign(nInpu.filename(i));
			std::replace(rtn.begin(), rtn.end(), '\\', '/');

			rtnVal.push_back(rtn);
			cout << rtn << endl;
		}
	}



	return rtnVal;
}

void View::scaleImage(int amount)
{
	if (currentImage != NULL)
	{
		FREE_IMAGE_FILTER x = FREE_IMAGE_FILTER();
		currentImage->image->rescale(currentImage->image->getWidth() + amount, currentImage->image->getHeight() + amount, x);
		displayImage();
	}
}

void View::rotateImage(double angle)
{
	if (currentImage != NULL)
	{
		currentImage->image->rotate(90);
		displayImage();
	}
}

