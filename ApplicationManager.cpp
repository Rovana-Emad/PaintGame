#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include"Actions\AddTriAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCirAction.h"
#include"Actions\SaveAction.h"
#include"Actions\SwitchToPlay.h"
#include"Actions\SwitchToDraw.h"
#include"Actions\LoadAction.h"
#include"Actions\AddvoiceAction.h"
#include"Actions\select.h"
#include"Actions\DElete.h"
#include"Actions\clear.h"
#include"Actions\tofront.h"
#include"Actions\toback.h"
#include"Actions\ChngeBrdrClr.h"
#include"Actions\ChngeFILLClr.h"
#include"Actions\CopyAction.h"
#include"Actions\CutAction.h"
#include"Figures\CSquare.h"
#include"Figures\CRectangle.h"
#include"Figures\CHexagon.h"
#include"Figures\CTriangle.h"
#include"Figures\CCircle.h"
#include"Actions/FillColorPlayMode.h"
#include"Actions/TypePlay.h"


//#include"Actions\FillColorPlayMode.h"
#include"GUI\Output.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <cmath>
#include "Actions\PasteAction.h"


//Constructor

ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	//variables intialized
	FigCount = 0;
	voiceActivated = false;
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	Clipboard = nullptr;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSqrAction(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriAction(this);
			break;
		case DRAW_HEXAGON:
			pAct = new AddHexAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCirAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlay(this);
			break;
		case TO_DRAW:
			pAct = new SwitchToDraw(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case CLEAR:
			pAct = new clear(this);
			break;
		case DELETE_ICON:
			pAct = new DEleteFigures(this);
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case VOICE:
			pAct = new AddvoiceAction(this);
			break;
		case COPY:
			pAct = new CopyAction(this);
			break;
		case CUT:
			pAct = new CutAction(this);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		case OUT_ICON:
			pAct = new ChngeBORDERClr(this);
			break;
		case IN_ICON:
			pAct = new ChngeFILLClr(this);
			break;
		case TOFORWARD:
			pAct = new tofront(this);
			break;
		case TOBACK:
			pAct = new toback(this);
			break;
			case HIDE_COLOR:
				pAct = new FillColorPlayMode(this);
			case HIDE_TYPE:
				pAct = new TypePlay(this);

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Already excuted in the lines above no need for it delete
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::bringtofront()
{
	if (SelectedFig != NULL) {
		int index = -1;
		for (int i = 0; i < FigCount; ++i) {
			if (FigList[i] == SelectedFig) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			for (int i = index; i < FigCount - 1; ++i) {
				CFigure* temp = FigList[i];
				FigList[i] = FigList[i + 1];
				FigList[i + 1] = temp;
			}
		}
	}
}

void ApplicationManager::sendtoback()
{
	if (SelectedFig != NULL) {
		int index = -1;
		for (int i = 0; i < FigCount; i++) {
			if (FigList[i] == SelectedFig) {
				index = i;
				break;
			}
		}
		if (index != NULL){
		for (int i = index; i > 0; --i) {
			CFigure* temp = FigList[i];
			FigList[i] = FigList[i - 1];
			FigList[i - 1] = temp;

		}
		}
	}
}



CFigure* ApplicationManager::GetFigure(Point p)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->checkincludedpoints(p) == true)
		{
			SelectedFig = FigList[i];
			count++;
		}
	}
	if (count > 0)
	{
		return SelectedFig;

	}
	else if (count == 0)
	{
		return NULL;
	}
}



void ApplicationManager::unselectfigure(CFigure* figg)
{
	if (figg->IsSelected() == true)
	{
		figg->SetSelected(false);
		SelectedFig = NULL;
	}

}

void ApplicationManager::unselectall()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			FigList[i]->SetSelected(false);
			SelectedFig = NULL;
		}
	}

}



int ApplicationManager :: GetnumSelectedFigs() {
	int n = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			++n;
		}
	}
	return n;
}



CFigure* ApplicationManager::GetFigRand() 
{
	srand(time(NULL));
	int randI = rand() % (FigCount + 1);
	return FigList[randI];
}



//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }

//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
 //==================================================================================//
//							SaveAll  Function 						//
//==================================================================================//
void ApplicationManager::SaveAll(ofstream& outFile) {


	//outFile << colortoStringcurrent(SelectedColor());

	int countOfFigures = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != nullptr) {
			countOfFigures++;
		}
	}
	outFile <<countOfFigures<< "\n ";                           // displays number of current figures 
	//outFile << GfxInfo.DrawClr << GfxInfo.FillClr <<" \n "; 
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(outFile);
	}
}


void ApplicationManager::DElete() {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected() == true)
		{
			delete FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
		}
	}
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected() == true)
		{
			delete FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
		}
	}
	UpdateInterface();
}

void ApplicationManager::clearall()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		pOut->ClearDrawArea();
	}
	FigCount = 0;
}


void ApplicationManager::copy() {
	if (SelectedFig != nullptr) {
		const CFigure* sourceFig = SelectedFig;
		if (Clipboard != nullptr) {
			delete Clipboard; // Clear the previous clipboard content
		}
		Clipboard = sourceFig->clone();
	}
}

void ApplicationManager::cut() {
	Output* pOut=GetOutput();
	const CFigure* sourceFig = SelectedFig;
	color OG_Drawcolor = sourceFig->GetDrawClr();
	color OG_Fillcolor = sourceFig->GetFillClr();
	//color OG_Fillcolor = sourceFig->GetFillClr();
	if (Clipboard != nullptr) {
		if (SelectedFig->IsCut()) {
			SelectedFig->ChngDrawClr(OG_Drawcolor);
			SelectedFig->ChngFillClr(OG_Fillcolor);
		}
		delete Clipboard; // Clear the previous clipboard content
	}
	Clipboard = sourceFig->clone();
	SelectedFig->ChngDrawClr(GRAY);
	SelectedFig->ChngFillClr(GRAY);
	SelectedFig->SetCut(true);
}


void ApplicationManager::paste(int&a, int&b) {
	Point p1;
	p1.x = a;
	p1.y = b;
	Point p2;
	p2.x = 0;
	p2.y = 0;
	Point p3;
	p3.x = 0;
	p3.y = 0;
	Output* pOut = GetOutput();
	Input* pIn = GetInput();
	CSquare* S;
	CRectangle* R;
	CCircle* C;
	CTriangle* T;
	CHexagon* H;

	if (Clipboard != nullptr) {
		//CFigure* copiedfigure = Clipboard->clone();
		if (SelectedFig->IsCut()) {
			DElete();
		}
		GfxInfo figInfo= Clipboard->GetFigInfo();
		switch (Clipboard->GetFigType()) {
		case SQUARE:
			S = new CSquare(p1, figInfo);
			AddFigure(S);
			S->Draw(pOut);
			break;
		case RECTANGLE:
		{	
			Point OG_p1r = Clipboard->GetPoint1();
			Point OG_p2r = Clipboard->GetPoint2();
			

			double v1x = OG_p2r.x - OG_p1r.x;
			double v1y = OG_p2r.y - OG_p1r.y;
			p2.x = p1.x + v1x;
			p2.y = p1.y + v1y;
			R = new CRectangle(p1, p2, figInfo);
			AddFigure(R);
			R->Draw(pOut);
		}
			break;
		case TRIANGLE:
		{
			Point OG_p1t = Clipboard->GetPoint1();
			Point OG_p2t = Clipboard->GetPoint2();
			Point OG_p3t = Clipboard->GetPoint3();
			findOtherCoordinates(OG_p1t, OG_p2t, OG_p3t, p1, p2, p3);
			T = new CTriangle(p1, p2, p3, figInfo);
			AddFigure(T);
			T->Draw(pOut);
		}
			break;
		case HEXAGON:
		{
			H = new CHexagon(p1, figInfo);
			AddFigure(H);
			H->Draw(pOut);
		}
			break;
		case CIRCLE:
		{
			Point OG_p1c = Clipboard->GetPoint1();
			Point OG_p2c = Clipboard->GetPoint2();
			double radius = sqrt(pow(OG_p1c.x - OG_p2c.x, 2) + pow(OG_p1c.y - OG_p2c.y, 2));
			p2.x = p1.x + radius;
			p2.y = p1.y;
			C = new CCircle(p1, p2, figInfo);
			AddFigure(C);
			C->Draw(pOut);
		}
			break;
		}
		

	}
}
// Function to find the other two coordinates of triangle B
void ApplicationManager:: findOtherCoordinates(const Point& A1, const Point& A2, const Point& A3, const Point& B, Point& B2, Point& B3) {
	// Calculate the length of the sides of triangle A
	double aLength = std::sqrt(std::pow(A2.x - A3.x, 2) + std::pow(A2.y - A3.y, 2));
	double bLength = std::sqrt(std::pow(A1.x - A3.x, 2) + std::pow(A1.y - A3.y, 2));
	double cLength = std::sqrt(std::pow(A1.x - A2.x, 2) + std::pow(A1.y - A2.y, 2));

	// Find the angle of triangle A at vertex A3 using law of cosines
	double cosAngleA = (std::pow(aLength, 2) + std::pow(cLength, 2) - std::pow(bLength, 2)) / (2 * aLength * cLength);

	// Calculate the distance between A1 and A3
	double distA1A3 = std::sqrt(std::pow(A1.x - A3.x, 2) + std::pow(A1.y - A3.y, 2));

	// Calculate the direction vector from A3 to A1
	double dirX = (A1.x - A3.x) / distA1A3;
	double dirY = (A1.y - A3.y) / distA1A3;

	// Calculate the coordinates of the other two vertices of triangle B based on the congruence with triangle A
	
	B2.x = B.x + distA1A3 * cosAngleA;
	B2.y = B.y + distA1A3 * std::sqrt(1 - std::pow(cosAngleA, 2));
	B3.x = B.x + distA1A3 * cosAngleA;
	B3.y = B.y - distA1A3 * std::sqrt(1 - std::pow(cosAngleA, 2));
}


color ApplicationManager::SelectedColor() const {
	Input* pIn = GetInput();
	ActionType Chosenclr = GetUserAction();
	switch (Chosenclr) {
	case ITM_BLACKO:
		return BLACK;
		break;
	case ITM_YELLOWO:
		return YELLOW;
		break;
	case ITM_ORANGEO:
		return ORANGE;
		break;
	case ITM_REDO:
		return RED;
		break;
	case ITM_GREENO:
		return GREEN;
		break;
	case ITM_BLUEO:
		return BLUE;
		break;
	}
}
void ApplicationManager::ChangeBrdrClr(color chosen) {
	SelectedFig->ChngDrawClr(chosen);
	}
void ApplicationManager::ChangeFillClr(color chosen) {
	SelectedFig->ChngFillClr(chosen);
}


//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	delete Clipboard;
	delete SelectedFig;

}
