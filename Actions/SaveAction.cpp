#include "SaveAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}
void SaveAction::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    // Read the file name
    pOut->PrintMessage("Enter File Name");
    inputstring = pIn->GetSrting(pOut);
    pOut->PrintMessage("File is saved");
}

void SaveAction::Execute()
{    
    ReadActionParameters();
    ofstream OutputFile;
    string fileName = inputstring + ".txt"; // Append .txt extension So its always a text file
    OutputFile.open(fileName, ios::out | ios::trunc); // Use of  ios::trunc flag is  to overwrite the file if it  already  exists
    pManager->SaveAll(OutputFile);
    OutputFile.close();
}


