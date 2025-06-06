#include "DElete.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
DEleteFigures::DEleteFigures(ApplicationManager* pApp) :Action(pApp)
{}

void DEleteFigures::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("The Selected Figures are deleted");


}
void DEleteFigures::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->DElete();

}
