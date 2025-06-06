#pragma once
#include "Action.h"
class DEleteFigures : public Action
{
public:
	DEleteFigures(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};
