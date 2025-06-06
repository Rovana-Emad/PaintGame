
#include"CHexagon.h"

#include <fstream>
#include <iostream>

CHexagon::CHexagon() :CFigure()
{  //for load
}

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	//Setting an ID for the figure
	ID = IDSetter++;
	Center1 = P1;
	FigGfxInfo.figtype = HEXAGON;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon on screen
	pOut->DrawHex(Center1, FigGfxInfo, Selected == true);


}
bool CHexagon::checkincludedpoints(Point p)
{
	double halssidelength = 75 / 2.0;  //const
	double apothem = halssidelength * sqrt(3) / 2.0;	//th perpendicular distance from the center to any side

	double dx = std::abs(p.x - Center1.x);
	double dy = std::abs(p.y - Center1.y);

	if (dx <= halssidelength && dy <= apothem * 2) {
		return true;
	}
	else if (dy <= 2 * apothem && dx <= halssidelength + apothem) {
		return true;
	}
	else { return false; }
}
void CHexagon::Save(ofstream& outFile) {
	outFile << "HEXA" << " " << ID << " " << Center1.x << " " << Center1.y ;

	outFile << " " << colorToString(FigGfxInfo.DrawClr);
	
	if (FigGfxInfo.isFilled == 0) {
		outFile << " " << "NO_FILL" << "\n";
	}
	else {
		outFile << " " << colorToString(FigGfxInfo.FillClr) << "\n";
	}
}

void CHexagon::Load(ifstream& inFile) {
	inFile >> ID;

	inFile >> Center1.x >> Center1.y ;

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

CFigure* CHexagon::clone() const {
	return new CHexagon (*this);
}

Figure_type CHexagon::GetFigType() const {
	return FigGfxInfo.figtype;
}