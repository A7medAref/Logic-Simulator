#include "Simulate.h"
#include "..\ApplicationManager.h"

Simulate::Simulate(ApplicationManager *pApp):Action(pApp)
{

}

Simulate::~Simulate(void)
{
}

void Simulate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Simulate");

	//Wait for User Input
	pIn->GetPointClicked(Cx ,Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

bool Simulate::Execute()
{

	if (pManager->GetSimulated()==false)
	{
		pManager->SimulateComponents();
	}
	else {
		pManager->ChangeSimulation();
		pManager->UnSelect();
	}
	return false;
}

void Simulate::Undo()
{}

void Simulate::Redo()
{}

