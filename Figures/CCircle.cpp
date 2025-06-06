
#include "CCircle.h"
#include <fstream>
#include <iostream>

CCircle::CCircle() :CFigure()
{//for load
}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{

	//Setting an ID for the figure
	ID = IDSetter++;
	Center = P1;
	Radius = P2;
	FigGfxInfo.figtype = CIRCLE;
}

Point  CCircle::GetPoint1()const {
	return Center;
}
Point  CCircle::GetPoint2()const {
	return Radius;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCir(Center, Radius, FigGfxInfo, Selected==true);



}

bool CCircle::checkincludedpoints(Point p)
{

	int distc = sqrt((p.x - Center.x) * (p.x - Center.x) + (p.y - Center.y) * (p.y - Center.y));
	int Rad = sqrt((Radius.x - Center.x) * (Radius.x - Center.x) + (Radius.y - Center.y) * (Radius.y - Center.y));
	if (distc <= Rad) {
		return true;
	}
	else {
		return false;
	}
}

Figure_type CCircle::GetFigType() const {
	return FigGfxInfo.figtype;
}

void CCircle::Save(ofstream& outFile) { 
	outFile << "CIRC" << " " << ID << " " << Center.x << " " << Center.y << " " << Radius.x << " " << Radius.y;
	
	outFile<<" " << colorToString(FigGfxInfo.DrawClr);
	if (FigGfxInfo.isFilled == 0) {
		outFile << " " << "NO_FILL" <<"\n";
		 }
	else {
		outFile << " " << colorToString(FigGfxInfo.FillClr) <<"\n";
	}
	//outFile << " " << FigGfxInfo.isFilled << "\n";
}

void CCircle::Load(ifstream& inFile) {
	inFile >> ID; 

	inFile >> Center.x >> Center.y >> Radius.x >> Radius.y;

	//get drawing, filling colors and pen width from the file
	string s;
	string t;
	inFile >> s;    //Reading Drawcolor
	FigGfxInfo.DrawClr = StringToColor(s)  ;
	inFile >> t;   //Reading fill color
	if (StringToColor(t) == TAN) {
		FigGfxInfo.isFilled = 0;
	}
	else{ FigGfxInfo.FillClr = StringToColor(t); }
	
	
		
}

CFigure* CCircle::clone() const {
	return new CCircle (*this);
}
