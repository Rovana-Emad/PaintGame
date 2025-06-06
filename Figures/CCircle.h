#ifndef CCIR_H
#define CCIR_H

#include"CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile);	//load the figure parameters from the file
	virtual bool checkincludedpoints(Point p);
	virtual CFigure* clone() const;
	virtual Figure_type GetFigType() const;
	virtual Point  GetPoint1()const;
	virtual Point  GetPoint2()const;
};

#endif