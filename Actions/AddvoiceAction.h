

#ifndef ADD_Voice_ACTION_H
#define ADD_Voice_ACTION_H

#include "Action.h"


class AddvoiceAction : public Action
{
private:

public:

	AddvoiceAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};



#endif