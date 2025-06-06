#include "LoadAction.h"
#include "..\Figures\CRectangle.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CHexagon.h"
#include"..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h" 
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"


#include "..\GUI/Input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>

using namespace std;


LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}


void LoadAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (UI.InterfaceMode == MODE_DRAW)
	{
		pOut->PrintMessage("Please enter the file name to be loaded");
		inputstring = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
	}
	else
		inputstring = "temp";
}


void LoadAction::Execute() {

	ReadActionParameters();
	
	
	string filename = inputstring + ".txt";
	ifstream File(filename); 

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (File.is_open())
	{
		
		pManager->clearall();//Clears everything in drawing area

		pOut->PrintMessage("File is successfully loaded");

		//Read the current fill and draw color and set them
		

		int n;      //Reading num of figures the first int in the text file
		File >> n;
		string FIGtype;
		
		CFigure * myFig = NULL;
		
		for (int i = 0; i < n; i++) {
			
			File >> FIGtype;
			if (FIGtype == "RECT") {
				myFig = new CRectangle();
			}
			else if(FIGtype == "CIRC"){
				myFig = new CCircle();
			}
			else if (FIGtype == "TRIA") {
				myFig = new CTriangle();
			}
			else if (FIGtype == "HEXA") {
				myFig = new CHexagon();
			}
			else if (FIGtype == "SQUR") {
				myFig = new CSquare();
			}
			if (myFig != nullptr) {
				myFig->Load(File);
				myFig->SetID(CFigure::GetNextID());
				CFigure::IncrementNextID();
				pManager->AddFigure(myFig);
			}
			
		}
		
		File.close();
	}
	else
	{
		pOut->PrintMessage("Unable to open file");
	}

}