#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	//CreateDesignToolBar2();
	UI.AppMode = SIMULATION;
	CreateSimulationToolBar();
	UI.AppMode = DESIGN;
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (desgin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,UI.ToolBarHeight + 33 , UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Highlighted\\and.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Highlighted\\or.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\Highlighted\\not.jpg";
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\Highlighted\\buffer.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Highlighted\\nand.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Highlighted\\nor.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Highlighted\\xor.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Highlighted\\xnor.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Highlighted\\and3.jpg";
	MenuItemImages[ITM_OR3] = "images\\Menu\\Highlighted\\or3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Highlighted\\xor3.jpg";
	MenuItemImages[ITM_XNOR3] = "images\\Menu\\Highlighted\\xnor3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Highlighted\\nor3.jpg";
	MenuItemImages[ITM_NAND3] = "images\\Menu\\Highlighted\\nand3.jpg";
	MenuItemImages[ITM_SWT] = "images\\Menu\\Highlighted\\switch_off.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Highlighted\\led.jpg";      /// HERE ADD LED
	MenuItemImages[ITM_LINE] = "images\\Menu\\Highlighted\\line.jpg";

	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////   CREATE ANOTHER TOOLBAR2 /////2////
//void Output::CreateDesignToolBar2() const {
//
//	UI.AppMode = DESIGN;
//	
//
//
//	string MenuItemImages[ITM_DSN_CNT2];
//	
//	MenuItemImages[ITM_XNOR3] = "images\\Menu\\Highlighted\\xnor3.jpg";
//	MenuItemImages[ITM_NOR3] = "images\\Menu\\Highlighted\\nor3.jpg";
//	MenuItemImages[ITM_NAND3] = "images\\Menu\\Highlighted\\nand3.jpg";
//	MenuItemImages[ITM_SWT] = "images\\Menu\\Highlighted\\switch_off.jpg";
//	MenuItemImages[ITM_LED] = "images\\Menu\\Highlighted\\led.jpg";      /// HERE ADD LED
//	MenuItemImages[ITM_LINE] = "images\\Menu\\Highlighted\\line.jpg";
//	
//	
//
//	for (int i = 0; i < ITM_DSN_CNT2; i++)
//		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 83, UI.ToolItemWidth, UI.ToolBarHeight);
//
//
//
//		
//
//	pWind->SetPen(BLACK, 3);
//	pWind->DrawLine(0, UI.ToolBarHeight+80, UI.width, UI.ToolBarHeight+80);
//
//
//
//
//
//
//
//
//
//
//}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	//UI.AppMode = SIMULATION;	//Simulation Mode
	UI.AppMode = DESIGN;
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SIM] = "images\\Menu\\Highlighted\\SIM.jpg";
	MenuItemImages[ITM_DESIGN] = "images\\Menu\\Highlighted\\DESIGN.jpg";

	MenuItemImages[ITM_TRUTH] = "images\\Menu\\Highlighted\\TRUTH.jpg";
	MenuItemImages[ITM_Delete] = "images\\Menu\\Highlighted\\DELETE.jpg";
	MenuItemImages[ITM_Edit] = "images\\Menu\\Highlighted\\EDIT.jpg";
	MenuItemImages[ITM_Copy] = "images\\Menu\\Highlighted\\COPY.jpg";
	MenuItemImages[ITM_Cut] = "images\\Menu\\Highlighted\\CUT.jpg";
	MenuItemImages[ITM_Paste] = "images\\Menu\\Highlighted\\PASTE.jpg";
	MenuItemImages[ITM_Move] = "images\\Menu\\Highlighted\\MOVE.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Menu\\Highlighted\\SELECT.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Highlighted\\UNDO.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Highlighted\\REDO.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Highlighted\\SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Highlighted\\LOAD.jpg";
	MenuItemImages[ITM_1] = "images\\Menu\\Highlighted\\1.jpg";
	MenuItemImages[ITM_2] = "images\\Menu\\Highlighted\\2.jpg";
	MenuItemImages[ITM_3] = "images\\Menu\\Highlighted\\3.jpg";
	MenuItemImages[ITM_4] = "images\\Menu\\Highlighted\\4.jpg";


	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i] ,i * UI.ToolItemWidth ,62 ,UI.ToolItemWidth ,UI.ToolBarHeight2);
	pWind->SetPen(BLACK ,3);
	pWind->DrawLine(0 ,UI.ToolBarHeight + 30 ,UI.width ,UI.ToolBarHeight + 30);


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo ,bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage ,r_GfxInfo.x1 ,r_GfxInfo.y1 ,UI.OR2_Width ,UI.OR2_Height);
}
void Output::DrawNOT(GraphicsInfo r_GfxInfo ,bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_INV_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_INV.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage ,r_GfxInfo.x1 ,r_GfxInfo.y1 ,UI.NOT_Width ,UI.NOT_Height);
}
void Output::DrawBuff(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_Buff_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_Buff.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Buff_Width, UI.Buff_Height);
}
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR3_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_OR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}

void Output::DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR3_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawNAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND3_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_NAND3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpeg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH_ON.jpg";
	else
		GateImage = "Images\\Gates\\SWITCH_OFF.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED_ON.jpg";
	else
		GateImage = "Images\\Gates\\LED_OFF.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BLACK, 3);
	int b = r_GfxInfo.x1 + 6;
	/*int a = (r_GfxInfo.x1 + r_GfxInfo.x2) / 2;*/
	if (r_GfxInfo.y1 == r_GfxInfo.y2)
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, b, r_GfxInfo.y1, FRAME);
	}
	
	else {
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, b, r_GfxInfo.y1, FRAME);
		pWind->DrawLine(b, r_GfxInfo.y1, b, r_GfxInfo.y2, FRAME);
		pWind->DrawLine(b, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);
		//TODO: Add code to draw connection
	}

}


Output::~Output()
{
	delete pWind;
}
