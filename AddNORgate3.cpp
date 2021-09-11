#include "AddNORgate3.h"
#include "ApplicationManager.h"

AddNORgate3::AddNORgate3(ApplicationManager* pApp) :Action(pApp)
{
	loaded = false;
}
AddNORgate3::AddNORgate3(ApplicationManager *pApp ,bool l ,int cx ,int cy) : Action(pApp)
{
	loaded = l;
	Cx = cx; Cy = cy;
}
AddNORgate3::~AddNORgate3(void)
{
}

void AddNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (loaded == false)
	{
	//Print Action Message
	pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	}
}

bool AddNORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output *pOut = pManager->GetOutput();
	//Calculate the rectangle Corners
	int Len = UI.OR2_Width;
	int Wdth = UI.OR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (pManager->CanDraw(Cx ,Cy)) {
		NOR3 *pA = new NOR3(GInfo ,AND2_FANOUT);
		pManager->AddComponent(GInfo ,pA);
	}
	else
		pOut->PrintMsg("invalid location please tryagain ");

	return true;
}

void AddNORgate3::Undo()
{
	Output *pOut = pManager->GetOutput();

	pManager->SelectComponent(Cx ,Cy);

	pManager->DeleteComp();
}

void AddNORgate3::Redo()
{
	Output *pOut = pManager->GetOutput();


	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	NOR3 *pA = new NOR3(GInfo ,AND2_FANOUT);
	pManager->AddComponent(GInfo ,pA);
}

