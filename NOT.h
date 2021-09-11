#pragma once
#ifndef _NOT_H
#define _NOT_H
#include"Components/Gate.h"
class NOT :public Gate
{
public:
	NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void Draw(GraphicsInfo, bool, Output* pOut);
	virtual OutputPin& Get_OutputPin();
	virtual InputPin *Get_InputPin();
	virtual int GetInputs();

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual int no();
	virtual void Set_noOfConnectedPins(int x);
	void save(ofstream &file);
};
#endif