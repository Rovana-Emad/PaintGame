#ifndef CSQR_H
#define CSQR_H


#include"CFigure.h"


class CSquare : public CFigure
{
private:
	Point Center1;

public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile);	//load the figure parameters from the file
	virtual bool checkincludedpoints(Point p);
	virtual CFigure* clone() const;
	virtual Figure_type GetFigType() const;

};

#endif
