#include "FillColorPlayMode.h"
#include "..\ApplicationManager.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CSquare.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillColorPlayMode::FillColorPlayMode(ApplicationManager* pApp) :Action(pApp) {}

FillColorPlayMode::~FillColorPlayMode() {}

void FillColorPlayMode::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    Point P1;
    pIn->GetPointClicked(P1.x, P1.y);
}

void FillColorPlayMode::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pOut->PrintMessage("Play with me! Pick all the figures based on COLOURS.");
    CFigure* randFig = pManager->GetFigRand();
    int wrong = 0, right = 0;
    if (dynamic_cast<CHexagon*>(randFig)) {
        pOut->PrintMessage("HEXAGON");
    }
    else if (dynamic_cast<CCircle*>(randFig)) {
        pOut->PrintMessage("HEXAGON");

    }
    else if (dynamic_cast<CSquare*>(randFig)) {
        pOut->PrintMessage("HEXAGON");

    }
    else if (dynamic_cast<CRectangle*>(randFig)) {
        pOut->PrintMessage("HEXAGON");

    }
    else {
        pOut->PrintMessage("None");

    }
   
    Point P1;
    pIn->GetPointClicked(P1.x, P1.y);
    while (P1.y > 50) {
     CFigure* clickedFig = pManager->GetFigure(P1);
        if (!clickedFig) {
     pOut->PrintMessage("Click Again!");
       }
         else {
             if (clickedFig->GetFigGfxfoIn().FillClr == randFig->GetFigGfxfoIn().FillClr)
 {
    right++;
     pManager->DElete();
     pOut->PrintMessage("trsh trsh!");
    
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