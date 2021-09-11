#include "Select.h"
#include "..\ApplicationManager.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{}

Select::~Select(void)
{}

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Select an Item");

	//Wait for User Input
	pIn->GetPointClicked(Sx, Sy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
bool Select::Execute()
{
	//Get Point Selected
	ReadActionParameters();
	pManager->SelectComponent(Sx, Sy);
	return true;
}
void Select::Undo()
{
	pManager->UnSelect();
}

void Select::Redo()
{
	pManager->SelectComponent(Sx ,Sy);
}