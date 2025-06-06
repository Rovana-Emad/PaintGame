#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H
#include "..\Figures\CFigure.h"
#include "Action.h"
class PasteAction :
    public Action
{ 
private:
	Point p1;
public:
	PasteAction(ApplicationManager* pApp);

	//till now maloosh ay m3na bas has to be implemented
	virtual void ReadActionParameters();

	//Executes "Paste"
	virtual void Execute();

};

#endif