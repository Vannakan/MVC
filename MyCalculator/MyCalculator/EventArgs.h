#include "IEventArgs.h"
#pragma once
class EventArgs : public IEventArgs
{
public:
	EventArgs(double val);
	~EventArgs();

	double IEventArgs::args();

private:
	double _result;
};

