#include"CSquare.h"
#include <fstream>
#include <iostream>
CSquare::CSquare() :CFigure()
{//for load
}
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {

	//Setting an ID for the figure
	ID = IDSetter++;
	Center1 = P1;
	FigGfxInfo.figtype = SQUARE;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqr to draw a square on screen
	pOut->DrawSqr(Center1, FigGfxInfo, Selected==true );


}
bool CSquare::checkincludedpoints(Point p)
{
	double half = (75 * sqrt(2) / 2.0);
	if ((p.x >= Center1.x - half) && (p.x <= Center1.x + half) && (p.y >= Center1.y - half) && (p.y <= Center1.y + half)) {
		return true;
	}
	else { return false; }
}
void CSquare::Save(ofstream& outFile) {
	outFile << "SQUR" << " " << ID << " " << Center1.x << " " << Center1.y;

	outFile << " " << colorToString(FigGfxInfo.DrawClr);
	
	if (FigGfxInfo.isFilled == 0) {
		outFile << " " << "NO_FILL" << "\n";
	}
	else {
		outFile << " " << colorToString(FigGfxInfo.FillClr) << "\n";
	}
}

void CSquare::Load(ifstream& inFile) {
	inFile >> ID;

	inFile >> Center1.x >> Center1.y;

	//get drawing, filling colors and pen width from the file
	string s;
	string t;
	inFile >> s;    //Reading Drawcolor
	FigGfxInfo.DrawClr = StringToColor(s);
	inFile >> t;   //Reading fill color
	if (StringToColor(t) == TAN) {
		FigGfxInfo.isFilled = 0;
	}
	else { FigGfxInfo.FillClr = StringToColor(t); }
}

CFigure* CSquare::clone() const {
	return new CSquare(*this);
}
Figure_type CSquare::GetFigType() const {
	return FigGfxInfo.figtype;
}