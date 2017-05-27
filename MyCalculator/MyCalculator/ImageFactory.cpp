#include "stdafx.h"
#include "ImageFactory.h"
#include "Image.h"


shared_ptr<IMedia> ImageFactory::Create(string name)
{
	shared_ptr<Image> myImage{ new Image() };
	shared_ptr<fipImage>img{ new fipImage() };

	const char* imgFile = name.c_str(); //Change this from rraw pointer

	//TRY: to load the image file

	try
	{
		img->load(imgFile);
		myImage->image = img;

		if (!img->load(imgFile))
		{
			throw 1;
		}
	}

		catch (int e)
		{

		} 

		myImage->Initialise();

		shared_ptr<IMedia> mediaImg = myImage;

		return mediaImg;
	
}