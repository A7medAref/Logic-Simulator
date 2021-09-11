#include "AddLED.h"
#include "..\ApplicationManager.h"
#include "../LED.h"

AddLED::AddLED(ApplicationManager *pApp):Action(pApp)
{
	loaded = false;
}

AddLED::AddLED(ApplicationManager *pApp ,bool l ,int cx ,int cy) : Action(pApp)
{
	Cx = cx; Cy = cy; loaded = l;
}

AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	if (loaded == false)
		//Print Action Message
	{
		pOut->PrintMsg("LED: Click to add LED");

		//Wait for User Input
		pIn->GetPointClicked(Cx ,Cy);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
}

bool AddLED::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.OR2_Width;
	int Wdth = UI.OR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (pManager->CanDraw(Cx ,Cy))
	{
		LED *pA = new LED(GInfo ,0);
		pManager->AddComponent(GInfo ,pA);
	}
	return true;
}

void AddLED::Undo()
{
	Output *pOut = pManager->GetOutput();

	pManager->SelectComponent(Cx ,Cy);

	pManager->DeleteComp();
}

void AddLED::Redo()
{

	Output *pOut = pManager->GetOutput();


	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	LED *pA = new LED(GInfo ,0);
	pManager->AddComponent(GInfo ,pA);

}

