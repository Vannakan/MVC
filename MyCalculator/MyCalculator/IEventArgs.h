
#pragma once

#include "FreeImagePlus.h"
#include <memory>
class IEventArgs
{
public:

	IEventArgs()
	{
	}

	virtual ~IEventArgs()
	{
	}

	virtual double args() = 0;

};

