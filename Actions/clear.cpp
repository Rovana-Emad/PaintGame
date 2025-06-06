#include "clear.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
clear::clear(ApplicationManager* pApp) :Action(pApp)
{}

void clear::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("All Figures are deleted");

}
void clear::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->clearall();

}