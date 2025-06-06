#include "TypePlay.h"
#include "..\ApplicationManager.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CSquare.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


TypePlay::TypePlay(ApplicationManager* pApp) :Action(pApp)

{}

void TypePlay::ReadActionParameters()
{}

void TypePlay::Execute()
{
	Output* pOut = pManager->GetOutput();
	// Choose shape randomly
	int chosen_shape = pManager->GetFigRand()->GetShapeID();
	switch (chosen_shape)
	{
	case DRAW_RECT:
		pOut->PrintMessage("Pick All The Rectangles. Gooo!");
		break;

	case DRAW_SQUARE:
		pOut->PrintMessage("Pick All The Squares. Gooo!");
		break;

	case DRAW_TRIANGLE:
		pOut->PrintMessage("Pick All The Triangles. Gooo!");
		break;

	case DRAW_HEXAGON:
		pOut->PrintMessage("Pick All The Hexagons. Gooo!");
		break;

	case DRAW_CIRCLE:
		pOut->PrintMessage("Pick All The Circles. Gooo!");
		break;
	}
	CFigure* randFig = pManager->GetFigRand();
	int wrong = 0, right = 0;
	Point P1;
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y > 50)
	{
		CFigure* clickedFig = pManager->GetFigure(P1);
		if (!clickedFig)
		{
			pOut->PrintMessage("Click Again!");
		}
		else {
			if (clickedFig->GetFigGfxfoIn().ShapeType == randFig->GetFigGfxfoIn().ShapeType)
			{
				right++;
				pManager->DElete();
				pOut->PrintMessage("click again!");
			}
			else
			{
				wrong++;
				pOut->PrintMessage("Click Again!");
			}
		}
		pIn->GetPointClicked(P1.x, P1.y);
	}


}