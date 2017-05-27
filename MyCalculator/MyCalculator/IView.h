#include "IClick.h"

#include <memory>
#pragma once
class IView
{
public:

	

	virtual void ImageSelect() = 0;

	virtual void setClick(shared_ptr<IClick> click) = 0;
};

