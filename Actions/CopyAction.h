#ifndef COPY_ACTION_H
#define COPY_ACTION_H
#include "..\Figures\CFigure.h"
#include "Action.h"


class CopyAction :
	public Action
{
public:
	CopyAction(ApplicationManager* pApp);

	//static void copy(CFigure*& clipbrd, const CFigure* sourcefig);  //not sure el source hyeb2a constant pointer walla refrence lessa

	//till now maloosh ay m3na bas has to be implemented
	virtual void ReadActionParameters();

	//Executes "Copy"
	virtual void Execute();


};





#endif
