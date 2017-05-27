#include "IEventListener.h"
#include <memory>
#pragma once
class IEventPublisher
{
public:

	IEventPublisher()
	{
	}

	virtual ~IEventPublisher()
	{
	}

	virtual void subscribe(std::shared_ptr<IEventListener> evel) = 0;
};

