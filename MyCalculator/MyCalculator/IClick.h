
#pragma once
#include <string>
#include <vector>
using namespace std;
class IClick
{
public:
	IClick()
	{
	}

	~IClick()
	{
	}

	//Handle user input via a string input
	//If the string passed in is equal to "Equals" call the equals event (we havent created..)
	virtual void handleClick(double va1, double val2, char op) = 0;

	virtual void requestLoad(vector<string> data) = 0;

	virtual void requestImage(int index) = 0;
	
};

