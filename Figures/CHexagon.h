#ifndef HEX_H
#define HEX_H


#include"CFigure.h"


class CHexagon : public CFigure
{
private:
	Point Center1;

public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile);	//load the figure parameters from the file
	virtual bool checkincludedpoints(Point p);
	virtual CFigure* clone() const;
	virtual Figure_type GetFigType() const;
};

#endif