#include "CutAction.h"

#include"..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"

CutAction::CutAction(ApplicationManager* pApp) :Action(pApp) {}


void CutAction::ReadActionParameters()
{}

//Executes "Cut"
void CutAction::Execute() {



	int number = pManager->GetnumSelectedFigs();
	Output* pOut = pManager->GetOutput();
	if (number == 1) {
		pManager->cut();
		pOut->PrintMessage("Figure Cut");
	}
	else if (number == 0) {
		pOut->PrintMessage("No figure selected. Cannot cut.");
	}
	else if (number > 0) {
		pOut->PrintMessage("More than one selected figure. Cannot cut multiple figures.");
	}



}

