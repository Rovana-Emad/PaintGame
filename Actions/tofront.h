
#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class tofront : public Action
{
private:
	CFigure* figg;
	Point p;
public:
	tofront(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};


