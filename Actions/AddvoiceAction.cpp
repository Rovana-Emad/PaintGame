#include "AddvoiceAction.h"

#include "..\ApplicationManager.h"
#include "AddCirAction.h"
#include "AddHexAction.h"
#include "AddRectAction.h"
#include "AddSqrAction.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>


AddvoiceAction::AddvoiceAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddvoiceAction::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();


    pOut->PrintMessage("VOICE (ON/OFF) add a figure to try  ");

}

void AddvoiceAction::Execute()
{
    ReadActionParameters();

    if (pManager->voiceActivated == true) {
        pManager->voiceActivated = 0;
    }
    else {
        pManager->voiceActivated = true;
    }

}