#pragma once

#include"Action.h"

class TypePlay :public Action
{

public:
	TypePlay(ApplicationManager* pApp);
	~TypePlay();
	void ReadActionParameters();
	void Execute();

};

