#include "Input.h"
#include "Output.h"
#include <iostream>
using namespace std;
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut, GraphicsInfo GfxInfo, bool again, string LABEL) const {
	if (again)
	{
		pWind->SetPen(WHITE, 1);
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle((GfxInfo.x1) + 10, (GfxInfo.y1) + 23, (GfxInfo.x1) + LABEL.length() * 18, (GfxInfo.y1) + 3);
	}
	const int ESCAPE = 27;
	const int ENTER = 13;
	const int BACKSPACE = 8;

	char c;
	string s = " ";

	pWind->FlushKeyQueue();

	do {
		pOut->PrintMsg(s);
		pWind->WaitKeyPress(c);

		switch (c) {
		case BACKSPACE:
			if (!s.empty()) s.pop_back();
			break;
		case ESCAPE:
			s.clear();
			break;
		case ENTER:
			// Nothing to be done here
			break;
		default:
			s.push_back(c);
			break;
		}

	} while (c != ESCAPE && c != ENTER);
	pWind->DrawString((GfxInfo.x1) + 5, (GfxInfo.y1) + 5, s);

	return s;
}

string Input::GetString_InLoad(string l ,GraphicsInfo GfxInfo)
{
	pWind->SetPen(BLACK ,1);

	pWind->DrawString(( GfxInfo.x1 ) + 5 ,( GfxInfo.y1 ) + 5 ,l);
	return l;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NOT: return ADD_INV;
			case ITM_BUFFER: return ADD_BUFF;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_OR3: return ADD_OR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_XNOR3: return ADD_XNOR_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_NAND3: return ADD_NAND_GATE_3;
			case ITM_EXIT: return EXIT;
			case ITM_SWT: return ADD_Switch;
			case ITM_LED: return ADD_LED;
			case ITM_LINE: return ADD_CONNECTION;
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		if (y > UI.ToolBarHeight + 1 && y < UI.ToolBarHeight + 30) {

			int ClickedItemOrder = ( x / UI.ToolItemWidth );
			switch (ClickedItemOrder)
			{


			case ITM_SIM: return SIM_MODE;
			case ITM_DESIGN: return DSN_MODE;
			case ITM_TRUTH: return Create_TruthTable;
			case ITM_Delete: return DEL;
			case ITM_Edit: return 	EDIT_Label;
			case  ITM_Copy: return COPY;
			case ITM_Cut: return CUT;
			case ITM_Paste: return PASTE;
			case ITM_Move: return 	MOVE;
			case ITM_SELECT: return SELECT;
			case ITM_UNDO: return 	UNDO;
			case ITM_REDO: return 	REDO;
			case ITM_SAVE: return 	SAVE;
			case ITM_LOAD: return 	LOAD;





			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}

		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight2 && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
