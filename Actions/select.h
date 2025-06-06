#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class Select : public Action
{
private:
	Point p;
	CFigure* fig;
public:
	Select(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};


