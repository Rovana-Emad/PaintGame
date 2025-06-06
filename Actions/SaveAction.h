#pragma once
#include "Action.h"
#include <fstream>

class SaveAction : public Action
{
private:
	string inputstring;
public:

	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	string colorToString(color c);
};