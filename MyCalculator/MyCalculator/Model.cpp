#include "stdafx.h"
#include "Model.h"
#include "EventArgs.h"
#include <iostream>
#include <memory>

Model::Model()
{
	_mediaManager = make_shared<MediaManager>();
}


Model::~Model()
{
}


///Subscribe the listeners for the observer
void Model::subscribe(shared_ptr<IEventListener> listener)
{
	_eventHandlers.push_back(listener);
}

///Load all the files from the filename list, return the first image loaded.
void Model::LoadImages(vector<string> fileNames)
{
	_mediaManager->load(fileNames);
	for (int i = 0; i < _eventHandlers.size(); i++)
	{
		_eventHandlers[i]->receiveImage(_mediaManager->getMediaItemIndex(0));	
	}
}

///Return an image based on an input index
void Model::ReturnImage(int index)
{
	
	for (int i = 0; i < _eventHandlers.size(); i++)
	{
		_eventHandlers[i]->receiveImage(_mediaManager->getMediaItemIndex(index));
		cout << "BANG";
	}
}
