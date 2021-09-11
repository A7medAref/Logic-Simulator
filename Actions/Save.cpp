#include "Save.h"
#include "..\ApplicationManager.h"

Save::Save(ApplicationManager *pApp):Action(pApp)
{}

Save::~Save(void)
{}

void Save::ReadActionParameters()
{

}
bool Save::Execute()
{
	Output *pOut = pManager->GetOutput();
	write.open("data.txt");
	write.clear();
	pManager->Msave(write);
	pOut->PrintMsg("saved");
	write.close();
	return false;
}
void Save::Undo()
{}

void Save::Redo()
{}