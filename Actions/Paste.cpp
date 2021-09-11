#include "Paste.h"
#include "Select.h"
#include "..\ApplicationManager.h"
#include "../Components/BUFFER.h"
Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{}

Paste::~Paste(void)
{}

void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Select a location to Paste");
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
bool Paste::Execute()
{//Get Point Selected
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->PasteComp(Cx,Cy);
	
	return true;
}
void Paste::Undo()
{
	pManager->SelectComponent(Cx ,Cy);
	pManager->DeleteComp();
}

void Paste::Redo()
{
	pManager->PasteComp(Cx ,Cy);
}