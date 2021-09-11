#include "UNDO.h"
#include "../Switch.h"

UndoAction::UndoAction(ApplicationManager *pApp):Action(pApp)
{
}

UndoAction::~UndoAction(void)
{
}

void UndoAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();

}

bool UndoAction::Execute()
{
	//Get Center point of the Gate
	pManager->Undo();
	//pManager->GetOutput()->ClearStatusBar();

	return false;


}

void UndoAction::Undo()
{
	//Output* pOut = pManager->GetOutput();
	//pOut->PrintMsg("und");

}

void UndoAction::Redo()
{}

