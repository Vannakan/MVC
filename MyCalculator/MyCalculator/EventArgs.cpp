#include "stdafx.h"
#include "EventArgs.h"


EventArgs::EventArgs(double val)
{
	_result = val;
}


EventArgs::~EventArgs()
{
}

double EventArgs::args()
{
	return _result;
}
