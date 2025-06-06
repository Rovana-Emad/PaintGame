#include "SwitchToDraw.h"
#include"..\ApplicationManager.h"
#include<fstream>
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"



SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{}


void SwitchToDraw::ReadActionParameters()
{}


void SwitchToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pManager->ExecuteAction(LOAD);

	pOut->CreateDrawToolBar();
}