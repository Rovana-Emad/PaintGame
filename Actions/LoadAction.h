#pragma once
#include "Action.h"
#include <fstream>

class LoadAction :public Action
{
	string inputstring;
public:
	LoadAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	string colorToString(string s);
};
