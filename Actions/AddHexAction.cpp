#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"
#include "AddvoiceAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	


	if (pManager->voiceActivated == true) {


		PlaySound(TEXT("hexagon.wav"), NULL, SND_FILENAME | SND_SYNC);
	}

	pOut->PrintMessage("New Hexagon: Click at the center of the Hexagon");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);



	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	
	//Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P1, HexGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}