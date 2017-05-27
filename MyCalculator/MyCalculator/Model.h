#include "IEventPublisher.h"
#include "IModel.h"
#include <memory>
#include <vector>
#include "FreeImagePlus.h"
#include "MediaManager.h"
#include <string>

#pragma once





using namespace std;
class Model : public IModel, public IEventPublisher
{
public:
	Model();
	~Model();

	//Subscribe a listener to the observer
	void IEventPublisher::subscribe(shared_ptr<IEventListener> obj);

	//Load all images based on all strings within the filenames vector
	void IModel::LoadImages(vector<string> fileNames);
	//Return an image located within the container based upon the index given
	void IModel::ReturnImage(int index);

private:
	double _result;
	//Reference to all the listeners for the events
	vector<shared_ptr<IEventListener>> _eventHandlers;
	//A reference to the media manager which will load,store and return our images.
	shared_ptr<IMediaManager> _mediaManager;

	
};

