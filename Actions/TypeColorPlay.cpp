#include"TypeColorPlay.h"
#include "..\ApplicationManager.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CSquare.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
TypeColorPlay::TypeColorPlay(ApplicationManager* pApp) :Action(pApp) {}

TypeColorPlay::~TypeColorPlay() {}

void TypeColorPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point P1;
	pIn->GetPointClicked(P1.x, P1.y);

}

void TypeColorPlay::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//CFigure* randFig = pManager->GetFigRand();
	int wrong = 0, right = 0;

}