#pragma once
#include "Action.h"

class SwitchToPlay :public Action
{
public:
	SwitchToPlay(ApplicationManager* pApp);
	~SwitchToPlay();
	void ReadActionParameters();
	void Execute();
};