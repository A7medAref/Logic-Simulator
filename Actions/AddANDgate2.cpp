#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
	loaded = 0;
}
AddANDgate2::AddANDgate2(ApplicationManager *pApp ,bool l ,int cx ,int cy) : Action(pApp)
{
	loaded = l;
	Cx = cx; Cy = cy;
}
AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (loaded == false)
	{
		//Print Action Message
		pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

		//Wait for User Input
		pIn->GetPointClicked(Cx ,Cy);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
}

bool AddANDgate2::Execute()
{
	Output *pOut = pManager->GetOutput();
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Width = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Width/2;
	GInfo.y2 = Cy + Width/2;
	if (pManager->CanDraw(Cx ,Cy))
	{

		AND2* pA = new AND2(GInfo, AND2_FANOUT);
		pManager->AddComponent(GInfo, pA);
	}
	else
		pOut->PrintMsg("invalid location please tryagain ");

	return true;
}

void AddANDgate2::Undo()
{
	Output *pOut = pManager->GetOutput();
	pManager->SelectComponent(Cx ,Cy);
	pManager->DeleteComp();
}

void AddANDgate2::Redo()
{
	Output *pOut = pManager->GetOutput();


	int Len = UI.AND2_Width;
	int Width = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Width / 2;
	GInfo.y2 = Cy + Width / 2;
	AND2 *pA = new AND2(GInfo ,AND2_FANOUT);
	pManager->AddComponent(GInfo ,pA);
}

