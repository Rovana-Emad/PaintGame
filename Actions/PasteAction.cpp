#include "PasteAction.h"
#include"..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"



PasteAction::PasteAction(ApplicationManager* pApp) :Action(pApp) {
}

void PasteAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click at the location to paste figure.");
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->ClearStatusBar();
}

//Executes "Paste"
void PasteAction::Execute() {
	ReadActionParameters();
	pManager->paste(p1.x, p1.y);
}