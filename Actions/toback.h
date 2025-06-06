#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class toback : public Action
{
private:
	CFigure* figg;
	Point p;
public:
	toback(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};
