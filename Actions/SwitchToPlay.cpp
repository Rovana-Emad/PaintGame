#include "SwitchToPlay.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) :Action(pApp)
{}

SwitchToPlay::~SwitchToPlay
()
{
}
void SwitchToPlay::ReadActionParameters() {

}

void SwitchToPlay::Execute() {
	Output* pOut = pManager->GetOutput();

	pOut->ClearStatusBar();
	ofstream File;

	pOut->PrintMessage("SWITCHED TO PLAY MODE");

	File.open("temp.txt");

	pManager->SaveAll(File);
	File.close();


	pOut->ClearDrawbar();
	pOut->CreatePlayToolBar();


}