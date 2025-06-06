#include "CRectangle.h"
#include <fstream>
#include <iostream>

CRectangle::CRectangle() :CFigure()
{
	//for the load
	
	
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	//Setting an ID for the figure
	ID = IDSetter++;
	Corner1 = P1;
	Corner2 = P2;
	FigGfxInfo.figtype = RECTANGLE;

}

Point  CRectangle::GetPoint1()const{
	return Corner1;
}
Point  CRectangle::GetPoint2()const {
	return Corner2;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected==true );  //so the load isnt selected
	

}
bool CRectangle::checkincludedpoints(Point p)
{
	if (Corner1.x < Corner2.x && Corner1.y < Corner2.y)
	{
		if (p.x >= Corner1.x && p.x <= Corner2.x && p.y >= Corner1.y && p.y <= Corner2.y)
		{
			return true;
		}
		else { return false; }
	}
	else if (Corner1.x > Corner2.x && Corner1.y > Corner2.y)
		if (p.x <= Corner1.x && p.x >= Corner2.x && p.y <= Corner1.y && p.y >= Corner2.y)
		{
			return true;
		}
		else { return false; }

	else if (Corner1.x < Corner2.x && Corner1.y > Corner2.y)
	{
		if (p.x >= Corner1.x && p.x <= Corner2.x && p.y <= Corner1.y && p.y >= Corner2.y)
		{
			return true;
		}
		else { return false; }
	}
	else if (Corner1.x > Corner2.x && Corner1.y < Corner2.y)
	{
		if (p.x <= Corner1.x && p.x >= Corner2.x && p.y >= Corner1.y && p.y <= Corner2.y)
		{
			return true;
		}
		else { return false; }
	}
}

void CRectangle::Save(ofstream& outFile) {
	outFile << "RECT" << " " << ID  << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y;

	outFile << " " << colorToString(FigGfxInfo.DrawClr);
	
	if (FigGfxInfo.isFilled == 0) {
		outFile << " " << "NO_FILL" << "\n";
	}
	else {
		outFile << " " << colorToString(FigGfxInfo.FillClr) << "\n";
	}
}

void CRectangle::Load(ifstream& inFile) {
	inFile >> ID;

	inFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;

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

CFigure* CRectangle::clone() const {
	return new CRectangle(*this);
}
Figure_type CRectangle::GetFigType() const {
	return FigGfxInfo.figtype;
}