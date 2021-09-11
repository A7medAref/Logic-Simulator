#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window

public:
	Input(window*);
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting(Output*, GraphicsInfo,bool again ,string LABEL)const;		//Returns a string entered by the user

	string GetString_InLoad(string l ,GraphicsInfo GfxInfo);
	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	~Input();
};
