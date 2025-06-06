#include "CFigure.h"
#include <iostream>
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	isCut = false;
}

CFigure::CFigure()
{
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }
bool CFigure::checkincludedpoints(Point p)
{
	return true;
}
Point  CFigure::GetPoint1()const {
	std::cout << "Point 3 f Cfigure\n";
	Point p;
	p.x = NULL;
	p.y = NULL;
	return p;
}
Point  CFigure::GetPoint2()const{
	std::cout << "Point 3 f Cfigure\n";
	Point p;
	p.x = NULL;
	p.y = NULL;
	return p;
}
Point  CFigure::GetPoint3()const {
	std::cout << "Point 3 f Cfigure\n";
	Point p;
	p.x = NULL;
	p.y = NULL;
	return p;
}

color CFigure::GetDrawClr() const {
	return FigGfxInfo.DrawClr;
}
color CFigure::GetFillClr() const {
	return FigGfxInfo.FillClr;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;



	FigGfxInfo.FillClr = Fclr; 
}

bool CFigure::IsCut() const {
	return isCut;
}
void CFigure::SetCut(bool figcut) {
	isCut = figcut;
}

GfxInfo CFigure::GetFigGfxfoIn() const
{
	return this->FigGfxInfo;
}
int CFigure::GetShapeID()
{
	return ID;
}



int CFigure::IDSetter = 1; //initialization of IDSetter outside the class



