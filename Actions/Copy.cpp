#include "Copy.h"
#include "Select.h"
#include "..\ApplicationManager.h"
Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{}

Copy::~Copy(void)
{}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Select an Item to Copy");
	//Wait for User Input
	pIn->GetPointClicked(Sx, Sy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
bool Copy::Execute()
{
	//Get Point Selected
	ReadActionParameters();

	pManager->SelectComponent(Sx, Sy);
	pManager->SetCopiedComp();
	return false;
}
void Copy::Undo()
{}

void Copy::Redo()
{}