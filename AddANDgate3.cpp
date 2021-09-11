#include "AddANDgate3.h"
#include "ApplicationManager.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp) :Action(pApp)
{
	loaded = false;
}
AddANDgate3::AddANDgate3(ApplicationManager *pApp ,bool l ,int cx ,int cy) : Action(pApp)
{
	loaded = true; Cx = cx; Cy = cy;
}
AddANDgate3::~AddANDgate3(void)
{
}

void AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (loaded == false) //in case of loaded it wouldn't take a point from user
	{
		//Print Action Message
		pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

		//Wait for User Input
		pIn->GetPointClicked(Cx ,Cy);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
}

bool AddANDgate3::Execute()
{
	Output *pOut = pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (pManager->CanDraw(Cx ,Cy))
	{
		AND3 *pA = new AND3(GInfo ,AND2_FANOUT);
		pManager->AddComponent(GInfo ,pA);
	}
	else {
		pOut->PrintMsg("invalid location please tryagain ");
	}
	return true;
}

void AddANDgate3::Undo()
{
	Output *pOut = pManager->GetOutput();
	pManager->SelectComponent(Cx ,Cy);
	pManager->DeleteComp();
}

void AddANDgate3::Redo()
{

	Output *pOut = pManager->GetOutput();


	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	AND3 *pA = new AND3(GInfo ,AND2_FANOUT);
	pManager->AddComponent(GInfo ,pA);
}

