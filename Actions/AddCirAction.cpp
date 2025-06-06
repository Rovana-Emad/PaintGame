
#include <Windows.h>
#include<mmsystem.h>
#include<iostream>             //voice
#pragma comment(lib,"winmm.lib")

#include "AddCirAction.h"
#include "AddvoiceAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCirAction::AddCirAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCirAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->voiceActivated == true) {
		PlaySound(TEXT("circle.wav"), NULL, SND_FILENAME | SND_SYNC);
	}

	pOut->PrintMessage("New Circle: Click at the Center of the Circle");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at the Radius of the Circle");

	//Read Radius  and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = false;	//default is not filled

	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCirAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	
	//Create a Circle with the parameters read from the user
	CCircle* C = new CCircle(P1, P2, CircleGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(C);
}
