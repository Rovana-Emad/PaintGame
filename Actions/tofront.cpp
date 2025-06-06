#include "tofront.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
tofront::tofront(ApplicationManager* pApp) :Action(pApp)
{
	figg = NULL;
}

void tofront::ReadActionParameters()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Bring to front icon, The selected Figure will be front all figures");
}
void tofront::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
		pManager->bringtofront();
}