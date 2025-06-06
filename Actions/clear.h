
#pragma once
#include "Action.h"
class clear : public Action
{
public:
	clear(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};
