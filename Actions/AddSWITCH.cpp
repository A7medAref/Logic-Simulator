#include "AddSWITCH.h"
#include "..\ApplicationManager.h"
AddSWITCH::AddSWITCH(ApplicationManager *pApp):Action(pApp)
{
	loaded = false;
}

AddSWITCH::~AddSWITCH(void)
{
}

AddSWITCH::AddSWITCH(ApplicationManager *pApp ,bool l ,int cx ,int cy): Action(pApp)
{
	loaded = l;
	Cx = cx; Cy = cy;
}




void AddSWITCH::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	if (loaded == false)
	{
		//Print Action Message
		pOut->PrintMsg("SWITCH: Click to add SWITCH");

		//Wait for User Input
		pIn->GetPointClicked(Cx ,Cy);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
	else
	{

	}
}

bool AddSWITCH::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output *pOut = pManager->GetOutput();
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
		SWT *D = new SWT(GInfo ,AND2_FANOUT);
		pManager->AddComponent(GInfo ,D);
	}
	else
		pOut->PrintMsg("invalid location please tryagain ");

	return true;
}
void AddSWITCH::Undo()
{
	Output *pOut = pManager->GetOutput();



	pManager->SelectComponent(Cx ,Cy);


	pManager->DeleteComp();
}

void AddSWITCH::Redo()
{

	Output *pOut = pManager->GetOutput();


	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	SWT *pA = new SWT(GInfo ,AND2_FANOUT);
	pManager->AddComponent(GInfo ,pA);

}

