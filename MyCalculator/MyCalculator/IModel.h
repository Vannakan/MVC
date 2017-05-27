#pragma once

#include <string>
#include <memory>
#include <vector>

#include "IMedia.h"

using namespace std;
class IModel
{
public:



	virtual ~IModel()
	{
	}


	virtual void LoadImages(vector<string> fileNames)= 0; //Change to load IMAGES which takes a vector of files, and perhaps return only the files that have loaded? (in string format)
	
	virtual void ReturnImage(int index) = 0;
	//// Load the media items pointed to by 'pathfilenames' into the 'Model':
	//// @param pathfilenames is a vector of strings; each string containing path/filename for an image file to be loaded
	//// (the vector should contain at least one string)
	//// @return the unique identifiers of the images that have been loaded as a vector<KeyType>
	//virtual shared_ptr<vector<KeyType>> load(vector<string> pathfilenames) = 0;

	//// Return a copy of the media item specified by 'key':
	//// @param key is the unique identifier for the image to be returned
	//virtual shared_ptr<IMedia> getMediaItem(KeyType key) = 0;
};

