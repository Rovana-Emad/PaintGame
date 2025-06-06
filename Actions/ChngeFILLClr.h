#ifndef CHNGE_FILL_CLR_H
#define CHNGE_FILL_CLR_H
#include "..\Figures\CFigure.h"
#include "Action.h"
class ChngeFILLClr :
	public Action
{
public:
	ChngeFILLClr(ApplicationManager* pApp);

	//static void copy(CFigure*& clipbrd, const CFigure* sourcefig);
	//till now maloosh ay m3na bas has to be implemented
	virtual void ReadActionParameters();

	//Executes "Copy"
	virtual void Execute();
};
#endif

