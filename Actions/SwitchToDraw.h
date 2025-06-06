#pragma once
#include "Action.h"
class SwitchToDraw :
    public Action
{
public:
	SwitchToDraw(ApplicationManager* pApp);
	~SwitchToDraw();
	void ReadActionParameters();
	void Execute();
};

