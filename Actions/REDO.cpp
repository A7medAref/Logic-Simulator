#include "REDO.h"
#include "../SWITCH.h"

RedoAction::RedoAction(ApplicationManager *pApp):Action(pApp)
{
}

RedoAction::~RedoAction(void)
{
}

void RedoAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();


}

bool RedoAction::Execute()
{
	pManager->Redo();
	//pManager->GetOutput()->ClearStatusBar();
	return false;
}

void RedoAction::Undo()
{}

void RedoAction::Redo()
{}

