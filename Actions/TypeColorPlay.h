#pragma once

#include"Action.h"

class TypeColorPlay :public Action
{

public:
	TypeColorPlay(ApplicationManager* pApp);
	~TypeColorPlay();
	void ReadActionParameters();
	void Execute();

};