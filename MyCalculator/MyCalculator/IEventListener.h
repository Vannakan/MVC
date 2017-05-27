#include "IEventArgs.h"
#include <memory>
#include "IMedia.h"
#pragma once
class IEventListener
{
public:


	virtual ~IEventListener()
	{
	}


	
	virtual void receiveImage(std::shared_ptr<IMedia> args) = 0;

	virtual bool acceptsThumbnails() = 0;
	
};

