#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int IDSetter; ///to set id 
	bool isCut; //checks whether figure is cut
	/// Add more parameters if needed.
public:
	GfxInfo GetFigInfo(){
		return FigGfxInfo;
	}
	void SetID(int id) { //trying
		ID = id;
	}
	static int GetNextID() {
		return IDSetter;
	}

	static void IncrementNextID() {
		IDSetter++;
	}
	GfxInfo GetFigGfxfoIn() const;
	int GetShapeID();
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure
	virtual bool checkincludedpoints(Point p)=0;

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	color CFigure::GetDrawClr() const; //gets drawing color
	color CFigure::GetFillClr() const; //gets fill color

	///The following functions should be supported by the figure class
	/// 
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file
	string colorToString(color c) {
		if (c == RED) { return "Red"; }
		if (c == BLUE) { return "Blue"; }
		if (c == GREEN) { return "Green"; }
		if (c == BLACK) { return "Black"; }
		if (c == YELLOW) { return "Yellow"; }
		if (c == ORANGE) { return "Orange"; }
		else { return "NO_FILL"; }

	}
	color StringToColor(string s) {
		if (s == "Red") { return RED; }
		if (s == "Blue") { return BLUE; }
		if (s == "Green") { return GREEN; }
		if (s == "Black") { return BLACK; }
		if (s == "Yellow") { return YELLOW; }
		if (s == "Orange") { return ORANGE; }
		if (s == "NO_FILL") { return TAN; }   //just because the function has to return a color

	}

	virtual Point  GetPoint1()const;
	virtual Point  GetPoint2()const;
	virtual Point  GetPoint3()const;


	//clones a figure by returning a dynamically allocated version of it (for cut and copy)
	virtual CFigure* clone() const = 0;

	//checks whether figure is cut
	bool IsCut()const;
	//sets isCut
	void SetCut(bool cut);

	virtual Figure_type GetFigType() const = 0;

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif
