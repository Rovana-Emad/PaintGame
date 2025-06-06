#include "CTriangle.h"
#include <fstream>
#include <iostream>

CTriangle::CTriangle() :CFigure()
{//for the load
}

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{

	//Setting an ID for the figure
	ID = IDSetter++;
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	FigGfxInfo.figtype = TRIANGLE;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri	on screen
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, Selected==true );


}
bool CTriangle::checkincludedpoints(Point p)
{

	Point p0 = { Corner2.x - Corner1.x, Corner2.y - Corner1.y };
	Point p1 = { Corner3.x - Corner1.x, Corner3.y - Corner1.y };
	Point p2 = { p.x - Corner1.x, p.y - Corner1.y };

	float dot0 = p0.x * p0.x + p0.y * p0.y;
	float dot1 = p0.x * p1.x + p0.y * p1.y;
	float dot2 = p0.x * p2.x + p0.y * p2.y;

	float dot11 = p1.x * p1.x + p1.y * p1.y;
	float dot12 = p1.x * p2.x + p1.y * p2.y;

	float x = 1 / (dot0 * dot11 - dot1 * dot1);
	float u = (dot11 * dot2 - dot1 * dot12) * x;
	float v = (dot0 * dot12 - dot1 * dot2) * x;

	return (u >= 0) && (v >= 0) && (u + v < 1);
}
void CTriangle::Save(ofstream& outFile) {
	outFile << "TRIA" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y  ;

	outFile << " " << colorToString(FigGfxInfo.DrawClr);
	
	if (FigGfxInfo.isFilled == 0) {
		outFile << " " << "NO_FILL" << "\n";
	}
	else {
		outFile << " " << colorToString(FigGfxInfo.FillClr) << "\n";
	}
}

void CTriangle::Load(ifstream& inFile) {
	inFile >> ID;

	inFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;

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

CFigure* CTriangle::clone() const {
	return new CTriangle(*this);
}

Figure_type CTriangle::GetFigType() const {
	return FigGfxInfo.figtype;
}

Point CTriangle::GetPoint1()const {
	return Corner1;
}
Point CTriangle::GetPoint2()const {
	return Corner2;
}
Point CTriangle::GetPoint3()const {
	return Corner3;
}