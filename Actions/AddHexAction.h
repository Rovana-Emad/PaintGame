#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H


#include "Action.h"

//Add Hexagon Action class
class AddHexAction :public Action
{
private:
	Point P1; //Center of the Hexagon
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();
};

#endif
