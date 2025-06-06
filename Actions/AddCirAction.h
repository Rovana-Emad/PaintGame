#ifndef ADD_CIR_ACTION_H
#define ADD_CIR_ACTION_H

#include "Action.h"

//Add Circle Action class
class AddCirAction : public Action
{
private:
	Point P1, P2; //Circle center and Radius
	GfxInfo CircleGfxInfo;
public:
	AddCirAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

#endif
