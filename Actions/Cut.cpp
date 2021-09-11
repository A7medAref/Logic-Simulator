#include "Cut.h"
#include "Select.h"
#include "..\ApplicationManager.h"
Cut::Cut(ApplicationManager *pApp):Action(pApp)
{}

Cut::~Cut(void)
{}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Select an Item to Cut");
	//Wait for User Input
	pIn->GetPointClicked(Sx ,Sy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
bool Cut::Execute()
{
	//Get Point Selected
	ReadActionParameters();

	pManager->SelectComponent(Sx ,Sy);
	pManager->SetCopiedComp();
	//pManager->CutComp();
	pManager->DeleteComp();
	/*ReadActionParameters();
	pManager->PasteComp(Sx,Sy);*/
	return false;
}
void Cut::Undo()
{}

void Cut::Redo()
{}