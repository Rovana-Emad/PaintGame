#ifndef CUT_ACTION_H
#define CUT_ACTION_H
#include "..\Figures\CFigure.h"
#include "Action.h"



class CutAction :
    public Action
{
public:
	CutAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	//Executes "Cut"
	virtual void Execute();

};

#endif