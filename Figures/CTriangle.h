#ifndef CTRI_H
#define CTRI_H

#include"CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle();
	 CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);

	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile);	//load the figure parameters from the file
	virtual bool checkincludedpoints(Point p);
	virtual CFigure* clone() const;
	virtual Figure_type GetFigType() const;
	virtual Point  GetPoint1()const;
	virtual Point  GetPoint2()const;
	virtual Point  GetPoint3()const;
};

#endif
