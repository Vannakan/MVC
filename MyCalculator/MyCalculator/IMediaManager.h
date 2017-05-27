#pragma once

#include <FreeImagePlus.h>
#include <string>
#include <iostream>
#include <memory>
#include "IMedia.h"
#include "Image.h"
#include "IModel.h"
#include "stdafx.h"
#include "ImageFactory.h"
#include <map>

#pragma comment (lib, "Libs/FreeImagePlusd.lib")
#pragma comment (lib, "Libs/FreeImaged.lib")

class IMediaManager
{
public:

	IMediaManager()
	{
	}

	virtual ~IMediaManager()
	{
	}
	//Load all strings as media items.
	virtual shared_ptr<vector<string>>load(vector<string>pathfilenames) = 0;
	//Return an image based off the given index
	virtual shared_ptr<IMedia>getMediaItemIndex(int index) = 0;

private:

	
};

