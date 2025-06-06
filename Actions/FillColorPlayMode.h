
#pragma once

#include"Action.h"

class FillColorPlayMode :public Action
{

public:
	FillColorPlayMode(ApplicationManager* pApp);
	~FillColorPlayMode();
	void ReadActionParameters();
	void Execute();

};

