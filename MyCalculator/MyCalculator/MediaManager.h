#pragma once

#include "IMediaManager.h"
class MediaManager : public IMediaManager
{
public:
	MediaManager();
	~MediaManager();


	shared_ptr<vector<string>>load(vector<string>pathfilenames);

	shared_ptr<IMedia>getMediaItemIndex(int index);

	int containerSize();


private:
	shared_ptr<ImageFactory> imageFactory{ new ImageFactory() };

	shared_ptr<map<string, shared_ptr<IMedia>>> container{ new map<string, shared_ptr<IMedia>> };

	shared_ptr<map<int, shared_ptr<IMedia>>> _container{ new map<int,shared_ptr<IMedia>> };
};

