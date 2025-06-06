#include "AddSqrAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"
#include "AddvoiceAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->voiceActivated == true) {
		PlaySound(TEXT("square.wav"), NULL, SND_FILENAME | SND_SYNC);
	}

	pOut->PrintMessage("New Square: Click at the center of the square");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	

	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	
	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(P1, SqrGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(S);
}