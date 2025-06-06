#include "CopyAction.h"

#include"..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"




CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp) {}



void CopyAction::ReadActionParameters()
{}

//Executes "Copy"
void CopyAction::Execute() {
	int number=pManager->GetnumSelectedFigs();
	Output* pOut = pManager->GetOutput();
	if (number == 1) {
		pManager->copy();
		pOut->PrintMessage("Figure Copied");
	}
	else if (number == 0) {
		pOut->PrintMessage("No figure selected. Cannot copy.");
	}
	else if (number > 0) {
		pOut->PrintMessage("More than one selected figure. Cannot copy multiple figures.");
	}
}

