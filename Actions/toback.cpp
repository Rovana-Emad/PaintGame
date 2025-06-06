#include "toback.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
using namespace std;
toback::toback(ApplicationManager* pApp) :Action(pApp)
{
	figg = NULL;
}

void toback::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Send to Back icon, The selected Figure will be back all figures");
}
void toback::Execute()
{
	ReadActionParameters();
		pManager->sendtoback();
}