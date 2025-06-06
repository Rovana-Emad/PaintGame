#include "ChngeBrdrClr.h"

#include"..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"


ChngeBORDERClr::ChngeBORDERClr(ApplicationManager* pApp) :Action(pApp) {
	//P.x = NULL;
	//P.y = NULL;
}



void ChngeBORDERClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Select border color");
}

//Executes "Copy"
void ChngeBORDERClr::Execute() {
	ReadActionParameters();
	int number = pManager->GetnumSelectedFigs();
	Output* pOut = pManager->GetOutput();
	
	if (number == 1) {
		color Chosen=pManager->SelectedColor();
		pManager->ChangeBrdrClr(Chosen);
		pOut->ClearStatusBar();
		pOut->PrintMessage("Color changed");
	}
	else if (number == 0) {
		pOut->PrintMessage("No figure selected. Cannot change color.");
	}
	else if (number > 0) {
		pOut->PrintMessage("More than one selected figure. Please select only one figure to change its color.");
	}
}

//black, yellow, orange, red, green, and blue.