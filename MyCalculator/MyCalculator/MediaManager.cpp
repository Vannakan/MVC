#include "stdafx.h"
#include "MediaManager.h"



MediaManager::MediaManager()
{
}


MediaManager::~MediaManager()
{
}

//return the amount of media items in the container
int MediaManager::containerSize()
{
	return _container->size();
}

//Load all of the files that have been requested from the filename list and push them into the container
shared_ptr<vector<string>> MediaManager::load(vector<string>pathfilenames)
{
	//
	shared_ptr<vector<string>>ptr{ new vector<string>() };

	_container->clear();

	for (vector<string>::size_type i = 0; i != pathfilenames.size(); i++)
	{
		//Create a blank image and load it via the image factory and the current texture name
		shared_ptr<IMedia> img{ new Image() };
		img = imageFactory->Create(pathfilenames[i]);
		//Insert image into the container
		_container->insert(pair<int, shared_ptr<IMedia>>(i, img));
		cout << pathfilenames[i] << endl;
	}
	
	return ptr;
}



//return a shared pointer to a media item within the container via its index
shared_ptr<IMedia> MediaManager::getMediaItemIndex(int index)
{
	//Create a blank image reference
	shared_ptr<IMedia> img{ new Image() };

		img = _container->find(index)->second;
		if (_container->find(index) == _container->end())
		{
			//Throw exception
			
		}
	
	
		return img;
}