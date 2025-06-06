#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 2;
	UI.MenuItemWidth = 48;

	UI.DrawColor = BLUE;	// rayatesting //Drawing color  ///
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2024");

	CreateDrawToolBar();

	CreateStatusBar();

}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUAR] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRIG] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_SELECT.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\COPY.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\CUT.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\PASTE.jpg";
	MenuItemImages[ITM_TOBACK] = "images\\MenuItems\\TO BACK.jpg";
	MenuItemImages[ITM_TOFORWARD] = "images\\MenuItems\\TO FORWARD.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\LOAD.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\CLEAR.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\DELETE.jpg";
	MenuItemImages[ITM_OUT] = "images\\MenuItems\\in.jpg";
	MenuItemImages[ITM_BLACKO] = "images\\MenuItems\\BLACK.jpg";
	MenuItemImages[ITM_YELLOWO] = "images\\MenuItems\\YELLOW.jpg";
	MenuItemImages[ITM_ORANGEO] = "images\\MenuItems\\ORANGE.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\RED.jpg";
	MenuItemImages[ITM_GREENO] = "images\\MenuItems\\GREEN.jpg";
	MenuItemImages[ITM_BLUEO] = "images\\MenuItems\\BLUE.jpg";
	MenuItemImages[ITM_IN] = "images\\MenuItems\\OUT.jpg";
	MenuItemImages[ITM_playmode] = "images\\MenuItems\\playmode.jpg";
	MenuItemImages[ITM_VOICE] = "images\\MenuItems\\Voice.jpg";
	
	//potential voice?
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];


	MenuItemImages[ITM_hidetype] = "images\\MenuItems\\type.jpg";
	MenuItemImages[ITM_hidecolor] = "images\\MenuItems\\color.jpg";
	MenuItemImages[ITM_hidetypeandcolor] = "images\\MenuItems\\type&color.jpg";
	MenuItemImages[ITM_drawmode] = "images\\MenuItems\\drawmode.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	///TODO: write code to create Play mode menu
	
}
//////////////////////////////////////////////////////////////////////////////////////////



void Output::ClearDrawbar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
void Output::Clearplaybar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawSqr(Point P1, GfxInfo SqrGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;

	//constant 75
	int distance = 75;

	const int numVertices = 4;
	int xCoords[numVertices];
	int yCoords[numVertices];

	// Calculate the coordinates of the square's vertices
	xCoords[0] = P1.x - distance;
	yCoords[0] = P1.y - distance;

	xCoords[1] = P1.x + distance;
	yCoords[1] = P1.y - distance;

	xCoords[2] = P1.x + distance;
	yCoords[2] = P1.y + distance;

	xCoords[3] = P1.x - distance;
	yCoords[3] = P1.y + distance;

	// Call the DrawPolygon function to draw the square
	pWind->DrawPolygon(xCoords, yCoords, numVertices, style);
}



void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const //raya added
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawHex(Point P1, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	const int numVertices = 6;
	int x[numVertices];
	int y[numVertices];

	// Define the value of pi as an approximation
	const double pi = 3.14159265358979323846;

	//constant distance
	double distance = 75;

	// Calculate the coordinates of the hexagon vertices
	for (int i = 0; i < numVertices; i++) {
		double angle = 2 * pi / numVertices * i;
		x[i] = P1.x + distance * cos(angle);
		y[i] = P1.y + distance * sin(angle);
	}

	// Call the existing DrawPolygon function with the calculated vertices
	pWind->DrawPolygon(x, y, numVertices, style);
}
void Output::DrawCir(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	// Calculate the coordinates of the center and radius


	int radius = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2)); // Calculate the radius
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	// Set the drawing pen color
	pWind->SetPen(DrawingClr, 1);

	// Determine the drawing style (filled or frame)
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	// Draw the circle using the provided coordinates and style
	pWind->DrawCircle(P1.x, P1.y, radius, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

