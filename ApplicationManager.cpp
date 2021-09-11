#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include"AddORgate2.h"
#include"AddORgate3.h"
#include "AddANDgate3.h"
#include"AddNORgate3.h"
#include"AddNANDgate3.h"
#include "Actions/AddNANDgate2.h"
#include "AddNORgate2.h"
#include"AddXORgate2.h"
#include"Actions/AddXORgate3.h"
#include"AddXNORgate2.h"
#include "AddNORgate2.h"
#include"AddConc.h"
#include "Components\Connection.h"
#include"Components/Component.h"
#include"AddNOTgate.h"
#include"AddNORgate2.h"
#include "Actions/Select.h"
#include "Actions/Copy.h"
#include "Actions/Paste.h"
#include "Actions/Delete.h"
#include "Actions/Cut.h"
#include "Actions/AddSWITCH.h"
#include "Actions/AddLED.h"
#include "Actions/Simulate.h"
#include "NOR2.h"
#include "LED.h"
#include "Actions/UNDO.h"
#include "Actions/REDO.h"
#include "Actions/AddBUFFER.h"
#include "Actions/Edit.h"
#include "Actions/Save.h"
#include "Actions/Load.h"
#include "Actions/AddXNORgate3.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	Simulated = false;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;
	
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(GraphicsInfo GInfo,Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////
Component* ApplicationManager::getCopied() const
{
	return Copied_Component;
}
int ApplicationManager::GetCompCount()
{
	return CompCount;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteComp()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (i == SelectedComponent)
		{
			for (int j= 0; j < CompList[i]->Get_OutputPin().GetConnCount(); j++)
			{
				CompList[i]->Get_OutputPin().GetConnections()[j]->getDestPin()->SetConnected(false);
				CompList[i]->Get_OutputPin().GetConnections()[j]->getDestPin()->setStatus(LOW);
			}
			for (int j = 0; j < CompList[i]->Get_OutputPin().GetConnCount(); j++)
			{
				CompList[CompList[i]->Get_OutputPin().GetConnIndices()[j]]->SetDeleted(true);
			}
			CompList[SelectedComponent]->SetDeleted(true);
			SelectedComponent = -1;
			OutputInterface->ClearDrawingArea();
			UpdateInterface();
			break;
		}
	}
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::SetCopiedComp()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (i == SelectedComponent)
		{
			Copied_Component = CompList[i];
			CompList[SelectedComponent]->SetSelected(false);
		}
	}
}
void ApplicationManager::PasteComp(int Sx ,int Sy)
{
		int Len = UI.AND2_Width;
		int Width = UI.AND2_Height;
		GraphicsInfo PasteInfo;
		PasteInfo.x1 = Sx - Len / 2;
		PasteInfo.x2 = Sx + Len / 2;
		PasteInfo.y1 = Sy - Width / 2;
		PasteInfo.y2 = Sy + Width / 2;
		
		Output *pOut = GetOutput();
		  // Check the type of the Component to choose suitable Draw Function
		if (CanDraw(Sx,Sy)) {  
			AND2 *pA = dynamic_cast <AND2 *> ( Copied_Component );
			if (pA != NULL)
			{
				pA = new AND2(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pA);
				pA->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			AND3 *pB = dynamic_cast <AND3 *> ( Copied_Component );
			if (pB != NULL)
			{
				pB = new AND3(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pB);
				pB->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			BUFFER *pC = dynamic_cast <BUFFER *> ( Copied_Component );
			if (pC != NULL)
			{
				pC = new BUFFER(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pC);
				pC->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			NAND2 *pD = dynamic_cast <NAND2 *> ( Copied_Component );
			if (pD != NULL)
			{
				pD = new NAND2(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pD);
				pD->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			NAND3 *pE = dynamic_cast <NAND3 *> ( Copied_Component );
			if (pE != NULL)
			{
				pE = new NAND3(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pE);
				pE->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			NOT *pF = dynamic_cast <NOT *> ( Copied_Component );
			if (pF != NULL)
			{
				pF = new NOT(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pF);
				pF->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			NOR2 *pG = dynamic_cast <NOR2 *> ( Copied_Component );
			if (pG != NULL)
			{
				pG = new NOR2(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pG);
				pG->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			NOR3 *pH = dynamic_cast <NOR3 *> ( Copied_Component );
			if (pH != NULL)
			{
				pH = new NOR3(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pH);
				pH->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			OR2 *pI = dynamic_cast <OR2 *> ( Copied_Component );
			if (pI != NULL)
			{
				pI = new OR2(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pI);
				pI->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			OR3 *pJ = dynamic_cast <OR3 *> ( Copied_Component );
			if (pJ != NULL)
			{
				pJ = new OR3(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pJ);
				pJ->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			XNOR2 *pK = dynamic_cast <XNOR2 *> ( Copied_Component );
			if (pK != NULL)
			{
				pK = new XNOR2(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pK);
				pK->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			XNOR3 *pL = dynamic_cast <XNOR3 *> ( Copied_Component );
			if (pL != NULL)
			{
				pL = new XNOR3(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pL);
				pL->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			XOR2 *pM = dynamic_cast <XOR2 *> ( Copied_Component );
			if (pM != NULL)
			{
				pM = new XOR2(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pM);
				pM->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			XOR3 *pN = dynamic_cast <XOR3 *> ( Copied_Component );
			if (pN != NULL)
			{
				pN = new XOR3(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pN);
				pN->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			SWT *pO = dynamic_cast <SWT *> ( Copied_Component );
			if (pO != NULL)
			{
				pO = new SWT(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pO);
				pO->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
			LED *pQ = dynamic_cast <LED *> ( Copied_Component );
			if (pQ != NULL)
			{
				pQ = new LED(PasteInfo ,AND2_FANOUT);
				AddComponent(PasteInfo ,pQ);
				pQ->Draw(PasteInfo ,Copied_Component->GetSelected() ,pOut);
				return;
			}
		}
}

void ApplicationManager::EditComponent() 
{
	for (int i = 0; i < CompCount; i++)
	{
		if (i == SelectedComponent)
		{
			GraphicsInfo position = CompList[SelectedComponent]->GetGraphicsInfo();
			position.y1 -= 25;
			if (CompList[SelectedComponent]->GetLabel() == "ignore")  //ignore mean with no name
			{
				CompList[SelectedComponent]->SetLabel(InputInterface->GetSrting(OutputInterface ,position ,false ," "));
			}
			else
			{
				CompList[SelectedComponent]->SetLabel(InputInterface->GetSrting(OutputInterface ,position ,true ,CompList[SelectedComponent]->GetLabel()));
			}
			CompList[SelectedComponent]->SetSelected(false);
			SelectedComponent = -1;

		}
	}
}

void ApplicationManager::Msave(ofstream &h) //save information of all gates
{
	h << CompCount << endl;
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->save(h);
	}
}

void ApplicationManager::Mload(ifstream &h) //add gates according to data come from text file data
{
	for (int i = 0; i < CompCount; i++)
	{
		delete CompList[i];
		OutputInterface->ClearDrawingArea();
	}
	CompCount = 0; int f = 0; lP l; Action *pAct;
	h >> f; string name; GraphicsInfo GInfo;
	for (int i = 0; i < f; i++)
	{
		h >> name;
		if (name == "connection")
		{
			h >> GInfo.x1; h >> GInfo.x2; h >> GInfo.y1; h >> GInfo.y2;
			pAct = new AddConc(this ,true ,GInfo);
			pAct->Execute();
		}
		if (name != "connection")
		{
			h >> l.cx; h >> l.cy;
		}
		if (name == "AND2")
		{
			pAct = new AddANDgate2(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		if (name == "AND3")
		{
			pAct = new AddANDgate3(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		if (name == "LED")
		{
			pAct = new AddLED(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "NAND3")
		{
			pAct = new AddNANDgate3(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "NOR3")
		{
			pAct = new AddNORgate3(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "NOR2")
		{
			pAct = new AddNORgate2(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "Switch")
		{
			pAct = new AddSWITCH(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "XNOR2")
		{
			pAct = new AddXNORgate2(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "XOR2")
		{
			pAct = new AddXORgate2(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "NOT")
		{
			pAct = new AddNOTgate(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "OR2")
		{
			pAct = new AddORgate2(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "OR3")
		{
			pAct = new AddORgate3(this ,true ,l.cx ,l.cy);
			pAct->Execute();
		}
		else if (name == "NAND2")
		{
			pAct = new AddNANDgate2(this, true, l.cx, l.cy);
			pAct->Execute();
		}
		else if (name == "XOR3")
		{
			pAct = new AddXORgate3(this, true, l.cx, l.cy);
			pAct->Execute();
		}
		else if (name == "XNOR3")
		{
			pAct = new AddXNORgate3(this, true, l.cx, l.cy);
			pAct->Execute();
		}
		else if (name == "BUFFER")
		{
			pAct = new AddBUFFERgate(this, true, l.cx, l.cy);
			pAct->Execute();
		}
		h >> name;
		if (name != "ignore")
		{

			GInfo.x1 = l.cx-20; GInfo.x2 = l.cx; GInfo.y1 = l.cy; GInfo.y2 = l.cy;
			GInfo.y1 -= 50;
			CompList[i]->SetLabel(InputInterface->GetString_InLoad(name ,GInfo));
		}
	}
}

void ApplicationManager::SimulateComponents()
{
	Simulated = true;
	// Calls operate Function of the Component if not deleted
	//Switches first then gates the LEDs
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetDeleted() == false)
		{
			SWT *ptr = dynamic_cast<SWT *>( CompList[i] );
			if (ptr != NULL)
			{
				CompList[i]->Operate();
				for (int j = 0; j < CompList[i]->Get_OutputPin().GetConnCount(); j++)
				{
					CompList[i]->Get_OutputPin().GetConnections()[j]->Operate();
				}
			}
		}
	}
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetDeleted() == false)
		{
			LED *Ledptr = dynamic_cast<LED *>( CompList[i] );
			if (Ledptr == NULL)
			{
				CompList[i]->Operate();
				for (int j = 0; j < CompList[i]->Get_OutputPin().GetConnCount(); j++)
				{
					CompList[i]->Get_OutputPin().GetConnections()[j]->Operate();
				}
			}
		}
	}
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetDeleted() == false)
		{
			LED *Ledptr = dynamic_cast<LED *>( CompList[i] );
			if (Ledptr != NULL)
			{
				CompList[i]->Operate();
			}
		}
	}
}

void ApplicationManager::ChangeSimulation() // To reset Simulation
{
	Simulated = false;
}

bool ApplicationManager::GetSimulated() 
{
	return Simulated;
}

void ApplicationManager::UnSelect() // Unselect all Components
{
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->SetSelected(false);
		SelectedComponent = -1;
	}
}
//Check if the position clicked is valid for Drawing the component
bool ApplicationManager::CanDraw(int Sx ,int Sy)
{

	int x = 1;
	
	if (( Sy >= UI.ToolBarHeight + 33 + 25 ) && Sy < UI.height - UI.StatusBarHeight - 20)

	{
		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i]->GetDeleted() == false)
			{
				
				if (Sx >= CompList[i]->GetGraphicsInfo().x1 - 25 && Sx <= CompList[i]->GetGraphicsInfo().x1 + 50 + 25)
				{
					if (Sy >= CompList[i]->GetGraphicsInfo().y1 - 25 && Sy <= CompList[i]->GetGraphicsInfo().y1 + 50 + 25)
					{
						x = 0;
						break;
					}
				}
			}
				else
					x = 1;
		}

	}
	else
		x = 0;

	return x;
}


///////////////////////////////////////////////////////////////////
//Selects the clicked Component
void ApplicationManager::SelectComponent(int Sx, int Sy)
{

	for (int i = 0; i < CompCount; i++)
	{
		if (Sx >= CompList[i]->GetGraphicsInfo().x1 && Sx <= CompList[i]->GetGraphicsInfo().x1 + 50)
			if (Sy >= CompList[i]->GetGraphicsInfo().y1 && Sy <= CompList[i]->GetGraphicsInfo().y1 + 50)
			{
				/*if (SelectedComponent >= 0 && SelectedComponent != i)
				{
					CompList[SelectedComponent]->SetSelected(false);
				}*/
				CompList[i]->SelectComp();
				if (CompList[i]->GetSelected() == false)
				{
					SelectedComponent = -1;
				}
				else {
					SelectedComponent = i;
				}
			}
	}
}


ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;
	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;
	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;
	case ADD_OR_GATE_3:
		pAct = new AddORgate3(this);
		break;
	case EDIT_Label:
		pAct = new Edit(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;
	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;
	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;
	case ADD_NAND_GATE_3:
		pAct = new AddNANDgate3(this);
		break;
	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;
	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;
	case ADD_XNOR_GATE_3:
		pAct = new AddXNORgate3(this);
		break;
	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;
	case ADD_INV:
		pAct = new AddNOTgate(this);
		break;
	case ADD_BUFF:
		pAct = new AddBUFFERgate(this);
		break;
	case ADD_Switch:
		pAct = new AddSWITCH(this);
		break;
	case ADD_LED:
		pAct = new AddLED(this);
		break;
	case DEL:
		pAct = new Delete(this);
		break;
	case LOAD:
		pAct = new Load(this);
		break;
	case SAVE:
		pAct = new Save(this);
		break;
	case ADD_CONNECTION:
			pAct = new AddConc(this);
			break;
	case REDO:
			pAct = new RedoAction(this);
			break;
	case UNDO:
			pAct = new UndoAction(this);
			break;
	case COPY:
		pAct = new Copy(this);
		break;
	case CUT:
		pAct = new Cut(this);
		break;
	case PASTE:
		pAct = new Paste(this);
		break;
	case SIM_MODE:
		pAct = new Simulate(this);
		break;
			

		case EXIT:
			break;
	}
	/*if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}*/
	if (pAct != NULL) {
		if (pAct->Execute()) {
			UndoStack.push(pAct);
		}
		else {
			delete pAct;
		}
	}
}
////////////////////////////////////////////////////////////////////
//reDraws all existing Components (not deleted)
void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			if (CompList[i]->GetDeleted() != true)
			{
				CompList[i]->Draw(OutputInterface);
			}
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}
//Check if there can be a connection between clicked Points
bool ApplicationManager::ValidConnenction(GraphicsInfo* g, Component*& p1, Component* &p2)
{
	bool done = 0;
	for (int i = 0; i<CompCount; i++)
	{
		if (CompList[i]->GetGraphicsInfo().x1 <= g->x1 && CompList[i]->GetGraphicsInfo().x2 >= g->x1 &&
			CompList[i]->GetGraphicsInfo().y1 <= g->y1 && CompList[i]->GetGraphicsInfo().y2 >= g->y1
			&& dynamic_cast<Connection*>(CompList[i]) == NULL)
		{
			for (int j = 0; j < CompCount; j++)
			{
				if (CompList[j]->GetGraphicsInfo().x1 <= g->x2 && CompList[j]->GetGraphicsInfo().x2 >= g->x2 &&
					CompList[j]->GetGraphicsInfo().y1 <= g->y2 && CompList[j]->GetGraphicsInfo().y2 >= g->y2
					&& dynamic_cast<Connection*>(CompList[j]) == NULL && CompList[j] != CompList[i])
				{
					p1 = CompList[i]; p2 = CompList[j];
					LED *Ledptr = dynamic_cast <LED*> (p1);
					if (Ledptr != NULL)
					{
						done = false;
						break;
					}
					done = true;
					break;
				}

			}
			
		}
	}
	return done;
}

void ApplicationManager::Undo()
{
	if (UndoStack.empty()) {
		return;
	}
	OutputInterface->PrintMsg("Undo");
	Action *lastAction = UndoStack.top();

	lastAction->Undo();

	UndoStack.pop();
	RedoStack.push(lastAction);
}

void ApplicationManager::Redo()
{
	if (RedoStack.empty()) {
		return;
	}
	OutputInterface->PrintMsg("REDO");
	Action *lastAction = RedoStack.top();
	lastAction->Redo();
	RedoStack.pop();
	UndoStack.push(lastAction);
}

Component *ApplicationManager::getlastcomp()
{
	return  CompList[CompCount];
}
