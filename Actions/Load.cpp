#include "Load.h"
#include "..\ApplicationManager.h"

Load::Load(ApplicationManager *pApp):Action(pApp)
{}

Load::~Load(void)
{}

void Load::ReadActionParameters()
{

}
bool Load::Execute()
{
	read.open("data.txt");
	pManager->Mload(read);
	read.close();
	Output *pOut = pManager->GetOutput();
	pOut->PrintMsg("loaded");
	return false;
}
void Load::Undo()
{}

void Load::Redo()
{}