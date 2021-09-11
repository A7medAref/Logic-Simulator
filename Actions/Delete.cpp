#include "Delete.h"
#include "..\ApplicationManager.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{}

Delete::~Delete(void)
{}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Select an Item to Delete");
	//Wait for User Input
	pIn->GetPointClicked(Sx, Sy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
bool Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	//Get Point Selected
	ReadActionParameters();

	pManager->SelectComponent(Sx, Sy);
	pManager->DeleteComp();
	return true;
}
void Delete::Undo()
{
	pManager->SelectComponent(Sx ,Sy);
	pManager->SetCopiedComp();
	pManager->PasteComp(Sx ,Sy);
}

void Delete::Redo()
{
	pManager->SelectComponent(Sx ,Sy);
	pManager->DeleteComp();
}