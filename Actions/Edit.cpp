#include "Edit.h"
#include "..\ApplicationManager.h"

Edit::Edit(ApplicationManager *pApp):Action(pApp)
{}

Edit::~Edit(void)
{}

void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("select an item to edit");
	//Wait for User Input
	pIn->GetPointClicked(Sx ,Sy);
	//Clear Status Bar
	pOut->ClearStatusBar();
}
bool Edit::Execute()
{
	//Get Point Selected
	ReadActionParameters();
	pManager->SelectComponent(Sx ,Sy);
	pManager->EditComponent();
	Output *pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	return false;
}
void Edit::Undo()
{}

void Edit::Redo()
{}