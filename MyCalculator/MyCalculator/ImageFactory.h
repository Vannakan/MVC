#pragma once
#include <string>
#include "IMedia.h"


using namespace std;
class ImageFactory
{
public:
	ImageFactory() {}
	virtual ~ImageFactory() {}
	//Create a type of IMedia	
	shared_ptr<IMedia> Create(string name);
};

