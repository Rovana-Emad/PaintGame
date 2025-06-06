#include "ChngeFILLClr.h"
#include"..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"


ChngeFILLClr::ChngeFILLClr(ApplicationManager* pApp) :Action(pApp) {
	//P.x = NULL;
	//P.y = NULL;
}



void ChngeFILLClr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Select fill color");
}


void ChngeFILLClr::Execute() {
	Output* pOut = pManager->GetOutput();
	
	ReadActionParameters();
	int number = pManager->GetnumSelectedFigs();
	if (number == 1) {
		color Chosen = pManager->SelectedColor();
		pManager->ChangeFillClr(Chosen);
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