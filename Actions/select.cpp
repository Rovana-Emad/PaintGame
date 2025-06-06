#include "select.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Select::Select(ApplicationManager* pApp) :Action(pApp)
{}

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select icon, click on any figure");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearStatusBar();

}
void Select::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	fig = pManager->GetFigure(p);
	if (fig != NULL)
	{
		if (fig->IsSelected() == true)
		{
			pManager->unselectfigure(fig);

		}
		else
		{
			fig->SetSelected(true);
		}
	}
	else
	{

		pManager->unselectall();

	}
	fig = NULL;
}