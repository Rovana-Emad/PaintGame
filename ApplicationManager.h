#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	CFigure* Clipboard;  //Pointer to copied/cut figure
	
public:	
	
	bool voiceActivated;
	void unselectfigure(CFigure* figg);
	void unselectall();
	 
	ApplicationManager(); 
	~ApplicationManager();

	int GetnumSelectedFigs();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(Point p); //Search for a figure given a point inside the figure
	CFigure* checktheselection(Point p);
	void bringtofront();
	void sendtoback();
	CFigure* GetFigRand();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	// -- Save/Load Action functions
	void SaveAll(ofstream& outFile);
	string colorToString(color c);
	void DElete();
	void clearall();
	void copy(); 
	void cut();
	void paste(int& a, int& b);
	void findOtherCoordinates(const Point& A1, const Point& A2, const Point& A3, const Point& B, Point& B2, Point& B3);
	color SelectedColor() const;
	void ChangeBrdrClr(color chosen);
	void ChangeFillClr(color chosen);
	string colortoStringcurrent(color c) {
		if (c == RED) { return "Red"; }
		if (c == BLUE) { return "Blue"; }
		if (c == GREEN) { return "Green"; }
		if (c == BLACK) { return "Black"; }
		if (c == YELLOW) { return "Yellow"; }
		if (c == ORANGE) { return "Orange"; }
		else { return "NO_FILL"; }

	}
	
};



#endif