
//#pragma once
#include "stdafx.h"
#include "IView.h"
#include "IEventListener.h"
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Native_File_Chooser.H>

#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_RGB_Image.H>
#include "FreeImagePlus.h"
#include <FL/Fl_Button.H>

#include "IClick.h"
#include "IMedia.h"
#include "Image.h"

#include <memory>
#include <string>
#include <vector>


using namespace std;

//New


class View : public IView,public Fl_Double_Window, public IEventListener
{


	static void loadButton_cb(Fl_Toggle_Button* b, void* data)
	{

	}

	static void editButton_cb(Fl_Toggle_Button* b, void* data)
	{

	}
public:


	View();
	~View();
	//A reference to the event handler;
	shared_ptr<IClick> handler;
	//Method to set the event handler
	void setClick(shared_ptr<IClick> c);
	//Called when we want to save an iamge
	void saveImage();
	//Called when we want to adjust our window and display our image
	void displayImage();
	//FOR IMAGES
	void IEventListener::receiveImage(shared_ptr<IMedia>);
	//Called when we want to request a series of images
	void requestImage();
	//Called when we wish to move to the next or previous image
	void ImageSelect();

	bool IEventListener::acceptsThumbnails();

	///////////////////// Button References/Declerations\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	static void fwdsButton_cb(Fl_Widget* b, void* data);
	static void PushFileNames(Fl_Widget *w, void *data);
	static void bwdsButton_cb(Fl_Widget* b, void* data);
	static void saveButton_cb(Fl_Widget* b, void* data);
	static void flipButtonUp_cb(Fl_Widget* b, void* data);
	static void flipButtonDown_cb(Fl_Widget* b, void* data);
	static void scaleButtonUp_cb(Fl_Widget* b, void* data);
	static void scaleButtonDown_cb(Fl_Widget* b, void* data);
	static void rotateButton_cb(Fl_Widget* b, void* data);

	shared_ptr<Fl_Toggle_Button> toggle;
	shared_ptr<Fl_Box> imageBox;
	shared_ptr<fipImage> test;
	shared_ptr<IMedia> test1;
	shared_ptr<Fl_Button> loadButton;
	shared_ptr<Fl_Button> fwdsButton;
	shared_ptr<Fl_Button> bwdsButton;
	shared_ptr<Fl_Button> saveButton;

	shared_ptr<Fl_Button> flipButtonUp;
	shared_ptr<Fl_Button> flipButtonDown;
	shared_ptr<Fl_Button> rotateButton;
	shared_ptr<Fl_Button> scaleButton;
	shared_ptr<Fl_Button> upButton;
	shared_ptr<Fl_Button> downButton;
/////////////////////////////////////////////////////////////////////////////////////////////

	vector<string> getInput(string prompt);
private:

	//Code below is for IMAGES

	// DECLARE ints to represent width and height of imageBox, call them 'boxWidth' and 'boxHeight':
	const int minBoxWidth = 700, minBoxHeight = 200;
	int boxWidth = minBoxWidth, boxHeight = minBoxHeight;

	// DECLARE ints to represent horizontal padding of topWindow wrt imageBox, call them 'leftPadding' and 'rightPadding':
	int leftPadding = 10, rightPadding = 10;

	// DECLARE ints to represent vertical padding of topWindow wrt imageBox, call them 'upperPadding' and 'lowerPadding':
	int upperPadding = 10, lowerPadding = 100;

	// DECLARE ints to represent loadButton size, call them 'loadWidth' and 'loadHeight':
	int loadWidth = 100, loadHeight = 30;

	//DECLARE: a short for point to the current selected item in the ImageContainer
	unsigned short currentItem = 0;
	//A reference to the current image we want to display and manipulate
	shared_ptr<Image> currentImage;
	//A reference to the current index we are at
	int index = 0;
	//A reference to the amount of images in the stack
	int stack = 0;
	//A method to resize the window
	void resizeWindow();

	int windowWidth = 800;
	int windowHeight = 600;

	void flipImage(int flip);
	void scaleImage(int amount);
	void rotateImage(double amount);

};

